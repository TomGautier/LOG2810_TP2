#include "Vehicule.h"

Vehicule::Vehicule()
{
	automate_ = nullptr;
}

Vehicule::~Vehicule()
{
	delete automate_;
}

Vehicule::Vehicule(Automate* automate,const string & code, bool occupation)
	: code_(code), occupation_(occupation), nTrajetsOccupes_(0), nTrajetsVides_(0)
{
	automate_ = automate;
}

Automate * Vehicule::getZone() const
{
	return automate_;
}

string Vehicule::getCode() const
{
	return code_;
}

bool Vehicule::isOccupied() const
{
	return occupation_;
}

void Vehicule::setZone(Automate* automate)
{
	automate_ = automate;
}

void Vehicule::setCode(const string & code)
{
	code_ = code;
}

void Vehicule::setOccupation(bool occupation)
{
	occupation_ = occupation;
}

void Vehicule::incrementerCompteurTrajetsOccupes()
{
	nTrajetsOccupes_++;
}

void Vehicule::incrementerCompteurTrajetsVides()
{
	nTrajetsVides_++;
}
