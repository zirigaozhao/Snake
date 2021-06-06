#include "Snake.h"

Snake::Snake( Stage* stage ) :
_stage( stage ){
	initSnake();
}

Snake::~Snake( ) {
}

void Snake::snakeMove( ) {
	Snake_type::iterator it = _snake.begin( );
	for ( ; it != _snake.end( ); it++ ) {

	}
}

void Snake::snakeEat( ) {
}

Snake::Snake_type Snake::getSnake( ) const {
	return _snake;
}

void Snake::initSnake( ) {
	int init_width = _stage->getStageWidth( ) / 2;
	int init_height = _stage->getStageHeight( ) / 2;
	for ( int i = 0; i < 3; ++i ) {
		SNAKE snake;
		snake.x = init_width - i;
		snake.y = init_height;
		snake.dir = DIR::RIGHT;
		_snake.push_back( snake );
	}
}

void Snake::snakeMoveProcess( SNAKE& snake ) {
	switch ( snake.dir ) 	{
	case DIR::UP:
		--snake.y;
		break;
	case DIR::DOWN:
		++snake.y;
		break;
	case DIR::LEFT:
		++snake.x;
		break;
	case DIR::RIGHT:
		--snake.x;
		break;
	default:
		break;
	}
}
