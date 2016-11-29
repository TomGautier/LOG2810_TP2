#pragma once

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>

class Utilisateur
{
public :
	Utilisateur();
	~Utilisateur();

	Utilisateur(const std::string& origine, const std::string& destination);

	std::string getOrigine() const;
	std::string getDestination() const;
private:
	std::string origine_;
	std::string destination_;
};

#endif // !UTILISATEUR_H