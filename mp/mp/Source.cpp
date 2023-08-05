#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Fox.h"
#include "Rabbit.h"
#include "Background.h"
#include "Game.h"

using namespace std;
using namespace sf;
typedef vector<Rabbit> rabbitlist;
int main()
{
	RenderWindow window(VideoMode(1500, 1000), "FOX AND RABBIT");
	window.setFramerateLimit(30);
	int x = 0;
	int temp = 0;
	int y = 0;
	rabbitlist object;

	Game game;
	Background board(1200.0f, 950.0f, "green.png", window);  
	Background bg(1500.0f, 1000.0f, "bg.jpg", window); 
	Fox player(55.0f, 50.0f, "fox.png", board.getBackground(), game.checkboard()); 

	for (x = 0; x < game.numberofrabbits(); x++)
	{
		Rabbit* enemy = new Rabbit(55.0f, 50.0f, "rabbit.png", board.getBackground(), game.checkboard());
		object.push_back(*enemy);
	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
	
		game.foxMove(player.foxinput(game.checkboard()));

		if (game.foxaction())
		{
			for (x = 0; x < object.size(); x++)
			{
				if (player.FoxPos()[0] == object[x].RabPos()[0] && player.FoxPos()[1] == object[x].RabPos()[1])
				{
					object.erase(object.begin() + x);
					game.Rabbitnumber(game.numberofrabbits() - 1);
				}
			}
		}

		if (game.foxaction())
		{
			if (game.foxaction())
			{
				for (x = 0; x < object.size(); x++)
				{
					object[x].Rabbitinput(game.checkboard(), true);
				}
				game.foxMove(false);
				player.foxmove(false);
			}
		}
		
		if (player.totalMoves() == 3)
		{
				temp = game.numberofrabbits();
				game.Rabbitnumber(game.numberofrabbits() * 2);
				for (x = temp; x < game.numberofrabbits(); x++)
				{
					Rabbit* enemy = new Rabbit(55.0f, 50.0f, "rabbit.png", board.getBackground(), game.checkboard()); 
					object.push_back(*enemy);
				}
				player.numberofMoves(0);
		}

		window.clear();
		window.draw(bg.getBackground());
		window.draw(board.getBackground());
		window.draw(player.getfox());
		for (x = 0; x < game.numberofrabbits(); x++)
		{
			window.draw(object[x].getrabbit()); 
		}
	
		if (game.numberofrabbits() >= 50 )
		{
			cout << " You lose" << endl;
			window.close();
		}

		else if (game.numberofrabbits() == 0 )
		{
			cout << " You win" << endl;
			window.close();
		}
		window.display();
		
	}

	return 0;
}

