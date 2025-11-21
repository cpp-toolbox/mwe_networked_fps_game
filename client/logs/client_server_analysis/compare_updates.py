import re

# Regexes for parsing
id_regex = re.compile(r"id=(\d+)")
state_after_regex = re.compile(
    r"State after updating: \{yaw=([-0-9.e+]+), pitch=([-0-9.e+]+), "
    r"last_mouse_position_x=([-0-9.e+]+), last_mouse_position_y=([-0-9.e+]+)\}"
)


def parse_log_file(path):
    updates = {}  # id -> (state dict, line number)
    with open(path, "r") as f:
        lines = f.readlines()

    current_id = None

    for i, line in enumerate(lines):
        # Extract ID if this line begins an update
        m_id = id_regex.search(line)
        if m_id:
            current_id = int(m_id.group(1))

        # Extract `State after updating`
        m_state = state_after_regex.search(line)
        if m_state and current_id is not None:
            yaw, pitch, lx, ly = m_state.groups()
            updates[current_id] = (
                {
                    "yaw": float(yaw),
                    "pitch": float(pitch),
                    "last_mouse_position_x": float(lx),
                    "last_mouse_position_y": float(ly),
                },
                i + 1,
            )  # store 1-based line number

            # Reset so the next update must have a new id
            current_id = None

    return updates


client_updates = parse_log_file("client_logs.txt")
server_updates = parse_log_file("server_logs.txt")

# Compare updates
all_ids = sorted(set(client_updates.keys()) & set(server_updates.keys()))

print(f"Found {len(all_ids)} matching update IDs.\n")

for update_id in all_ids:
    client_state, client_line = client_updates[update_id]
    server_state, server_line = server_updates[update_id]

    diffs = []
    for key in client_state:
        if (
            abs(client_state[key] - server_state[key]) > 1e-9
        ):  # float comparison tolerance
            diffs.append((key, client_state[key], server_state[key]))

    if diffs:
        print(f"❌ MISMATCH for update id={update_id}:")
        print(f"   client_logs.txt line {client_line}")
        print(f"   server_logs.txt line {server_line}")
        for key, cval, sval in diffs:
            print(f"     {key}: client={cval}  server={sval}")
        print()
