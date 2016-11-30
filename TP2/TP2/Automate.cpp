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
				if (line[i] != ' ')
				{
					string subLine = line.substr(0, i);
					Etat* etat = nullptr;

					auto fin = etats_.end();
					for (auto it = etats_.begin(); it != fin; it++)
					{
						if ((*it)->getCode() == subLine)
						{
							etat = (*it);
							break;
						}
					}

					if (etat == nullptr)
						etat = new Etat(subLine);

					if (subLine.size() == 1)
						etatInitial_ = etat;

					if (i == line.size())
						etat->setFinal(true);
					else // palier au probleme d'ajout d'une transition vide pour les etats finaux
					{
						Etat etatSortant = Etat(line.substr(0, i + 1));

						etat->addTransition(line[i], etatSortant);
						etiquettes_.insert(line[i]);
					}

					etats_.insert(etat);
				}
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

set<char> Automate::getEtiquettes() const
{
	return etiquettes_;
}

Etat* Automate::parcoursAutomate(const string& mot)
{
	Etat* etatRetour = nullptr;
	Etat* etatCourant = etatInitial_;
	string line;

	int i = 0;
	while (!etatCourant->isFinal())
	{
		line = mot.substr(0, i + 1);
		vector<Transition*> trans = etatCourant->getTransitions();

		for (unsigned int i = 0; i < trans.size(); i++)
		{
			if (trans[i]->getEtatSortant().getCode() == line)
			{
				etatCourant = &(trans[i]->getEtatSortant());
			}
		}

	}

	return etatRetour;
}

