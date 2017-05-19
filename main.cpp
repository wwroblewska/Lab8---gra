#include "stdafx.h"
#include "klasy.h"
#include "funkcje.h"
#include <iomanip>
#include <conio.h>

using namespace std;

int main(int argc, char *argv[]){
	Board map;
	Player player;
	char key;
	
		createMap(&map, &player);//tu tworzymy i umieszczamy wszystkie rzeczy na mapie
		
		
			cout << setw(40) << "Witaj w grze";
			cout << setw(40) << endl << "Wykonanie: Weronika Wroblewska" << endl;
			cout <<">>>>  Kliknij dowolny przycisc aby rozpoczac przygode!<<<<";
			_getch();
		do{
			system("CLS"); // 
			showMap(map);
			showStats(player);// pokazuje lvl, hp, siłe
			key = _getch(); 
			player.calculate();
			keyEvent(key, &player, &map); // wszystkie zdarzenia
			if (player.currentHp == 0){
				key = 'z';
				system("CLS");
				cout << "GAME OVER";
			}
		} while (key != 'z');  // zamykanie gry
	cout << endl << endl << endl;
	system("PAUSE");
	return 0;
}
