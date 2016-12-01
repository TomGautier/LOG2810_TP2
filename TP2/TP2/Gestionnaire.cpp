#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
	/*for (Automate* a : automates_)
		delete a;
	for (Vehicule* v : vehicules_)
		delete v;
	for (Utilisateur* u : utilisateurs_)
		delete u;*/
}

void Gestionnaire::creerLexiques(const string& nomFichier)
{
	Automate* automate = new Automate(nomFichier);
	this->addAutomate(automate);
}

void Gestionnaire::creerVehicule(const string& code) 
{
	Automate* zone = trouverAutomate(code);
	if (zone != nullptr)
		vehicules_.push_back(new Vehicule(zone, code, false));
	else
		cout << "Code inexistant." << endl;
}

void Gestionnaire::creerUtilisateur(const string& origine, const string& destination ) {
	utilisateurs_.push_back(new Utilisateur(origine, destination));
}

void Gestionnaire::equilibrerFlotte()
{
	/*int i = 0;
	string mot = "";
	while (mot.length() != user.getdestination().length()) {
		auto it = automates_[i].getEtats().begin();

		//premier caractere
		while (it != automates_[i].getEtats().end()) {
			if (user->getDestination()[0] == it->getCode()[0]) {
				mot = it->getCode()[0];
			}
		}
	}*/
}

void Gestionnaire::lancerSimulation()
{
	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
	{
		Vehicule* vehicule = trouverVehiculeDisponible(utilisateurs_[i]);
		if (vehicule != nullptr) {
			miseAJourInformations(vehicule, utilisateurs_[i]);
			equilibrerFlotte();
		}
		else{
			cout << "Aucun vehicule n'est disponible. Marche! fait du sport!";
		}
	}
}

Vehicule* Gestionnaire::trouverVehiculeDisponible(Utilisateur* user)
{
	Vehicule* vehicule = nullptr;
	Automate* zone = trouverAutomate(user->getOrigine());

	//Trouver une voiture dans le voisinage du client
	for (unsigned int i = 0; i < vehicules_.size(); i++) {
		if (vehicules_[i]->getCode() == user->getOrigine() && !vehicules_[i]->isOccupied())
		{
			vehicule = vehicules_[i];
			break;
		}
	}

	//Assigner la premiere voiture disponible dans la zone du client
	if (vehicule == nullptr) {
		for (unsigned int i = 0; i < vehicules_.size(); i++)
		{
			/*
			//TODO : comparaison de deux pointeurs : ne marchera pas.
			*/
			Automate* automate = vehicules_[i]->getZone();
			if (vehicules_[i]->getZone() == zone && !vehicules_[i]->isOccupied())
			{
				vehicule = vehicules_[i];
				break;
			}
		}
	}

	return vehicule;
}

void Gestionnaire::miseAJourInformations(Vehicule* vehicule, Utilisateur* user)
{
	Automate* automateDepart = trouverAutomate(user->getOrigine());
	Automate* automateArrivee = trouverAutomate(user->getDestination());

	vehicule->setCode(user->getDestination());
	vehicule->setZone(automateArrivee);
	vehicule->incrementerCompteurTrajetsOccupes();
	vehicule->setOccupation(true);
	automateArrivee->incrementerNbVehicules();
	automateDepart->decrementerNbVehicules();
}

std::vector<Automate*> Gestionnaire::getAutomates() const
{
	return automates_;
}

void Gestionnaire::addAutomate(Automate* automate)
{
	automates_.push_back(automate);
}

Automate* Gestionnaire::trouverAutomate(const string& code) const{
	
	Automate* automate = nullptr;

	for (unsigned int i = 0; i < automates_.size(); i++)
	{
		automate = automates_[i]->parcoursAutomate(code);
		if (automate != nullptr)
			break;
	}
	return automate;

}