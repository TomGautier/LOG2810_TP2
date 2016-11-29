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
	
	void creerLexiques(const string& nomFichier);
	void equilibrerFlotte();
	void lancerSimulation();
	
	std::vector<Automate> getAutomates() const;
	Automate* getAutomate(const string& code);
	void addAutomate(const Automate&);
private:
	void miseAJourInformations(Vehicule* vehicule, Utilisateur* user);
	Vehicule* trouverVehiculeDisponible(Utilisateur* user);

	std::vector<Automate> automates_;
};

#endif // !GESTIONNAIRE_H
