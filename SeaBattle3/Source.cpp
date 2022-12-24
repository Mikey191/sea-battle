#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#define widght 11

//
//char plus = '+';
char space = ' ';
char numbers[10] = { '1', '2', '3', '4','5','6','7','8','9','10' };
char letters[10] = { 'a', 'b', 'c', 'd','e','f','j','h','i','j' };
char symbols[3] = { '*', '.', '+'};
//

void show_ground(char b1[][widght]);

void gamePvp(char* b1, char* b2, char* b3, char* b4);
void gamePve(char* b1, char* b2, char* b3, char* b4);

void fill_ground_space(char b1[][widght]);
void fill_ground_player(char b1[][widght]);
void fill_ground_random_left(char b1[][widght]);
void fill_ground_random_up(char b1[][widght]);
void fill_ground_random(char b1[][widght]);

void bang(char* b1, char* b2);
void bang_computer(char* b1, char* b2);
void show_battle_ground(char* b1, char* b2);

int main() {

	srand(time(NULL));
	int n = 0; //переменная для записи новой записи на гит
	//Game g;
	char battle_ground_first_player_ship[widght][widght];
	char battle_ground_first_player_bang[widght][widght];
	char battle_ground_second_player_ship[widght][widght];
	char battle_ground_second_player_bang[widght][widght];
	//заполнение полей пробелами
	fill_ground_space(battle_ground_first_player_ship);
	fill_ground_space(battle_ground_first_player_bang);
	fill_ground_space(battle_ground_second_player_ship);
	fill_ground_space(battle_ground_second_player_ship);
	//--------------------------------------------------
	int menu;
	do {
		system("cls");
		cout << "\tMain Menu" << endl;
		cout << "1 - Player vs Player " << endl;
		cout << "2 - Player vs Computer " << endl;
		cout << "0 - exit" << endl;
		cout << ">>>: ";
		cin >> menu;
		switch (menu) {
		case 1: cout << "PvP" << endl; break;
		case 2: cout << "PvE" << endl; break;
		case 3: fill_ground_random(battle_ground_first_player_ship); break;
		}
	} while (menu != 0);

	return 0;
}

void fill_ground_space(char b1[][widght]) {

	b1[0][0] = '+';

	for (int i = 0; i < 1; i++) {
		for (int j = 1; j < widght; j++) {
			b1[i][j] = numbers[j - 1];
		}
	}

	for (int i = 1; i < widght; i++) {
		for (int j = 0; j < 1; j++) {
			b1[i][j] = letters[i - 1];
		}
	}

	for (int i = 1; i < widght; i++) {
		for (int j = 1; j < widght; j++) {
			b1[i][j] = space;
		}
	}
}

void show_ground(char b1[][widght]) {
	for (int i = 0; i < widght; i++) {
		for (int j = 0; j < widght; j++) {
			cout << b1[i][j] << " ";
		}cout << endl;
	}
	system("pause");
}

bool chek_random_left_first(char b1[][widght],const int &x_rand_for_start_ship,const int &y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}

bool chek_random_left_second(char b1[][widght],const int &x_rand_for_start_ship,const int &y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[2]
		) chek = true;
	return chek;
}

bool chek_random_left_therd(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[2]
		) chek = true;
		return chek;
}

bool chek_random_left_fourth(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[2]
		) chek = true;
	return chek;
}

