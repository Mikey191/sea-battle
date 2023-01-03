#include "Player.h"

void Computer::fill_ground_rand(char b_player[][widght])
{
	fill_ground_random(b_player);
}

void Computer::bang_ship(char b_player[][widght], char b_enemy[][widght])
{
	cout << "computer" << endl;
}

void Human::fill_ground_rand(char b_player[][widght])
{
	fill_ground_random(b_player);
}

void Human::fill_ground_hands(char b_player[][widght])
{
	fill_ground_player(b_player);
}

void Human::bang_ship(char b_player[][widght], char b_enemy[][widght])
{
	cout << "bang human" << endl;
}
