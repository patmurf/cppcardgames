//Written by: Patrick Murphy
//Class implementation file
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"


card::card()
//Default constructor definition
{
	myFace = FACE_OVERFLOW;
	mySuit = SUIT_OVERFLOW;
}


//Explicit constructor definition
card::card(face f, suit s)

{
	myFace = f < FACE_OVERFLOW ? f : FACE_OVERFLOW;
	mySuit = s < SUIT_OVERFLOW ? s : SUIT_OVERFLOW;
}

card::~card()
{}
//I/O method for card class
void card::display(std::ostream &out) const
{
	std::string listedFaces[] = { 	"ACE", "TWO", "THREE", "FOUR", "FIVE",
					"SIX", "SEVEN", "EIGHT", "NINE", "TEN",
					"JACK", "QUEEN", "KING", "ERROR"};

	std::string listedSuits[] =  {	"CLUBS", "SPADES", "DIAMONDS", 						"HEARTS", "ERROR"};

	bool goodCard = true;
	if (listedFaces[myFace] != "ERROR")
	{
		if (listedSuits[mySuit] != "ERROR")
		{ 
			std::cout << listedFaces[myFace] << " OF "
			<< listedSuits[mySuit] << std::endl;
		}	
		else
		{
			goodCard = false;
			std::cout << "ERROR: malformed card data\n";
		}
	}
	else if (goodCard)
	{
		std::cout << "ERROR: malformed card data\n";
	}
}

//Setter definitions
const card &card::operator= (const card &c)
{
	if (this != &c)
	{
		this->myFace = c.cardFace();
		this->mySuit = c.cardSuit();
	}
}

//index methods
void card::setFace(int i) 
{
	if(i < 13)
	{
		this->myFace = static_cast<face>(i);
	}
}

void card::setSuit(int i) 
{
	if (i < 4)
	{
		this->mySuit = static_cast<suit>(i);
	}
}
//insertion op methods
void card::getFace(std::istream &in, card &faceVal)
{
	void stringToUpper(std::string &str);	//prototype

	std::string listedFaces[] = { 	"ACE", "TWO", "THREE", "FOUR", "FIVE",
					"SIX", "SEVEN", "EIGHT", "NINE", "TEN",
					"JACK", "QUEEN", "KING"};

	unsigned index = 0;
	bool found = false;
	std::string strFace;
	
	in >> strFace;
	stringToUpper(strFace);

	for (; !found &&index < 13; index++)
	{
		found = (strFace == listedFaces[index]);
	}
	if (found)
	{
		faceVal.myFace = static_cast<face>(index);
	}
	else
	{
		faceVal.myFace = static_cast<face>(FACE_OVERFLOW);
	}
		
}


void card::getSuit(std::istream &in, card &suitVal)
{
	void stringToUpper(std::string &str);	//prototype

	std::string listedSuits[] = {	"CLUBS", "SPADES", 
					"DIAMONDS", "HEARTS" };

	unsigned index = 0;
	bool found = false;
	std::string strSuit;

	in >> strSuit;
	stringToUpper(strSuit);

	for (; !found &&index <13; index++)
	{
		found = (strSuit == listedSuits[index]);
	}
	if (found)
	{
		suitVal.mySuit = static_cast<suit>(index);
	}
	else
	{
		suitVal.mySuit = static_cast<suit>(SUIT_OVERFLOW);
	}
}

//Getter definitions
face card::cardFace() const
{
	return myFace;
}

suit card::cardSuit() const
{
	return mySuit;
}



//Private Helper methods
void stringToUpper(std::string &str)
{
	for (unsigned i = 0; i < str.length(); i++)
	{
		str.at(i) = toupper(str.at(i));
	}
}

//Functions
void displayCard(std::ostream &out, const face &faceVal, const suit &suitVal)
{
	std::string listedFaces[] = { 	"ACE", "TWO", "THREE", "FOUR", "FIVE",
					"SIX", "SEVEN", "EIGHT", "NINE", "TEN",
					"JACK", "QUEEN", "KING", "ERROR"};

	std::string listedSuits[] = {	"CLUBS", "SPADES", "DIAMONDS", 						"HEARTS", "ERROR"};

	out << listedFaces[faceVal];
	out << " OF ";
	out << listedSuits[suitVal];
	out << std::endl;
}

void displayFace(std::ostream &out, const face &faceVal)
{
	std::string listedFaces[] = { 	"ACE", "TWO", "THREE", "FOUR", "FIVE",
					"SIX", "SEVEN", "EIGHT", "NINE", "TEN",
					"JACK", "QUEEN", "KING", "ERROR"};
	out << listedFaces[faceVal];
}

void displaySuit(std::ostream &out, const suit &suitVal)
{
	std::string listedSuits[] =  {	"CLUBS", "SPADES", "DIAMONDS", 						"HEARTS", "ERROR"};
	out << listedSuits[suitVal];
}

//Class Operator Overloads
std::ostream &operator<<(std::ostream &out, const card &cardVal)
{
	cardVal.display(out);
	return out;
}

bool operator< (const card &lhs, const card &rhs)
{
	return lhs.cardFace() < rhs.cardFace();
}

bool operator> (const card &lhs, const card &rhs)
{
	return lhs.cardFace() > rhs.cardFace();
}

bool operator==(const card &lhs, const card &rhs)
{
	return lhs.cardFace() == rhs.cardFace();
}


