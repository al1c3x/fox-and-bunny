#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Background.h"
using namespace std;
using namespace sf;

Background::Background(float x, float y , string filename, RenderWindow& window)
{
	this->bg.setSize(sf::Vector2f(x,y));
	this->bg.setOrigin(x/2, y/2);
	this->bg.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	this->bgTexture.loadFromFile(filename);
	this->bg.setTexture(&bgTexture);
}

RectangleShape Background::getBackground()
{
	return this->bg;
}