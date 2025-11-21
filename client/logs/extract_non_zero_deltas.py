import re
import sys

# Regex patterns
physics_regex = re.compile(
    r"delta position=\(([-0-9\.eE]+), ([-0-9\.eE]+), ([-0-9\.eE]+)\), "
    r"delta velocity=\(([-0-9\.eE]+), ([-0-9\.eE]+), ([-0-9\.eE]+)\)"
)

camera_regex = re.compile(
    r"delta yaw=([-0-9\.eE]+), delta pitch=([-0-9\.eE]+), "
    r"delta last_mouse_position_x=([-0-9\.eE]+), delta last_mouse_position_y=([-0-9\.eE]+)"
)


def is_non_zero(x):
    try:
        return float(x) != 0.0
    except:
        return True  # in case of weird formatting


def process_physics_line(line, line_number, show_zero):
    m = physics_regex.search(line)
    if not m:
        return None

    pos = tuple(m.group(i) for i in range(1, 4))
    vel = tuple(m.group(i) for i in range(4, 7))

    if any(is_non_zero(v) for v in pos + vel):
        return f"[line {line_number}] Non-zero delta found:\ndelta position={pos}, delta velocity={vel}\n"
    elif show_zero:
        return f"[line {line_number}] Zero delta found:\ndelta position={pos}, delta velocity={vel}\n"

    return None


def process_camera_line(line, line_number, show_zero):
    m = camera_regex.search(line)
    if not m:
        return None

    yaw, pitch, mouse_x, mouse_y = (m.group(i) for i in range(1, 5))

    if any(is_non_zero(v) for v in (yaw, pitch, mouse_x, mouse_y)):
        return (
            f"[line {line_number}] Non-zero delta found:\n"
            f"delta yaw={yaw}, delta pitch={pitch}, "
            f"delta last_mouse_position_x={mouse_x}, delta last_mouse_position_y={mouse_y}\n"
        )
    elif show_zero:
        return (
            f"[line {line_number}] Zero delta found:\n"
            f"delta yaw={yaw}, delta pitch={pitch}, "
            f"delta last_mouse_position_x={mouse_x}, delta last_mouse_position_y={mouse_y}\n"
        )

    return None


def main():
    if len(sys.argv) < 2:
        print(f"Usage: python {sys.argv[0]} <log_file> [--show-zero]")
        sys.exit(1)

    log_path = sys.argv[1]
    show_zero = "--show-zero" in sys.argv

    with open(log_path, "r") as f, open(
        "physics_deltas.txt", "w"
    ) as physics_file, open("camera_deltas.txt", "w") as camera_file:

        for line_number, line in enumerate(f, start=1):
            physics_result = process_physics_line(line, line_number, show_zero)
            if physics_result:
                physics_file.write(physics_result)

            camera_result = process_camera_line(line, line_number, show_zero)
            if camera_result:
                camera_file.write(camera_result)

    print(
        "Processing complete. Results saved to 'physics_deltas.txt' and 'camera_deltas.txt'."
    )


if __name__ == "__main__":
    main()
