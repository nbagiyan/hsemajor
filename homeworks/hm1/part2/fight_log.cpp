#include <iostream> 
#include "units.h" 

int fight(Soldier&, Orc&);

int main() {
	Soldier sold(200.0, 20.0 * (rand() % 4));
	Orc orc(300.0, 10 * (rand() % 5));
	sold.getinfo();
	orc.getinfo();
	fight(sold, orc);
	return 0;
}

int fight(Soldier& sold, Orc& orc) {
	if (orc.getHP() == 0) {
		std::cout << "Soldier win!";
		return 0;
	}
	if (sold.getHP() == 0) {
		std::cout << "Orc win!";
		return 0;
	}
	orc.hit(sold);
	sold.showHP();
	sold.hit(orc);
	orc.showHP();
	fight(sold, orc);
}
