
#include "klasy.h"
#include "cstdlib"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


void position(Board map);//tu tylko wyswietlamy

void createMap(Board *map, Player *gracz);//tu ja edytujenmy na poczatku gry

void showMap(Board map);//tu tylko wyswietlamy po kazdym okrazeniu / ruchu

void showStats(Player gracz); // info pod mapa

void pick_up(char klawisz, Board *mapa, Player *gracz); // podnoszenie itemka

void fight(char klawisz, Board *mapa, Player *gracz);  // walka

void keyEvent(char klawisz, Player *gracz, Board *mapa); // obsluga zdarzen
