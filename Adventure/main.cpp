#include <iostream>
#include <string>
#include <algorithm>
#include "funcions.h"
#include "ConsoleControl/ConsoleControl.h"

using namespace std;

int pharser(string phrase, int hab) {
	int whereVerb = -1;
	int whereNom = -1;
	int verbint=9, nomint=9;
	int CN;
	bool saved = false;
	//                  0        1       2        3       4      5        6       7      8        9       10       11     12      13      14           
	string verbs[15] = {"grab", "use", "play", "throw", "get", "talk", "drink", "buy", "yell", "acces", "kill", "sleep", "go", "punch", "look"};
	string names[7] = {"boss", "out", "pen", "north", "east", "west", "south" };

	for (size_t i = 0; i < 15; i++)//Mirar els verbs
	{
		if (saved)
		{
			break;
		}
		whereVerb = phrase.find(verbs[i]);
		if (whereVerb != -1) //D'aquesta manera nomes pots escriure 1 verb ja que si fa 2 acabara agafant el segont
		{
			saved = true;
			verbint = i;
		}
	}
	saved = false;
	for (size_t i = 0; i < 7; i++)//Mirar els noms/objectes
	{
		if (saved)
		{
			break;
		}
		whereNom = phrase.find(names[i]);
		if (whereNom != -1) 
		{
			saved = true;
			nomint = i;
		}
	}
	if (whereVerb!=-1 && whereNom!=-1)
	{
		CN = (hab * 10000) + (verbint * 100) + (nomint);
		return CN;
	}
	else
	{
		return 999999999;
	}


}

Object inventari[10];
bool comprovadors[8];
int main() {
	int habitacio = 1;
	int CN;
	bool repetir = true;
	string repeat;
	string phrase;
	
	while (repetir)
	{
		int chres = true;
		bool inici = true;
		bool finished = false;
		bool notend = true;
		do {
			//ConsoleClear();
			whatRoom(habitacio);
			whatItemInRoom(habitacio, inventari, inici, finished, comprovadors);
			//Pharser
			cout << endl;
			getline(cin, phrase); //Verb + nom
			transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower); //Fer minuscules
			CN = pharser(phrase, habitacio);
			cout << CN << endl;
			accio(CN, inventari, habitacio, notend, comprovadors);

		} while (notend);
		while (chres)
		{
			cout<< "\nDo you want to repeat? (y = yes, n = no)"; 
			getline(cin, repeat);
			if (repeat == "y" || repeat == "n")
			{
				chres = false;
				if (repeat == "y")
				{
					repetir = true;
				}
				else if(repeat == "n")
				{
					repetir = false;
				}
			}
			
		}
	}

	return 0;
}