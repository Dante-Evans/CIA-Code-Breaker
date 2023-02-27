//This is the code breaker for the CIA. 
//Written by: Daniel Hall

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Func.h"

using namespace std;

enum guesses { WORD, HINT, CHANCES};
const int WORDS = 10;

int main()
{
	const string CODES[WORDS][CHANCES] =
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
	return 0;
}