#include "Point.h"
#include <iostream>
#include <vector>
#include <array>

//int max(int i1, int i2)
//{
//	return (i1 > i2) ? i1 : i2;
//}

template<typename T>
T max(T v1, T v2)
{
	return (v1 > v2) ? v1 : v2;
}

template<typename T1, typename T2>
T1 max(T1 v1, T2 v2)
{
	return (v1 > v2) ? v1 : v2;
}

int main()
{
	Point<int> p1(4, 8);
	Point<int> p2(5, 10);
	Point<float> p3(4.2f, 8.5f);

	Point<int> p4 = max(p1, p2);

	array<std::string, 5> words;

	std::vector<int> numbers;

	std::cout << max<int>(10, 14) << std::endl;
	std::cout << max<float>(4.5f, 3.2f) << std::endl;
	std::cout << max(4.5f, 3) << std::endl;
}