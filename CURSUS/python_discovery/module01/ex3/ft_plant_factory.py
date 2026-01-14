class Plant:
    def __init__(self, nombre, altura, edad):
        self.nombre = nombre
        self.altura = altura
        self.edad = edad


if __name__ == "__main__":
    plants_data = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120),
    ]
    plants = []
    for name, height, age in plants_data:
        plant = Plant(name, height, age)
        plants.append(plant)
        print(f"Created: {name} ({height}cm, {age} days)")
    print(f"Total plants created: {len(plants)}")
