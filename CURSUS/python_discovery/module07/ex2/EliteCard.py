from ex0.Card import Card
from ex2.Combatable import Combatable
from ex2.Magical import Magical


class EliteCard(Card, Combatable, Magical):
    def __init__(
        self,
        name: str,
        cost: int,
        rarity: str,
        attack: int,
        health: int,
        mana: int,
    ):
        super().__init__(name, cost, rarity)
        self.attack_power = attack
        self.health = health
        self.mana = mana

    def play(self, game_state: dict) -> dict:
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Elite card played",
        }

    def attack(self, target) -> dict:
        return {
            "attacker": self.name,
            "target": target,
            "damage": self.attack_power,
        }

    def defend(self, incoming_damage: int) -> dict:
        return {
            "defender": self.name,
            "incoming_damage": incoming_damage,
            "health": self.health,
        }

    def get_combat_stats(self) -> dict:
        return {
            "attack": self.attack_power,
            "health": self.health,
        }

    def cast_spell(self, spell_name: str, targets: list) -> dict:
        return {
            "caster": self.name,
            "spell": spell_name,
            "targets": targets,
        }

    def channel_mana(self, amount: int) -> dict:
        return {
            "channeled": amount,
            "mana": self.mana,
        }

    def get_magic_stats(self) -> dict:
        return {
            "mana": self.mana,
        }
