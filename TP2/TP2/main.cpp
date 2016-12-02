
#include "Gestionnaire.h"

#include "TD2.h"

int main()
{
	Gestionnaire gestionnaire = Gestionnaire();
	TD2 td2 = TD2();

	td2.menu1();
	/*
	// Création des automates correspondant à chaque zone

	gestionnaire.creerLexiques("zone1.txt");
	gestionnaire.creerLexiques("zone2.txt");
	gestionnaire.creerLexiques("zone3.txt");
	gestionnaire.creerLexiques("zone4.txt");

	//Utilises pour tests manuels:

	// Creation de vehicules
	//Vehicule* vehicule1Zone1 = new Vehicule(automate, "H1A 0A1", false);
	//Vehicule* vehicule2Zone1 = new Vehicule(automate, "H1A 1K9", false);
	gestionnaire.creerVehicule("H1A 0A1");
	gestionnaire.creerVehicule("H1A 1K9");

	//Vehicule* vehicule1Zone2 = new Vehicule(automate, "H1A 5B5", false);
	//Vehicule* vehicule2Zone2 = new Vehicule(automate, "H1B 1R1", false);
	gestionnaire.creerVehicule("H1A 5B5");
	gestionnaire.creerVehicule("H1B 1R1");
	

	//Vehicule* vehicule1Zone3 = new Vehicule(automate, "H1B 5W5", false);
	//Vehicule* vehicule2Zone3 = new Vehicule(automate, "H1C 0B2", false);
	gestionnaire.creerVehicule("H1B 5W5");
	gestionnaire.creerVehicule("H1C 0B2");
	gestionnaire.creerVehicule("H1C 0B5");
	gestionnaire.creerVehicule("H1C 0C9");
	gestionnaire.creerVehicule("H1C 0E9");

	//Vehicule* vehicule1Zone4 = new Vehicule(automate, "H1C 1L5", false);
	//Vehicule* vehicule2Zone4 = new Vehicule(automate, "H1A 1M4", false);
	gestionnaire.creerVehicule("H1C 1L5");
	gestionnaire.creerVehicule("H1C 1M4");
	gestionnaire.creerVehicule("H1C 1K4");

	// Creation de clients 

	// Depart et arrivee dans la même zone
	gestionnaire.creerUtilisateur("H1A 0A1", "H1A 4B5"); // zone 1 -> zone 1
	gestionnaire.creerUtilisateur("H1B 1P5", "H1C 0B3"); // zone 2 -> zone 3
	// Départ zone 1 arrivée zone 4
	gestionnaire.creerUtilisateur("H1A 0A1", "H1C 1M6");
	// Départ zone 2 arrivée zone 3
	gestionnaire.creerUtilisateur("H1B 1P7", "H1B 5X4");

	// Lancement de la simulation

	gestionnaire.lancerSimulation();

	*/
}