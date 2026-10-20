#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct jatekos
{
	string nev;
	int jido;
	int pont;
};

int main()
{
	setlocale(LC_ALL, "hu_HU.UTF-8");

	srand((unsigned int)time(NULL));

	jatekos meccs[15];

	int lsz;

	do
	{
		cout << "Kerem a jatekosok szamat[6;15]: ";
		cin >> lsz;

		if (lsz < 6 || lsz > 15)
		{
			cout << "hiba ! a jatekosok szama: [6;15]!" << endl;
		}

	} while (lsz < 6 || lsz > 15);

	cin.ignore();

	for (int i = 0; i < lsz; i++)
	{
		cout << "Kerem a(z) " << i + 1 << ". jatekos nevet: ";
		getline(cin, meccs[i].nev);

		meccs[i].jido = rand() % 91;
		meccs[i].pont = rand() % 25;
	}

	system("cls");

	cout.setf(ios::left);

	cout << "\t\tA merkozes adatai\n\n";

	for (int i = 0; i < lsz; i++)
	{
		cout << "\t" << setw(20) << meccs[i].nev
			<< setw(3) << meccs[i].jido << "perc  "
			<< setw(3) << meccs[i].pont << "pont" << endl;
	}

	int psum = 0;

	for (int i = 0; i < lsz; i++)
	{
		psum += meccs[i].pont;
	}

	cout << "\n A csapat osszesen " << psum << " pontot szerzett" << endl;

	int minpi = 0;

	for (int i = 1; i < lsz; i++)
	{
		if (meccs[i].pont < meccs[minpi].pont)
		{
			minpi = i;
		}
	}

	cout << " a legkevesebb, " << meccs[minpi].pont << " pontot " << meccs[minpi].nev << " szerezte" << endl;

	int lg7 = 0;

	for (int i = 0; i < lsz; i++)
	{
		if (meccs[i].pont >= 7)
		{
			lg7++;
		}
	}

	cout << " A merkozesen " << lg7 << " jatekos szerzett legalabb 7 pontot" << endl;

	cout << "\n 15 percnel kevesebbet, de jatszottak: " << endl;

	for (int i = 0; i < lsz; i++)
	{
		if (meccs[i].jido <= 15 && meccs[i].jido > 0)
		{
			cout << "\t" << meccs[i].nev << " -> " << meccs[i].jido << " perc" << endl;
		}
	}

	int ltji = 0, ltpi = 0;

	for (int i = 0; i < lsz; i++)
	{
		if (meccs[i].jido > meccs[ltji].jido)
		{
			ltji = i;
		}

		if (meccs[i].pont > meccs[ltpi].pont)
		{
			ltpi = i;
		}
	}

	cout << "\n legtobbet jatszott: " << meccs[ltji].nev << "\tlegtobb pontot szerezte: "
		<< meccs[ltpi].nev << " vagyis:" << endl;

	if (ltji == ltpi)
	{
		cout << " igaz";
	}
	else
	{
		cout << " nem igaz";
	}

	cout << ", hogy a legtobbet jatszo jatekos szerezte a legtobb pontot" << endl;

	return 0;
}