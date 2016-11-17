#pragma once

#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <Set>
#include "Etat.h"
#include "Transition.h"

using namespace std;

class Automate
{
public:
	Automate();
	~Automate();
	
private:
	set<Etat> etats;
	set<Etat> etatsFinaux;
	set<Transition> transitions;
};

#endif // !AUTOMATE_H