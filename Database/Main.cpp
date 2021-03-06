#include "Database.h"
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC


int main()
{
	Database* database = new Database;
	bool quit = false;
	while (!quit)
	{
		//	Display menu
		std::cout << "1) Add\n";
		std::cout << "2) Display All\n";
		std::cout << "3) Display Name\n";
		std::cout << "4) Display Type\n";
		std::cout << "5) Remove\n";
		std::cout << "6) Load\n";
		std::cout << "7) Save \n";
		std::cout << "8) Quit\n";

		std::cout << "Enter selection: ";
		int selection;
		std::cin >> selection;

		switch (selection)
		{
		case 1:
		{
			std::cout << "1) Bird\n";
			std::cout << "2) Mammal\n";
			int type;
			std::cin >> type;
			database->Add(static_cast<Animal::eType>(type));
		}
			break;
		case 2:
			database->DisplayAll();
			break;
		case 3:
		{
			std::cout << "Enter name: ";
			std::string name;
			std::cin >> name;
			database->Display(name);
		}
			break;
		case 4:
		{
			std::cout << "1) Bird\n";
			std::cout << "2) Mammal\n";
			int type;
			std::cin >> type;
			database->Display(static_cast<Animal::eType>(type));
		}
			break;
		case 5:
		{
			std::cout << "1) All\n";
			std::cout << "2) Name\n";
			std::cout << "3) Type\n";
			std::cout << "enter:\n";
			int selection;
			std::cin >> selection;
			if (selection == 1)
			{
				database->RemoveAll();
			}
			else if (selection == 2)
			{
				std::cout << "Enter name:\n";
				std::string name;
				std::cin >> name;
				database->Remove(name);
			}
			else
			{
				std::cout << "1) Bird\n";
				std::cout << "2) Mammal\n";
				int type;
				std::cin >> type;
				database->Remove(static_cast<Animal::eType>(type));
			}
			break;
		}
		case 6:
		{
			std::cout << "Enter filename: ";
			std::string name;
			std::cin >> name;
			database->Load(name);
			break;
		}
		case 7:
		{
			std::cout << "Enter filename: ";
			std::string name;
			std::cin >> name;
			database->Save(name);
			break;
		}
		case 8:
			quit = true;
			break;
		default:
			break;
		}

	}

	delete database;
	_CrtDumpMemoryLeaks();
}