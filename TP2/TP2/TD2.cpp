#include "TD2.h"

#include <string>
#include <iostream>
#include <fstream>

#define creerZones "Creer les zones."
#define entrerVehiculesEtClients "Entrer les clients et les vehicules."
#define demarrerSimulation "Demarrer la simulation."
#define quitter	"Quitter."
#define menu "--------- MENU --------- \n\nVeuillez choisir une des options suivantes: \n\n"
#define optionInvalide "Option invalide. Veuillez recommencer.\n"

TD2::TD2()
	: option_(' '), continueProgram_(true)
{
	gestionnaire_ = Gestionnaire();
}

TD2::~TD2()
{
}

void TD2::menu1()
{
	option_ = ' ';
	while (continueProgram_)
	{
		cout << menu;
		cout << "1. " << creerZones << endl
			 << "2. " << quitter << endl << endl;
		cin >> option_;
		switch (option_)
		{
			case '1':
				menuZones();
				menu2();
				break;
			case '2':
				continueProgram_=false;
				break;
			default:
				cout << optionInvalide;
				break;
		}
	}

}

void TD2::menu2()
{
	while (continueProgram_)
	{
		cout << menu;
		cout <<"1. " << creerZones << endl
			<< "2. " << entrerVehiculesEtClients << endl
			<< "3. " << quitter << endl;

		cin >> option_;
		switch (option_)
		{
			case '1':
				menuZones();
				break;
			case '2':
				menuVehiculesEtClients();
				menu3();
				break;
			case '3':
				continueProgram_ = false;
				break;
			default:
				cout << optionInvalide;
				break;
		}
	}
}

void TD2::menu3()
{
	while (continueProgram_)
	{
		cout << menu;
		cout << "1. " << creerZones << endl
			 << "2. " << entrerVehiculesEtClients << endl
			 << "3. " << demarrerSimulation << endl
			 << "4. " << quitter << endl;

		cin >> option_;
		switch (option_)
		{
			case '1':
				menuZones();
				break;
			case '2':
				menuVehiculesEtClients();
				break;
			case '3':
				gestionnaire_.lancerSimulation();
				break;
			case '4':
				continueProgram_ = false;
				break;
			default:
				cout << optionInvalide;
				break;
		}
	}
}

void TD2::menuZones()
{
	cout << "\n\n--------- MENU ZONES --------- " << endl
		<< "\nVeuillez entrer les noms des fichiers a utiliser ou -1 pour terminer: \n(les noms peuvent etre separes par un espace ou un retour a la ligne)\n " << endl;
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
	bool menuVehiculesEtClients = true;

	while (menuVehiculesEtClients){
		cout << "\n\n--------- MENU VEHICULES ET CLIENTS --------- " << endl << endl
			<< "Veuillez choisir une des options suivantes:"
			<< endl << endl
			<< "1. Entrer un client" << endl
			<< "2. Entrer un vehicule" << endl
			<< "3. Quittez et retourner au menu principale" << endl;
		

		string code, origine, arrivee, choix;
		cin >> option_;
		bool client = true;
		bool vehicule = true;
		switch (option_)
		{
		case '1':
			while (client){
				cout << "\nClient " << gestionnaire_.getUtilisateurs().size() << endl;
				cout << "Entrez la postion actuelle du client : (Ex: H1A 0A1)\n";
				cin.ignore();
				getline(cin, origine);
				cout << "Entrez la destination du client : (Ex: H1A 0A1)\n";
				getline(cin, arrivee);
				gestionnaire_.creerUtilisateur(origine, arrivee);
				cout << "\nVoulez vous entrez un autre client :\nEntrez o (pour oui) ou n (pour non) "<<endl;
				cin >> choix;
				if (choix == "n")
					client = false;
			}
			break;
		case '2':
			while (vehicule){
				cout << "\nVehicule " << gestionnaire_.getVehicules().size() << endl;
				cout << "Entrez la postion actuelle du vehicule : (Ex: H1A 0A1)\n";
				cin.ignore();
				getline(cin, code);
				cout << "\nVoulez vous entrez un autre vehicule :\nEntrez o (pour oui) ou n (pour non) " << endl;
				cin >> choix;
				gestionnaire_.creerVehicule(code);
				if (choix == "n")
					vehicule = false;
			}
			break;
		case '3':
			menuVehiculesEtClients = false;
			break;
		default:
			cout << optionInvalide;
			break;
		}



		/*<< "Chaque entree du fichier doit etre sur une ligne differente et etre sous la forme : " << endl
		<< " - pour un client : C point_de_depart (ex: H1B 2K1) point_darrivee (ex: H1A 5K2)" << endl
		<< " - pour un taxi : T zone_de_depart (ex: H1B)" << endl << endl
		<< "Entrez -1 pour terminer." << endl;*/



		/*while (nomFichier != "-1")
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
		gestionnaire_.creerUtilisateur(line.substr(2, 7 /*size of code postal), line.substr(9, 7));
		break;
		case 'T':
		gestionnaire_.creerVehicule(line.substr(2, 7 /*size of code postal));
		break;
		default:
		cout << "Erreur de format dans le fichier a la ligne : " + compteurLigne;
		}
		}
		}
		}*/




	}
}
