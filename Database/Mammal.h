#pragma once
#include "Animal.h"

class Mammal : public Animal
{

public:
	eType GetType() { return eType::Mammal; };

	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);

protected:
	int m_numLegs = 0;


};

