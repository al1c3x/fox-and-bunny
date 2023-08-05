#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Rabbit.h"
using namespace std;
using namespace sf;

Rabbit::Rabbit(float x, float y, string filename, RectangleShape background, vector<vector<int>>& board)
{
	while (true)
	{
		this->rabbitPos[0] = rand() % 20; //current index x
		this->rabbitPos[1] = rand() % 20; //current index y
		if (board[rabbitPos[0]][rabbitPos[1]] == 1 || board[rabbitPos[0]][rabbitPos[1]] == 2)
			continue;
		else
			break;
	}
	board[rabbitPos[0]][rabbitPos[1]] = 1;
	this->initialPosition[0] = background.getPosition().x - (background.getSize().x / 2) + 4 + (this->rabbitPos[0] * 60); 
	this->initialPosition[1] = background.getPosition().y - (background.getSize().y / 2) + (this->rabbitPos[1] * 47.5); 
	this->rabbit.setSize(sf::Vector2f(x,y));
	this->rabbit.setPosition(this->initialPosition[0], this->initialPosition[1]);
	this->rabbitTexture.loadFromFile(filename);
	this->rabbit.setTexture(&rabbitTexture);

}

RectangleShape Rabbit::getrabbit()
{
	return this->rabbit;
}

vector<int> Rabbit::RabPos()
{
	return this->rabbitPos;
}

void Rabbit::Rabbitinput(vector<vector<int>>& board, bool allowed)
{
	srand(time(NULL));
	int x, y;
	vector<bool> out = { false, false, false, false };
	if (rabbitPos[0] + 1 > 19)
	{
		out[0] = true;
	}
		
	else if (rabbitPos[0] - 1 < 0)
	{
		out[1] = true;
	}
		
	else if (rabbitPos[1] + 1 > 19)
	{
		out[2] = false;
	}
		
	else if (rabbitPos[1] - 1 < 0)
	{
		out[3] = false;
	}
		

	if ((out[0] || (rabbitPos[0] + 1 <= 19 && board[rabbitPos[0] + 1][rabbitPos[1]] == 1) || (rabbitPos[0] + 1 <= 19 && board[rabbitPos[0] + 1][rabbitPos[1]] == 2)) &&
		(out[1] || (rabbitPos[0] - 1 >= 0 && board[rabbitPos[0] - 1][rabbitPos[1]] == 1) || (rabbitPos[0] - 1 >= 0 && board[rabbitPos[0] - 1][rabbitPos[1]] == 2)) &&
		(out[2] || (rabbitPos[1] + 1 <= 19 && board[rabbitPos[0]][rabbitPos[1] + 1] == 1) || (rabbitPos[1] + 1 <= 19 && board[rabbitPos[0]][rabbitPos[1] + 1] == 2)) &&
		(out[3] || (rabbitPos[1] - 1 >= 0 && board[rabbitPos[0]][rabbitPos[1] - 1] == 1) || (rabbitPos[1] - 1 >= 0 && board[rabbitPos[0]][rabbitPos[1] - 1] == 2)))
	{
		allowed = false;
	}
		


	while (allowed)
	{
		board[this->rabbitPos[0]][this->rabbitPos[1]] = 0;
		x = rand() % 2; 
		y = rand() % 2; 
		if (x == 0)
		{
			if (y == 0)
			{
				++this->rabbitPos[0];
				if (this->rabbitPos[0] > 19 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 1 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 2)
				{
					--this->rabbitPos[0];
					continue;
				}
				board[this->rabbitPos[0]][this->rabbitPos[1]] = 1;
				this->initialPosition[0] += 60;
				this->rabbit.setPosition(this->initialPosition[0], this->initialPosition[1]);
				
			}
			else if (y == 1)
			{
				--this->rabbitPos[0];
				if (this->rabbitPos[0] < 0 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 1 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 2)
				{
					++this->rabbitPos[0];
					continue;
				}
				board[this->rabbitPos[0]][this->rabbitPos[1]] = 1;
				this->initialPosition[0] -= 60;
				this->rabbit.setPosition(this->initialPosition[0], this->initialPosition[1]);
				
			}
		}
		else if (x == 1)
		{
			if (y == 0)
			{
				++this->rabbitPos[1];
				if (this->rabbitPos[1] > 19 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 1 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 2)
				{
					--this->rabbitPos[1];
					continue;
				}
				board[this->rabbitPos[0]][this->rabbitPos[1]] = 1;
				this->initialPosition[1] += 47.5;
				this->rabbit.setPosition(this->initialPosition[0], this->initialPosition[1]);
			}
			else if (y == 1)
			{
				--this->rabbitPos[1];
				if (this->rabbitPos[1] < 0 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 1 || board[this->rabbitPos[0]][this->rabbitPos[1]] == 2)
				{
					++this->rabbitPos[1];
					continue;
				}
				board[this->rabbitPos[0]][this->rabbitPos[1]] = 1;
				this->initialPosition[1] -= 47.5;
				this->rabbit.setPosition(this->initialPosition[0], this->initialPosition[1]);
			}
		}
		allowed = false;
	}

}


