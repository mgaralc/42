from ex3.GameStrategy import GameStrategy


class AggressiveStrategy(GameStrategy):

    def get_strategy_name(self) -> str:
        return "AggressiveStrategy"

    def prioritize_targets(self, available_targets: list) -> list:
        return available_targets

    def execute_turn(self, hand: list, battlefield: list) -> dict:
        cards_played = [card.name for card in hand]
        damage_dealt = sum(
            getattr(card, "attack_power", 0) for card in hand
        )

        return {
            "strategy": self.get_strategy_name(),
            "actions": {
                "cards_played": cards_played,
                "mana_used": sum(card.cost for card in hand),
                "targets_attacked": ["Enemy Player"],
                "damage_dealt": damage_dealt,
            },
        }
