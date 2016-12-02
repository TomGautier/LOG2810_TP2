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

	set<Etat*> getEtats() const;
	int getNvehicules() const;

	Automate* parcoursAutomate(const string&);

	void decrementerNbVehicules();
	void incrementerNbVehicules();
	
private:
	Etat* createOrRetrieveEtat(const string&);

	set<Etat*> etats_;
	Etat* etatInitial_;
	int nVehicules_;
};

#endif // !AUTOMATE_H