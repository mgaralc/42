from ex0.CreatureCard import CreatureCard


def main() -> None:
    print("=== DataDeck Card Foundation ===")

    creature = CreatureCard(
        name="Fire Dragon",
        cost=5,
        rarity="Legendary",
        attack=7,
        health=5,
    )

    print("CreatureCard Info:")
    print(creature.get_card_info())

    print("Playing Fire Dragon with 6 mana available:")
    print("Playable:", creature.is_playable(6))
    print("Play result:", creature.play({}))

    print("Fire Dragon attacks Goblin Warrior:")
    print(
        "Attack result:",
        creature.attack_target("Goblin Warrior"),
    )

    print("Testing insufficient mana (3 available):")
    print("Playable:", creature.is_playable(3))


if __name__ == "__main__":
    main()
