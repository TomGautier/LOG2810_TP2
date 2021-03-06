#pragma once

#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include "Automate.h"

class Vehicule
{
public:
	Vehicule();
	~Vehicule();
	Vehicule(Automate*, const string&, bool);

	// Accesseurs
	Automate* getZone() const;
	string getCode() const;
	bool isOccupied() const;
	int getNtrajetsOccupes() const;
	int getNtrajetsVides() const;

	// Modificateurs
	void setZone(Automate*);
	void setCode(const string&);
	void setOccupation(bool);

	void incrementerCompteurTrajetsOccupes();
	void incrementerCompteurTrajetsVides();

private:
	Automate* zone_;
	string code_;
	bool occupation_;

	int nTrajetsOccupes_;
	int nTrajetsVides_;
};

#endif // !VEHICULE_H