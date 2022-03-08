#pragma once

#include "Event.h"
#include "Vector2.h"

#pragma warning(push, 0)
#include <SFML/Window/Mouse.hpp>
#pragma warning(pop)

namespace ae {

enum class MouseEventAction {
    UndefinedMouseAction = -1,
    Pressed,
    Released,
    Moved,
};

namespace Mouse {

enum class Button {
    Undefined = -1,
    Left,
    Right,
    Middle,
    XButton1,
    XButton2,

    ButtonCount
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

Mouse::Button sfButtonToAeButton(sf::Mouse::Button sfButton);

} // namespace ae