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
	Etat(const std::string& code, std::set<Transition*> transitions);

	Etat(const Etat&);

	void setFinal(bool final);
	void setCode(const std::string&);
	void setTransitions(std::set<Transition*>&);

	string getCode() const;
	bool getFinal()const;
	std::set<Transition*> getTransitions() const;

	void addTransition(char etiquette, Etat e);

	bool operator<(const Etat&) const;
private:
	std::string code_;
	bool final_;
	std::set<Transition*> transitions_;
};

#endif // !ETAT_H