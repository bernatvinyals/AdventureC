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
		break;
	case 2: //Secretary Office
		cout << "Secretary Office \n";
		cout << "West: Boss Office \nEast: Meeting Room \nSouth: Reception \n";
		break;
	case 3:
		cout << "Reception \n";
		cout << "North: Secretary Office \nWest: Market \nEast: Open Office \n";
		break;
	case 4:
		cout << "Market \n";
		cout << "East: Reception \n";
		break;
	case 5:
		cout << "Meeting room \n";
		cout << "West: Secretary Office \n";
		break;
	case 6:
		cout << "Open office \n";
		cout << "West: Reception \nEast: Open Office \n";
		break;
	case 7:
		cout << "Free time office \n";
		cout << "North: Storage \nWest: Open Office \nEast: Balcony \n";
		break;
	case 8:
		cout << "Storage \n";
		cout << "East: Storage 2 \n";
		break;
	case 9:
		cout << "Storage 2 \n";
		cout << "West: Storage \n";
		break;
	case 10:
		cout << "Balcony \n";
		cout << "West: Free time office \n";
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
void whatItemInRoom(int hab, Object inventari[], bool &started, bool finished, bool comprovadors[]) {
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
			cout << "You give the cup of coffee to your boss. \n The end.";
		}
		else
		{
			break;
		}
	case 2: //Secretary Office
		if (comprovadors[0]== true && comprovadors[1] == false)
		{
			cout << "You get out of the boss office and decide to go to \'Storage 2\' and pick the coffee grains that you need.\nAlso you decide to grab the 'bosses mug'.\n(To do so say 'grab mug')";
			comprovadors[1] = true;
			for (int i = 0; i < 10; i++)//amount of items
			{
				if (inventari[i].onEsta == 2)
				{
					
					objphrase = inventari[i].Nom;
					cout << "\nObjects in room: " << objphrase;
				}
			}
			//cout << "I can see that there is a couple of objects here:\n" << objphrase;
		}
		else
		{
			cout << "This is the secretary office, nothing special about it.";
			
			if (checkItem(inventari, hab))
			{
				for (int i = 0; i < 10; i++)//amount of items
				{
					if (inventari[i].onEsta == 2)
					{
						objphrase.append(inventari[i].Nom);
						objphrase.append(" and ");
					}
				}
			}
			
			cout<< "I can see that there's a "<< objphrase;
			break;
		}
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	default:
		break;
	}
}