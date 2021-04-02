// UserDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Sandwich
{
public:
    void Display() { std::cout << "Price: $" << price << std::endl; }

public:
    char name[32];
    float price;
    bool isHot;
};

int main()
{
    std::cout << "Hello World!\n";

    Sandwich turkey;
    turkey.price = 4.99f;
    turkey.isHot = true;
    turkey.Display();

    int i = 5;
    char c = 34;

    i = c;

    float f = 23.4f; // 4 bits
    double d = 34.5; // 8 bits

    f = static_cast<float>(d);
    f = (float)d;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
