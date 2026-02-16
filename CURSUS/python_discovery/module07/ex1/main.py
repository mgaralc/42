from ex0.CreatureCard import CreatureCard
from ex1 import ArtifactCard, Deck
from ex1.SpellCard import SpellCard


def main() -> None:
    print("=== DataDeck Deck Builder ===")

    deck = Deck()

    creature = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)
    spell = SpellCard("Lightning Bolt", 3, "Common", "damage")
    artifact = ArtifactCard("Mana Crystal", 2, "Rare", 3, "+1 mana per turn")

    deck.add_card(creature)
    deck.add_card(spell)
    deck.add_card(artifact)

    print("Deck stats:")
    print(deck.get_deck_stats())

    deck.shuffle()

    print("\nDrawing and playing cards:")
    while deck.cards:
        card = deck.draw_card()
        print(f"Drew: {card.name} ({card.__class__.__name__})")
        print("Play result:", card.play({}))


if __name__ == "__main__":
    main()
