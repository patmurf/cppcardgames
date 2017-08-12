/*---card.h---------------------------------------------------------------
	Class template of card class.
	Basic Operation:
		Constructor:
		(?)
		(?)
	Private utility:
	Future versions:
		Inherit definition of suit heirarchy for specific games
	Written by: Patrick Murphy
------------------------------------------------------------------------*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#ifndef CARD
#define CARD
//BEGIN ENUM DEFINITIONS
enum face {
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK,
	QUEEN, KING, FACE_OVERFLOW
};

enum suit {
	CLUBS, SPADES, DIAMONDS, HEARTS, SUIT_OVERFLOW
};
//END ENUM DEFINITIONS

//BEGIN CLASS DEFINITION

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
	~card();
	/*---------------------------------------------------------------
	Destructor.
	---------------------------------------------------------------*/
	void display(std::ostream &out) const;
	void setFace(int i);
	void setSuit(int i);
	void getFace(std::istream &in, card &faceVal);
	void getSuit(std::istream &in, card &suitVal);
	/*----------------------------------------------------------------
	I/O method for card class
	----------------------------------------------------------------*/
	face cardFace() const;
	suit cardSuit() const;
	/*----------------------------------------------------------------
	Getters for card class
	----------------------------------------------------------------*/
	const card &operator= (const card &c);
	/*---------------------------------------------------------------
	Assignment operator
	---------------------------------------------------------------*/
	private:
		face myFace;
		suit mySuit;

//end card class
};
//END CLASS DEFINITION

//FUNCTIONS---------------------------------------------------------------
void displayCard(std::ostream &out, const face &faceVal, const suit &suitVal);
void displayFace(std::ostream &out, const face &faceVal);
void displaySuit(std::ostream &out, const suit &suitVal);

//OPERATOR OVERLOADS------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const face &faceVal);
std::ostream &operator<<(std::ostream &out, const suit &suitVal);
std::ostream &operator<<(std::ostream &out, const card &cardVal);
std::istream &operator>>(std::istream &in, face &faceVal);
std::istream &operator>>(std::istream &in, suit &suitVal);

bool operator< (const card &lhs, const card &rhs);
bool operator> (const card &lhs, const card &rhs);
bool operator==(const card &lhs, const card &rhs);






#endif
	
