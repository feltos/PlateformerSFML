#include <iostream>
#include <rectangle.h>
#include <SFML/Graphics.hpp>



int main(int argc, const char* argv[])
{
	sf::RenderWindow window(
		sf::VideoMode(800, 600), 
		"SFML Box2D Example");
	window.setFramerateLimit(60.f);


	b2World world = b2World(b2Vec2(0.f, 9.81f));
	MyContactListener myContactListenerInstance;
	world.SetContactListener(&myContactListenerInstance);

	sf::Clock clock;

	Rect rect;
	Rect ground(sf::Vector2f(400.f, 600.f), sf::Vector2f(800.f, 100.f));
	rect.init(world, b2_dynamicBody);
	ground.init(world, b2_staticBody);

	float32 timeStep = 1 / 60.f;      //the length of time passed to simulate (seconds)
	int32 velocityIterations = 8;   //how strongly to correct velocity
	int32 positionIterations = 3;   //how strongly to correct position

	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		rect.Move();

		world.Step(timeStep, velocityIterations, positionIterations);
		rect.update(dt);

		window.clear();
		rect.draw(window);
		ground.draw(window);
		window.display();
	}


#if WIN32
	system("pause");
#endif
	return EXIT_SUCCESS;
}
