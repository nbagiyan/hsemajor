#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>


using namespace std;

class Fighter {

public:
	int HP;
	int min_DMG;
	int max_DMG;
	string class_name;
	Fighter(int _HP, int _min_DMG, int _max_DMG) :HP(_HP), min_DMG(_min_DMG), max_DMG(_max_DMG), class_name("Fighter") {}
	virtual ~Fighter() {}
	virtual int make_damage()
	{
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		cout << class_name << " makes damage: " << DMG << endl;;
		return DMG;
	}
	virtual void get_damage(int DMG)
	{
		HP -= DMG;
		cout << class_name <<" gets damage: " << DMG << " (HP: " << HP << ")" << endl;
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

class Elf : public Fighter {
	int Defl;
	//string class_name;
public:
	Elf(int _HP, int _min_DMG, int _max_DMG) : Fighter(_HP, _min_DMG, _max_DMG), Defl(15){
		this->class_name = "Elf";
	}
	virtual ~Elf(){}
	virtual void get_damage(int DMG)
	{
		int p = rand() % 100;
		if (p <= Defl)
			cout << "Elf avoid any damage (HP: " << HP << ")" << endl;
		else
		{
			HP -= DMG;
			cout << "Elf gets damage: " << DMG << " (HP: " << HP << ")" << endl;
		}
	}

};

class Dwarf : public Fighter
{
	int avd;
public:
	Dwarf(int _HP, int _min_DMG, int _max_DMG) :Fighter(_HP, _min_DMG, _max_DMG), avd(50) {
		this->class_name = "Dwarf";
	}
	virtual ~Dwarf(){
	}
	virtual void get_damage(int DMG)
	{
		int p = rand() % 100;
		if (p <= avd) {
			cout << "Dwarf avoids half of damage (HP: " << HP << ")" <<endl;
			HP -= DMG / 2;
		}
		else
		{
			HP -= DMG;
			cout << "Dwarf gets damage: " << DMG << " (HP: " << HP << ")"<<endl;
		}
	}

};

class Wizard :public Fighter
{
	int heal;
	int HP_max;
public:
	Wizard(int _HP, int _min_DMG, int _max_DMG ) :Fighter(_HP, _min_DMG, _max_DMG), heal(40), HP_max(_HP) {
		this->class_name = "Wizard";
	}
	virtual ~Wizard() {}
	virtual int make_damage() {
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		cout << "Wizard makes damage: " << DMG << endl;;
		int p = rand() % 100;
		if (p <= heal) {
			if ((HP + 0.6*DMG) >= HP_max) {
				HP = HP_max;
				cout << "Wizard heals 60% of damage (HP: " << HP << ")"<<endl;
			}
			else {
				HP += 0.6*DMG;
				cout << "Wizard heals 60% of damage (HP: " << HP << ")"<<endl;
			}
			return DMG;
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
	Orc(int _HP, int _min_DMG, int _max_DMG) : Fighter(_HP, _min_DMG, _max_DMG), dbl_dmg(30) {
		this->class_name = "Orc";
	}
	~Orc() {}
	virtual int make_damage() {
		int p = rand() % 100;
		int DMG = rand() % (max_DMG - min_DMG) + min_DMG;
		if (p <= dbl_dmg) {
			cout << "Orc makes double damage: " << DMG <<endl;
		}
		else {
			cout << "Orc makes damage: " << DMG << endl;
			return DMG;
		}
	}

};


class Team {
	deque<Fighter*> team;
	string team_name;
public:
	~Team(){
		team.clear();
	}
	void add_member(Fighter& member){
		team.push_back(&member);
	}
	friend ostream & operator<<(ostream& out, Team& party){
		for (deque<Fighter*>::iterator it = party.team.begin(); it != party.team.end(); ++it){
			out << (*it)->class_name << " ";
		}
			return out;
	}
	void get_damage(int dmg) {
		deque<Fighter*>::iterator temp = team.begin();
		for (deque<Fighter*>::iterator it = team.begin() + 1; it != team.end(); ++it) {
			if ((*it)->get_HP() > (*temp)->get_HP()) {
				temp = it;
			}
		}
		(*temp)->get_damage(dmg);
	}
	void make_damage(Team* op_team) {
		Fighter* temp;
		temp = team.front();
		team.pop_front();
		team.push_back(temp);
		op_team->get_damage(temp->make_damage());
	}
	
	bool AnyAlive() {
		for (deque<Fighter*>::iterator it = team.begin(); it != team.end(); ++it)
			if ((*it)->Alive()) {
				return true;
			}
		return false;

	}
};

class BuilderForDirector {
public:
	virtual Elf* make_elf() = 0;
	virtual Dwarf* make_dwarf() = 0;
	virtual Wizard* make_wizard() = 0;
	virtual Orc* make_orc() = 0;
};

class Director {
	BuilderForDirector* builder;

public:
	void setBuilder(BuilderForDirector* newBuilder) {
		builder = newBuilder;
	}

	Team* make_team(const int nElfs, const int nOrcs, const int nDwarfs,const int nWizards) {
		Team* party = new Team();
		for (int i = 0; i < nElfs; i++) {
			party->add_member(*(builder->make_elf()));
		}
		for (int i = 0; i < nOrcs; i++) {
			party->add_member(*(builder->make_dwarf()));
		}
		for (int i = 0; i < nDwarfs; i++) {
			party->add_member(*(builder->make_orc()));
		}
		for (int i = 0; i < nWizards; i++) {
			party->add_member(*(builder->make_wizard()));
		}

		return party;
			
	}
};

class BuilderforNormalTeam : public BuilderForDirector{
	virtual Elf* make_elf(){
		return new Elf(100, 10, 20);
	}
	virtual Dwarf* make_dwarf(){
		return new Dwarf(100, 10, 20);
	}
	virtual Wizard* make_wizard() {
		return new Wizard(100, 10, 20);
	}
	virtual Orc* make_orc() {
		return new Orc(100, 10, 20);
	}
};
