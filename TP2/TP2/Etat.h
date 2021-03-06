#pragma once

#ifndef ETAT_H
#define ETAT_H

using namespace std;

#include <string>
#include <vector>


class Transition;

class Etat
{
public: 
	Etat();
	~Etat();
	Etat(const string& code);
	Etat(const std::string& code, std::vector<Transition*> transitions);

	Etat(const Etat&);

	// Modificateurs
	void setFinal(bool final);
	void setCode(const std::string&);
	void setTransitions(std::vector<Transition*>&);

	// Accesseurs
	string getCode() const;
	bool isFinal()const;
	std::vector<Transition*> getTransitions() const;

	// Encapsulation de l'attribut transitions_;
	void addTransition(char etiquette, Etat* e);

	// Surchage de l'operator < pour l'utilisation de Set d'Etats
	bool operator<(const Etat&) const;
private:
	std::string code_;
	bool final_;
	std::vector<Transition*> transitions_;
};

#endif // !ETAT_H