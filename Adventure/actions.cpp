#include <iostream>
#include <string>
#include "funcions.h"
#include "ConsoleControl/ConsoleControl.h"

using namespace std;
extern Object inventari[10];
extern bool comprovadors[8];

void omplirInventari(Object inventari[]) {
	for (int i = 0; i < 8; i++)//amount of items
	{
		comprovadors[i] = false;
	}
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
	inventari[5].onEsta = 34;
	inventari[6].Nom = "Soda Can"; //Can get this by buying it on the store
	inventari[6].hotinc = false;
	inventari[6].onEsta = 34;
	inventari[7].Nom = "Mug with Coffee (Coffee)"; //Can get this by combining the bosses mug with Coffee grains 
	inventari[7].hotinc = false;
	inventari[7].onEsta = 34;
}
void emptyInventari(Object inventari[]) {
	for (int i = 0; i < 10; i++)
	{
		inventari[i].hotinc = false;
	}
	for (int i = 0; i < 8; i++)//amount of items
	{
		comprovadors[i] = false;
	}
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
	if (inventari.hotinc == true)
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
void displayInventory() {
	string phrase="#";
	cout << "\n+----RESULT:-----------------------------------------------------------------------------------------------------------+\n";
	cout << "On inventory: ";
	for (int i = 0; i < 10; i++)
	{
		if (inventari[i].hotinc == true)
		{
			phrase = inventari[i].Nom;
			phrase.append(", ");
		}
	}
	if (phrase != "#")
	{
		phrase.resize(phrase.size() - 2);
		phrase.erase(phrase.begin());
		cout << phrase << ".\n";
	}
	else
	{
		cout << "You don't have anything right now.\n";
	}
	cout << "+----------------------------------------------------------------------------------------------------------------------+\n";	
}

void accio(int CN, Object inventari[], int &hab, bool &notend, bool comprovadors[], int &second, bool &finished) {
	cout << endl;
	bool isItem=false; //Per dir que el objecte no esta (true)
	bool isHaveit = false;
	ConsoleClear();
	cout << "+----RESULT:-----------------------------------------------------------------------------------------------------------+\n";
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
	case 10508:
		if (true)
		{
			cout << "You try to talk a little bit more with your boss but he refuses and you procced to leave.";
			hab = 2;
		}
	
		break;
	case 11308:
		cout << "You punch your boss without a reason. \n";
		cout << "He suddently grabs you and throws you into the ground telling you that youre fired \n";
		cout << "Game over\n";
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
		if (inventari[7].hotinc == true || finished == true)
		{
			hab = 1;
			break;
		}
		else if (comprovadors[0] == true && finished == false)
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
	case 21016:
		if (comprovadors[4]== false)
		{
			comprovadors[4] = true;
			inventari[4].hotinc = true;
			cout << "The secretary gives you the Storage key. Now don't lose it!\n";
		}
		break;
	case 21012://ask secretary for storage key
		if (second == 16)
		{
			if (comprovadors[4] == false)
			{
				comprovadors[4] = true;
				inventari[4].hotinc = true;
				cout << "The secretary gives you the Storage key. Now don't lose it!\n";
			}
			else
			{
				cout << "You already asked for the keys.";
			}
		}
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
	case 31000: //ask receptionist for money
		if (second == 17)
		{
			if (comprovadors[5] == true)
			{
				inventari[1].hotinc = true;
				cout << "After some talking with the receptionist you get 5$ to spend in supplies.\n";
			}
		}
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
	case 40710:
		if (inventari[1].hotinc == true)
		{
			if (second == 11)
			{
				cout << "You bought a pack of Coffee grains and one Soda Can. A bit expensive but it works.\n";
				inventari[1].hotinc = false;
				inventari[5].hotinc = true;
				inventari[6].hotinc = true;
			}
			else
			{
				cout << "You bought 2 packs of Coffe grains with the money that they gave you. One of these packs go directly to storage but with the other one i can now combine it with the bosses mug and finally give this coffee to him.\n";
				inventari[1].hotinc = false;
				inventari[5].hotinc = true;
			}
		}
		else
		{
			cout << "What am i going to buy without cash?\n";
		}
		break;
	case 40711:
		cout << "If anything you should buy Coffee Grains first.\n";
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



	case 50902://browse notebook
		cout << "You procced to browse this notebook and find an odd pattern. You see that there's a Youtube link printed in every single pair page. Maybe you should see what it contains. https://youtu.be/dQw4w9WgXcQ\n";
		break;
	case 51205:
		hab = 2;
		break;
	case 50121: //use calculator
		cout << "You spend some time using the calculator witout a reason.";
		break;

	case 61204:
		hab = 7;
		break;
	case 61205:
		hab = 3;
		break;
	case 60509:
		cout << "You have a great time talking with your colleagues but you also forget that you had to get coffee for your boss.\n";
		cout << "Game over\n";
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
		if (comprovadors[4] == false)
		{
			cout << "It's locked... I guess i have to ask to the Secretary for the key\n";
		}
		else
		{
			hab = 8;
		}
		
		break;
	case 71205:
		hab = 6;
		break;
	case 71119://sleep in couch
		cout << "You are very lazy and procced to sleep a while on the couch. Problem is... it wasn't just a while, it was all day!\nGame Over\n";
		notend = false;
		break;
	case 70220: // Play Videogames
		if (inventari[3].hotinc==true)
		{
			cout << "Another day back to 'work' for you if it wasn't that your boss found you playing for a while instead of doing the simple assignment that is preparing coffee\nGame Over\n";
			notend = false;
		}
		else
		{
			cout << "There's no controller here, maybe i should look around.";
		}

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
	case 80623:
		cout << "You drink this suspicious liquid and instantly pass out. Your coworkers find you at the groud and call an ambulance. The ambulance was so late that you dided right there, at the groud, on your workspace... Mental note for your next live don't drink something suspicious that turns out to be dish detergent.\n";
		notend = false;
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
	case 10318://Throw coffee
		if (inventari[7].hotinc == true)
		{
			cout << "You throw every single drop of coffee through the balcony with stress and anger.\nYou feel like you're wasting time doing this job and procced to fill for unemployment and quit this city.\nYou wonder if this was the right decision, to leave the city and focus on yourself.\n Game Over\n";
			notend = false;
		}
		else
		{
			isHaveit = true;
		}
		
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
	cout << "+----------------------------------------------------------------------------------------------------------------------+\n";
	cout << endl;
}