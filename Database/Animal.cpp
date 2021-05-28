#include "Animal.h"
#include <iostream>
#include <fstream>


void Animal::Read(std::ostream& ostream, std::istream& istream)
{
	ostream << "Enter name: ";
	istream >> m_name;

	ostream << "Enter lifespan: ";
	istream >> m_lifespan;
}

void Animal::Write(std::ostream& ostream)
{
	ostream << "Name: " << m_name << std::endl;
	ostream << "Lifespan: " << m_lifespan << std::endl;
}

void Animal::Read(std::ifstream& ifstream)
{
	ifstream >> m_name;
	ifstream >> m_lifespan;
}

void Animal::Write(std::ofstream& ofstream)
{
	ofstream << m_name << std::endl;
	ofstream << m_lifespan << std::endl;
}

std::istream& operator>>(std::istream& istream, Animal& animal)
{
	animal.Read(std::cout, istream);

	return istream;
}

std::ostream& operator<<(std::ostream& ostream, Animal& animal)
{
	animal.Write(ostream);

	return ostream;
}

std::ifstream& operator>>(std::ifstream& ifstream, Animal& animal)
{
	animal.Read(ifstream);

	return ifstream;
}

std::ofstream& operator<<(std::ofstream& ofstream, Animal& animal)
{
	animal.Write(ofstream);

	return ofstream;
}

bool operator == (const std::unique_ptr<Animal>& animal, const std::string& name) { return (name == animal->GetName()); };
bool operator == (const std::unique_ptr<Animal>& animal, Animal::eType type) { return (type == animal->GetType()); };
