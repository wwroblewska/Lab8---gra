#include "cstdlib"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Item
{
public:
	int strength;
	int id;
	Item();
	~Item();
};



class Player
{
public:
	int lvl;
	int maxHp;
	int currentHp;
	Item items[30];
	int str;
	int tempStr;
	int cordX;
	int cordY;
	
	
	void calculate(){   // mechanizm obliczania 
		str = lvl * 5;
		tempStr = str;
		for (int i = 0; i < 30; i++){
			tempStr += items[i].strength;
		}
		maxHp = 300+ lvl * 10 + 2*tempStr;
	}
	Player();
	~Player();
};


class Enemy
{
public:

	int str;
	int hp;
	

	Enemy(int id);
	~Enemy();
};


class Potion
{
public:
	int cordX;
	int cordY;
	

	Potion();
	~Potion();
};


class Board
{
public:
	int map[50][20];




	Board();
	~Board();
};
