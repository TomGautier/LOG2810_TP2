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

	Automate* getZone() const;
	string getCode() const;
	bool getOccupation() const;

	void setZone(Automate*);
	void setCode(const string&);
	void setOccupation(bool);

private:
	Automate* automate_;
	string code_;
	bool occupation_;
};

#endif // !VEHICULE_H