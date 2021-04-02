// PrimitiveDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string firstName;
    char lastInitial;
    unsigned int age;
    bool isAdult;
    unsigned int zipcode;
    float wage;
    unsigned int daysWorked;
    int hoursWorkedPerDay[] = { 0,0,0,0,0,0,0 };

    static const float TAX = 0.1f;
    

    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last initial: ";
    cin >> lastInitial;

    cout << "Enter age: ";
    cin >> age;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: " << endl;
        cin >> age;
    }

    if (age >= 18) {
        isAdult = true;
    } else {
        isAdult = false;
    }

    cout << "Enter zipcode: ";
    cin >> zipcode;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: " << endl;
        cin >> zipcode;
    }

    cout << "Enter wage: ";
    cin >> wage;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: " << endl;
        cin >> wage;
    }

    cout << "Enter days worked: ";
    cin >> daysWorked;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: " << endl;
        cin >> daysWorked;
    }

    for (int i = 0; i < daysWorked; i++) {
        cout << "Enter hours worked for day " + to_string(i + 1) + ": ";
        int hours;
        cin >> hours;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number: " << endl;
            cin >> hours;
        }
        hoursWorkedPerDay[i] = hours;
    }

    int totalHours = 0;
    for (int i = 0; i < 7; i++) {
        totalHours += hoursWorkedPerDay[i];
    }
         

    cout << fixed;
    cout << setprecision(2);

    cout << firstName << " has worked " << totalHours << " hours at $" << wage << " an hour.\n";

    int gross = totalHours * wage;
    int net = gross - (gross * TAX);
    cout << "Gross income: " << gross << endl;
    cout << "Net income: " << net;
    
    
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
