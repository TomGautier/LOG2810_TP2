#pragma once

#ifndef TD2_H
#define TD2_H

#include "Gestionnaire.h"

using namespace std;

class TD2
{
public:
	TD2();
	~TD2();

	void menu1();
	void menu2();
	void menu3();

private:
	void menuZones();
	void menuVehiculesEtClients();

	Gestionnaire gestionnaire_;
	char option_;
	bool continueProgram_;

};

#endif // !TD2_H