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
	_snake.push_back( snake );
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

int Snake::moveTarget( ) const {
	return moveTargetXYToIdx( _snake[ 0 ] );
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


int Snake::xYToStageIdx( int& x, int& y ) const {
	return y * 17 + x;
}

void Snake::snakeMoveProcess( SNAKE& snake ) {
	//需要重写，只对蛇头做xy位移剩下的做xy拷贝处理
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
	snake.x = iter->x;
	snake.y = iter->y;
	switch ( iter->dir ) 	{
	case DIR::UP:
		snake.y += 1;
		break;
	case DIR::DOWN:
		snake.y -= 1;
		break;
	case DIR::LEFT:
		snake.x += 1;
		break;
	case DIR::RIGHT:
		snake.x -= 1;
		break;
	default:
		break;
	}
	snake.dir = iter->dir;
}

void Snake::snakeBodyLinkProcess( ) {
	//遍历蛇的身体（不包括蛇头）
	for ( unsigned int i = 1; i < _snake.size( ); ++i ) {
		if ( isChangeDir( _snake[ i ] ) ) {
			//让当前身段和前一节身段移动方向相同
			_snake[ i ].dir = _snake[ i - 1 ].dir;
		}
	}
}

int Snake::moveTargetXYToIdx( const SNAKE& snake ) const {
	int idx = -1;
	int x = snake.x;
	int y = snake.y;
	switch ( snake.dir ) {
	case DIR::UP:
		--y;
		break;
	case DIR::DOWN:
		++y;
		break;
	case DIR::LEFT:
		--x;
		break;
	case DIR::RIGHT:
		++x;
		break;
	default:
		break;
	}

	idx = xYToStageIdx( x, y );

	if ( idx < 0 ) {
		throw( "坐标错误！！" );
	}
	return idx;
}

bool Snake::isChangeDir( SNAKE& snake ) {
	int idx = moveTargetXYToIdx( snake );
	if ( !isHaveBody( idx ) ) {
		return true;
	}
	return false;
}

bool Snake::isHaveBody( int& idx ) {
	for ( SNAKE& snake : _snake ) {
		int target_idx = xYToStageIdx( snake.x, snake.y );
		if ( idx == target_idx ) {
			return true;
		}
	}
	return false;
}
