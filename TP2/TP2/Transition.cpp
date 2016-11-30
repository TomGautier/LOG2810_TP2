#include "Transition.h"

Transition::Transition()
{
}

Transition::~Transition()
{
}

Transition::Transition(char c, Etat* In, Etat* Out)
{
	etiquette_ = c;
	etatEntrant_ = In;
	etatSortant_ = Out;
}

char Transition::getEtiquette() const
{
	return etiquette_;
}

Etat* Transition::getEtatEntrant() const
{
	return etatEntrant_;
}

Etat* Transition::getEtatSortant() const
{
	return etatSortant_;
}

bool Transition::operator<(const Transition & transition) const
{
	return etiquette_ < transition.getEtiquette();
}
