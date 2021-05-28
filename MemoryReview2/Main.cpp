#include <iostream>
#include <iomanip>
using namespace std;

struct Person
{
	char name[32];
	int id;
};

void square(int &i)
{
	i = i * i;
}

void Double(int *i)
{
	*i = *i * 2;
}

int main()
{
	// ** REFERENCE **
	// 
	// declare an int variable and set the value to some number (less than 10)
	int var = 5;
	// declare a int reference and set it to the int variable above
	int& ref = var;



	// output the int variable
	cout << var << endl;
	cout << ref << endl;

	// set the int reference to some number
	ref = 7;
	// output the int variable
	cout << var << endl;
	cout << ref << endl;

	// what happened to the int variable when the reference was changed? (insert answer)
	//	The value was also changed

	// output the address of the int variable
	cout << &var << endl;
	// output the address of the int reference
	cout << &ref << endl;
	// are the addresses the same or different? (insert answer)
	//	Same

	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	square(ref);

	// output the int variable to the console
	cout << var << endl;

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

	// ** POINTER VARIABLE **
	// 
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* ptr = nullptr;

	// set the int pointer to the address of the int variable created in the REFERENCE section
	ptr = &var;

	// output the value of the pointer
	cout << ptr << endl;
	// what is this address that the pointer is pointing to? (insert answer)
	//	0073FBA8 , same as the reference address
	
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << *ptr << endl;


	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(ptr);

	// output the dereference pointer
	cout << *ptr << endl;
	// output the int variable created in the REFERENCE section
	cout << var << endl;
	// did the int variable's value change when using the pointer?
	//	Yes

	// ** ALLOCATION/DEALLOCATION **
	//
	// create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
	// output the pointer value, this should be the address of the int allocated on the heap
	// output the dereference pointer
	// deallocate the int pointer to free up the memory
	int* p = new int(6);
	cout << p << endl;
	cout << *p << endl;
	delete p;

	// create an int pointer that points at an array of ints allocated on the heap, the array size should be 4-6
	int* a = new int[4];
	// use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
	for (int i = 0; i < sizeof(a); i++)
	{
		a[i] = rand() % 10;
	}
	// use a for loop and output each of the ints in the array
	for (int i = 0; i < sizeof(a); i++)
	{
		cout << "Index: " << i << " = " << a[i] << endl;
	}

	// use a for loop and output the address of each of the ints in the array
	for (int i = 0; i < sizeof(a); i++)
	{
		cout << &a[i] << endl;
	}
	// deallocate the int pointer to free up the memory block (remember it's an array)
	delete[] a;
	a = nullptr;

	// ** STRUCTURE **
	//
	// create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
	Person* people = new Person[2];
	// read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter name: ";
		cin >> people[i].name;

		cout << "Enter ID: ";
		cin >> people[i].id;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid number: " << endl;
			cin >> people[i].id;
		}

	}
	// use a for loop and output the name and id of each person in the array
	for (int i = 0; i < 2; i++)
	{
		cout << "Name: " << people[i].name << " | ID: " << people[i].id << endl;
	}

	// deallocate the person pointer to free up the memory block (remember it's an array)
	delete[] people;
	people = nullptr;
}