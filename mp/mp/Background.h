#ifndef BACKGROUND
#define BACKGROUND
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Background
{
private:
	RectangleShape bg;
	Texture bgTexture;
	float x;
	float y;
public:
	
	Background(float x, float y, string filename, RenderWindow& window);
	RectangleShape getBackground();
};

#endif
