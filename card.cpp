#include "card.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

card::card()
//Default constructor definition
{
	face = suit = "Unassigned";
}

card::card(const std::string &f, const std::string &s)
