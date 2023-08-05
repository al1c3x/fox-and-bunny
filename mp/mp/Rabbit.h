#ifndef RABBIT
#define RABBIT
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Rabbit
{
private:
	RectangleShape rabbit;
	Texture rabbitTexture;
	float x;
	float y;
	float initialPosition[2];
	vector<int> rabbitPos = {0,0}; 
	


public:
	Rabbit(float x, float y, string filename, RectangleShape background, vector<vector<int>>& board);

public:
	RectangleShape getrabbit();
	vector<int> RabPos();
	void Rabbitinput(vector<vector<int>>& board, bool startMove);
	
};

#endif