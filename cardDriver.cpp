/*---cardDriver.cpp-------------------------------------------------------
	Driver routine to testing card class.
------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"

int main()
{
/*
	std::cout << 	"\n==============================================\n"
			"Testing Constructors"
			"\n==============================================\n";

	card 	sample,
		ex(ACE, HEARTS);
*/	
//end part one
/*

	std::cout <<	"\n==============================================\n"
			"Testing display()"
			"\n==============================================\n";
	
	std::cout <<	"Value of card: ";
	sample.display(std::cout);
	std::cout << std::endl;
	std::cout << " Explicit is: ";
	ex.display(std::cout);
	std::cout << std::endl;
*/
//end part two
/*

	std::cout <<	"\n==============================================\n"
			"Testing output operator"
			"\n==============================================\n";

	std::cout <<	"Value of sample is : " << sample << std::endl;
	std::cout <<	"Value of ex is : "	<< ex << std::endl;
*/
//end part three

	card deck[52];
	int cnt = 0;
	//assignment loop
	for(int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			deck[cnt].setFace(i);
			deck[cnt].setSuit(j);
			cnt++;
		}
	}

	//display loop
	for (int i = 0; i < 52; i++)
	{
		std::cout << "Card " << i+1 << ": " << deck[i] <<std::endl;
	}

	std::cout <<"This concludes the preliminary tests. " << std::endl;


return 0;
}

