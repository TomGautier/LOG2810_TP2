#pragma once

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "Automate.h"
#include "Vehicule.h"
#include "Utilisateur.h"
#include <vector>

using namespace std;

class Gestionnaire
{
public:
	Gestionnaire();
	~Gestionnaire();
	
	void creerLexiques(const string&);
	void creerVehicule(const string&);
	void creerUtilisateur(const string& , const string&);

	Automate* trouverAutomate(const string& code) const;
	Automate* Gestionnaire::trouverMax();

	void SwapVehicule(Automate*, Automate*);

	void equilibrerFlotte();
	void lancerSimulation();
	
	std::vector<Automate*> getAutomates() const;
	std::vector<Utilisateur*> getUtilisateurs() const;
	std::vector<Vehicule*> getVehicules() const;

	void addAutomate(Automate*);
private:
	void miseAJourInformations(Vehicule* vehicule, Utilisateur* user);
	Vehicule* trouverVehiculeDisponible(Utilisateur* user);

	std::vector<Automate*> automates_;
	std::vector<Vehicule*> vehicules_;
	std::vector<Utilisateur*> utilisateurs_;
};

#endif // !GESTIONNAIRE_H
