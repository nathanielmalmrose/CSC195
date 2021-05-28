#pragma once
#include "Animal.h"


class Reptile : public Animal
{
public:
	eType GetType() { return eType::Bird; };

	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;


protected:
	int m_numLegs = 0;


};

