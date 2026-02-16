from ex2.EliteCard import EliteCard


def main() -> None:
    print("=== DataDeck Ability System ===")

    elite = EliteCard(
        name="Arcane Warrior",
        cost=5,
        rarity="Epic",
        attack=5,
        health=10,
        mana=7,
    )

    print("Play:", elite.play({}))
    print("Attack:", elite.attack("Enemy"))
    print("Defend:", elite.defend(3))
    print("Combat stats:", elite.get_combat_stats())
    print("Cast spell:", elite.cast_spell("Fireball", ["Enemy1", "Enemy2"]))
    print("Channel mana:", elite.channel_mana(2))
    print("Magic stats:", elite.get_magic_stats())


if __name__ == "__main__":
    main()
