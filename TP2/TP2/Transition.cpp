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

bool Transition::operator<(const Transition & transition) const
{
	return sortie_ < transition.getSortie();
}
