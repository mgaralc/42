class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


class GardenManager:
    def __init__(self):
        self.plants = []

    def add_plant(self, plant):
        """
        Add a plant to the garden.
        """
        if not isinstance(plant, dict):
            raise PlantError("Error: Plant must be a dictionary.")

        name = plant.get("name")
        if not isinstance(name, str) or name == "":
            raise PlantError("Error: Plant name cannot be empty!")

        self.plants.append(plant)

    def check_plant_health(self, plant_name, water_level, sunlight_hours):
        """
        Validate plant health values.

        Raises ValueError on invalid inputs.
        Returns a success message if everything is okay.
        """
        if not isinstance(plant_name, str) or plant_name == "":
            raise ValueError("Error: Plant name cannot be empty!")

        if water_level < 1:
            raise ValueError(
                f"Error: Water level {water_level} is too low (min 1)"
            )
        if water_level > 10:
            raise ValueError(
                f"Error: Water level {water_level} is too high (max 10)"
            )

        if sunlight_hours < 2:
            raise ValueError(
                f"Error: Sunlight hours {sunlight_hours} is too low (min 2)"
            )
        if sunlight_hours > 12:
            raise ValueError(
                f"Error: Sunlight hours {sunlight_hours} is too high (max 12)"
            )

        return f"Plant '{plant_name}' is healthy!"

    def water_plants(self):
        """
        Water all plants (Exercise 3 style cleanup with finally).
        Demonstrates that cleanup happens even if an error occurs.
        """
        print("=== Garden Watering System ===")
        print("Opening watering system")

        try:
            for plant in self.plants:
                name = plant.get("name")

                if not isinstance(name, str) or name == "":
                    raise PlantError(
                        "Error: Cannot water a plant with an invalid name!"
                    )

                water_level = plant.get("water")
                if not isinstance(water_level, int):
                    raise WaterError(
                        f"Error: Cannot water '{name}' "
                        "- water level is invalid!"
                    )

                print(f"Watering {name}...")
        finally:
            print("Closing watering system (cleanup)")

        print("Cleanup always happens, even with errors!")


def test_garden_management():
    print("=== Garden Management System Demo ===")
    manager = GardenManager()

    tomato = {"name": "tomato", "water": 5, "sun": 8}
    lettuce = {"name": "", "water": 5, "sun": 27}
    banana = {"name": "banana", "water": -1, "sun": 6}

    print("\nAdding plants...")
    for plant in (tomato, lettuce, banana):
        try:
            manager.add_plant(plant)
            print(f"Added plant: {plant['name']}")
        except PlantError as e:
            print(e)

    print("\nWatering plants...")
    try:
        manager.water_plants()
    except (PlantError, WaterError) as e:
        print(e)

    print("\nChecking plant health...")
    test_cases = [
        ("tomato", 5, 8),
        ("", 5, 8),
        ("banana", -1, 6),
        ("lettuce", 5, 27),
    ]

    for name, water, sun in test_cases:
        try:
            msg = manager.check_plant_health(name, water, sun)
            print(msg)
        except ValueError as e:
            print(e)

    print("\nAll garden management tests completed!")


if __name__ == "__main__":
    test_garden_management()
