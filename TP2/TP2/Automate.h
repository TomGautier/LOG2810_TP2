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
	set<char> getTransition() const;

	//Etat* parcoursAutomate(const string& mot);
	
private:
	set<Etat*> etats_;
	set<char> transitions_;
};

#endif // !AUTOMATE_H