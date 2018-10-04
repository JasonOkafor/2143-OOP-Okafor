/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: The program controls of how the game of life is updated.
*
*  @author Jason Okafor
   @orignalauthor Dr.Griffin
*  @version 1.1 01/03/17
*  @github repo: https://github.com/JasonOkafor
*/
#include <SFML/Graphics.hpp>

using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	RenderWindow Window;
	golCell** World;
	int frameCount;//how many frames its elapsed
	int frameRate;//how many frames per seconds
	sf::Clock C;//the clock of the sfml 
	sf::Time T;//the time of the sfml
	gameOfLife(int width, int height) {
		Width = width;
		Height = height;
		frameCount = 0;//initializing to 0
		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i<height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j<width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	void drawWorld() {

		T = C.getElapsedTime();//setting T to the elapsed time 
		frameRate = frameCount / T.asSeconds();//having per second 
		Window.clear();
		for (int i = 0; i<Height; i++) {
			for (int j = 0; j<Width; j++) {
				Window.draw(World[i][j].Rect);
			}
		}
		Window.display();
	}
};



int main() {

	gameOfLife Gol(400, 400);

	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event)&& !(Gol.frameCount % 20))//how frames its passing up
		{
			Gol.drawWorld();
			if (event.type == Event::Closed)
				Gol.Window.close();

		}

		Gol.frameCount++;//incrementing the framecount
	}

	return 0;
}