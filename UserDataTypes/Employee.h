#pragma once

class Employee {
private:
	char firstName[32];
	char lastInitial;
	int age;
	int zipcode;
	float wage;
	int daysWorked;
	int hoursWorkedPerDay[7];
	int totalHours;

	static const float TAX;

public:
	void Read();
	void Write();
};