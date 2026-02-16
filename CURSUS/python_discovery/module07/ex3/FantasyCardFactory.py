from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard
from ex3.CardFactory import CardFactory


class FantasyCardFactory(CardFactory):

    def create_creature(
        self,
        name_or_power: str | int | None = None
    ) -> CreatureCard:
        if isinstance(name_or_power, str):
            name = name_or_power
        else:
            name = "Dragon"
        return CreatureCard(name, 5, "Rare", 6, 6)

    def create_spell(
        self,
        name_or_power: str | int | None = None
    ) -> SpellCard:
        if isinstance(name_or_power, str):
            name = name_or_power
        else:
            name = "Fireball"
        return SpellCard(name, 3, "Common", "damage")

    def create_artifact(
        self,
        name_or_power: str | int | None = None
    ) -> ArtifactCard:
        if isinstance(name_or_power, str):
            name = name_or_power
        else:
            name = "Magic Ring"
        return ArtifactCard(
            name,
            2,
            "Uncommon",
            3,
            "+1 mana per turn",
        )

    def create_themed_deck(self, size: int) -> dict:
        cards = []
        for _ in range(size):
            cards.append(self.create_creature())
        return {
            "deck_size": size,
            "cards": cards,
        }

    def get_supported_types(self) -> dict:
        return {
            "creatures": ["Dragon"],
            "spells": ["Fireball"],
            "artifacts": ["Magic Ring"],
        }
