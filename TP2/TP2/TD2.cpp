#include "TD2.h"

#include <string>
#include <iostream>
#include <fstream>

#define creerZones "Creer les zones."
#define entrerVehiculesEtClients "Entrer les clients et les vehicules."
#define demarrerSimulation "Demarrer la simulation."
#define quitter	"Quitter."
#define menu "--------- MENU --------- \n Veuillez choisir une des options suivantes: \n"
#define optionInvalide "Option invalide. Veuillez recommencer."

TD2::TD2()
	: option_(' ')
{
	gestionnaire_ = Gestionnaire();
}

TD2::~TD2()
{
}

void TD2::menu1()
{
	option_ = ' ';
	while (continueProgram_ || gestionnaire_.getAutomates().size())
	{
		cout << menu;
		cout << "a. " << creerZones << endl
			<< "b. " << quitter << endl;
		cin >> option_;
		switch (option_)
		{
			case 'a':
				menuZones();
				break;
			case 'b':
				//JUST FOR TESTING
				menuVehiculesEtClients();
				//continueProgram_ = false;;
				break;
			default:
				cout << optionInvalide;
		}
	}

}

void TD2::menu2()
{
	while (continueProgram_)
	{
		cout << menu;
		cout << "a. " << creerZones << endl
			<< "b. " << entrerVehiculesEtClients << endl
			<< "c. " << quitter << endl;

		cin >> option_;
		switch (option_)
		{
			case 'a':
				menuZones();
				break;
			case 'b':
				menuVehiculesEtClients();
				break;
			case 'c':
				continueProgram_ = false;
				break;
			default:
				cout << optionInvalide;
		}
	}
}

void TD2::menu3()
{
	while (continueProgram_)
	{
		cout << menu;
		cout << "a. " << creerZones << endl
			<< "b. " << entrerVehiculesEtClients << endl
			<< "c. " << demarrerSimulation << endl
			<< "d. " << quitter << endl;

		cin >> option_;
		switch (option_)
		{
			case 'a':
				menuZones();
				break;
			case 'b':
				menuVehiculesEtClients();
				break;
			case 'c':
				gestionnaire_.lancerSimulation();
				break;
			case 'd':
				continueProgram_ = false;
				break;
			default:
				cout << optionInvalide;
		}
	}
}

void TD2::menuZones()
{
	cout << "--- MENU ZONES --- " << endl
		<< "Veuillez entrer les noms des fichiers a utiliser ou -1 pour terminer: " << endl;
	string nomFichier = "";
	cin >> nomFichier;
	
	while (nomFichier != "-1")
	{
		gestionnaire_.creerLexiques(nomFichier);
		cin >> nomFichier;
	}
}

void TD2::menuVehiculesEtClients()
{
	cout << "--- MENU VEHICULES ET CLIENTS --- " << endl
		<< "Veuillez entrer le(s) nom(s) du(des) fichier(s) contenant les informations des personnes et vehicules. " 
		<< endl << endl
		<< "Chaque entree du fichier doit etre sur une ligne differente et etre sous la forme : " << endl
		<< " - pour un client : C point_de_depart (ex: H1B 2K1) point_darrivee (ex: H1A 5K2)" << endl
		<< " - pour un taxi : T zone_de_depart (ex: H1B)" << endl << endl
		<< "Entrez -1 pour terminer." << endl;

	string nomFichier = "";
	cin >> nomFichier;

	while (nomFichier != "-1")
	{
		ifstream fichierClients;
		string line;
		int compteurLigne = 0;

		cin >> nomFichier;

		fichierClients.open(nomFichier);

		if (fichierClients.fail())
			cout << "Erreur d'ouverture du fichier.\n";
		else
		{
			while (getline(fichierClients, line)) // tant que fichier pas termine
			{
				compteurLigne++;

				switch (line[0])
				{
				case 'C':
					gestionnaire_.creerUtilisateur(line.substr(2, 7 /*size of code postal*/), line.substr(9, 7));
					break;
				case 'T':
					gestionnaire_.creerVehicule(line.substr(2, 7 /*size of code postal*/));
					break;
				default:
					cout << "Erreur de format dans le fichier a la ligne : " + compteurLigne;
				}
			}
		}
	}
}
