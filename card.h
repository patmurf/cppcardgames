/*---card.h---------------------------------------------------------------
	Class template of card class.
	Basic Operation:
		Constructor:
		(?)
		(?)
	Private utility:
	Future versions:

	Written by: Patrick Murphy
------------------------------------------------------------------------*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#ifndef CARD
#define CARD

enum face {
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK,
	QUEEN, KING, FACE_OVERFLOW
};

enum suit {
	CLUBS, SPADES, DIAMONDS, HEARTS, SUIT_OVERFLOW
};


class card
{
//begin card class
	public:
	/*****Function Members*****/
	card();
	/*----------------------------------------------------------------
	Default constructor:
		Constructs a card
	----------------------------------------------------------------*/
	card(face f, suit s);
	/*----------------------------------------------------------------
	Explicit constructor:
		Constructs a specific card by face value and suit. Note
		order of inputs.
	----------------------------------------------------------------*/
	std::string showCard();
	/*----------------------------------------------------------------

	----------------------------------------------------------------*/
	private:
		face thisFace;
		suit thisSuit;
//end card class
};

//FUNCTIONS---------------------------------------------------------------
//OPERATOR OVERLOADS------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const face &faceVal);
std::ostream &operator<<(std::ostream &out, const suit &suitVal);
std::ostream &operator<<(std::ostream &out, const card &cardVal);




#endif
	
