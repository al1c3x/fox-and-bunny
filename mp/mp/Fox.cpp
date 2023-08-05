#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Fox.h"
using namespace std;
using namespace sf;

Fox::Fox(float x ,float y, string textureFile, RectangleShape background, vector<vector<int>>& board)
{
	
	randomvalue[0] = rand() % 20;
	randomvalue[1] = rand() % 20;
		
	board[randomvalue[0]][randomvalue[1]] = 2;
	moveUnits[0] = randomvalue[0];
	moveUnits[1] = randomvalue[1];
	this->initialPosition[0] = background.getPosition().x - (background.getSize().x / 2) + 4; 
	this->initialPosition[1] = background.getPosition().y - (background.getSize().y / 2);
	this->fox.setSize(sf::Vector2f(x,y));
	this->fox.setPosition(this->initialPosition[0] + (randomvalue[0] * 60), this->initialPosition[1] + (randomvalue[1] * 47.5));
	this->foxTexture.loadFromFile(textureFile);
	this->fox.setTexture(&this->foxTexture);
	this->move = false;

}

RectangleShape Fox::getfox()
{
	return this->fox;
}

bool Fox::foxinput(vector<vector<int>>& board)
{
	++this->time;
	if (Keyboard::isKeyPressed(Keyboard::Left) && this->time >= cd)
	{
		++this->foxMoves;
		board[moveUnits[0]][moveUnits[1]] = 0;
		--this->moveUnits[0]; 
		if (this->moveUnits[0] < 0)	
			this->moveUnits[0] = 0;
		this->time = 0;
		this->fox.setPosition(this->initialPosition[0] + (this->moveUnits[0] * 60), this->initialPosition[1] + (this->moveUnits[1] * 47.5));
		this->move = true;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && this->time >= cd)
	{
		++this->foxMoves;
		board[moveUnits[0]][moveUnits[1]] = 0;
		++this->moveUnits[0];
		if (this->moveUnits[0] > 19)	
			this->moveUnits[0] = 19;
		this->time = 0;
		this->fox.setPosition(this->initialPosition[0] + (this->moveUnits[0] * 60) , this->initialPosition[1] + (this->moveUnits[1] * 47.5));
		this->move = true;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && this->time >= cd)
	{
		++this->foxMoves;
		board[moveUnits[0]][moveUnits[1]] = 0;
		--this->moveUnits[1];
		if (this->moveUnits[1] < 0)	
			this->moveUnits[1] = 0;
		this->time = 0;
		this->fox.setPosition(this->initialPosition[0] + (this->moveUnits[0] * 60),this->initialPosition[1] + (this->moveUnits[1] * 47.5));
		this->move = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && this->time >= cd)//for the down arrow key
	{
		++this->foxMoves;
		board[moveUnits[0]][moveUnits[1]] = 0;
		++this->moveUnits[1];
		if (this->moveUnits[1] > 19)
			this->moveUnits[1] = 19;
		this->time = 0;
		this->fox.setPosition(this->initialPosition[0] + (this->moveUnits[0] * 60) , this->initialPosition[1] + (this->moveUnits[1] * 47.5));
		this->move = true;
	}
	randomvalue[0] = moveUnits[0];
	randomvalue[1] = moveUnits[1];
	
	board[moveUnits[0]][moveUnits[1]] = 2;
	return move;
}

int Fox::totalMoves()
{
	return this->foxMoves;
}

void Fox::numberofMoves(int moves)
{
	this->foxMoves = moves;
}

vector<int> Fox::FoxPos()
{
	return this->randomvalue;
}

void Fox::foxmove(bool condition)
{
	this->move = condition;
}



