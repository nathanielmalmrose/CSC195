#include "Bird.h"
#include <iostream>
#include <fstream>

void Bird::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "Enter number of eggs: ";
	istream >> m_numEggs;
}

void Bird::Write(std::ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "Number of eggs: " << m_numEggs << std::endl;

}

void Bird::Read(std::ifstream& istream)
{
	Animal::Read(istream);
	istream >> m_numEggs;
}

void Bird::Write(std::ofstream& ostream)
{
	Animal::Write(ostream);
	ostream << m_numEggs << std::endl;
	
}
