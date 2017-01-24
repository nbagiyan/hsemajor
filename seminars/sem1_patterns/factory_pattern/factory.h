using namespace std;

//enum Unit_ID{ Soldier_ID = 0, Artillery_ID = 0, Tank_ID = 0 };

class Unit
{
public:
  virtual void info() = 0;
  virtual ~Unit() {};

  // static Unit* createUnit(Unit_ID id); 
};

class Soldier :public Unit
{
public:
  void info()
  {
    std::cout << "Soldier" << std::endl;
  }
};

class Artillery : public Unit
{
public:
  void info()
  {
    std::cout << "Artillery" << std::endl;
  }
};

class Tank : public Unit
{
public:
  void info()
  {
    std::cout << "Tank" << std::endl;
  }
};


class Factory
{
public:
  virtual Unit* createUnit() = 0;
  virtual ~Factory() { }
};

class SoldierFactory : public Factory
{
public:
  Unit* createUnit(){
    return new Soldier;
  }
};


class TankFactory : public Factory
{
public:
  Unit* createUnit(){
    return new Tank;
  }
};

