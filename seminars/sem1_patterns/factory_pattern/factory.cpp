#include <factory.h>

int main()
{
  SoldierFactory* fact = new SoldierFactory;
  TankFactory* fact_tank = new TankFactory;

  //std::
  vector<Unit*> units;

  units.push_back(fact->createUnit());
  units.push_back(fact_tank->createUnit());

  // units.push_back(Unit::createUnit(Soldier_ID));
  // units.push_back(Unit::createUnit(Artillery_ID));
  // units.push_back(Unit::createUnit(Tank_ID));

  for (int i = 0; i < units.size(); i++)
    units[i]->info();
}
