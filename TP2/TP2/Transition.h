#pragma once

#ifndef TRANSITION_H
#define TRANSITION_H

#include "Etat.h"

class Transition
{
public : 
	Transition();
	~Transition();

	Transition(char, Etat, Etat);

	char getSortie() const;
	Etat getEtatEntrant() const;
	Etat getEtatSortant() const;

	bool operator<(const Transition & transition) const;

private:
	char sortie_;
	Etat etatEntrant_;
	Etat etatSortant_;
};

#endif // !TRANSITION_H