void fill_ground_random_left(char b1[][widght]) {
	//правила заполнения
		//корабли компьютер строит либо вверх либо влево
		//рандомно выбирает точку старта.Если в это точке есть "точка" или "цифра" или "буква" или "умножение" точка не может быть выбрана, и он выбирает заного пока не выберит пустую
		//рандомно выбирает направление.
		//роверить длину корабля, который надо поставить
		//проверить если длина корабля от точки начала до конца не пересикает "точка" или "цифра" или "буква" или "умножение", то корабль можно строить
		// если вверх j - const
		// если влево i - const
	//---------------------------------------------------------------------------------------------------------------------------------------------------

	//счетчик кол-ва кораблей
	int ship_count = 10;
	//координаты стартовой точки корабля
	//int x_rand_for_start_ship = rand() % 10;
	//int y_rand_for_start_ship = rand() % 10;
	bool flag = 0;
	//направление построение(1 = влево или 0 = вверх)
	//int dir = rand() % 1;
	//system("pause");

	//влево 4 палубы
	do {
		do
		{
		//координаты стартовой точки корабля
		int x_rand_for_start_ship = rand() % 11;
		int y_rand_for_start_ship = rand() % 11;
		//направление построение(1 = влево или 0 = вверх)
		int dir = rand() % 2;
		cout << "4 palubi: ";
		cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl << endl;
		if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)){
			if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_left_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_fourth(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						//постраение корабля
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[0];
						//постраение области вокруг коробля
							//заполняем строчку выше 
						if (x_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 3] = symbols[1];
						}
							//заполняем строчку ниже//область ниже не должна быть пустой
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 3] = symbols[1];
						}
							//заполняем столбец левее 
						if (y_rand_for_start_ship - 3 > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 4] = symbols[1];//центральная левая точка
							if(x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 4] = symbols[1];//верхняя левая точка
							if(x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 4] = symbols[1];//нижняя левая точка
						}
							//заполняем столбец правее //область правее не должна быть пустой 
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];//центральня правая точка
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];//верхняя правая точка
							if(x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];//нижняя правая точка
						}
						flag = true;
						ship_count--;
						cout << "4 palub ship is bilding!" << endl;
					}
				}
			}
		}
		} while (flag != true);
		flag = false;
	}while (ship_count > 9);
	show_ground(b1);
	//влево 2 3х палубных
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "3 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
			if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)){
				if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						//постраение корабля
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
						//постраение области вокруг коробля
							//заполняем строчку выше
						if (x_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
						}
							//заполняем строчку ниже
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
						}
							//заполняем столбец левее
						if (y_rand_for_start_ship - 2 > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[1];
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 3] = symbols[1];
							if (x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 3] = symbols[1];
						}
							//заполняем столбец правее
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
							if (x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;	
						cout << "3 palub ship is bilding!" << endl;
						}
					}
				}
			}while (flag != true);
		flag = false;
	} while (ship_count > 7);
	show_ground(b1);
	//влево 3 2х палубных
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "2 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
			if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)
					) {
						//постраение корабля
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
						//постраение области вокруг коробля
							//заполняем строчку выше
						if (x_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						}
							//заполняем строчку ниже
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
						}
							//заполняем столбец левее
						if (y_rand_for_start_ship - 1 > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[1];
							if(x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
							if(x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
						}
							//заполняем столбец правее
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							if(x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
							if(x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;
						cout << "2 palub ship is bilding!" << endl;
					}
			}
		} while (flag != true);
		flag = false;
	} while (ship_count > 4);
	show_ground(b1);
	//влево 4 1о палубных
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "1 paluba: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
			if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					//постраение корабля
					b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
					//постраение области вокруг коробля
						//заполняем строчку выше
					if (x_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
					}
					//заполняем строчку ниже
					if (x_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
					}
					//заполняем столбец левее
					if (y_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
						if (x_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						if (x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
					}
					//заполняем столбец правее
					if (y_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
						if (x_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
						if (x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					flag = true;
					ship_count--;
					cout << "1 palub ship is bilding!" << endl;
				}
		} while (flag != true);
		flag = false;
	} while (ship_count > 0);
	//cout << "flag = " << flag << endl;
	show_ground(b1);
}

bool chek_random_up_first(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}

bool chek_random_up_second(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}

bool chek_random_up_therd(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}

bool chek_random_up_fourth(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}

void fill_ground_random_up(char b1[][widght]) {
	//счетчик кол-ва кораблей
	int ship_count = 10;
	bool flag = 0;
	//наверх 4 палубы
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "4 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl << endl;
			if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_up_fourth(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//постраение корабля
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] = symbols[0];
							//постраение области вокруг коробля
								//заполняем строчку выше 
							if (x_rand_for_start_ship - 3 > 1) {
								b1[x_rand_for_start_ship - 4][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 4][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship - 4][y_rand_for_start_ship + 1] = symbols[1];
							}
								//заполняем строчку ниже
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
								//заполняем столбец левее 
							if (y_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship - 1] = symbols[1];
							}
								//заполняем столбец правее 
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "4 palub ship is bilding!" << endl;
						}
					}
				}
			}
		} while (flag != true);
		flag = false;
	} while (ship_count > 9);
	show_ground(b1);
	//влево 2 3х палубных
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "3 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
			if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						//постраение корабля
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[0];
						//постраение области вокруг коробля
							//заполняем строчку выше
						if (x_rand_for_start_ship - 2 > 1) {
							b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] = symbols[1];
							if (y_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship - 1] = symbols[1];
							if (y_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship + 1] = symbols[1];
						}
						//заполняем строчку ниже
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							if (y_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
							if (y_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						//заполняем столбец левее
						if (y_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
						}
						//заполняем столбец правее
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;
						cout << "3 palub ship is bilding!" << endl;
					}
				}
			}
		} while (flag != true);
		flag = false;
	} while (ship_count > 7);
	show_ground(b1);
	//влево 3 2х палубных
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "2 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
			if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					//постраение корабля
					b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
					b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
					//постраение области вокруг коробля
						//заполняем строчку выше
					if (x_rand_for_start_ship - 1 > 1) {
						b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[1];
						if (y_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
						if (y_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
					}
					//заполняем строчку ниже
					if (x_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
						if (y_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
						if (y_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					//заполняем столбец левее
					if (y_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
					}
					//заполняем столбец правее
					if (y_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					flag = true;
					ship_count--;
					cout << "2 palub ship is bilding!" << endl;
				}
			}
		} while (flag != true);
		flag = false;
	} while (ship_count > 4);
	show_ground(b1);
	//влево 4 1о палубных
	do {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			//направление построение(1 = влево или 0 = вверх)
			int dir = rand() % 2;
			cout << "1 paluba: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
			if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				//постраение корабля
				b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
				//постраение области вокруг коробля
					//заполняем строчку выше
				if (x_rand_for_start_ship > 1) {
					b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
					if (y_rand_for_start_ship > 1)
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
					if (y_rand_for_start_ship < 10)
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
				}
				//заполняем строчку ниже
				if (x_rand_for_start_ship < 10) {
					b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
					if (y_rand_for_start_ship > 1)
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
					if (y_rand_for_start_ship < 10)
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
				}
				//заполняем столбец левее
				if (y_rand_for_start_ship > 1) {
					b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
				}
				//заполняем столбец правее
				if (y_rand_for_start_ship < 10) {
					b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
				}
				flag = true;
				ship_count--;
				cout << "1 palub ship is bilding!" << endl;
			}
		} while (flag != true);
		flag = false;
	} while (ship_count > 0);
	//cout << "flag = " << flag << endl;
	show_ground(b1);
}

