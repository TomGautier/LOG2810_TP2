#include "Automate.h"

Automate::Automate()
{
}

Automate::~Automate()
{
}

void Automate::creerAutomate(string nomFichier)
{
	if (false)
	{
		//verif ouverture fichier
	}
	while (!fichier.empty()) // tant que fichier pas termine
	{
		string line = fichier.getline();
		for (unsigned int i = 0; i < line.size(); i++)
		{
			if (line[i] != ' ')
			{
				Etat etat = Etat(line.substr(0, line[i]));
				if (i = line.size() - 1)
				{
					etat.setFinal(true);
				}

				etats.insert(etat);
				transitions.insert(line[i]);
			}
		}
	
	}

}

