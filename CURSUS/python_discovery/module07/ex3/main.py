from ex3.GameEngine import GameEngine
from ex3.FantasyCardFactory import FantasyCardFactory
from ex3.AggressiveStrategy import AggressiveStrategy


def main() -> None:
    print("=== DataDeck Game Engine ===")

    engine = GameEngine()

    factory = FantasyCardFactory()
    strategy = AggressiveStrategy()

    engine.configure_engine(factory, strategy)

    print("Engine status:")
    print(engine.get_engine_status())

    print("Simulating turn:")
    result = engine.simulate_turn()
    print(result)


if __name__ == "__main__":
    main()
