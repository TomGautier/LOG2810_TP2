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
	Automate();
	~Automate();

	void creerAutomate(const string& nomFichier);
	
private:
	set<Etat> etats;
	set<char> transitions;
};

#endif // !AUTOMATE_H