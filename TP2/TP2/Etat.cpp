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

Etat::Etat(const string& code)
	: code_(code), final_(false)
{
}

Etat::Etat(const string& code, vector<Transition*> transitions) {
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

void Etat::setTransitions(vector<Transition*>& transitions)
{
	transitions_ = transitions;
}

string Etat::getCode() const
{
	return code_;
}

bool Etat::isFinal() const
{
	return final_;
}

vector<Transition*> Etat::getTransitions() const
{
	return transitions_;
}

void Etat::addTransition(char etiquette, Etat* e)
{
	// On vérifie d'abord si la transition existe déjà
	auto fin = transitions_.end();
	for (auto it = transitions_.begin(); it != fin; it++)
	{
		if ((*it)->getEtiquette() == etiquette)
		{
			return;
		}
	}

	transitions_.push_back(new Transition(etiquette, this, e));
}

// Necessaire pour les set
bool Etat::operator<(const Etat & etat) const
{
	return code_ < etat.code_;
}
