#include "stdafx.h"
#include "funkcje.h"
#include "klasy.h"
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;


void position(Board map){
	int x, y;
	x = (rand() % 49) + 1;
	y = (rand() % 19) + 1;
}

//stowrzenie mapy
void createMap(Board *zmienna, Player *gracz){
	srand(time(NULL));
	int x, y;
	for (int j = 0; j < 20; j++){
		for (int i = 0; i < 50; i++){
			zmienna->map[i][j] = 0; // pusta mapa
		}
	}
	//gracz na mape
	zmienna->map[gracz->cordX][gracz->cordY] = 22;
	int ileItem = (rand() % 15) + 15;
	for (int i = 0; i <= ileItem; i++){
		x = (rand() % 49) + 1;
		y = (rand() % 19) + 1;
		if (zmienna->map[x][y] != 0){
			i--;
		}else{
			zmienna->map[x][y] = (rand() % 10) + 1;
		}
		
	}

	int ilePotw = (rand() % 15) + 15;
	for (int i = 0; i <= ilePotw; i++){
		x = (rand() % 49) + 1;
		y = (rand() % 19) + 1;
		if (zmienna->map[x][y] != 0){
			i--;
		}
		else{
			zmienna->map[x][y] = (rand() % 11) + 10;
		}

	}
	int ilePots = (rand() % 3) + 13;
	for (int i = 0; i <= ilePots; i++){
		x = (rand() % 49) + 1;
		y = (rand() % 19) + 1;
		if (zmienna->map[x][y] != 0){
			i--;
		}
		else{
			zmienna->map[x][y] = 21;
		}

	}
}
// wyśmietlenie mapy z zawartoscia
void showMap(Board zmienna){

	for (int j = 0; j < 20; j++){
		for (int i = 0; i < 50; i++){
			
			// 0 puste, 1-10 przedmioty, 11-20 potworki, 21 potion, 22 gracz
			switch (zmienna.map[i][j])
			{
			case 0:
				cout << " ";
				break;
			case 1:
				cout << (char)43;		
				break;
			case 2:
				cout << (char)43;
				break;
			case 3:
				cout << (char)43;
				break;
			case 4:
				cout << (char)43;
				break;
			case 5:
				cout << (char)43;
				break;
			case 6:
				cout << (char)43;
				break;
			case 7:
				cout << (char)43;
				break;
			case 8:
				cout << (char)43;
				break;
			case 9:
				cout << (char)43;
				break;
			case 10:
				cout << (char)43;
				break;
			case 11:
				cout << (char)69;
				break;
			case 12:
				cout << (char)69;
				break;
			case 13:
				cout << (char)69;
				break;
			case 14:
				cout << (char)69;
				break;
			case 15:
				cout << (char)69;
				break;
			case 16:
				cout << (char)69;
				break;
			case 17:
				cout << (char)69;
				break;
			case 18:
				cout << (char)69;
				break;
			case 19:
				cout << (char)69;
				break;
			case 20:
				cout << (char)69;
				break;
			case 21:
				cout << (char)38;
				break;
			case 22:
				cout << (char)35;
				break;
			default:
				cout << "cos nie zadzialalo";
				break;
			}
		}
		cout << "|" << endl;
	}
	cout << "--------------------------------------------------";
}

// wyświetlenie stats, plecaka, menu
void showStats(Player gracz){
	cout << endl << "Lvl postaci = " << gracz.lvl << "   HP: " << gracz.currentHp << "/" << gracz.maxHp << "   Sila: " << gracz.tempStr;
	cout << endl << "Przedmioty w plecaku: ";
	for (int i = 0; i <= 29; i++){
		switch (gracz.items[i].id)
		{
		case 1:
			cout << (char)43 << " ";
			break;
		case 2:
			cout << (char)43 << " ";
			break;
		case 3:
			cout << (char)43 << " ";
			break;
		case 4:
			cout << (char)43 << " ";
			break;
		case 5:
			cout << (char)43 << " ";
			break;
		case 6:
			cout << (char)43 << " ";
			break;
		case 7:
			cout << (char)43 << " ";
			break;
		case 8:
			cout << (char)43 << " ";
			break;
		case 9:
			cout << (char)43 << " ";
			break;
		case 10:
			cout << (char)43 << " ";
			break;
		}
	}
	cout << endl << endl<< "Menu: [k] -zapisz, [l] -wczytaj, [h] -help, [z] -zamknij, sterowanie: W,A,S,D";
}

