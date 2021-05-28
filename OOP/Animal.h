#pragma once
#include <iostream>


class Animal

{


public:
	//	Constructor
	Animal() {
		m_lifespan = 0;
		m_p = new int(50);
		std::cout << "animal Constructor\n";
	}	
	Animal(int lifespan) { m_lifespan = lifespan; }

	//	Destructor
	~Animal() {
		delete m_p;
		std::cout << "Destructor\n";
	}

	virtual void Speak() = 0;

	int GetLifeSpan() { return m_lifespan; };

	enum class eType;

protected:
	int m_lifespan;
	int* m_p = nullptr;


};