#include "Clock.h"

ae::Clock::Clock()
{
}

float ae::Clock::getDelta()
{
	return this->clock.getElapsedTime().asSeconds();
}

long int ae::Clock::uGetDelta()
{
	return this->clock.getElapsedTime().asMicroseconds();
}

float ae::Clock::resetDelta()
{
	return this->clock.restart().asSeconds();
}

long int ae::Clock::uResetDelta()
{
	return this->clock.restart().asMicroseconds();
}
