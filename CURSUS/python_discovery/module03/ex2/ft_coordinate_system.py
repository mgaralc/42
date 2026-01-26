import math

if __name__ == "__main__":
    orig = (0, 0, 0)
    print("=== Game Coordinate System ===\n")
    pos1 = (10, 20, 5)

    print(f"Position created: {pos1}")
    dist = math.sqrt(
        (pos1[0] - orig[0]) ** 2 +
        (pos1[1] - orig[1]) ** 2 +
        (pos1[2] - orig[2]) ** 2
    )
    print(f"Distance between {orig} and {pos1}: {dist:.2f}\n")

    pos2 = "3,4,0"
    print(f'Parsing coordinates: "{pos2}"')
    parts = pos2.split(",")
    parsed_pos2 = (int(parts[0]), int(parts[1]), int(parts[2]))
    print(f"Parsed position: {parsed_pos2}")
    dist2 = math.sqrt(
        (parsed_pos2[0] - orig[0]) ** 2 +
        (parsed_pos2[1] - orig[1]) ** 2 +
        (parsed_pos2[2] - orig[2]) ** 2
    )
    print(f"Distance between {orig} and {parsed_pos2}: {dist2}\n")

    bad = "abc,def,ghi"
    print(f'Parsing invalid coordinates: "{bad}"')
    try:
        parts = bad.split(",")
        parsed_bad = (int(parts[0]), int(parts[1]), int(parts[2]))
        print(f"Parsed position: {parsed_bad}")
    except ValueError as e:
        print(f"Error parsing coordinates: {e}")
        print(
            "Error details - Type: "
            f"{type(e).__name__}, Args: {e.args}\n"
        )

    print("Unpacking demonstration:")
    x, y, z = parsed_pos2
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, Z={z}")
