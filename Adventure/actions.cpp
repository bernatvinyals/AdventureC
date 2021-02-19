#include <iostream>
#include <string>
#include "funcions.h"


using namespace std;
extern Object inventari[10];
extern bool comprovadors[8];

void omplirInventari(Object inventari[]) {
	inventari[0].Nom = "Bosses mug"; //Can get it by picking it up at the secretary office
	inventari[0].hotinc = false;
	inventari[0].onEsta = 2;
	inventari[1].Nom = "5$"; //Can get it by talking to the receptionist
	inventari[1].hotinc = false;
	inventari[1].onEsta = 31;
	inventari[2].Nom = "Secretary Mug"; //Can get it by talking to the secretary
	inventari[2].hotinc = false;
	inventari[2].onEsta = 31;
	inventari[3].Nom = "PS1 Controller"; //Can get it picking it up on the balcony
	inventari[3].hotinc = false;
	inventari[3].onEsta = 10;
	inventari[4].Nom = "Storage Key"; //Can get it talking with the secretary
	inventari[4].hotinc = false;
	inventari[4].onEsta = 31;
	inventari[5].Nom = "Coffee grains"; //Can get this by buying it on the store
	inventari[5].hotinc = false;
	inventari[5].onEsta = 4;
	inventari[6].Nom = "Soda Can"; //Can get this by buying it on the store
	inventari[6].hotinc = false;
	inventari[6].onEsta = 4;
}
void grabItem(Object &inventari, bool &isItem, int hab) {
	if (inventari.hotinc == false)
	{
		if (inventari.onEsta == hab)
		{
			inventari.hotinc = true;
			inventari.onEsta = 0;
			cout << "You picked the "<< inventari.Nom<<"\n";
		}
		else
		{
			isItem = true;
		}
	}
}
void dropItem(Object &inventari, bool &isItem, int hab) {
	if (inventari.hotinc == hab)
	{
		inventari.hotinc = false;
		inventari.onEsta = hab;
		cout << "You droped the " << inventari.Nom << "\n";
	}
	else
	{
		isItem = true;
	}
	
}

void accio(int CN, Object inventari[], int &hab, bool &notend, bool comprovadors[]) {
	cout << endl;
	bool isItem=false; //Per dir que el objecte no esta (true)
	bool isHaveit = false;
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

	case 11308:
		cout << "You punch your boss without a reason. \n";
		cout << "He suddently grabs you and throws you into the ground telling you that youre fired \n";
		cout << "Game over";
		notend = false;
		break;
	case 10007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 11407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 10015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 11415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 10014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 11414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 10013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 11413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 10012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 11412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 10010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 11410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 10011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 11411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;






	case 21205:
		if (comprovadors[0] == true)
		{
			cout << "You shouldn't go into the bosses office until you have the coffee\n";
		}
		break;
	case 21201:
		hab = 3;
		
		break;
	case 21204:

		hab = 5;
		break;
	
	case 20007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 21407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 20015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 21415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 20014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 21414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 20013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 21413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 20012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 21412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 20010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 21410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 20011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 21411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
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
	case 30500:
		//Posar la condicio de que necesito diners per comprar el cafe----------------------------------------------------------
		break;
	case 30007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 31407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 30015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 31415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 30014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 31414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 30013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 31413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 30012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 31412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 30010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 31410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 30011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 31411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;




	case 41204:
		hab = 3;
		break;
	case 40007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 41407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 40015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 41415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 40014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 41414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 40013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 41413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 40012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 41412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 40010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 41410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 40011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 41411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;

	
	
	case 61204:
		hab = 7;
		break;
	case 61205:
		hab = 3;
		break;
	case 60509:
		cout << "You have a great time talking with your colleagues but you also forget that you had to get coffee for your boss.\n";
		cout << "Game over";
		notend = false;
	case 60007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 61407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 60015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 61415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 60014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 61414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 60013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 61413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 60012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 61412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 60010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 61410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 60011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 61411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
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
	case 70007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 71407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 70015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 71415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 70014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 71414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 70013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 71413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 70012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 71412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 70010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 71410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 70011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 71411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;


	case 81204:
		hab = 9;
		break;
	case 81201:
		hab = 7;
		break;
	case 80007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 81407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 80015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 81415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 80014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 81414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 80013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 81413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 80012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 81412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 80010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 81410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 80011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 81411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;


	case 91205:
		hab = 8;
		break;
	case 90007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 91407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 90015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 91415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 90014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 91414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 90013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 91413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 90012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 91412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 90010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 91410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 90011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 91411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;


	case 101205:
		hab = 7;
		break;
	case 100007://Grab Mug
		grabItem(inventari[0], isItem, hab);
		break;
	case 101407: //Drop Mug
		dropItem(inventari[0], isHaveit, hab);
		break;
	case 100015://Grab 5$
		grabItem(inventari[1], isItem, hab);
		break;
	case 101415://Drop 5$
		dropItem(inventari[1], isHaveit, hab);
		break;
	case 100014://Grab secretary mug
		grabItem(inventari[2], isItem, hab);
		break;
	case 101414://Drop secretary mug
		dropItem(inventari[2], isHaveit, hab);
		break;
	case 100013://Grab PS1 Controller
		grabItem(inventari[3], isItem, hab);
		break;
	case 101413: //Drop PS1 Controller
		dropItem(inventari[3], isHaveit, hab);
		break;
	case 100012://Grab Storage Key
		grabItem(inventari[4], isItem, hab);
		break;
	case 101412: //Drop Storage Key
		dropItem(inventari[4], isHaveit, hab);
		break;
	case 100010://Grab Coffee grains
		grabItem(inventari[5], isItem, hab);
		break;
	case 101410: //Drop Coffee grains
		dropItem(inventari[5], isHaveit, hab);
		break;
	case 100011://Grab Soda Can
		grabItem(inventari[6], isItem, hab);
		break;
	case 101411: //Drop Soda Can
		dropItem(inventari[6], isHaveit, hab);
		break;

	default:
		cout << "My thoughts are blured and i dont even know what i'm saying\n";
		break;
	}
	if (isItem)
	{
		cout << "There isn't such a thing in here\n";
	}
	if (isHaveit)
	{
		cout << "I don't have that item in orther to drop it!\n";
	}
	cout << endl;
}