#include "Vehicule.h"

Vehicule::Vehicule()
{
	zone_ = nullptr;
}

Vehicule::~Vehicule()
{
	zone_->decrementerNbVehicules();
	zone_ = nullptr;
}

Vehicule::Vehicule(Automate* automate,const string & code, bool occupation)
	: code_(code), occupation_(occupation), nTrajetsOccupes_(0), nTrajetsVides_(0)
{
	zone_ = automate;
	automate->incrementerNbVehicules();
}

Automate * Vehicule::getZone() const
{
	return zone_;
}

string Vehicule::getCode() const
{
	return code_;
}

bool Vehicule::isOccupied() const
{
	return occupation_;
}

int Vehicule::getNtrajetsOccupes() const{
	return nTrajetsOccupes_;
}

int Vehicule::getNtrajetsVides() const{
	return nTrajetsVides_;
}


void Vehicule::setZone(Automate* automate)
{
	zone_ = automate;
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
