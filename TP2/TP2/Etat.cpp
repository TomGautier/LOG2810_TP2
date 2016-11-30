#include "Transition.h"
#include "Etat.h"

using namespace std;

Etat::Etat()
	: final_(false)
{
}

Etat::~Etat()
{
	for (Transition* t : transitions_)
		delete t;
}

Etat::Etat(string& code)
	: code_(code), final_(false)
{
}

Etat::Etat(const string& code, set<Transition*> transitions) {
	code_ = code;
	transitions_ = transitions;
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

void Etat::setTransitions(set<Transition*>& transitions)
{
	transitions_ = transitions;
}

string Etat::getCode() const
{
	return code_;
}

bool Etat::getFinal() const
{
	return final_;
}

set<Transition*> Etat::getTransitions() const
{
	return transitions_;
}

void Etat::addTransition(char etiquette, Etat e)
{
	transitions_.insert(new Transition(etiquette, *this, e));
}

// Necessaire pour les set
bool Etat::operator<(const Etat & etat) const
{
	return code_ < etat.code_;
}
