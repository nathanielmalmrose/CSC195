#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const float Employee::TAX = 0.01f;

void Employee::Read() {
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

    

    totalHours = 0;
    for (int i = 0; i < daysWorked; i++) {
        totalHours += hoursWorkedPerDay[i];
    }
}

void Employee::Write() {
    cout << fixed;
    cout << setprecision(2);

    cout << firstName << " has worked " << totalHours << " hours at $" << wage << " an hour.\n";

    int gross = (totalHours * wage);
    int net = (gross - (gross * TAX));
    cout << "Gross income: " << gross << endl;
    cout << "Net income: " << net << endl;
}