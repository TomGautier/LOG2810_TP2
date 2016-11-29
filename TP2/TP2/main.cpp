
#include "Gestionnaire.h"

int main()
{
	Gestionnaire gestionnaire = Gestionnaire();
	char option = ' ';

	gestionnaire.creerLexiques("zone1.txt");
	gestionnaire.creerLexiques("zone2.txt");
	gestionnaire.creerLexiques("zone3.txt");
	gestionnaire.creerLexiques("zone4.txt");

	cout << "Voila!";
}