#pragma once

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "Automate.h"
#include "Vehicule.h"
#include "Utilisateur.h"
#include <vector>

using namespace std;

class Gestionnaire
{
public:
	Gestionnaire();
	~Gestionnaire();
	
	// Methodes de creation des attributs avec verification des parametres (utilisées par la classe TD2)
	void creerLexiques(const string&); // Méthode C1
	void creerVehicule(const string&);
	void creerUtilisateur(const string& , const string&);

	// Méthodes C2 et C3
	void equilibrerFlotte();
	void lancerSimulation();
	
	// Accesseurs
	std::vector<Automate*> getAutomates() const;
	std::vector<Utilisateur*> getUtilisateurs() const;
	std::vector<Vehicule*> getVehicules() const;

	// Encapsulation de l'utilisation de l'attribut Automate
	void addAutomate(Automate*);
private:
	// Méthodes utilitaires
	Automate* trouverAutomate(const string& code) const;
	Automate* trouverMax(); // trouve la zone qui a le plus de vehicule
	Vehicule* trouverVehiculeDisponible(Utilisateur* user); // trouve un vehicule disponible dans la zone de l'utilisateur
	void SwapVehicule(Automate*, Automate*); // change un vehicule de zone
	void miseAJourInformations(Vehicule* vehicule, Utilisateur* user); // met a jour les infos d'un vehicule et d'un utilisateur apres un deplacement
	
	// Attributs
	std::vector<Automate*> automates_;
	std::vector<Vehicule*> vehicules_;
	std::vector<Utilisateur*> utilisateurs_;
};

#endif // !GESTIONNAIRE_H
