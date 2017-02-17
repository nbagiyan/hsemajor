#include <iostream>
#include <windows.h>
#include <cmath>
#include "unit.h"
#include <vector>
#include <ctime>

using namespace std;


typedef vector<Fighter*> FArr;

bool AnyAlive(const FArr& farr)
{
	for (int i = 0; i < farr.size(); i++)
		if (!farr[i]->Alive())
			return false;
	return true;

}



int main()
{
	int a;
	srand(time(NULL));
	Fighter
		*f1 = new Fighter(100,10,15),
		*elf = new Elf(100, 10, 20, 15),
		*dwarf = new Dwarf(100,10,20,50),
		*wizard = new Wizard(100,10,20,40,100),
		*orc = new Orc(100,10,20,30);
		
	FArr fs;
	cout << "Choose fighters:" << endl;
	cout << "1. Elf and Wizard" << endl;
	cout << "2. Dwarf and Orc" << endl;
	cout << "3. Wizard and Dwarf" << endl;
	cout << "4. Orc and Elf" << endl;
	cin >> a;
	switch (a) {
	case 1:
		fs.push_back(elf);
		fs.push_back(wizard);
		break;
	case 2:
		fs.push_back(dwarf);
		fs.push_back(orc);
		break;
	case 3:
		fs.push_back(wizard);
		fs.push_back(dwarf);
		break;
	case 4:
		fs.push_back(orc);
		fs.push_back(elf);
		break;
	default:
		fs.push_back(f1);
		fs.push_back(elf);
		break;
	}
	int i = 0;
	while (AnyAlive(fs))
	{
		cout << "round: " << i << "\n";
		int j = i % 2;
		int D = fs[j]->make_damage();
		cout << "\n";
		fs[(j + 1) % 2]->get_damage(D);
		cout << "\n";
		i++;

	}
	cin >> i;
	return 0;
}