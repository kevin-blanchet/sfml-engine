#include "TestObject.h"
#include "DisplayManager.h"
#include "KeyboardEvent.h"
#include "SceneManager.h"

TestObject::TestObject()
{
	testString = "test";
}

TestObject::~TestObject()
{
}

bool TestObject::eventHandler(const ae::Event* event)
{
	if (event->getType() == "KeyboardEvent") {
		const ae::KeyboardEvent* kEvent = dynamic_cast<const ae::KeyboardEvent*>(event);
		if (kEvent->getKey() == ae::Keyboard::Key::A) {
			testString = "Hello World!";
		}
		if (kEvent->getKey() == ae::Keyboard::Key::Down) {
			ae::Vector2 pos = this->getPosition();
			ae::Vector2 move = { 0, 50 };
			this->setPosition(pos + move);
		}
	}
	return false;
}

void TestObject::draw()
{
	DM.drawString(this->getPosition(), this->testString, ae::Justification::Left, sf::Color::Black);
}
