#include "house.h"

/*
 * The Constructor for the House class
 * Call the super constructor with the given name
 *
 * Parameters: A reference to a std::string name
 */
House::House(const std::string& name):
	GenericPlayer(name)
{}

/*
 * The destructor for the House object
 */
House::~House()
{}

/*
 *
 * Parameters: None
 * Returns: ????? (up to you) a boolean whenever it wishes to draw a card
 */
bool House::IsHitting() const //expand
{
    return (GetTotal() <= 16);
}   

/*
 * Because the House always has their first card face down, we want a method to flip the first card
 * If the hand is empty simply print "No card to flip!\n" and return.
 * Otherwise flip the first card of the House's hand.
 *
 * Parameters: None
 * Returns: None
 */
void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
        m_Cards[0]->Flip();
    else std::cout << "No card to flip!\n";
}