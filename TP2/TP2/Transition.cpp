#include "Transition.h"

Transition::Transition()
{
}

Transition::~Transition()
{
}

Transition::Transition(char, Etat*, Etat*)
{
}

char Transition::getSortie() const
{
	return sortie_;
}

bool Transition::operator<(const Transition & transition) const
{
	return sortie_ < transition.getSortie();
}