void keyEvent(char klawisz, Player *gracz, Board *mapa){
	if (klawisz == 'z'){
	}
	if (klawisz == 'a'){
		if (mapa->map[gracz->cordX - 1][gracz->cordY] == 0) { //gdy powyzej nic nie ma
			mapa->map[gracz->cordX - 1][gracz->cordY] = 22;
			mapa->map[gracz->cordX][gracz->cordY] = 0;
			gracz->cordX--;
		}
		else{ 
			if (mapa->map[gracz->cordX - 1][gracz->cordY] <= 10){ //gdy tam jest przedmiot
				pick_up(klawisz,mapa, gracz);//funkcja podnosi przedmiot  !!!  bez przesuniecia
				mapa->map[gracz->cordX - 1][gracz->cordY] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordX--;
			}
			if (mapa->map[gracz->cordX - 1][gracz->cordY] <= 20 && mapa->map[gracz->cordX - 1][gracz->cordY] > 10){
				fight(klawisz, mapa, gracz);
				mapa->map[gracz->cordX - 1][gracz->cordY] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordX--;
			}
			if (mapa->map[gracz->cordX - 1][gracz->cordY] == 21){
				gracz->currentHp += 0.2*gracz->maxHp;
				mapa->map[gracz->cordX - 1][gracz->cordY] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordX--;
				if (gracz->currentHp > gracz->maxHp) gracz->currentHp = gracz->maxHp;
				
			}
		}
	}
	if (klawisz == 'w'){
		if (mapa->map[gracz->cordX][gracz->cordY-1] == 0) { //gdy powyzej nic nie ma
			mapa->map[gracz->cordX][gracz->cordY-1] = 22;
			mapa->map[gracz->cordX][gracz->cordY] = 0;
			gracz->cordY--;
		}
		else{ 
			if (mapa->map[gracz->cordX][gracz->cordY-1] <= 10){ //gdy tam jest przedmiot
				pick_up(klawisz, mapa, gracz);//funkcja podnosi przedmiot
				mapa->map[gracz->cordX][gracz->cordY-1] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordY--;
			}
			if (mapa->map[gracz->cordX][gracz->cordY-1] <= 20 && mapa->map[gracz->cordX][gracz->cordY-1] > 10){
				fight(klawisz, mapa, gracz);
				mapa->map[gracz->cordX][gracz->cordY - 1] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordY--;
			}
			if (mapa->map[gracz->cordX][gracz->cordY-1] == 21){
				gracz->currentHp += 0.2*gracz->maxHp;
				mapa->map[gracz->cordX][gracz->cordY - 1] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordY--;
				if (gracz->currentHp > gracz->maxHp) gracz->currentHp = gracz->maxHp;
				
			}
		}
	}
	if (klawisz == 'd'){
		if (mapa->map[gracz->cordX + 1][gracz->cordY] == 0) { //gdy powyzej nic nie ma
			mapa->map[gracz->cordX + 1][gracz->cordY] = 22;
			mapa->map[gracz->cordX][gracz->cordY] = 0;
			gracz->cordX++;
		}
		else{ 
			if (mapa->map[gracz->cordX + 1][gracz->cordY] <= 10){ //gdy tam jest przedmiot
				pick_up(klawisz, mapa, gracz);//funkcja podnosi przedmiot
				mapa->map[gracz->cordX + 1][gracz->cordY] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordX++;
			}
			if (mapa->map[gracz->cordX + 1][gracz->cordY] <= 20 && mapa->map[gracz->cordX + 1][gracz->cordY] > 10){
				fight(klawisz, mapa, gracz);
				mapa->map[gracz->cordX + 1][gracz->cordY] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordX++;
			}
			if (mapa->map[gracz->cordX + 1][gracz->cordY] == 21){
				gracz->currentHp += 0.2*gracz->maxHp;
				mapa->map[gracz->cordX + 1][gracz->cordY] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordX++;
				if (gracz->currentHp > gracz->maxHp) gracz->currentHp = gracz->maxHp;
			}
		}
	}
	if (klawisz == 's'){
		if (mapa->map[gracz->cordX ][gracz->cordY+1] == 0) { //gdy powyzej nic nie ma
			mapa->map[gracz->cordX ][gracz->cordY+1] = 22;
			mapa->map[gracz->cordX][gracz->cordY] = 0;
			gracz->cordY++;
		}
		else{ 
			if (mapa->map[gracz->cordX - 1][gracz->cordY] <= 10){ //gdy tam jest przedmiot
				pick_up(klawisz, mapa, gracz);//funkcja podnosi przedmiot
				mapa->map[gracz->cordX][gracz->cordY + 1] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordY++;
			}
			if (mapa->map[gracz->cordX - 1][gracz->cordY] <= 20 && mapa->map[gracz->cordX - 1][gracz->cordY] > 10){
				fight(klawisz, mapa, gracz);
				mapa->map[gracz->cordX][gracz->cordY + 1] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordY++;
			}
			if (mapa->map[gracz->cordX - 1][gracz->cordY] == 21){
				gracz->currentHp += 0.2*gracz->maxHp;
				mapa->map[gracz->cordX][gracz->cordY + 1] = 22;
				mapa->map[gracz->cordX][gracz->cordY] = 0;
				gracz->cordY++;
				if (gracz->currentHp > gracz->maxHp) gracz->currentHp = gracz->maxHp;
			}
		}
	}



	if (klawisz == 'k'){
		//zapis do pliku
		fstream plik("save.txt", ios::out);
		if (plik.good())
		{
			for (int j = 0; j < 20; j++){
				for (int i = 0; i < 50; i++){
					plik << mapa->map[i][j] << " "; 
				}
			}
		}
	}


	
	
	if (klawisz == 'l'){
		//odczyt z pliku
		fstream plik;
		plik.open("save.txt", ios::in);
		if (plik.good())
		{
			while (!plik.eof())
			{
				for (int j = 0; j < 20; j++){
					for (int i = 0; i < 50; i++){
						plik >> mapa->map[i][j];

					}
				}
			}
			plik.close();

		}
	}

	

	
	if (klawisz == 'h'){
		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "LEGENDA: # - gracz, + - przedmioty, E - wrogowie, & - eliksir zycia";
		cout << endl << endl << endl;
		cout << "[  Naciśnij cokolwiek aby wrocic  ]";

		_getch();

	}
}
// funkcja podnosi przedniot, zmienia pozycję gracza, usuwa przedmiot z mapy
void pick_up(char klawisz, Board *mapa, Player *gracz){
	int pozycja = 0;
	while (gracz->items[pozycja].id != 0 && pozycja <30){
		pozycja++;
	}

	if (klawisz == 'a'){
		gracz->items[pozycja].id = mapa->map[gracz->cordX - 1][gracz->cordY];
		gracz->items[pozycja].strength = gracz->items[pozycja].id * 3;
	}
	if (klawisz == 'w'){
		gracz->items[pozycja].id = mapa->map[gracz->cordX][gracz->cordY-1];
		gracz->items[pozycja].strength = gracz->items[pozycja].id * 3;
	}
	if (klawisz == 'd'){
		gracz->items[pozycja].id = mapa->map[gracz->cordX + 1][gracz->cordY];
		gracz->items[pozycja].strength = gracz->items[pozycja].id * 3;

	}
	if (klawisz == 's'){
		gracz->items[pozycja].id = mapa->map[gracz->cordX][gracz->cordY+1];
		gracz->items[pozycja].strength = gracz->items[pozycja].id * 3;
	}
	
}
// walka z przeciwnikiem, jeżeli player wygra to zmiana pozycji, usunięcie enemy, else 'game over'
void fight(char klawisz, Board *mapa, Player *gracz){
	int idEnemy;
	if (klawisz == 'a'){
		idEnemy = mapa->map[gracz->cordX - 1][gracz->cordY];

	}
	if (klawisz == 'w'){
		idEnemy = mapa->map[gracz->cordX][gracz->cordY - 1];

	}
	if (klawisz == 'd'){
		idEnemy = mapa->map[gracz->cordX + 1][gracz->cordY];

	}
	if (klawisz == 's'){
		idEnemy = mapa->map[gracz->cordX][gracz->cordY + 1];
	if (gracz->lvl = 10) {
			klawisz = 'z';
			system("CLS");
			cout << "Gratulacje";
		}
	}
	Enemy potworek(idEnemy);
	if (potworek.str > gracz->str){
		gracz->currentHp = 0;
	}
	else{
		gracz->currentHp -= 5 * potworek.str;
		gracz->lvl++;
		if (gracz->currentHp < 0){
			gracz->currentHp = 0;
		}
	}

}