#pragma once

#include "Event.h"
#include "Vector2.h"

namespace ae {

enum class MouseEventAction {
    UndefinedMouseAction = -1,
    Pressed,
    Released,
    Moved,
};

namespace Mouse {
enum class Button {
    Unedefined = -1,
    Left, Right, Middle,
    ButtonCount,
};
} // namespace Mouse

class MouseEvent :
    public Event
{
public:
    MouseEvent();

    void setButton(Mouse::Button newButton);
    Mouse::Button getButton() const;

    void setMouseAction(MouseEventAction newAction);
    MouseEventAction getMouseAction() const;

    void setMousePosition(Vector2 newPosition);
    Vector2 getMousePostion() const;
private:
    Mouse::Button button;
    MouseEventAction action;
    Vector2 position;
};

/*Mouse::Button sfButtonToAeButton(sf::Mouse::Button sfButton) {
	switch (sfButton)
	{
	case sf::Mouse::Left:
		return Mouse::Button::Left;
		break;
	case sf::Mouse::Right:
		return Mouse::Button::Right;
		break;
	case sf::Mouse::Middle:
		return Mouse::Button::Middle;
		break;
	default:
		return Mouse::Button::Unedefined;
		break;
	}
}*/

} // namespace ae