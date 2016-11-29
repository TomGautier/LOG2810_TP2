#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
}

void Gestionnaire::creerLexiques(const string& nomFichier)
{
	Automate automate = Automate();
	automate.creerAutomate(nomFichier);
	addAutomate(automate);
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
