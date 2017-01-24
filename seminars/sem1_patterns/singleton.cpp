#include <iostream>
#include <vector>

class Unit
{
public:
	virtual void info() = 0;
	virtual ~Unit() {};
};



class Soldier : public Unit
{
public:
	void info()
	{
		std::cout << "Soldier" << std::endl;
	}
};

class MySingleton
{
public:
	static MySingleton* iInstance;
	static MySingleton* GetInstance();
	void assign();
	void dismiss();
private:
	MySingleton();
	std::vector<Soldier*> obj;

};

MySingleton* MySingleton::iInstance = NULL;

MySingleton::MySingleton()
{
	std::cout << "In construction" << std::endl;
}
MySingleton* MySingleton::GetInstance()
{
	if (iInstance == NULL)
		iInstance = new MySingleton();
	return iInstance;
}

void MySingleton::assign(){
	if (obj.size() < 10)
		obj.push_back(new Soldier);
	else
		std::cout << "No place left";
}

void MySingleton::dismiss(){
	if (obj.size() > 0)
		obj.pop_back();
	else
		std::cout << "No soldier to fire";
}

