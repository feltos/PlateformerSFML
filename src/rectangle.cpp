#include <rectangle.h>

Rect::Rect(b2World& world,
	sf::Vector2f position, 
	sf::Vector2f size)
{
	centerPos = position;
	pixelSize = size;

	rectShape.setPosition(centerPos-pixelSize/2.f);
	rectShape.setSize(pixelSize);
	rectShape.setFillColor(sf::Color::Red);
}

Rect::~Rect()
{

}

void Rect::update(sf::Time dt)
{

}

void Rect::draw(sf::RenderWindow& window)
{
	window.draw(rectShape);
}
