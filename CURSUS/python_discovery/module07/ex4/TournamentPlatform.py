from ex4.TournamentCard import TournamentCard


class TournamentPlatform:

    def __init__(self) -> None:
        self.cards: dict[str, TournamentCard] = {}
        self._next_id = 1

    def register_card(self, card: TournamentCard) -> str:
        card_id = str(self._next_id)
        self._next_id += 1
        self.cards[card_id] = card
        return card_id

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        card1 = self.cards[card1_id]
        card2 = self.cards[card2_id]

        if card1.calculate_rating() >= card2.calculate_rating():
            winner = card1
            winner_id = card1_id
            loser = card2
        else:
            winner = card2
            winner_id = card2_id
            loser = card1

        winner.update_wins(1)
        loser.update_losses(1)

        return {
            "card1_id": card1_id,
            "card2_id": card2_id,
            "winner_id": winner_id,
        }

    def get_leaderboard(self) -> list:
        leaderboard = []
        for card_id, card in self.cards.items():
            leaderboard.append(
                {
                    "id": card_id,
                    "name": card.name,
                    "rating": card.calculate_rating(),
                }
            )

        leaderboard.sort(
            key=lambda entry: entry["rating"],
            reverse=True,
        )

        return leaderboard

    def generate_tournament_report(self) -> dict:
        return {
            "total_cards": len(self.cards),
            "leaderboard": self.get_leaderboard(),
        }
