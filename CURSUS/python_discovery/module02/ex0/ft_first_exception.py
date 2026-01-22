def check_temperature(temp_str):
    print(f"Testing temperature: {temp_str}")
    try:
        convert = int(temp_str)
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number\n")
        return

    if (convert >= 0 and convert <= 40):
        print(f"Temperature {temp_str}°C is perfect for plants!\n")
    elif (convert < 0):
        print(f"Error: {temp_str}°C is too cold for plants (min 0°C)\n")
    elif (convert > 40):
        print(f"Error: {temp_str}°C is too hot for plants (max 40°C)\n")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    check_temperature("25")
    check_temperature("abc")
    check_temperature("100")
    check_temperature("*50")

    print("All tests completed – program didn’t crash!")
