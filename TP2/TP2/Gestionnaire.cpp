#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
	for (unsigned int i = 0; i < automates_.size(); i++)
		delete automates_[i];
	for (unsigned int i = 0; i < vehicules_.size(); i++)
		delete vehicules_[i];
	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		delete utilisateurs_[i];
}

void Gestionnaire::creerLexiques(const string& nomFichier)
{
	Automate* automate = new Automate(nomFichier);
	if (automate->getEtats().size()){
		addAutomate(automate);
		cout << "Automate cree." << endl;
	}
}

void Gestionnaire::creerVehicule(const string& code) 
{
	// On cherche la zone � laquelle appartient le v�hicule
	Automate* zone = trouverAutomate(code);
	if (zone != nullptr){
		vehicules_.push_back(new Vehicule(zone, code, false));
		cout << "\nVehicule " << vehicules_.size() - 1 << " cree" << endl;
	}
	else
		cout << "\nERROR Vehicule non cree : Code inexistant." << endl;
}

void Gestionnaire::creerUtilisateur(const string& origine, const string& destination )
{
	// On cherche les zones correspondantes
	Automate* depart = trouverAutomate(origine);
	Automate* arrivee = trouverAutomate(destination);
	if (depart != nullptr && arrivee != nullptr){
		utilisateurs_.push_back(new Utilisateur(origine, destination));
		cout << "\nClient " <<utilisateurs_.size()-1 <<" cree"<< endl;
	}
	else if (depart != nullptr && arrivee == nullptr)
		cout << "\nERROR Client non cree : la destination du client est inexistante." << endl;
	else if (depart == nullptr && arrivee != nullptr)
		cout << "\nERROR Client non cree : l'origine du client est inexistante." << endl;
	else
		cout << "\nERROR Client non cree : L'origine et la destination du client sont inexistantes." << endl;
}

void Gestionnaire::equilibrerFlotte()
{
	int j = 0;
	Automate* Max = trouverMax();
	for (unsigned int i = 0; i < automates_.size(); i++)
	{
		int nbrVehicule = automates_[i]->getNvehicules();
		int diff = Max->getNvehicules() - nbrVehicule;
		//On �quilibre entre les automates jusqu'� avoir au plus 2 v�hicules d'�cart
		while (Max->getNvehicules() - nbrVehicule >= 2){
			SwapVehicule(automates_[i], Max);
		}
		Max = trouverMax();
	}
	
}

void Gestionnaire::SwapVehicule(Automate* automate1, Automate* automate2){
	for (unsigned int i = 0; i < vehicules_.size(); i++){
		if (vehicules_[i]->getZone() == automate2 && !vehicules_[i]->isOccupied()){
			automate2->decrementerNbVehicules();
			automate1->incrementerNbVehicules();
			vehicules_[i]->setZone(automate1);
			vehicules_[i]->incrementerCompteurTrajetsVides();
			return;
		}
	}
}


Automate* Gestionnaire::trouverMax(){
	
	int maximum = 0;
	Automate* automate = nullptr;

	if (!automates_.empty()){
		for (unsigned int i = 0; i < automates_.size(); i++){
			if (automates_[i]->getNvehicules() > maximum){
				maximum = automates_[i]->getNvehicules();
				automate = automates_[i];
			}
		}
	}
	return automate;
}

void Gestionnaire::lancerSimulation()
{
	// On stocke le nombre initial de v�hicules de chaque zone
	vector<int> nbVehiculesinitial;
	for (unsigned int k = 0; k < automates_.size(); k++){
		nbVehiculesinitial.push_back(automates_[k]->getNvehicules());
	}

	// On effectue les d�placements de chaque utilisateurs en �quilibrant la flotte
	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
	{
		Vehicule* vehicule = trouverVehiculeDisponible(utilisateurs_[i]);
		if (vehicule != nullptr) {
			miseAJourInformations(vehicule, utilisateurs_[i]);
			equilibrerFlotte();
		}
		else{
			cout << "\nAucun vehicule n'est disponible.\n";
		}
	}

	// Affichage du nombre de trajets avec occupant et � vide pour chaque v�hicule
	for (unsigned int j = 0; j < vehicules_.size(); j++){
		cout << endl;
		cout << "VEHICULE " << j << endl;
		cout << "Nombres de trajets avec un occupant : " <<vehicules_[j]->getNtrajetsOccupes() <<endl;
		cout << "Nombres de trajets a vide : "<< vehicules_[j]->getNtrajetsVides() << endl;
	}

	// Affichage du nombre de v�hicules par zones avant et apr�s la simulation.
	for (unsigned int n = 0; n < nbVehiculesinitial.size(); n++){
		cout << "AUTOMATE " << n << endl
			<< "\nNombre de vehicules au debut de la simulation : " << nbVehiculesinitial[n] << endl;
		cout << "Nombre de vehicules a la fin de la simulation pour l'automate " << n << " : " << automates_[n]->getNvehicules() <<endl <<endl;
	}
}

Vehicule* Gestionnaire::trouverVehiculeDisponible(Utilisateur* user)
{
	Vehicule* vehicule = nullptr;
	Automate* zone = trouverAutomate(user->getOrigine());

	// Trouver une voiture dans le voisinage du client s'il y en a une
	for (unsigned int i = 0; i < vehicules_.size(); i++) {
		if (vehicules_[i]->getCode() == user->getOrigine() && !vehicules_[i]->isOccupied())
		{
			vehicule = vehicules_[i];
			break;
		}
	}

	//Sinon, on assigne la premiere voiture disponible dans la zone du client
	if (vehicule == nullptr) {
		for (unsigned int i = 0; i < vehicules_.size(); i++)
		{
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
	vehicule->setOccupation(false);
}

std::vector<Automate*> Gestionnaire::getAutomates() const
{
	return automates_;
}

std::vector<Utilisateur*> Gestionnaire::getUtilisateurs() const{
	return utilisateurs_;
}

std::vector<Vehicule*> Gestionnaire::getVehicules() const{
	return vehicules_;
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