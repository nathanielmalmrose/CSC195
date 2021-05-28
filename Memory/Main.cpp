#include <iostream>
using namespace std;

void set(int& i)
{
	i = 300;
}

void swap(int& i1, int& i2)
{
	int temp = i1;
	i1 = i2;
	i2 = temp;
}

void swap(int* i1, int* i2)
{
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

int main()
{
	int i1 = 10;
	int i2 = 20;

	int& r = i1;

	int* p;
	p = &i1;

	//set(i1);
	//swap(i1, i2);
	swap(&i1, &i2);

	cout << &i1 << endl;
	cout << &r << endl;
	cout << p << endl;
	cout << *p << endl;

	int* p1 = new int[5];
	cout << p1[0] << endl;
	cout << *p1 << endl;

	delete[] p1;

}