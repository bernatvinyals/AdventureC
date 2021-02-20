#pragma once
#include <string>
struct Object {
	bool hotinc;
	int onEsta;
	std::string Nom;
};
void accio(int CN, Object inventari[], int &hab, bool &notend, bool comprovadors[], int &second);
void whatRoom(int hab);
void omplirInventari(Object inventari[]);
void emptyInventari(Object inventari[]);
void whatItemInRoom(int hab, Object inventari[], bool &started, bool finished, bool comprovadors[]);
void showHeader();