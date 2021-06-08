#include "Controller.h"
#include "conio.h"
#include <thread>

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ENTER = 13;

Controller::Controller( ) {
	_key = KEY::NONE;
	_time = 0;
}

Controller::~Controller( ) {
}

void Controller::update( ) {
	++_time;
	//std::thread t1( inputProcess( ) );
}

void Controller::inputProcess( ) {
	_key = KEY::NONE;
	switch ( _getch( ) ) {
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
