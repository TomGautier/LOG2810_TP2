#pragma once

#ifndef ETAT_H
#define ETAT_H

using namespace std;

class Etat
{
public: 
	Etat(); // initialiser final a false
	~Etat();
	Etat(string& code);

	void setFinal(bool final);
private:
	string code;
	bool final;
};

#endif // !ETAT_H