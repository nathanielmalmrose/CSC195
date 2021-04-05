#include "Sandwich.h"
#include <iostream>

const float Sandwich::TAX = 0.01f;

void Sandwich::Read()
{
	std::cout << "name";
	std::cin >> name;

}

void Sandwich::Write()
{
	std::cout << "name = " << name << std::endl;

}
