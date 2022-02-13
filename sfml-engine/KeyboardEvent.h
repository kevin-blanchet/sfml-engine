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

/*enum class Key2 {
    Undefined = -1,
    Space = 0, Enter, Backspace, Escape, Tab, Pause,
    Left, Right, Up, Down,
    PageUp, PageDown, End, Home, Insert, Delete,
    LControl, RControl, LShift, RShift, LAlt, RAlt,
    Backslash, Comma, Period, Slash,
    Semicolon, Quote, Tilde,
    LBracket, RBracket,
    Equal, Hyphen,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, H, J, K, L, Z, X, C, V, B, N, M,
    Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,
    Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9, Numpad0,
    Add, Substract, Multiply, Divide,
    KeyCount,
};*/
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
/*Keyboard::Key sfKeyToAeKey2(sf::Keyboard::Key sfKey) {
	switch (sfKey)
	{
	case sf::Keyboard::A:
		return Keyboard::Key::A;
	case sf::Keyboard::B:
		return Keyboard::Key::B;
	case sf::Keyboard::C:
		return Keyboard::Key::C;
	case sf::Keyboard::D:
		return Keyboard::Key::D;
	case sf::Keyboard::E:
		return Keyboard::Key::E;
	case sf::Keyboard::F:
		return Keyboard::Key::F;
	case sf::Keyboard::G:
		return Keyboard::Key::G;
	case sf::Keyboard::H:
		return Keyboard::Key::H;
	case sf::Keyboard::I:
		return Keyboard::Key::I;
	case sf::Keyboard::K:
		return Keyboard::Key::K;
	case sf::Keyboard::L:
		return Keyboard::Key::L;
	case sf::Keyboard::M:
		return Keyboard::Key::M;
	case sf::Keyboard::N:
		return Keyboard::Key::N;
	case sf::Keyboard::O:
		return Keyboard::Key::O;
	case sf::Keyboard::P:
		return Keyboard::Key::P;
	case sf::Keyboard::Q:
		return Keyboard::Key::Q;
	case sf::Keyboard::R:
		return Keyboard::Key::R;
	case sf::Keyboard::S:
		return Keyboard::Key::S;
	case sf::Keyboard::T:
		return Keyboard::Key::T;
	case sf::Keyboard::U:
		return Keyboard::Key::U;
	case sf::Keyboard::V:
		return Keyboard::Key::V;
	case sf::Keyboard::W:
		return Keyboard::Key::W;
	case sf::Keyboard::X:
		return Keyboard::Key::X;
	case sf::Keyboard::Y:
		return Keyboard::Key::Y;
	case sf::Keyboard::Z:
		return Keyboard::Key::Z;
	case sf::Keyboard::Num0:
		return Keyboard::Key::Num0;
	case sf::Keyboard::Num1:
		return Keyboard::Key::Num1;
	case sf::Keyboard::Num2:
		return Keyboard::Key::Num2;
	case sf::Keyboard::Num3:
		return Keyboard::Key::Num3;
	case sf::Keyboard::Num4:
		return Keyboard::Key::Num4;
	case sf::Keyboard::Num5:
		return Keyboard::Key::Num5;
	case sf::Keyboard::Num6:
		return Keyboard::Key::Num6;
	case sf::Keyboard::Num7:
		return Keyboard::Key::Num7;
	case sf::Keyboard::Num8:
		return Keyboard::Key::Num8;
	case sf::Keyboard::Num9:
		return Keyboard::Key::Num9;
	case sf::Keyboard::Numpad1:
		return Keyboard::Key::Numpad1;
	case sf::Keyboard::Numpad2:
		return Keyboard::Key::Numpad2;
	case sf::Keyboard::Numpad3:
		return Keyboard::Key::Numpad3;
	case sf::Keyboard::Numpad4:
		return Keyboard::Key::Numpad4;
	case sf::Keyboard::Numpad5:
		return Keyboard::Key::Numpad5;
	case sf::Keyboard::Numpad6:
		return Keyboard::Key::Numpad6;
	case sf::Keyboard::Numpad7:
		return Keyboard::Key::Numpad7;
	case sf::Keyboard::Numpad8:
		return Keyboard::Key::Numpad8;
	case sf::Keyboard::Numpad9:
		return Keyboard::Key::Numpad9;
	case sf::Keyboard::Numpad0:
		return Keyboard::Key::Numpad0;
	case sf::Keyboard::Escape:
		return Keyboard::Key::Escape;
	case sf::Keyboard::LControl:
		return Keyboard::Key::LControl;
	case sf::Keyboard::RControl:
		return Keyboard::Key::RControl;
	case sf::Keyboard::LShift:
		return Keyboard::Key::LShift;
	case sf::Keyboard::RShift:
		return Keyboard::Key::RShift;
	case sf::Keyboard::LAlt:
		return Keyboard::Key::LAlt;
	case sf::Keyboard::RAlt:
		return Keyboard::Key::RAlt;
	case sf::Keyboard::LBracket:
		return Keyboard::Key::LBracket;
	case sf::Keyboard::RBracket:
		return Keyboard::Key::RBracket;
	case sf::Keyboard::Semicolon:
		return Keyboard::Key::Semicolon;
	case sf::Keyboard::Comma:
		return Keyboard::Key::Comma;
	case sf::Keyboard::Period:
		return Keyboard::Key::Period;
	case sf::Keyboard::Quote:
		return Keyboard::Key::Quote;
	case sf::Keyboard::Slash:
		return Keyboard::Key::Slash;
	case sf::Keyboard::Backslash:
		return Keyboard::Key::Backslash;
	case sf::Keyboard::Tilde:
		return Keyboard::Key::Tilde;
	case sf::Keyboard::Equal:
		return Keyboard::Key::Equal;
	case sf::Keyboard::Hyphen:
		return Keyboard::Key::Hyphen;
	case sf::Keyboard::Space:
		return Keyboard::Key::Space;
	case sf::Keyboard::Enter:
		return Keyboard::Key::Enter;
	case sf::Keyboard::Backspace:
		return Keyboard::Key::Backspace;
	case sf::Keyboard::Tab:
		return Keyboard::Key::Tab;
	case sf::Keyboard::PageUp:
		return Keyboard::Key::PageUp;
	case sf::Keyboard::PageDown:
		return Keyboard::Key::PageDown;
	case sf::Keyboard::End:
		return Keyboard::Key::End;
	case sf::Keyboard::Home:
		return Keyboard::Key::Home;
	case sf::Keyboard::Insert:
		return Keyboard::Key::Insert;
	case sf::Keyboard::Delete:
		return Keyboard::Key::Delete;
	case sf::Keyboard::Add:
		return Keyboard::Key::Add;
	case sf::Keyboard::Subtract:
		return Keyboard::Key::Substract;
	case sf::Keyboard::Multiply:
		return Keyboard::Key::Multiply;
	case sf::Keyboard::Divide:
		return Keyboard::Key::Divide;
	case sf::Keyboard::Left:
		return Keyboard::Key::Left;
	case sf::Keyboard::Right:
		return Keyboard::Key::Right;
	case sf::Keyboard::Up:
		return Keyboard::Key::Up;
	case sf::Keyboard::Down:
		return Keyboard::Key::Down;
	case sf::Keyboard::F1:
		return Keyboard::Key::F1;
	case sf::Keyboard::F2:
		return Keyboard::Key::F2;
	case sf::Keyboard::F3:
		return Keyboard::Key::F3;
	case sf::Keyboard::F4:
		return Keyboard::Key::F4;
	case sf::Keyboard::F5:
		return Keyboard::Key::F5;
	case sf::Keyboard::F6:
		return Keyboard::Key::F6;
	case sf::Keyboard::F7:
		return Keyboard::Key::F7;
	case sf::Keyboard::F8:
		return Keyboard::Key::F8;
	case sf::Keyboard::F9:
		return Keyboard::Key::F9;
	case sf::Keyboard::F10:
		return Keyboard::Key::F10;
	case sf::Keyboard::F11:
		return Keyboard::Key::F11;
	case sf::Keyboard::F12:
		return Keyboard::Key::F12;
	case sf::Keyboard::Pause:
		return Keyboard::Key::Pause;
	default:
		return Keyboard::Key::Undefined;
		break;
	}
}*/

} // namespace ae