#include "Controller.h"
#include "conio.h"

const int UP    = 72;
const int DOWN  = 80;
const int LEFT  = 75;
const int RIGHT = 77;
const int ENTER = 13;

Controller::Controller( ) {
	_key = KEY::NONE;
}

Controller::~Controller( ) {
}

void Controller::update( ) {
	inputProcess( );
}

inline Controller::KEY Controller::getHitKey( ) const {
	return _key;
}

void Controller::inputProcess( ) {
	_key = KEY::NONE;
	switch ( getch( ) ) {
	case UP:
		_key = KEY::UP;
		break;
	case DOWN:
		_key = KEY::DOWN;
		break;
	case LEFT:
		_key = KEY::LEFT;
		break;
	case RIGHT:
		_key = KEY::RIGHT;
		break;
	default:
		_key = KEY::NONE;
		break;
	}
}
