#include "Utilisateur.h"

using namespace std;

Utilisateur::Utilisateur()
{
}

Utilisateur::~Utilisateur()
{
}

Utilisateur::Utilisateur(const string& origine, const std::string & destination)
	: origine_(origine), destination_(destination)
{
}

std::string Utilisateur::getOrigine() const
{
	return origine_;
}

std::string Utilisateur::getDestination() const
{
	return destination_;
}
