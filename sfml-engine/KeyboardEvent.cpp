#include "KeyboardEvent.h"

namespace ae {

KeyboardEvent::KeyboardEvent()
{
	setType("KeyboardEvent");
	this->setKey(Keyboard::Key::Unknown);
	this->setKeyboardAction(KeyboardEventAction::UndefinedKeyboardAction);
}

void KeyboardEvent::setKey(Keyboard::Key newKey)
{
	this->key = newKey;
}

Keyboard::Key KeyboardEvent::getKey() const
{
	return this->key;
}

void KeyboardEvent::setKeyboardAction(KeyboardEventAction newAction)
{
	this->action = newAction;
}

KeyboardEventAction KeyboardEvent::getKeyboardAction() const
{
	return this->action;
}

Keyboard::Key sfKeyToAeKey(sf::Keyboard::Key sfKey)
{
	return static_cast<Keyboard::Key>(sfKey);
}

} // namespace ae