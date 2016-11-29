#include "Etat.h"

using namespace std;

Etat::Etat()
	: final_(false)
{
}

Etat::~Etat()
{
}

Etat::Etat(string& code)
	: code_(code), final_(false)
{
}

Etat::Etat(const Etat& etat)
{
	code_ = etat.code_;
	final_ = etat.final_;
}

void Etat::setFinal(bool final)
{
	final_ = final;
}

void Etat::setCode(const string & code)
{
	code_ = code;
}

string Etat::getCode() const
{
	return code_;
}

bool Etat::getFinal() const
{
	return final_;
}

void Etat::addTransition(Transition & transition)
{
	transitions_.insert(transition);
}

// Necessaire pour les set
bool Etat::operator<(const Etat & etat) const
{
	return code_ < etat.code_;
}
