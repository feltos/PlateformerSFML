#ifndef SFML_EXAMPLE_UTILITY_H
#define SFML_EXAMPLE_UTILITY_H

#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <rectangle.h>

float pixel2meter(float pixel);
float meter2pixel(float meter);
b2Vec2 pixel2meter(sf::Vector2f pixels);
sf::Vector2f meter2pixel(b2Vec2 meters);

class MyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};
	


#endif