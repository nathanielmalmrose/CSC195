#include <iostream>
#include <list>
#include <algorithm>

template<typename T, size_t Size>
class array
{
public:
	struct iterator
	{
		iterator(T* ptr) : _ptr{ ptr } { }

		iterator& operator ++ () { _ptr++; return *this; }
		iterator operator ++ (int)
		{
			iterator temp = *this;
			++(*this);
			return temp;
		}

		T& operator * () const { return *_ptr; }
		T* operator -> () { return _ptr; }

		friend bool operator == (const iterator& a, const iterator& b) { return a._ptr == b._ptr; }
		friend bool operator != (const iterator& a, const iterator& b) { return a._ptr != b._ptr; }

		T* _ptr;
	};


public:
	T& operator [] (size_t position) { return _values[position]; }

	iterator begin() { return iterator{ &_values[0] }; }
	iterator end() { return iterator{ &_values[Size] }; }

private:
	T _values[Size];
};

int main()
{
	array<int, 5> numbers;
	numbers[0] = 9;
	numbers[1] = 45;
	numbers[2] = 3;
	numbers[3] = 20;
	numbers[4] = 99;

	//	array<int, 5>::iterator iter = numbers.begin(); auto is cleaner
	auto iter = numbers.begin();
	iter++;
	std::cout << *iter << std::endl;

	for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	std::list<float> pay{ 4.5f, 6.23f, 10.0f };
	for (auto iter = pay.begin(); iter != pay.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	auto it = std::find(numbers.begin(), numbers.end(), 45);
	if (it != numbers.end())
	{
		std::cout << *iter << std::endl;
	}

}