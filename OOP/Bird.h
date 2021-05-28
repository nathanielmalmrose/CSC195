#pragma once
#include "Animal.h"
#include <iostream>

class Bird : public Animal
{
public:
	Bird(int lifespan, float speed) : Animal(lifespan)
	{
		m_lifespan = lifespan;
		m_flightspeed = speed;
		std::cout << "bird Constructor\n";
	};
	~Bird()
	{
		std::cout << "bird destructor\n";
	};

	void Speak() override;

protected:
	float m_flightspeed = 0.0f;

};

