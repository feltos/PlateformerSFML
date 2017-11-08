#include <rectangle.h>
#include <iostream>

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

	numFootContacts = 0;
	box = body->CreateFixture(&fixtureDef);
	box->IsSensor();
}

void Rect::BeginContact(b2Contact* contact) 
	{
		//check if fixture A was the foot sensor
		void* fixtureUserData = contact->GetFixtureA()->GetUserData();
		if ((int)fixtureUserData == 0)
			numFootContacts++;
	}

void Rect::EndContact(b2Contact* contact) 
	{
		//check if fixture A was the foot sensor
		void* fixtureUserData = contact->GetFixtureA()->GetUserData();
		if ((int)fixtureUserData == 1)
			numFootContacts--;
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

void Rect::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{		
		body->SetLinearVelocity(b2Vec2(2.0f,body->GetLinearVelocity().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		body->SetLinearVelocity(b2Vec2(-2.0f, body->GetLinearVelocity().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, -8.0f));
	}
}

RectType Rect::GetRectType()
{
	return rectType;
}
