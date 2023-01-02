#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
using namespace std;
#define widght 11

extern char space;
extern char numbers[10];
extern char letters[10];
extern char symbols[3];

void fill_ground_space(char b1[][widght]);
void show_ground(char b1[][widght]);
void copy_ground(char b1[][widght], char b2[][widght]);

bool chek_random_left_first(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship);
bool chek_random_left_second(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship);
bool chek_random_left_therd(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship);
bool chek_random_left_fourth(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship);
bool chek_random_up_first(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship);
bool chek_random_up_second(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship);
bool chek_random_up_therd(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship);
bool chek_random_up_fourth(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship);
void fill_ground_random(char b1[][widght]);

void dir_down(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void dir_up(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void dir_right(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void dir_left(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void fill_det_around_ship(char b1[][widght]);
void tap_ship_four_part_random_horizont(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void tap_ship_four_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void tap_ship_three_part_random_horizont(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void tap_ship_three_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void tap_ship_two_part_random_horizont(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void tap_ship_two_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
void tap_ship_one_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish);
int count_ship_part(char b1[][widght]);
void fill_ground_player(char b1[][widght]);