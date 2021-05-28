#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct player
{
	string name;
	int numWins;
};

string FindPlayerName(player Players[], bool playerTurn);
int askMove(bool player1Turn, int chipsInPile, player Players[]);
void getUserNames(player Players[]);


const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

int main()
{
	bool player1Turn = true;

	bool gameOver = false;
	int moveCounter = 0;
	int chipsInPile = 0;
	int chipsTaken = 0;

	int maxPerTurn = 0;
	char userChoice;
	player Players[2];

	ofstream outFile;
	outFile.open("Winners.txt", ios::app);
	

	//	Seed the random number generator
	srand(time(0));

	getUserNames(Players);

	do {
		chipsInPile = (rand() % MAX_CHIPS) + 1;
		cout << "This round will start with " << chipsInPile << " chips in the pile\n";
		gameOver = false;
		moveCounter = 0;
		while (gameOver == false)
		{
			chipsTaken = askMove(player1Turn, chipsInPile, Players);
			chipsInPile = chipsInPile - chipsTaken;
			cout << "There are " << chipsInPile << " left in the pile\n";
			player1Turn = !player1Turn;
			moveCounter++;
			if (chipsInPile == 0)
			{
				gameOver = true;
				cout << FindPlayerName(Players, player1Turn) << ", congratulations, you won!\n";
				outFile << FindPlayerName(Players, player1Turn) << " won in " << moveCounter << " moves";
			}
		}
		cout << "Do you wish to play again? (Y/N)\n";
		cin >> userChoice;
		userChoice = toupper(userChoice);

	} while (userChoice == 'Y');
	cout << Players[0].name << " had " << Players[0].numWins << " total wins this round " << endl;
	cout << Players[1].name << " had " << Players[1].numWins << " total wins this round " << endl;

	outFile.close();
	return 0;
};

void getUserNames(player Players[])
{
	cout << "Player 1, please enter your name: \n";
	cin >> Players[0].name;
	cout << "Player 2, please enter your name: \n";
	cin >> Players[1].name;
	Players[0].numWins = 0;
	Players[1].numWins = 0;
}

string FindPlayerName(player Players[], bool playerTurn)
{
	if (playerTurn == true)
		return Players[0].name;
	else
		return Players[1].name;
}

int askMove(bool player1Turn, int chipsInPile, player Players[])
{
	int chipsTaken;
	int maxPerTurn = MAX_TURN * chipsInPile;
	do
	{
		cout << FindPlayerName(Players, player1Turn) << " How many chips would you like to take? \n";
		cout << "You can take up to ";
		if (maxPerTurn == 0)
		{
			cout << " 1\n";
		}
		else
		{
			cout << maxPerTurn << endl;
		}
		if (FindPlayerName(Players, player1Turn) == "AI")
		{
			if (maxPerTurn == 0)
			{
				chipsTaken = 1;
			}
			else
			{
				chipsTaken = (rand() % maxPerTurn) + 1;
			}
		}
		else
		{
			cin >> chipsTaken;
		}
	} while ((chipsTaken > maxPerTurn) && (chipsInPile > 1));
	return chipsTaken;
}

void addWin(player Players[], bool player1Turn)
{
	if (player1Turn)
	{
		Players[0].numWins++;
	}
	else
	{
		Players[1].numWins++;
	}
}