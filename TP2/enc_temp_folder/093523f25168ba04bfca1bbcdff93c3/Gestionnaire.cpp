#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
}

void Gestionnaire::creerLexiques(const string& nomFichier)
{
	Automate automate = Automate();
	automate.creerAutomate(nomFichier);
	addAutomate(automate);
}

void Gestionnaire::equilibrerFlotte()
{
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

std::vector<Automate> Gestionnaire::getAutomates() const
{
	return std::vector<Automate>();
}

void Gestionnaire::addAutomate(const Automate & automate)
{
	automates_.push_back(automate);
}