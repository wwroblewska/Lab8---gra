#include <iostream>
#include <string>
using namespace std;

struct Position {
	int x, y;
};
//interfejsy:
class Objects {
private:
	Position p;
public:
	virtual int getPosition();
};
class Interactive {
public:
	virtual void interact(Player player);
};

//klasy sk³adowe:
class Player:public Object  {
private:
	string PlayerName;
	int HP;
	int CollectedItem;

};
class Item:public Object, public Interactive {
private:
	int item;
	double strength;
};
class Enemy:public Object, public Interactive {
private:
	string EnemyName;
	int EnemyStrength;

};
class Potion: public Object, public Interactive {
private:
	int HealthItem;
};
