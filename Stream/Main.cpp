#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Write(const std::string& text, std::ostream& ostream)
{
	ostream << text;
}

void Write(const std::string& text, std::ofstream& ostream)
{
	ostream << "file\n";
	ostream << text;
}

void Write(const std::vector<int>& numbers, std::ofstream& ostream)
{
	for (int n : numbers)
	{
		ostream << n << std::endl;
	}
}

void Read(std::string& text, std::ifstream& istream)
{
	istream >> text;
}

void Read(std::vector<int>& numbers, std::ifstream& istream)
{
	while (!istream.eof())
	{
		int n;
		istream >> n;

		numbers.push_back(n);
	}
}



int main()
{
	std::string text = "hello world\n";
	std::cout << text;
	Write(text, std::cout);

	//	Output to file
	std::ofstream output("data.txt");
	output << text;
	Write(text, output);
	output.close();

	text = "";

	//	Input from file
	std::ifstream input;
	input.open("data.txt");
	//	input >> text;
	std::getline(input, text);
	Read(text, input);
	input.close();

	std::cout << text;

	std::vector<int> numbers = { 1, 2, 3, 4 };
	output.open("numbers.txt");
	Write(numbers, output);
	output.close();

	numbers.clear();

	input.open("numbers.txt");
	Read(numbers, input);
	input.close();


	for (int n : numbers)
	{
		std::cout << n << std::endl;
	}
}