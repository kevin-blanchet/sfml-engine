#pragma once

#include "Event.h"

#pragma warning(push, 0)
#include <SFML/Window/Keyboard.hpp>
#pragma warning(pop)

namespace ae {

enum class KeyboardEventAction {
    UndefinedKeyboardAction = -1,
    KeyPressed,
    KeyReleased,
};

namespace Keyboard {

enum class Key {
	Unknown = -1,
	A = 0,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Num0,
	Num1,
	Num2,
	Num3,
	Num4,
	Num5,
	Num6,
	Num7,
	Num8,
	Num9,
	Escape,
	LControl,
	LShift,
	LAlt,
	LSystem,
	RControl,
	RShift,
	RAlt,
	RSystem,
	Menu,
	LBracket,
	RBracket,
	Semicolon,
	Comma,
	Period,
	Quote,
	Slash,
	Backslash,
	Tilde,
	Equal,
	Hyphen,
	Space,
	Enter,
	Backspace,
	Tab,
	PageUp,
	PageDown,
	End,
	Home,
	Insert,
	Delete,
	Add,
	Subtract,
	Multiply,
	Divide,
	Left,
	Right,
	Up,
	Down,
	Numpad0,
	Numpad1,
	Numpad2,
	Numpad3,
	Numpad4,
	Numpad5,
	Numpad6,
	Numpad7,
	Numpad8,
	Numpad9,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	F13,
	F14,
	F15,
	Pause,

	KeyCount,

	// Deprecated values:

	Dash = Hyphen,
	BackSpace = Backspace,
	BackSlash = Backslash,
	SemiColon = Semicolon,
	Return = Enter
};

} // namespace Keyboard

class KeyboardEvent :
    public Event
{
public:
    KeyboardEvent();

    void setKey(Keyboard::Key newKey);
    Keyboard::Key getKey() const;

    void setKeyboardAction(KeyboardEventAction newAction);
    KeyboardEventAction getKeyboardAction() const;
private:
    Keyboard::Key key;
    KeyboardEventAction action;
};

Keyboard::Key sfKeyToAeKey(sf::Keyboard::Key sfKey);

} // namespace ae