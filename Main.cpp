//This is the code breaker for the CIA. 
//Written by: Daniel Hall

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Func.h"

using namespace std;

enum guesses { WORD, HINT, CHANCES}; //enums for the word and the guesses
const int WORDS = 10; //constant for the number of words in the array.

int main()
{	
	const string CODES[WORDS][CHANCES] = //This is where I set up the array for the words to guess.
	{
		{"Cheat", "What you do on a test."},
		{"Sheet","What a piece of paper is called"},
		{"Hairspray","Something used in your hair"},
		{"Squeeze","Are things getting tight for you?"},
		{"Moisture","What happens when things get wet."},
		{"Short","Vertically challenged."},
		{"Nagger","It starts with an 'N' and ends with and 'r' and they annoy you."},
		{"Wench","Your wife"},
		{"Hag","Your in laws"},
		{"Congress","Abuse of power"},
	};	
	
	//I tried to make this next section a function and put it in a different file but it wasn't working and I couldn't make it work.
	srand(static_cast<unsigned int>(time(0))); //This is where I setup the random word generator
	int code = (rand() % WORDS); //This picks the word at random.
	string codeBreak = CODES[code][WORD]; //This gets the word to be cracked
	string codeHint = CODES[code][HINT]; //This gives a hint as to what the code word is.
	//End section

	string scramble = codeBreak; //This will scarmble the word.				
	int letters = scramble.size(); //This gets the size of the word.

	for (int i = 0; i < letters; ++i) //because I am unimaginative I am going to use the standard stuff for a for loop.
	{
		int letter1 = (rand() % letters); //first index of a letter randomly throughout the word.
		int letter2 = (rand() % letters); //second index of a letter randomly throughout the word.
		char chosen = scramble[letter1]; //This line and the next two scramble the word around.
		scramble[letter1] = scramble[letter2];
		scramble[letter2] = chosen;
	}

	//entering the game loop.
	//but first how about I greet the player and give them a chance to quit before starting.
	cout << "\t\t\t\tWelcome Operative.\n\n";
	cout << "You have been tasked with breaking the code before you.\n";
	cout << "This is a matter of life and death. If you are unable to crack this code a random operator\n";
	cout << "will lose their life because you weren't fast enough.\n";
	cout << "Do you think you have what it takes to crack the code?\n\n";
	cout << "Enter 'Quit' to quit the hack.\n";
	cout << "Type 'Hint' to receive a hint for the word. Sorry you only get one hint.\n";
	cout << "Your code to hack is: " << scramble; //This gets the scrambled word.

	string hack;
	cout << "\n\n\nYour hack attempt is: ";
	cin >> hack;			

		while ((hack != codeBreak) && (hack != "Quit"))
		{
			if (hack == "Hint")
			{
				cout << codeHint; //Gives the player a hint.
			}
			else
			{
				cout << "\nYou have failed to hack the code.\n\n";
			}
			cout << "\n\nYou have a chance to hack the code.\n";
			cout << "\nWhat is your attempt?\n\n";
			cin >> hack;
		}

		if (hack == codeBreak)
		{
			cout << "\nYou have successfully hacked the code. Your operator has advanced into the next area.\n";
			cout << "You have kept this operator alive this time. However, things aren't always going to be this easy.\n";
		}
	

	return 0;
}