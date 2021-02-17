#include <iostream>
#include <string>
#include "funcions.h"


using namespace std;
extern Object inventari[10];
extern bool comprovadors[8];

void omplirInventari(Object inventari[]) {
	inventari[0].Nom = "Booss mug";
	inventari[0].hotinc = "Booss mug";
	inventari[0].onEsta = 2;

}

void accio(int CN, Object inventari[], int &hab, bool &notend, bool comprovadors[]) {
	cout << endl;
	bool isItem=false; //Per dir que el objecte no esta (true)
	switch (CN)
	{
	case 10401:
		if (comprovadors[0] == true)
		{
			hab = 2;
		}		
		break;
	case 11204:
		if (comprovadors[0] == true)
		{
			hab = 2;
		}
		break;

	case 11300:
		cout << "You punch your boss without a reason. \n";
		cout << "He suddently grabs you and throws you into the ground telling you that youre fired \n";
		cout << "Game over";
		notend = false;
		break;

	case 21205:
		if (comprovadors[0] == true)
		{
			cout << "You shouldn't go into the bosses office until you have the coffe\n";
		}
		break;
	case 21201:
		hab = 3;
		
		break;
	case 21204:

		hab = 5;
		break;
	case 21203:
		break;
	case 20007:
		if (inventari[0].hotinc == false)
		{
			if (inventari[0].onEsta == hab)
			{
				inventari[0].hotinc = true;
				inventari[0].onEsta = 89;
				cout << "You picked the Bosses Mug\n";
			}
			else
			{
				isItem = true;
			}
		}
		
		break;



	case 31201:
		cout << "There's nowere to go there";
		break;
	case 31204:
		hab = 6;
		break;
	case 31203:
		hab = 2;
		break;
	case 31205:
		hab = 4;
		break;



	case 41204:
		hab = 3;
		break;

	
	
	case 61204:
		hab = 7;
		break;
	case 61205:
		hab = 3;
		break;


	case 71204:
		hab = 10;
		break;
	case 71203:
		hab = 8;
		break;
	case 71205:
		hab = 6;
		break;


	case 81204:
		hab = 9;
		break;
	case 81201:
		hab = 7;
		break;

	case 91205:
		hab = 8;
		break;

	case 101205:
		hab = 7;
		break;

	default:
		cout << "My thoughts are blured and i dont even know what i'm saying\n";
		break;
	}
	if (isItem)
	{
		cout << "There isn't such a thing in here";
	}
	cout << endl;
}