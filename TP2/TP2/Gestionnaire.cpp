#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
}

void Gestionnaire::creerLexiques(const string& nomFichier)
{
	Automate* automate = new Automate();
	automate->creerAutomate(nomFichier);
	this->addAutomate(automate);
}

void Gestionnaire::equilibrerFlotte()
{
	
	/*
	int i = 0;
	string mot = "";
	while (mot.length() != user.getdestination().length()) {
		auto it = automates_[i].getEtats().begin();
		
		//premier caractere
		while (it != automates_[i].getEtats().end()) {
			if (user->getDestination()[0] == it->getCode()[0]) {
				mot = it->getCode()[0];
			}
		}

		*/
}

void Gestionnaire::lancerSimulation()
{
/*	for (int i = 0; i < listeClients_.size(); i++)
	{
		Vehicule* vehicule = trouverVehiculeDisponible(Utilisateur* user);
		miseAJourInformations(vehicule, user);

		equilibrerFlotte();
	}*/
}

Vehicule* Gestionnaire::trouverVehiculeDisponible(Utilisateur* user)
{
	return nullptr;
}

void Gestionnaire::miseAJourInformations(Vehicule* vehicule, Utilisateur* user)
{
	/*
	for (unsigned int i = 0; i < automates_.size(); i++)
	{
		auto it = automates_[i].getEtats().begin();
		while( it!= automates_[i].getEtats().end()){
			if (user->getDestination()[0] == it->getCode()[0]) {

			}
		}

	}

	vehicule->setZone();
	user->
	vehicule->incrementerCompteurTrajetsOccupes();*/
}

std::vector<Automate*> Gestionnaire::getAutomates() const
{
	return automates_;
}

void Gestionnaire::addAutomate(Automate* automate)
{
	automates_.push_back(automate);
}
