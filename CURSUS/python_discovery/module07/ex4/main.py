from ex4.TournamentCard import TournamentCard
from ex4.TournamentPlatform import TournamentPlatform


def main() -> None:
    print("=== DataDeck Tournament Platform ===")

    platform = TournamentPlatform()

    card1 = TournamentCard("Fire Dragon", 5, "Legendary", 7, 10)
    card2 = TournamentCard("Ice Wizard", 4, "Epic", 5, 8)

    id1 = platform.register_card(card1)
    id2 = platform.register_card(card2)

    print("Registered cards:")
    print(id1, card1.name)
    print(id2, card2.name)

    print("\nCreating match:")
    result = platform.create_match(id1, id2)
    print(result)

    print("\nLeaderboard:")
    print(platform.get_leaderboard())

    print("\nTournament report:")
    print(platform.generate_tournament_report())


if __name__ == "__main__":
    main()
