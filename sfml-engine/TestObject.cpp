#include "TestObject.h"
#include "DisplayManager.h"
#include "KeyboardEvent.h"
#include "SceneManager.h"

TestObject::TestObject()
{
	isMoveDown = false;
	isMoveLeft = false;
	isMoveRight = false;
	isMoveUp = false;

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
			if (ae::KeyboardEventAction::KeyPressed == kEvent->getKeyboardAction()) {
				isMoveDown = true;
				isMoveUp = false;
			}
			if (ae::KeyboardEventAction::KeyReleased == kEvent->getKeyboardAction()) {
				isMoveDown = false;
			}
		}
		if (kEvent->getKey() == ae::Keyboard::Key::Right) {
			if (ae::KeyboardEventAction::KeyPressed == kEvent->getKeyboardAction()) {
				isMoveRight = true;
				isMoveLeft = false;
			}
			if (ae::KeyboardEventAction::KeyReleased == kEvent->getKeyboardAction()) {
				isMoveRight = false;
			}
		}
		if (kEvent->getKey() == ae::Keyboard::Key::Left) {
			if (ae::KeyboardEventAction::KeyPressed == kEvent->getKeyboardAction()) {
				isMoveLeft = true;
				isMoveRight = false;
			}
			if (ae::KeyboardEventAction::KeyReleased == kEvent->getKeyboardAction()) {
				isMoveLeft = false;
			}
		}
		if (kEvent->getKey() == ae::Keyboard::Key::Up) {
			if (ae::KeyboardEventAction::KeyPressed == kEvent->getKeyboardAction()) {
				isMoveUp = true;
				isMoveDown = false;
			}
			if (ae::KeyboardEventAction::KeyReleased == kEvent->getKeyboardAction()) {
				isMoveUp = false;
			}
		}
	}
	return false;
}

void TestObject::draw()
{
	DM.drawString(this->getPosition(), this->testString, ae::Justification::Left, sf::Color::Black);
}

void TestObject::update()
{
	float deltaTime = 0.33f;
	ae::Vector2 pos = this->getPosition();
	ae::Vector2 move = { 0, 0 };
	float speed = 20;

	if (isMoveDown) {
		move += { 0, 1 };
	}

	if (isMoveRight) {
		move += { 1, 0 };
	}

	if (isMoveLeft) {
		move += { -1, 0 };
	}

	if (isMoveUp) {
		move += { 0, -1 };
	}

	this->setPosition(pos + move * deltaTime * speed);
}
