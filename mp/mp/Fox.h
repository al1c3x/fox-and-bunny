#ifndef FOX
#define FOX
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;


class Fox
{
private:
	RectangleShape fox;
	Texture foxTexture;
	float x;
	float y;
	float initialPosition[2];
	int moveUnits[2] = { 0, 0 };
	float time = 0; 
	float cd = 10.0f; 
	int foxMoves = 0;
	bool move = false;
	vector <int> randomvalue = { 0,0 };
	


public:
	Fox(float x, float y, string textureFile, RectangleShape background, vector<vector<int>>& board);
	RectangleShape getfox();
	bool foxinput(vector<vector<int>>& board);
	int totalMoves();
	void numberofMoves(int moves);
	vector<int> FoxPos();
	void foxmove(bool condition);
};

#endif 