#ifndef SFML_EXAMPLE_RECT_H
#define SFML_EXAMPLE_RECT_H

#include <utility.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Rect
{
public:
	Rect(b2World& world, 
		sf::Vector2f position=sf::Vector2f(400,300),
		sf::Vector2f size=sf::Vector2f(100,100));
	~Rect();
	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape rectShape;
	sf::Vector2f centerPos;
	sf::Vector2f pixelSize;
};

#endif