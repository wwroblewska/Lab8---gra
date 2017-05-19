#include "stdafx.h"
#include "klasy.h"




Player::Player()
{
	for (int i = 0; i < 30; i++){
		items[i].strength = 0;
		items[i].id = 0;
	}
	lvl = 1;
	currentHp = maxHp= 300;
	tempStr = str = 5;
	cordX = 25;
	cordY = 12;
}

Player::~Player()
{
}

Item::Item(){
}

Item::~Item(){

}

Enemy::Enemy(int id){
	hp = 300 + id * 20;
	str = id * 5;
}

Enemy::~Enemy(){

}

Potion::Potion(){
}

Potion::~Potion(){

}



Board::Board(){

}

Board::~Board(){

}