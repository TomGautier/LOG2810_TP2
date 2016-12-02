#pragma once

#ifndef TRANSITION_H
#define TRANSITION_H

#include "Etat.h"

class Transition
{
public : 
	Transition();
	~Transition();

	Transition(char, Etat*, Etat*);
	
	// Accesseurs
	char getEtiquette() const;
	Etat* getEtatEntrant() const;
	Etat* getEtatSortant() const;

private:
	char etiquette_;
	Etat* etatEntrant_;
	Etat* etatSortant_;
};

#endif // !TRANSITION_H