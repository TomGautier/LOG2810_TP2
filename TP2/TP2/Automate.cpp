#include "Automate.h"


Automate::Automate()
{
}

Automate::~Automate()
{
}

void Automate::creerAutomate(const string& nomFichier)
{
	ifstream zone;
	zone.open(nomFichier);

	if (zone.fail())
		cout << "Erreur d ouverture\n";
	else
	{
		while (zone.peek() != EOF) // tant que fichier pas termine
		{
			string line;
			getline(zone, line, '\n');

			for (unsigned int i = 1; i <= line.size(); i++)
			{
				if (line[i] != ' ')
				{
					string subLine = line.substr(0, i);
					Etat etat = Etat(subLine);
					
					// Si on a les 6 caracteres du code, l'etat est final
					if (i == line.size())
					{
						etat.setFinal(true);
					}
					else // palier au probleme d'ajout d'une transition vide pour les etats finaux
					{
						transitions.insert(line[i]);
					}
		
					etats.insert(etat);
				}
			}

		}
	}
}