void fill_ground_random(char b1[][widght]) {
	system("cls");
	bool flag = 0;
	int ship_count = 10;
	//4 palubi
	int dir = rand() % 2;
	if (dir == 0) {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			cout << "4 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl << endl;
			if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_left_fourth(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//постраение корабля
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[0];
							//постраение области вокруг коробля
								//заполняем строчку выше 
							if (x_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 3] = symbols[1];
							}
							//заполняем строчку ниже//область ниже не должна быть пустой
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 3] = symbols[1];
							}
							//заполняем столбец левее 
							if (y_rand_for_start_ship - 3 > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 4] = symbols[1];//центральная левая точка
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 4] = symbols[1];//верхняя левая точка
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 4] = symbols[1];//нижняя левая точка
							}
							//заполняем столбец правее //область правее не должна быть пустой 
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];//центральня правая точка
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];//верхняя правая точка
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];//нижняя правая точка
							}
							flag = true;
							ship_count--;
							cout << "4 palub ship is bilding!" << endl;
						}
					}
				}
			}
		} while (flag != true);
		flag = false;
		show_ground(b1);
	} //влево 
	else {
		do
		{
			//координаты стартовой точки корабля
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			cout << "4 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl << endl;
			if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_up_fourth(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//постраение корабля
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] = symbols[0];
							//постраение области вокруг коробля
								//заполняем строчку выше 
							if (x_rand_for_start_ship - 3 > 1) {
								b1[x_rand_for_start_ship - 4][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 4][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship - 4][y_rand_for_start_ship + 1] = symbols[1];
							}
							//заполняем строчку ниже
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
							//заполняем столбец левее 
							if (y_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship - 1] = symbols[1];
							}
							//заполняем столбец правее 
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "4 palub ship is bilding!" << endl;
						}
					}
				}
			}
		} while (flag != true);
		flag = false;
		show_ground(b1);
	} //вверх

	//3 palubi
	do {
		dir = rand() % 2;
		if (dir == 0) {
			do
			{
				//координаты стартовой точки корабля
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "3 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << endl;
				if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_left_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//постраение корабля
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
							//постраение области вокруг коробля
								//заполняем строчку выше
							if (x_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
							}
							//заполняем строчку ниже
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
							}
							//заполняем столбец левее
							if (y_rand_for_start_ship - 2 > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[1];
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 3] = symbols[1];
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 3] = symbols[1];
							}
							//заполняем столбец правее
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "3 palub ship is bilding!" << endl;
						}
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //влево 
		else {
			do
			{
				//координаты стартовой точки корабля
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "3 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_up_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//постраение корабля
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[0];
							//постраение области вокруг коробля
								//заполняем строчку выше
							if (x_rand_for_start_ship - 2 > 1) {
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 3][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship - 3][y_rand_for_start_ship + 1] = symbols[1];
							}
							//заполняем строчку ниже
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
							//заполняем столбец левее
							if (y_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
							}
							//заполняем столбец правее
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "3 palub ship is bilding!" << endl;
						}
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //вверх
	} while (ship_count > 7);


	//2 palubi
	do {
		dir = rand() % 2;
		if (dir == 0) {
			do
			{
				//координаты стартовой точки корабля
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "2 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)
						) {
						//постраение корабля
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
						//постраение области вокруг коробля
							//заполняем строчку выше
						if (x_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						}
						//заполняем строчку ниже
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
						}
						//заполняем столбец левее
						if (y_rand_for_start_ship - 1 > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[1];
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
							if (x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
						}
						//заполняем столбец правее
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
							if (x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;
						cout << "2 palub ship is bilding!" << endl;
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //влево 
		else {
			do
			{
				//координаты стартовой точки корабля
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "2 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						//постраение корабля
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
						//постраение области вокруг коробля
							//заполняем строчку выше
						if (x_rand_for_start_ship - 1 > 1) {
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[1];
							if (y_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
							if (y_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
						}
						//заполняем строчку ниже
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							if (y_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
							if (y_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						//заполняем столбец левее
						if (y_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						}
						//заполняем столбец правее
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;
						cout << "2 palub ship is bilding!" << endl;
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //вверх
	} while (ship_count > 4);


	//1 palubi
	do {
		dir = rand() % 2;
		if (dir == 0) {
			do
			{
				//координаты стартовой точки корабля
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "1 paluba: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					//постраение корабля
					b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
					//постраение области вокруг коробля
						//заполняем строчку выше
					if (x_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
					}
					//заполняем строчку ниже
					if (x_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
					}
					//заполняем столбец левее
					if (y_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
						if (x_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						if (x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
					}
					//заполняем столбец правее
					if (y_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
						if (x_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
						if (x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					flag = true;
					ship_count--;
					cout << "1 palub ship is bilding!" << endl;
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //влево 
		else {
			do
			{
				//координаты стартовой точки корабля
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "1 paluba: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					//постраение корабля
					b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
					//постраение области вокруг коробля
						//заполняем строчку выше
					if (x_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
						if (y_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						if (y_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					//заполняем строчку ниже
					if (x_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
						if (y_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
						if (y_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					//заполняем столбец левее
					if (y_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
					}
					//заполняем столбец правее
					if (y_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
					}
					flag = true;
					ship_count--;
					cout << "1 palub ship is bilding!" << endl;
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //вверх
	} while (ship_count > 0);

}

