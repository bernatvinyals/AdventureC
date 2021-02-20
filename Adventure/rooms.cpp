#include <iostream>
#include <string>
#include "funcions.h"


using namespace std;
extern Object inventari[10];
void whatRoom(int hab) {
	cout << "Location: ";
	switch (hab)
	{
	case 1: //Boss Ofice
		cout << "Boss Office \n";
		cout << "East: Secretary Office \n";
		cout << "+---+---+---+---+---+\n";
		cout << "| # |   |   |   |   |\n";
		cout <<	"+---+---+---+---+---+\n";
		cout <<	"|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 2: //Secretary Office
		cout << "Secretary Office \n";
		cout << "West: Boss Office \nEast: Meeting Room \nSouth: Reception \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   | # |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 3:
		cout << "Reception \n";
		cout << "North: Secretary Office \nWest: Market \nEast: Open Office \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   | # |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 4:
		cout << "Market \n";
		cout << "East: Reception \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "| # |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 5:
		cout << "Meeting room \n";
		cout << "West: Secretary Office \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   | # |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 6:
		cout << "Open office \n";
		cout << "West: Reception \nEast: Open Office \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   | # |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 7:
		cout << "Free time office \n";
		cout << "North: Storage \nWest: Open Office \nEast: Balcony \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   | # |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 8:
		cout << "Storage \n";
		cout << "East: Storage 2 \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   | # |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 9:
		cout << "Storage 2 \n";
		cout << "West: Storage \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   | # |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	case 10:
		cout << "Balcony \n";
		cout << "West: Free time office \n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   |   |\n";
		cout << "+---+---+---+---+---+\n";
		cout << "|   |   |   |   | # |\n";
		cout << "+---+---+---+---+---+\n";
		break;
	default:
		cout << "??? \n";
		break;
	}
}
bool checkItem(Object inventari[], int hab) {
	for (int i = 0; i < 10; i++)//amount of items
	{
		if (inventari[i].onEsta == hab)
		{
			return true;
		}
	}
	return false;
}
void whatItemInRoom(int hab, Object inventari[], bool &started, bool finished, bool notend, bool comprovadors[]) {
	cout << endl;
	string objphrase;
	switch (hab)
	{
	case 1: //Boss Ofice

		if (started)
		{
			cout << "You are having a horrible day at work and your boss just asked for more coffee as if you were a maid. You obviously accept because this is the only job that would hire you as an intern and you have to pay your student loans.";
			started = true;
			comprovadors[0] = true;
			comprovadors[1] = false;
		}
		if (finished)
		{
			notend = false;
			cout << "\n\nAfter all this going back and fourth you finally bring Coffee to your boss\n";
			cout << "__________ ____    ______________       __________ ___      ___________   \n";
			cout << "MMMMMMMMMM `MM'    `MM'`MMMMMMMMM       `MMMMMMMMM `MM\\     `M'`MMMMMMMb.\n";
			cout << "/   MM   \\  MM      MM  MM      \\        MM      \\  MMM\\     M  MM    `Mb\n";
			cout << "    MM      MM      MM  MM               MM         M\\MM\\    M  MM     MM\n";
			cout << "    MM      MM      MM  MM    ,          MM    ,    M \\MM\\   M  MM     MM\n";
			cout << "    MM      MMMMMMMMMM  MMMMMMM          MMMMMMM    M  \\MM\\  M  MM     MM\n";
			cout << "    MM      MM      MM  MM    `          MM    `    M   \\MM\\ M  MM     MM\n";
			cout << "    MM      MM      MM  MM               MM         M    \\MM\\M  MM     MM\n";
			cout << "    MM      MM      MM  MM               MM         M     \\MMM  MM     MM\n";
			cout << "    MM      MM      MM  MM      /        MM      /  M      \\MM  MM    .M9\n";
			cout << "   _MM_    _MM_    _MM__MMMMMMMMM       _MMMMMMMMM _M_      \M _MMMMMMM9'\n\n";
		}

		else
		{
			break;
		}
	case 2: //Secretary Office
		if (comprovadors[0]== true && comprovadors[1] == false)
		{
			cout << "You get out of the boss office and decide to go to \'Storage 2\' and pick the coffee grains that you need.\nAlso you decide to grab the 'bosses mug'.\n(To do so by saying 'grab bosses mug')\nAlso it seems that the secretary wants to talk to you.";
			comprovadors[1] = true;
			
			//cout << "I can see that there is a couple of objects here:\n" << objphrase;
		}
		else
		{
			cout << "This is the secretary office, nothing special about it.\n";
			
		}
		break;
	case 3: //Reception
		cout << "This is reception. Nothing fancy but it does the job for this type of company.\n";
		break;
	case 4: //Market
		if (inventari[1].hotinc==true)
		{
			cout << "This is the Marketplace. A steamy place but everything that you bought here has always worked and been fine so... Since you have 5$ now you can buy 'Coffee grains' or 'Soda can'\n";
		}
		else
		{
			cout << "This is the Marketplace, i could buy things but i don't have money right now.\n";
		}
		break;
	case 5: //Meeting room
		cout << "This is the meeting room. It is the most corporate room in this building. It appears that there's a notebook, maybe i can browse it's contents... There's also a calculator here that i could use.\n";
		break;
	case 6: //Open office
		if (comprovadors[1] == true && comprovadors[2] == false)
		{
			comprovadors[2] = true;
			cout << "You enter the main big open office. You see how bored your colleagues are, maybe they want a little talk.\n";
		}
		else
		{
			cout << "This is the open office. There's a couple pepole around working but it seems that some are on break.\n";
		}

		break;
	case 7: //Free time office
		if (comprovadors[2] == true && comprovadors[3] == false)
		{
			comprovadors[3] = true;
			cout << "This is the best room of all. You're tired you can sleep at the couch. You want to play games? You can! Drink soda? You can do that too! Truly the best room... But i must go to storage and get this done.\n";
		}
		else
		{
			cout << "This is the best room of all. You're tired you can sleep at the couch. You want to play games? You can! Drink soda? You can do that too! Truly the best room...\n";
		}
		break;
	case 8: //Storage
		cout << "Here is where we put everything technological like computers and keyboards. The next room, Storage 2 is the one that has everything food related.\n";
		break;
	case 9: //Storage 2
		if (comprovadors[5]==false)
		{
			cout << "You enter to Storage 2 and oh what a non pleasant surprise! There's no Coffee grains! Now you should go and buy some with company money, but where and who should you ask? Your boss clearly doesn't want to see you, you just talked to the Secretary and maybe shell find it strange that you ask too many things. Maybe try and ask the Receptionist.\n";
			comprovadors[5] = true;
		}
		break;
	case 10: //Balcony

		break;
	default:
		break;
	}
	if (checkItem(inventari, hab))
	{
		cout << endl;
		for (int i = 0; i < 10; i++)//amount of items
		{
			if (inventari[i].onEsta == hab)
			{

				objphrase = inventari[i].Nom;
				cout << "\nObjects in room: " << objphrase;
			}
		}
	}
}
void showHeader() {
	cout << "  /$$$$$$                                 /$$                                 \n";
	cout << " /$$__  $$                               | $$                                 \n";
	cout << "| $$  \\ $$ /$$    /$$/$$$$$$  /$$$$$$$  /$$$$$$   /$$   /$$  /$$$$$$  /$$$$$$ \n";
	cout << "| $$$$$$$$|  $$  /$$/$$__  $$| $$__  $$|_  $$_/  | $$  | $$ /$$__  $$|____  $$\n";
	cout << "| $$__  $$ \\  $$/$$/ $$$$$$$$| $$  \\ $$  | $$    | $$  | $$| $$  \\__/ /$$$$$$$\n";
	cout << "| $$  | $$  \\  $$$/| $$_____/| $$  | $$  | $$ /$$| $$  | $$| $$      /$$__  $$\n";
	cout << "| $$  | $$   \\  $/ |  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$/| $$     |  $$$$$$$\n";
	cout << "|__/  |__/    \\_/   \\_______/|__/  |__/   \\___/   \\______/ |__/      \\_______/\n";
	cout << "                       Made by Bernat Vinals\n \n \n";
}