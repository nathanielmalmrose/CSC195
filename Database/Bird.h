#pragma once
#include "Animal.h"

class Bird : public Animal
{
public:
	eType GetType() { return eType::Bird; };

	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;

	void Read(std::ifstream& istream);
	void Write(std::ofstream& ostream);


protected:
	int m_numEggs = 0;


};

