
#include "Gestionnaire.h"

#include "TD2.h"

int main()
{
	Gestionnaire gestionnaire = Gestionnaire();
	TD2 td2 = TD2();

	//td2.menu1();
	gestionnaire.creerLexiques("zone1.txt");
	gestionnaire.creerLexiques("zone2.txt");
	gestionnaire.creerLexiques("zone3.txt");
	gestionnaire.creerLexiques("zone4.txt");
}