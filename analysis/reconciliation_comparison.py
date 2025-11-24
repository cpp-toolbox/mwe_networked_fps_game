import re
import sys
from dataclasses import dataclass
from typing import Dict, Tuple, Optional

# ============
# Data Classes
# ============


@dataclass
class PhysicsState:
    position: Tuple[float, float, float]
    velocity: Tuple[float, float, float]


@dataclass
class UpdateEvent:
    update_id: int
    dt: float
    before: Optional[PhysicsState]
    after: Optional[PhysicsState]


# ============
# Regex Patterns
# ============

# Example:
# Applying input: {id=101, character_physics_update_data={dt=0.001976,...
apply_re = re.compile(
    r"Applying (?:input|update):.*?id=(\d+).*?dt=([0-9.]+)",
)

state_before_re = re.compile(
    r"State before updating: \{position=\(([^)]+)\), velocity=\(([^)]+)\)\}"
)

state_after_re = re.compile(
    r"State after updating: \{position=\(([^)]+)\), velocity=\(([^)]+)\)\}"
)


# Utility to parse "(x, y, z)"
def parse_vec3(s: str) -> Tuple[float, float, float]:
    return tuple(float(v.strip()) for v in s.split(","))


# =============
# Parsing Logic
# =============


def parse_log(path: str) -> Dict[int, UpdateEvent]:
    """
    Parse either the client or server log.
    Returns dict: update_id -> UpdateEvent
    """
    updates: Dict[int, UpdateEvent] = {}

    current_id = None
    current_dt = None
    current_before = None

    with open(path, "r") as f:
        for line in f:
            # Detect "Applying input"/"Applying update"
            m = apply_re.search(line)
            if m:
                current_id = int(m.group(1))
                current_dt = float(m.group(2))
                updates[current_id] = UpdateEvent(
                    update_id=current_id, dt=current_dt, before=None, after=None
                )
                continue

            # Detect "State before updating"
            m = state_before_re.search(line)
            if m and current_id is not None:
                pos = parse_vec3(m.group(1))
                vel = parse_vec3(m.group(2))
                updates[current_id].before = PhysicsState(position=pos, velocity=vel)
                continue

            # Detect "State after updating"
            m = state_after_re.search(line)
            if m and current_id is not None:
                pos = parse_vec3(m.group(1))
                vel = parse_vec3(m.group(2))
                updates[current_id].after = PhysicsState(position=pos, velocity=vel)
                continue

    return updates


# =====================
# Comparison Logic
# =====================


def almost_equal(a: float, b: float, tol: float = 1e-5) -> bool:
    return abs(a - b) <= tol


def compare_states(s1: PhysicsState, s2: PhysicsState, what: str, uid: int):
    diffs = []
    for n, v1, v2 in [
        ("pos.x", s1.position[0], s2.position[0]),
        ("pos.y", s1.position[1], s2.position[1]),
        ("pos.z", s1.position[2], s2.position[2]),
        ("vel.x", s1.velocity[0], s2.velocity[0]),
        ("vel.y", s1.velocity[1], s2.velocity[1]),
        ("vel.z", s1.velocity[2], s2.velocity[2]),
    ]:
        if not almost_equal(v1, v2):
            diffs.append(f"{n}: client={v1} server={v2}")

    if diffs:
        print("❌ State mismatch for update id", uid, f"({what} state)")
        for d in diffs:
            print("   ", d)


# =====================
# Main Comparison
# =====================


def compare(client_path: str, server_path: str):
    client_updates = parse_log(client_path)
    server_updates = parse_log(server_path)

    print(f"extracted {len(client_updates)} many client updates")
    print(f"extracted {len(server_updates)} many server updates")

    print("======== COMPARING LOGS ========")

    all_client_ids = sorted(client_updates.keys())
    all_server_ids = sorted(server_updates.keys())

    # ---------- Missing Updates ----------
    print("\n--- Checking missing updates ---")
    for cid in all_client_ids:
        if cid not in server_updates:
            print(f"❌ Update ID {cid} exists on client but NOT on server!")

    # ---------- State Mismatch ----------
    print("\n--- Checking state mismatches ---")
    for cid in all_client_ids:
        if cid not in server_updates:
            continue

        cu = client_updates[cid]
        su = server_updates[cid]

        if cu.after is None or su.after is None:
            print(f"⚠️ Missing state data for update {cid}")
            continue

        # Compare AFTER states
        compare_states(cu.after, su.after, "after", cid)

        # You can also compare BEFORE states if desired:
        if cu.before and su.before:
            compare_states(cu.before, su.before, "before", cid)

    print("\nDone.")


# =====================
# Command-line Entrypoint
# =====================

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python compare_physics_logs.py <client_log> <server_log>")
        sys.exit(1)

    compare(sys.argv[1], sys.argv[2])
