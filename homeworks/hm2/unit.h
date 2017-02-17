#pragma ones
#include <iostream>
using namespace std;

class Fighter
{
protected:
	int HP;
	int min_DMG;
	int max_DMG;

public:

	Fighter(int _HP, int _min_DMG, int _max_DMG) :HP(_HP), min_DMG(_min_DMG), max_DMG(_max_DMG)
	{

	}

	virtual ~Fighter() {}

	virtual int make_damage()
	{
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		cout << "Fighter makes damage: " << DMG;
		return DMG;
	}


	virtual void get_damage(int DMG)
	{
		HP -= DMG;
		cout << "Figther gets damage: " << DMG << " (HP: " << HP << ")";
	}


	bool Alive() const
	{
		return (HP > 0);
	}

	int get_HP() const
	{
		return HP;
	}
};

class Elf :public Fighter
{
	int Defl;
public:
	Elf(int _HP, int _min_DMG, int _max_DMG, int _Defl) :Fighter(_HP, _min_DMG, _max_DMG), Defl(_Defl) {}
	~Elf() {}
	virtual int make_damage()
	{
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		cout << "Elf makes damage: " << DMG;
		return DMG;
	}

	virtual void get_damage(int DMG)
	{
		int p = rand() % 100;
		if (p <= Defl)
			cout << "Elf avoid any damage (HP: " << HP << ")";
		else
		{
			HP -= DMG;
			cout << "Elf gets damage: " << DMG << " (HP: " << HP << ")";
		}
	}

};

class Dwarf :public Fighter
{
	int avd;
public:
	Dwarf(int _HP, int _min_DMG, int _max_DMG, int _avd) :Fighter(_HP, _min_DMG, _max_DMG), avd(_avd) {}
	~Dwarf() {}
	virtual int make_damage()
	{
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		cout << "Dwarf makes damage: " << DMG;
		return DMG;
	}
	virtual void get_damage(int DMG)
	{
		int p = rand() % 100;
		if (p <= avd) {
			cout << "Dwarf avoids half of damage (HP: " << HP << ")";
			HP -= DMG / 2;
		}
		else
		{
			HP -= DMG;
			cout << "Dwarf gets damage: " << DMG << " (HP: " << HP << ")";
		}
	}
};

class Wizard :public Fighter
{
	int heal;
	int HP_max;
public:
	Wizard(int _HP, int _min_DMG, int _max_DMG, int _heal, int _HP_max) :Fighter(_HP, _min_DMG, _max_DMG), heal(_heal), HP_max(_HP_max) {}
	~Wizard() {}
	virtual void get_damage(int DMG)
	{
		HP -= DMG;
		cout << "Wizard gets damage: " << DMG << " (HP: " << HP << ")";
	}
	virtual int make_damage() {
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		cout << "Wizard makes damage: " << DMG << endl;;
		int p = rand() % 100;
		if (p <= heal) {

			if ((HP + 0.6*DMG) >= HP_max) {
				HP = HP_max;
				cout << "Wizard heals 60% of damage (HP: " << HP << ")";
			}
			else {
				HP += 0.6*DMG;
				cout << "Wizard heals 60% of damage (HP: " << HP << ")";
			}
		}
		else {
			return DMG;
		}
	}
};

class Orc : public Fighter
{
	int dbl_dmg;
public:
	Orc(int _HP, int _min_DMG, int _max_DMG, int _dbl_dmg) : Fighter(_HP, _min_DMG, _max_DMG), dbl_dmg(_dbl_dmg) {}
	~Orc() {}
	virtual void get_damage(int DMG)
	{
		HP -= DMG;
		cout << "Orc gets damage: " << DMG << " (HP: " << HP << ")";
	}
	virtual int make_damage() {
		int p = rand() % 100;
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		if (p <= dbl_dmg) {
			cout << "Orc makes double damage: " << DMG ;
		}
		else {
			cout << "Orc makes damage: " << DMG;
			return DMG;
		}
	}
};
