#pragma once

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "Automate.h"
#include <vector>

using namespace std;

class Gestionnaire
{
public:
	Gestionnaire();
	~Gestionnaire();
	
	Automate creerLexiques(string nomFichier);
	void equilibrerFlotte();
	void lancerSimulation();
	
	std::vector<Automate> getAutomates() const;
	void addAutomate(const Automate&);
private:
	std::vector<Automate> automates_;
};

#endif // !GESTIONNAIRE_H
