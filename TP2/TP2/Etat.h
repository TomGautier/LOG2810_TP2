#pragma once

#ifndef ETAT_H
#define ETAT_H

using namespace std;

#include <string>

class Etat
{
public: 
	Etat();
	~Etat();
	Etat(string& code);
	Etat(const Etat&);

	void setFinal(bool final);
	void setCode(const string& code);

	string getCode();
	bool getFinal();

	bool operator<(const Etat& etat) const;
private:
	string code_;
	bool final_;
};

#endif // !ETAT_H