#include "../include/BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>

RandPlayer::RandPlayer(char symbol, int dimension) : Player(symbol)
{
	this->dimension = dimension;
	this->name = "Bassyoni The Computer";
	cout << "My names is " << name << endl;
}

void RandPlayer::get_move(int& x, int& y) {
	srand(static_cast<unsigned int>(time(0)));
	int rows = 3;
	int cols = 5;

	x = rand() % rows;
	y = rand() % cols;
}
