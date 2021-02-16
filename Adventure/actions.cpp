#include <iostream>
#include <string>
#include "funcions.h"


using namespace std;
extern Object inventari[10];
extern bool comprovadors[8];
void accio(int CN, Object inventari[], int &hab, bool &notend, bool comprovadors[]) {
	cout << endl;

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
	default:
		cout << "My thoughts are blured and i dont even know what i'm saying";
		break;
	}
	cout << endl;
}