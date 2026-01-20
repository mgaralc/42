class Plant:
    """
    Base class that represent a basic plant

    Corresponds to:
    - "Build a plant family tree"
    Defines common behaviors of all plants of the system
    """

    def __init__(self, nombre: str, altura: int, edad: int):
        """
        Class constructor
        Args:
            nombre, altura, edad
        """
        self.nombre = nombre
        self.altura = altura
        self.edad = edad

    def grow(self):
        """
        Instance methot that makes the plant grow

        Correspond to:
        - Use instance methods.
        """
        self.altura += 1
        print(f"{self.nombre} grew 1cm")

    def info(self):
        """
        Return a str with the basic information, we use on reports
        """
        return f"{self.nombre}: {self.altura}cm"


class FloweringPlant(Plant):
    """
    Inheritance from plant
    """

    def __init__(
        self,
        nombre: str,
        altura: int,
        edad: int,
        flower_color: str,
        blooming: bool
    ):
        """
        Class constructor
        Args:
            nombre, altura, edad, flower_color, blooming
        """
        super().__init__(nombre, altura, edad)
        self.flower_color = flower_color
        self.blooming = blooming

    @staticmethod
    def blooming_text(blooming: bool) -> str:
        """
        Extra utility to format blooming state

        Convert true/false to blooming/not blooming
        """
        return "blooming" if blooming else "not blooming"

    def info(self):
        """
        Return str with information

        Overwrite info() from base class
        """
        return (
            f"{self.nombre}: {self.altura}cm, {self.flower_color} flowers "
            f"({self.blooming_text(self.blooming)})"
        )


class PrizeFlower(FloweringPlant):
    """
    Inheritance from plant
    """

    def __init__(
        self,
        nombre: str,
        altura: int,
        edad: int,
        flower_color: str,
        blooming: bool,
        prize_points: int
    ):
        """
        Class constructor
        Args:
            nombre, altura, edad, flower_color, blooming, prize_points
        """
        super().__init__(nombre, altura, edad, flower_color, blooming)
        self.prize_points = prize_points

    def info(self):
        """
        Return str with information

        Overwrite info() from base class
        """
        return (
            f"{self.nombre}: {self.altura}cm, {self.flower_color} flowers "
            f"({self.blooming_text(self.blooming)}), "
            f"Prize points: {self.prize_points}"
        )


class Garden:
    """
    Represent a Garden with Plants

    Correspond to:
    - "Each garden should track plant collections and statistics"
    """

    def __init__(self, nombre):
        """
        Class construcor

        Args:
            nombre
        """
        self.nombre = nombre
        self.plantas = []
        self.total_grow = 0

    def add_plant(self, plant):
        """
        Add plant to garden, append

        Relate garden object with plant object
        """
        self.plantas.append(plant)
        print(f"Added {plant.nombre} to {self.nombre}'s garden")

    def grow_all(self):
        """
        Use method grow of plant with every plant

        Use interaction bettwen  Garden and Plant
        """
        print(f"\n{self.nombre} is helping all plants grow...")
        for planta in self.plantas:
            planta.grow()
            self.total_grow += 1


class GardenManager:
    """
    Class responsible of managin multiple garden

    Correspond to:
    - "Create a GardenManager that can handle multiple gardens"
    - Uso de métodos de instancia, de clase y utilidades.
    """

    def __init__(self):
        """
        Class comstructor

        Inicializate garden manager and its statistics
        """
        self.gardens = []
        self.stats = GardenManager.GardenStats()

    def add_garden(self, garden):
        """
        Add garden to the manager
        """
        self.gardens.append(garden)

    def view_all(self):
        """
        Whow all reports of all gardensm, and a globar system sumary

        Here we print, height validation, scores and numer of gardens
        """
        scores = []
        all_valid = True

        for garden in self.gardens:
            score, is_valid = self.stats.helper(garden)
            scores.append((garden.nombre, score))
            all_valid = all_valid and is_valid

        print(f"\nHeight validation test: {all_valid}")

        scores_str = ", ".join(
            f"{name}: {score}" for name, score in scores
        )
        print(f"Garden scores - {scores_str}")
        print(f"Total gardens managed: {len(self.gardens)}")

    @classmethod
    def create_garden_network(cls):
        """
        Class method that build a complete network of gardens

        Correspond to:
        - "Include a method create_garden_network()
           that works on the manager type itself"
        """
        manager = cls()

        tulip = Plant("Tulipan", 30, 1)
        lilium = PrizeFlower("Lilium", 40, 23, "White", True, 25)
        rose = FloweringPlant("Rose", 33, 28, "Rose", False)
        white_rose = FloweringPlant("White Rose", 17, 10, "White", True)

        ana = Garden("Ana")
        bob = Garden("Bob")

        ana.add_plant(tulip)
        ana.add_plant(lilium)
        bob.add_plant(rose)
        bob.add_plant(white_rose)

        ana.grow_all()
        bob.grow_all()

        manager.add_garden(ana)
        manager.add_garden(bob)

        return manager

    @staticmethod
    def format_title(text: str) -> str:
        """
        Function that we use to format tittles

        Correspond to:
        - "Add utility functions that don’t need specific garden data"
        """
        return f"=== {text} ==="

    class GardenStats:
        """
        Internat helper that calculate the stadistic of a garden

        Correspond to:
        - "Include a helper GardenStats inside your manager"
        """

        def helper(self, garden):
            """
            Calculate and show stadistic of a garden

            Return:
                total score
                height validation
            """
            cont = 0
            total_regular = 0
            total_flowering = 0
            total_prized = 0
            score = 0
            result = True

            print()
            print(
                GardenManager.format_title(f"{garden.nombre}'s Garden Report")
            )
            print("Plants in garden:")

            for planta in garden.plantas:
                print(f"- {planta.info()}")
                cont += 1
                score += planta.altura

                if isinstance(planta, PrizeFlower):
                    total_prized += 1
                    score += planta.prize_points
                elif isinstance(planta, FloweringPlant):
                    total_flowering += 1
                else:
                    total_regular += 1

                if result:
                    result = self.height_validator(planta.altura)

            print(
                f"\nPlants added: {cont}. Total growth: {garden.total_grow}cm"
            )
            print(
                f"Plant types: {total_regular} regular, "
                f"{total_flowering} flowering, "
                f"{total_prized} prize flowers"
            )

            return score, result

        @staticmethod
        def height_validator(altura):
            """
            Use to validate the height

            Return true if is valid height (>= 0).
            """
            return altura >= 0


if __name__ == "__main__":
    """
    Program start, execute the system manager
    """
    print(GardenManager.format_title("Garden Management System Demo"))
    print()

    manager = GardenManager.create_garden_network()
    manager.view_all()
