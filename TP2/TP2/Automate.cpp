#include "Automate.h"

Automate::Automate()
{
}

Automate::~Automate()
{
	for (Etat* e : etats_)
		delete e;
}


void Automate::creerAutomate(const string& nomFichier)
{
	ifstream zone;
	string line;
	zone.open(nomFichier);

	if (zone.fail())
		cout << "Erreur d ouverture\n";
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
						
					if (i == line.size())
						etat->setFinal(true);
					else // palier au probleme d'ajout d'une transition vide pour les etats finaux
					{
						Etat etatSortant = Etat(line.substr(0, i + 1));

						etat->addTransition(line[i], etatSortant);
						transitions_.insert(line[i]);
					}

					etats_.insert(etat);
				}
			}

		}
	}
	
	zone.close();
}


set<Etat*> Automate::getEtats()
{
	return etats_;
}

