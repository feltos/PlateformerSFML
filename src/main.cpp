#include <iostream>
#include <rectangle.h>
#include <SFML/Graphics.hpp>

int main(int argc, const char* argv[])
{
	sf::RenderWindow window(
		sf::VideoMode(800, 600), 
		"SFML Box2D Example");

	b2World world = b2World(b2Vec2(0.f,-9.81f));

	Rect rect;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		rect.draw(window);
		window.display();
	}


#if WIN32
	system("pause");
#endif
	return EXIT_SUCCESS;
}
