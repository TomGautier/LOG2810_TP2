#pragma once

#ifndef ETAT_H
#define ETAT_H

using namespace std;

#include <string>
#include <set>


class Transition;

class Etat
{
public: 
	Etat();
	~Etat();
	Etat(string& code);
	Etat(string& code, set<Transition*> transitions);

	Etat(const Etat&);

	void setFinal(bool final);
	void setCode(const string& code);

	string getCode() const;
	bool getFinal()const;
	set<Transition*> getTransitions() const;

	void addTransition(Transition*);

	bool operator<(const Etat& etat) const;
private:
	string code_;
	bool final_;
	set<Transition*> transitions_;
};

#endif // !ETAT_H