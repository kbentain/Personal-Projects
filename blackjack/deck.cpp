#include "deck.h"

/*
 * Constructor for the Deck class
 * Populates the deck with all 52 distinct cards
 *
 * Parameters: None
 */
Deck::Deck()
{
	Populate();
}

/*
 * Destructor for the Deck. Don't forget the destructor for Hand will be called after this.
 */
Deck::~Deck()
{}


/*
 * If there were previously cards in the deck, get rid of them
 * Allocates space for all 52 cards and adds them to the deck
 *
 * Parameters: None
 * Returns: None
 */
void Deck::Populate()
{
	m_Cards.clear();
	m_Cards.reserve(52);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 12; j++) {
			m_Cards.push_back(new Card(static_cast<Card::rank>(j), static_cast<Card::suit>(i)));
		} 
}

/*
 * Shuffles all of the cards in the deck
 * Hint: If you get stuck, go read up on lesson 3 algorithm to learn about the standard library
 *
 * Parameters: None
 * Returns: None
 */
void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

/*
 * Deal one card from the deck to a Hand. If the deck has no cards remaining print out
 * "Out of cards. Unable to deal."
 *
 * Parameters: A reference to a Hand object
 * Returns: None
 */
void Deck::Deal(Hand& aHand)
{
	if (m_Cards.empty()) 
		std::cout << "Out of cards. Unable to deal." << std::endl;
	else {
		srand(time(0));
		aHand.Add(m_Cards[rand()%m_Cards.size()]);
	}
}


/*
 * Deal out any additional cards to a player beyond the first two cards.
 * A player can only be dealt extra cards if:
 * 1.) They have not busted yet
 * 2.) They wish to be hit
 *
 * After a card is dealt, print out the current hand so the player can keep making the decision
 * whether to stay or hit
 * If a player busts, let the player know they have busted
 *
 * Parameter: A reference to a Generic Player
 * Returns: None
 */
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	while (!aGenericPlayer.IsBusted() && aGenericPlayer.IsHitting()) {
		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << "\n";
		if (aGenericPlayer.IsBusted())
			aGenericPlayer.Bust();
	}
} 