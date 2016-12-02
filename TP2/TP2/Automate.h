#pragma once

#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <Set>
#include <iostream>
#include <fstream>
#include <string>
#include "Etat.h"
#include "Transition.h"

using namespace std;

class Automate
{
public:
	Automate(const string&);
	~Automate();

	// Accesseur
	set<Etat*> getEtats() const;
	int getNvehicules() const;

	// Méthode de parcours de l'automate
	// Elle permet de vérifier si un zip-code fait bien partie de l'automate
	Automate* parcoursAutomate(const string&);

	// Modificateurs
	void decrementerNbVehicules();
	void incrementerNbVehicules();
	
private:
	Etat* createOrRetrieveEtat(const string&);

	set<Etat*> etats_;
	Etat* etatInitial_;
	int nVehicules_;
};

#endif // !AUTOMATE_H