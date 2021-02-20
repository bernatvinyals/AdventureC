#include <iostream>
#include <string>
#include <algorithm>
#include "funcions.h"
#include "ConsoleControl/ConsoleControl.h"

using namespace std;

int pharser(string phrase, int hab, int &second) {
	int whereVerb = -1;
	int whereNom = -1;
	int whereNom2 = -1;
	int verbint=9, nomint=9, nomint2=0;
	int CN;
	bool saved = false;
	//                  0        1       2        3       4      5        6       7      8        9       10       11     12      13      14           
	string verbs[15] = {"grab", "use", "play", "throw", "get", "talk", "drink", "buy", "combine", "acces", "ask", "sleep", "go", "punch", "drop"};
	string names[18] = {"receptionist", "out", "pen", "north", "east", "west", "south", "bosses mug", "boss", "colleagues", "coffee grains", "soda can", "storage key", "ps1 controller", "secretary mug", "5$", "secretary", "money" };

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
	for (size_t i = 0; i < 18; i++)//Mirar els noms/objectes
	{
		if (saved)
		{
			saved = false;
			for (size_t i = 0; i < 18; i++)//Mirar els noms/objectes2
			{
				if (saved)
				{
					break;
				}
				whereNom2 = phrase.find(names[i]);
				if (whereNom2 != -1&& whereNom2 != whereNom)
				{
					saved = true;
					nomint2 = i;
				}
			}
			break;
		}
		whereNom = phrase.find(names[i]);
		if (whereNom != -1) 
		{
			saved = true;
			nomint = i;
		}
	}
	if (whereNom2 != -1)
	{
		second = nomint2;
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
	int second = 0;
	bool repetir = true;
	string repeat;
	string phrase;
	
	omplirInventari(inventari);
	while (repetir)
	{
		int chres = true;
		bool inici = true;
		bool finished = false;
		bool notend = true;
		showHeader();
		do {
			//ConsoleClear();
			whatRoom(habitacio);
			whatItemInRoom(habitacio, inventari, inici, finished, comprovadors);

			//DEBUG
			cout << endl;
			for (int i = 0; i < 10; i++)//amount of items
			{
				if (inventari[i].hotinc == true) { cout << "1 "; }
				if (inventari[i].hotinc == false) { cout << "0 "; }
			}
			//Pharser
			cout << endl;
			getline(cin, phrase); //Verb + nom
			transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower); //Fer minuscules
			if (phrase == "inventory")
			{
				//Show inventory function
			}
			else if (phrase == "restart game")
			{
				notend = false;
			}
			else
			{
				CN = pharser(phrase, habitacio, second);
			}
			cout << CN << endl;
			cout << second;
			accio(CN, inventari, habitacio, notend, comprovadors,second);

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