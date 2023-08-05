#ifndef GAME
#define GAME
#include <vector>
#include <iostream>
using namespace std;
using namespace sf;

class Game
{
private:
	int numberOfRabbits = 3;
	vector<vector<int>> board;
	bool Move = false;

	
public:
	Game();
	int numberofrabbits();
	void Rabbitnumber(int size);
	vector<vector<int>>& checkboard();
	bool foxaction();
	void foxMove(bool condition);
	
};

#endif 