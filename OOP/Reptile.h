#pragma once
#include "Animal.h"
#include <iostream>

class Reptile : public Animal
{
public:
	Reptile(int numEggs)
	{
		m_numEggs = numEggs;
		std::cout << "reptile Constructor\n";
	}
	void Speak() override;

protected:
	int m_numEggs = 0;
};

