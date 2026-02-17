if __name__ == "__main__":
    alice = {"first_kill", "level_10", "treasure_hunter", "speed_demon"}
    bob = {"first_kill", "level_10", "boss_slayer", "collector"}
    charlie = {
        "level_10",
        "treasure_hunter",
        "boss_slayer",
        "speed_demon",
        "perfectionist",
    }

    print("=== Achievement Tracker System ===\n")
    print(f"Player alice achievements: {alice}")
    print(f"Player bob achievements: {bob}")
    print(f"Player charlie achievements: {charlie}")

    print("\n=== Achievement Analytics ===")

    all_unique = alice.union(bob, charlie)
    print(f"All unique achievements: {all_unique}")
    print(f"Total unique achievements: {len(all_unique)}\n")

    common_all = alice.intersection(bob, charlie)
    print(f"Common to all players: {common_all}")

    others_for_alice = bob.union(charlie)
    alice_only = alice.difference(others_for_alice)

    others_for_bob = alice.union(charlie)
    bob_only = bob.difference(others_for_bob)

    others_for_charlie = alice.union(bob)
    charlie_only = charlie.difference(others_for_charlie)

    rare = alice_only.union(bob_only, charlie_only)
    print(f"Rare achievements (1 player): {rare}\n")

    alice_bob_common = alice.intersection(bob)
    print(f"Alice vs Bob common: {alice_bob_common}")

    alice_unique_vs_bob = alice.difference(bob)
    print(f"Alice unique: {alice_unique_vs_bob}")

    bob_unique_vs_alice = bob.difference(alice)
    print(f"Bob unique: {bob_unique_vs_alice}")
