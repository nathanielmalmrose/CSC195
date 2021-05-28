#include <iostream>
#include <bitset>

void func()
{
	//
}

using u8_t = unsigned char;
using u16_t = unsigned short;
using u32_t = unsigned int;

int main()
{
	int i = 0;
	i = i + 5;

	if (i != 10)
	{
		i = 0;
	}

	func();

	u8_t b1 = 0b00001111;
	u8_t b2 = 0b11110000;

	//	| OR
	//	& AND
	//	^ XOR
	//	~ NOT
	std::cout << std::bitset<8>(b1 | b2) << std::endl;

	u8_t shift = 1;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << std::bitset<8>(shift << i) << std::endl;
		std::cout << (shift << i) << std::endl;
	}

	u8_t lower = 0b10101110;
	u8_t upper = 0b11101010;

	u16_t ul = ((upper << 8) | lower);
	std::cout << std::bitset<8>(upper) << std::endl;
	std::cout << std::bitset<8>(lower) << std::endl;
	std::cout << std::bitset<16>(ul) << std::endl;
	std::cout << (ul) << std::endl;

	//u32_t rgba = (r << 24) | (g << 16) | (b << 8) | (a);
}