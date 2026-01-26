def water_plants(plant_list):
    print("=== Garden Watering System ===\n")
    print("Testing normal watering...")

    try:
        for plant in (plant_list):
            if not isinstance(plant, str) or plant == "":
                raise ValueError
            print(f"Watering {plant}")
    except ValueError:
        print(f"Error: Cannot water {plant} - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")

    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    plants = ["tomato", "lettuce", None, "", 423]
    water_plants(plants)
