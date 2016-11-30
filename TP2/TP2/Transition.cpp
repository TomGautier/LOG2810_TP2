#include "Transition.h"

Transition::Transition()
{
}

Transition::~Transition()
{
}

Transition::Transition(char c, Etat In, Etat Out)
{
	sortie_ = c;
	etatEntrant_ = In;
	etatSortant_ = Out;
}

char Transition::getSortie() const
{
	return sortie_;
}

Etat Transition::getEtatEntrant() const
{
	return etatEntrant_;
}

Etat Transition::getEtatSortant() const
{
	return etatSortant_;
}

bool Transition::operator<(const Transition & transition) const
{
	return sortie_ < transition.getSortie();
}
