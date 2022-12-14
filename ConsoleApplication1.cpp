#include <iostream>
#include <ctime>
using namespace std;

const int lignes = 10; 
const int elements = 10; //element se sont les représentation des colonnes 

int NavMax = 5; //c'est le nombre de bateau maximums de 5 navire

int BatNav[lignes][elements]; // entier creation tableau 

void Clear() // type vide  
{
	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			BatNav[i][j] = 0;
		}
	}
}

void Show() // type vide  
{
	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			cout << BatNav[i][j] << " ";
		}
		cout << endl;
	}
}

int NombreDeNavires() //nombre entier de navire 
{
	int c = 0;

	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (BatNav[i][j] == 1)
				c++;
		}
	}

	return c;
}

void Navires() //type vide 
{
	int s = 0;
	while (s < NavMax)//on boucle sur Nav max sachant que l'on a initialiser NavMax
	{
		int x = rand() % lignes; //flag lignes
		int y = rand() % elements; //flag elements de l'anglais drapeau pour afficher les variables 
		if (BatNav[x][y] != 1) 
		{
			s++;
			BatNav[x][y] = 1;
		} // on incrémente
	}
}

bool Attack(int x, int y) //type bool de la fonction 'attack'
{
	if (BatNav[x][y] == 1)
	{
		BatNav[x][y] = 2;
		return true;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	Clear();
	Navires();
	int pos1, pos2;
	char prompt;
	while (1)
	{
		cout << "Veuillez entrer l'emplacement: "; cin >> pos1 >> pos2;
		if (Attack(pos1, pos2))
			cout << "Bien jouer ! tu as trouv� un navire !" << endl;
		else
			cout << "Il n'y a pas de bateau ici ! " << endl;
		cout << "Le nombre de bateau restant est: " << NombreDeNavires() << endl;
		cout << "Veux tu abandonner ? (o/n)? "; cin >> prompt;
		if (prompt == 'o')
			break;
	}
	cout << "Perdu !" << endl;
	Show();
	system("pause");
	return 0;
}