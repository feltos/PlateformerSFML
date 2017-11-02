#include "utility.h"


const float pixelPerMeter = 64.f;

float pixel2meter(float pixel)
{
	return pixel/pixelPerMeter;
}

float meter2pixel(float meter)
{
	return meter*pixelPerMeter;
}

b2Vec2 pixel2meter(sf::Vector2f pixels)
{
	return b2Vec2(pixel2meter(pixels.x), 
		pixel2meter(pixels.y));
}

sf::Vector2f meter2pixel(b2Vec2 meters)
{
	return sf::Vector2f(meter2pixel(meters.x),
		meter2pixel(meters.y));
}

void CheckRectType(Rect** playerCharaterPtr, Rect** groundPtr, void* userData)
{

	if (userData != nullptr)
	{
		Rect* testedRect = static_cast<Rect*>(userData);
		switch (testedRect->GetRectType())
		{
		case RectType::GROUND:
			*groundPtr = testedRect;
			break;
		case RectType::PLAYER_CHARACTER:
			*playerCharaterPtr = testedRect;
			break;
		}
	}
}

void MyContactListener::BeginContact(b2Contact* contact) {


	Rect* playerCharacter = nullptr;
	Rect* ground = nullptr;

	CheckRectType(&playerCharacter, &ground, contact->GetFixtureA()->GetBody()->GetUserData());
	CheckRectType(&playerCharacter, &ground, contact->GetFixtureB()->GetBody()->GetUserData());
	if (playerCharacter != nullptr)
	{
		//TODO PLAYER ON GROUND
	}
}

void MyContactListener::EndContact(b2Contact* contact) {



	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();

	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();


}