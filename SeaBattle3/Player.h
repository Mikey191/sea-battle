#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include "for_player.h"
using namespace std;

class Player
{
public:
	virtual void fill_ground_rand(char b_player[][widght]) = 0;
	virtual void fill_ground_hands(char b_player[][widght]) = 0;
	virtual void bang_ship(char b_player[][widght], char b_enemy[][widght]) = 0;
};

class Human : public Player 
{
public:
	void fill_ground_rand(char b_player[][widght]) override;
	void fill_ground_hands(char b_player[][widght]) override;
	void bang_ship(char b_player[][widght], char b_enemy[][widght]) override;
};

class Computer : public Player
{
public:
	void fill_ground_rand(char b_player[][widght]) override;
	void bang_ship(char b_player[][widght], char b_enemy[][widght]) override;
};