#pragma once
#include<iostream>
#include <string>

class Unit {
public:
	double damage;
	double hp;
	double getHP() {
		return (this->hp);
	}
	void hit(Unit& enemy) {
		enemy.hp = enemy.hp - this->damage;
	
	}
	Unit() {
		hp = 100;
		damage = 10;
	}
	Unit(double HP, double dmg) : hp(HP), damage(dmg) {}

};

class Soldier : public Unit {
public:
	Soldier(double HP, double dmg) {
		hp = HP;
		damage = dmg;
	}
	void getinfo() {
		std::cout << "Soldier's HP: " << this->hp << ", Soldier's Damage: " << this->damage << std::endl;
	}
	void showHP() {
		std::cout << "Soldier's HP: " << this->hp<<std::endl;
	}
};

class Orc : public Unit {
public:
	Orc(double HP, double dmg) {
		hp = HP;
		damage = dmg;
	}
	void getinfo() {
		std::cout << "Orc's HP: " << this->hp << ", Orc's Damage: " << this->damage << std::endl;
	}
	void showHP() {
		std::cout << "Orc's HP: " << this->hp<<std::endl;
	}
