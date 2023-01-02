#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
//#define widght 11
const int n = 11;

class Player
{
public:
	virtual void fill_ground(char b1[][n]);
	virtual void bang_ship(char b1[][n]);
};

class Human : public Player 
{
public:
	void fill_ground(char b1[][n]);
	void bang_ship(char b1[][n]);
};

class Computer : public Player
{
public:
	void fill_ground(char b1[][n]);
	void bang_ship(char b1[][n]);
};