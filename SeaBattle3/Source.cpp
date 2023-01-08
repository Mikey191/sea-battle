#include <iostream>
#include <ctime>
#include <conio.h>
#include "for_player.h"
#include "Player.h"
using namespace std;

int main() {

	srand(time(NULL));
	Human player_1;
	Human player_2;
	//Computer player_3;
	char battle_ground_first_player_ship[widght][widght];
	char battle_ground_first_player_bang[widght][widght];
	char battle_ground_second_player_ship[widght][widght];
	char battle_ground_second_player_bang[widght][widght];
	//заполнение полей пробелами
	fill_ground_space(battle_ground_first_player_ship);
	fill_ground_space(battle_ground_first_player_bang);
	fill_ground_space(battle_ground_second_player_ship);
	fill_ground_space(battle_ground_second_player_bang);
	//--------------------------------------------------
	int menu;
	do {
		system("cls");
		cout << "\tMain Menu" << endl;
		cout << "9 - fill ground space" << endl;
		cout << "1 - just bang " << endl;
		cout << "2 - Player vs Computer " << endl;
		cout << "3 - test " << endl;
		cout << "4 - show bg" << endl;
		cout << "5 - bang random" << endl;
		cout << "6 - bang smart" << endl;
		cout << "7 - random horizon 4part ship" << endl;
		cout << "8 - random horizon 3part ship" << endl;
		cout << "0 - exit" << endl;
		cout << ">>>: ";
		cin >> menu;
		switch (menu) {
		case 1: just_bang(battle_ground_first_player_bang); break;
		case 2: cout << "PvE" << endl; break;
		case 3: player_1.fill_ground_rand(battle_ground_first_player_ship); break;
		case 4: show_two_ground(battle_ground_first_player_ship, battle_ground_first_player_bang); system("pause"); break;
		case 5: bang_random(battle_ground_first_player_ship, battle_ground_first_player_bang); break;
		case 6: bang_smart(battle_ground_first_player_ship, battle_ground_first_player_bang); break;
		case 7: fill_ground_random_fourth_horizont(battle_ground_first_player_ship); break;
		case 8: fill_ground_random_three_horizont(battle_ground_first_player_ship); break;
		case 9: fill_ground_space(battle_ground_first_player_ship); break;
		}
	} while (menu != 0);

	return 0;
}