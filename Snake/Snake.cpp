#include "Snake.h"

Snake::Snake( /*Stage& stage*/ )/* :
_stage( &stage )*/{
	initSnake();
}

Snake::~Snake( ) {
}

void Snake::snakeMove( ) {
	Snake_type::iterator it = _snake.begin( );
	for ( ; it != _snake.end( ); it++ ) {
		snakeMoveProcess( *it );
	}
}

void Snake::snakeEat( ) {
	SNAKE snake;
	snakeGrowthProcess( snake );
}

Snake::Snake_type Snake::getSnake( ) const {
	return _snake;
}

Snake::DIR& Snake::setMoveDir( ) {
	return _snake[ 0 ].dir;
}

Snake::DIR Snake::getMoveDir( ) const {
	return _snake[ 0 ].dir;
}

void Snake::initSnake( ) {
	int init_width = /*_stage->getStageWidth( )*/17 / 2;
	int init_height = /*_stage->getStageHeight( )*/17 / 2;
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
		--snake.x;
		break;
	case DIR::RIGHT:
		++snake.x;
		break;
	default:
		break;
	}
}

void Snake::snakeGrowthProcess( SNAKE& snake ) {
	Snake_type::iterator iter = _snake.end( );
	iter--;
	switch ( iter->dir ) 	{
	case DIR::UP:
		snake.y = iter->y + 1;
		break;
	case DIR::DOWN:
		snake.y = iter->y - 1;
		break;
	case DIR::LEFT:
		snake.x = iter->x - 1;
		break;
	case DIR::RIGHT:
		snake.x = iter->x + 1;
		break;
	default:
		break;
	}
	snake.dir = iter->dir;
}
