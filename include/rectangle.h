#ifndef SFML_EXAMPLE_RECT_H
#define SFML_EXAMPLE_RECT_H

#include <utility.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

enum class RectType
{
	PLAYER_CHARACTER,
	GROUND,
	NONE
};

class Rect
{
public:
	Rect(sf::Vector2f position=sf::Vector2f(400,300),
		sf::Vector2f size=sf::Vector2f(100,100));
	~Rect();
	void init(b2World& world, b2BodyType bodyType);
	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);
	RectType GetRectType();
	void Move();
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
private:
	sf::RectangleShape rectShape;
	sf::Vector2f centerPos;
	sf::Vector2f pixelSize;
	b2Body* body = nullptr;
	b2Fixture* box = nullptr;
	int numFootContacts;
	RectType rectType;
};

#endif