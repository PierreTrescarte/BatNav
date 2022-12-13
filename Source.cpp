#include <iostream>
#include <ctime>
using namespace std;

const int lignes = 10;
const int elements = 10;

int NavMax = 5;

int BatNav[lignes][elements];

void Clear()
{
	for (int i = 0; i < lignes; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			BatNav[i][j] = 0;
		}
	}
}

void Show()
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

int NombreDeNavires()
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

void Navires()
{
	int s = 0;
	while (s < NavMax)
	{
		int x = rand() % lignes;
		int y = rand() % elements;
		if (BatNav[x][y] != 1)
		{
			s++;
			BatNav[x][y] = 1;
		}
	}
}

bool Attack(int x, int y)
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
			cout << "Bien jouer ! tu as trouvé un navire !" << endl;
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