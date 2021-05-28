#include <iostream>

void func1(int& i)
{
	i = 10;
}

void func2(const std::string& text)
{
	//
}

void func3(int* i)
{
	if (i)
	{
		std::cout << *i << std::endl;
	}

}

int* Random(int max)
{
	int r = rand() % max + 1;

	return &r;
}

class A
{
public:
	A() : i{ 0 } {}
	A(int v) :i{ v } {}
	void Set(int v) { i = v; }
	int Get() const { return i; }
	int& GetRef() { return i; }
	int* GetPtr() { return &i; }

	int& operator [] (int index) { return elements[index];  }
	const int& operator [] (int index) const { return elements[index];  }

private:
	int i;
	int elements[10];
};

void func4(const A& a)
{
	a.Get();
	std::cout << a[4] << std::endl;
}



int main()
{
	A a;
	a[4] = 10;
	a.Set(15);
	a.GetRef() = 30;

	std::cout << *a.GetPtr() << std::endl;

	srand(static_cast<unsigned int>(time(NULL)));
	std::cout << Random(10) << std::endl;


	int i = 0;
	func1(i);

	std::cout << i << std::endl;

	std::string text = "Hello";
	time_t start = time(NULL);
	for (int i = 0; i < 1000000; i++)
	{
		func2(text);
	}
	time_t end = time(NULL);

	std::cout << end - start << std::endl;

	int* p = &i;
	func3(p);
}