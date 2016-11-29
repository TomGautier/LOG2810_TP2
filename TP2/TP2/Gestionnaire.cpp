#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
}

Automate Gestionnaire::creerLexiques(string nomFichier)
{
	return Automate();
}

void Gestionnaire::equilibrerFlotte()
{
}

void Gestionnaire::lancerSimulation()
{
}

std::vector<Automate> Gestionnaire::getAutomates() const
{
	return std::vector<Automate>();
}

void Gestionnaire::addAutomate(const Automate & automate)
{
	automates_.push_back(automate);
}
