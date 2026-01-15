class Plant:
    def __init__(self, nombre: str, altura: int, edad: int):
        self.nombre = nombre
        self.altura = altura
        self.edad = edad

    def grow(self):
        self.altura = self.altura + 1
        print(f"{self.nombre} grew 1cm")


class FloweringPlant(Plant):
    def __init__(self, nombre, altura, edad, flower_color, blooming):
        super().__init__(nombre, altura, edad)
        self.flower_color = flower_color
        self.blooming = blooming


class PrizeFlower(FloweringPlant):
    def __init__(
            self, nombre, altura, edad, flower_color, blooming, prize_points):
        super().__init__(nombre, altura, edad, flower_color, blooming)
        self.prize_points = prize_points


class Garden:
    