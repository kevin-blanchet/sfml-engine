#include "MouseEvent.h"

namespace ae {

MouseEvent::MouseEvent()
{
	this->setType("MouseEvent");
	this->setButton(Mouse::Button::Unedefined);
	this->setMouseAction(MouseEventAction::UndefinedMouseAction);
	this->setMousePosition({ 0, 0 });
}

void MouseEvent::setButton(Mouse::Button newButton)
{
	this->button = newButton;
}

Mouse::Button MouseEvent::getButton() const
{
	return this->button;
}

void MouseEvent::setMouseAction(MouseEventAction newAction)
{
	this->action = newAction;
}

MouseEventAction MouseEvent::getMouseAction() const
{
	return this->action;
}

void MouseEvent::setMousePosition(Vector2 newPosition)
{
	this->position = newPosition;
}

Vector2 MouseEvent::getMousePostion() const
{
	return this->position;
}

} // namespace ae