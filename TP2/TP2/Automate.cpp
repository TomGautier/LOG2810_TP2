#include <algorithm>
#include "Automate.h"

Automate::Automate(const string& nomFichier)
	: nVehicules_(0), etatInitial_(nullptr)
{
	ifstream zone;
	string line;
	zone.open(nomFichier);

	if (zone.fail())
		cout << "Erreur d'ouverture du fichier.\n";
	else
	{
		while (getline(zone, line)) // tant que fichier pas termine
		{
			for (unsigned int i = 1; i <= line.size(); i++)
			{
				string subLine = line.substr(0, i);
				Etat* etat = createOrRetrieveEtat(subLine);

				// On assume que l'etat initial est toujours le même 
				// (c'est à dire que la première lettre des zipcodes est toujours la même pour toutes les zones)
				if (subLine.size() == 1)
					etatInitial_ = etat;

				if (i == line.size())
					etat->setFinal(true);
				else // palie au probleme d'ajout d'une transition vide pour les etats finaux
				{
					Etat* etatSortant = createOrRetrieveEtat(line.substr(0, i + 1));
					etats_.insert(etatSortant);

					etat->addTransition(line[i], etatSortant);
				}

				etats_.insert(etat);
			}

		}
	}

	zone.close();
}

Automate::~Automate()
{
	etatInitial_ = nullptr;
	for (Etat* e : etats_)
		delete e;
}

set<Etat*> Automate::getEtats() const
{
	return etats_;
}

int Automate::getNvehicules() const{
	return nVehicules_;
}


void Automate::decrementerNbVehicules()
{
	nVehicules_--;
}

void Automate::incrementerNbVehicules()
{
	nVehicules_++;
}

Automate* Automate::parcoursAutomate(const string& mot)
{
	// etat auquel on est rendu
	Etat* etatCourant = etatInitial_;
	string line;

	bool transTrouve = false;

	int i = 1;
	// Si l'etat est final, on a trouvé le zip-code dans l'automate !
	while (!etatCourant->isFinal())
	{
		line = mot.substr(0, i + 1);
		vector<Transition*> trans = etatCourant->getTransitions();

		for (unsigned int j = 0; j < trans.size() && !transTrouve; j++)
		{
			// Si le code de l'etat sortant est le code que l'on cherche
			if (trans[j]->getEtatSortant()->getCode() == line)
			{
				// cet etat devient l'etat courant
				etatCourant = trans[j]->getEtatSortant();
				transTrouve = true;
			}
		}
		// Si on a pas trouvé la transition correspondante, le zip-code ne fait donc pas partie de l'automate
		if (transTrouve == false)
			return nullptr;

		transTrouve = false;
		i++;
	}

	return this;
}

Etat* Automate::createOrRetrieveEtat(const string & mot)
{
	auto fin = etats_.end();
	for (auto it = etats_.begin(); it != fin; it++)
	{
		if ((*it)->getCode() == mot)
		{
			// Retourne l'Etat s'il existe deja
			return (*it);
		}
	}

	// En cree un nouveau sinon
	return new Etat(mot);
}