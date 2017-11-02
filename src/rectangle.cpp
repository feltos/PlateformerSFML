#include <rectangle.h>

Rect::Rect(sf::Vector2f position, 
	sf::Vector2f size)
{
	centerPos = position;
	pixelSize = size;

	
}

Rect::~Rect()
{

}

void Rect::init(b2World& world, b2BodyType bodyType)
{
	switch (bodyType)
	{
	case b2_staticBody:
		rectType = RectType::GROUND;
		break;
	case b2_dynamicBody:
		rectType = RectType::PLAYER_CHARACTER;
		break;
	}
	rectShape.setPosition(centerPos - pixelSize / 2.f);
	rectShape.setSize(pixelSize);
	rectShape.setFillColor(sf::Color::Red);

	b2BodyDef bodyDef;
	bodyDef.type = bodyType;
	bodyDef.position = pixel2meter(centerPos);
	bodyDef.fixedRotation = true;
	bodyDef.userData = this;

	body = world.CreateBody(&bodyDef);

	b2FixtureDef fixtureDef;
	fixtureDef.userData = this;
	b2PolygonShape shape;
	shape.SetAsBox(
		pixel2meter(pixelSize.x / 2.f), pixel2meter(pixelSize.y / 2.f));
	fixtureDef.shape = &shape;

	box = body->CreateFixture(&fixtureDef);
}

void Rect::update(sf::Time dt)
{
	centerPos = meter2pixel(body->GetPosition());
	rectShape.setPosition(centerPos - pixelSize / 2.f);
}

void Rect::draw(sf::RenderWindow& window)
{
	window.draw(rectShape);
}

RectType Rect::GetRectType()
{
	return rectType;
}
