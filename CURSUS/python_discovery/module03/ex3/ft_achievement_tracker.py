class Player:
    def __init__(self, name, achievements):
        self.name = name
        self.achievements = achievements

    def __str__(self):
        return f"Player {self.name} achievements: {self.achievements}"


if __name__ == "__main__":
    alice = Player(
        "alice",
        {"first_kill", "level_10", "treasure_hunter", "speed_demon"},
    )
    bob = Player(
        "bob",
        {"first_kill", "level_10", "boss_slayer", "collector"},
    )
    charlie = Player(
        "charlie",
        {
            "level_10",
            "treasure_hunter",
            "boss_slayer",
            "speed_demon",
            "perfectionist",
        },
    )

    print("=== Achievement Tracker System ===\n")
    print(alice)
    print(bob)
    print(charlie)

    print("\n=== Achievement Analytics ===")

    all_unique = alice.achievements.union(
        bob.achievements, charlie.achievements
        )
    print(f"All unique achievements: {all_unique}")
    print(f"Total unique achievements: {len(all_unique)}\n")

    common_all = alice.achievements.intersection(
        bob.achievements, charlie.achievements
        )
    print(f"Common to all players: {common_all}")

    alice_only_global = alice.achievements.difference(
        bob.achievements.union(charlie.achievements)
    )
    bob_only_global = bob.achievements.difference(
        alice.achievements.union(charlie.achievements)
    )
    charlie_only_global = charlie.achievements.difference(
        alice.achievements.union(bob.achievements)
    )
    rare = alice_only_global.union(bob_only_global, charlie_only_global)
    print(f"Rare achievements (1 player): {rare}\n")

    alice_bob_common = alice.achievements.intersection(bob.achievements)
    print(f"Alice vs Bob common: {alice_bob_common}")

    alice_unique_vs_bob = alice.achievements.difference(bob.achievements)
    print(f"Alice unique: {alice_unique_vs_bob}")

    bob_unique_vs_alice = bob.achievements.difference(alice.achievements)
    print(f"Bob unique: {bob_unique_vs_alice}")
