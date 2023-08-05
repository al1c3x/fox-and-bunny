#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;


Game::Game()
{
	int x;
	this->board.resize(20);
	for (x = 0; x < this->board.size(); x++)
	{
		this->board[x].resize(20);
	}
}

int Game::numberofrabbits()
{
	return this->numberOfRabbits;
}

void Game::Rabbitnumber(int size)
{
	this->numberOfRabbits = size;
}


vector<vector<int>>& Game::checkboard()
{
	return this->board;
}

bool Game::foxaction()
{
	return this->Move;
}

void Game::foxMove(bool condition)
{
	this->Move = condition;
}

