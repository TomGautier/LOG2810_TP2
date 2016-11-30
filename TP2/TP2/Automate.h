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
	set<char> getEtiquettes() const;

	Etat* parcoursAutomate(const string&);
	
private:
	set<Etat*> etats_;
	Etat* etatInitial_;
	set<char> etiquettes_;
	int nVehicules_;
};

#endif // !AUTOMATE_H