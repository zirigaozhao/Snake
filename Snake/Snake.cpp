#include "Snake.h"

Snake::Snake( /*Stage& stage*/ )/* :
_stage( &stage )*/{
	_snake = new Snake::Snake_type;
	initSnake();
}

Snake::~Snake( ) {
	free( );
}

void Snake::snakeMove( ) {
	//通过更改指针所指向的地址更换坐标
	Snake_type::iterator iter = _snake->begin( );
	Snake_type::iterator end_iter = _snake->end( );
	SNAKE_BASE* temp = new SNAKE_BASE( );
	for ( ; iter != _snake->end( ); ++iter ) {
		if ( iter == _snake->begin( ) ) {
			temp->x = Head( *iter )->x;
			temp->y = Head( *iter )->y;
			snakeMoveProcess( *iter );
			continue;
		}
		changeBodyXY( iter, temp );
	}
	delete temp;

	/*Snake_type::iterator it = _snake.begin( );
	for ( ; it != _snake.end( ); it++ ) {
		snakeMoveProcess( **it );
	}*/
}

void Snake::snakeEat( ) {
	SNAKE_BODY* snake = new SNAKE_BODY( );
	//snakeGrowthProcess( *snake );
	_snake->push_back( snake );
}

Snake::Snake_type Snake::getSnake( ) const {
	return *_snake;
}

Snake::DIR& Snake::setMoveDir( ) {
	return Head( _snake->at( 0 ) )->dir;
}

Snake::DIR Snake::getMoveDir( ) const {
	return Head( _snake->at( 0 ) )->dir;
}

int Snake::moveTarget( ) const {
	return moveTargetXYToIdx(  *Head( _snake->at( 0 ) ) );
}

void Snake::initSnake( ) {
	int init_width = /*_stage->getStageWidth( )*/17 / 2;
	int init_height = /*_stage->getStageHeight( )*/17 / 2;
	for ( int i = 0; i < 3; ++i ) {
		if ( i == 0 ) {
			SNAKE_HEAD* snake_head = new SNAKE_HEAD( );
			snake_head->x = init_width;
			snake_head->y = init_height;
			snake_head->dir = DIR::RIGHT;
			_snake->push_back( snake_head );
		} else {
			SNAKE_BODY* snake_body = new SNAKE_BODY( );
			snake_body->x = init_width - i;
			snake_body->y = init_height;
			_snake->push_back( snake_body );
		}
	}
}


int Snake::xYToStageIdx( int& x, int& y ) const {
	return y * 17 + x;
}

void Snake::snakeMoveProcess( SNAKE_BASE* snake ) {
	//需要重写，只对蛇头做xy位移剩下的做xy拷贝处理
	switch ( Head( snake )->dir ) 	{
	case DIR::UP:
		--Head( snake )->y;
		break;
	case DIR::DOWN:
		++Head( snake )->y;
		break;
	case DIR::LEFT:
		--Head( snake )->x;
		break;
	case DIR::RIGHT:
		++Head( snake )->x;
		break;
	default:
		break;
	}
}

/*void Snake::snakeGrowthProcess( SNAKE_BASE& snake ) {
	//添加蛇身
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
*/
/*void Snake::snakeBodyLinkProcess( ) {
	//如果实现拷贝移动本函数废弃
	//遍历蛇的身体（不包括蛇头）
	for ( unsigned int i = 1; i < _snake.size( ); ++i ) {
		if ( isChangeDir( _snake[ i ] ) ) {
			//让当前身段和前一节身段移动方向相同
			_snake[ i ].dir = _snake[ i - 1 ].dir;
		}
	}
}
*/
int Snake::moveTargetXYToIdx( const SNAKE_HEAD& snake ) const {
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

void Snake::changeBodyXY( Snake_type::iterator& base1, SNAKE_BASE* base2) {
	SNAKE_BASE* t = new SNAKE_BASE;
	if ( base1 != _snake->end( ) ) {
		t->x = Body( *base1 )->x;
		t->y = Body( *base1 )->y;
	}
	Body( *base1 )->x = Body( base2 )->x;
	Body( *base1 )->y = Body( base2 )->y;
	if ( base1 != _snake->end( ) ) {
		Body( base2 )->x = t->x;
		Body( base2 )->y = t->y;
	}
	delete t;
}

/*bool Snake::isChangeDir( SNAKE& snake ) {
	int idx = moveTargetXYToIdx( snake );
	if ( !isHaveBody( idx ) ) {
		return true;
	}
	return false;
}
*/
/*bool Snake::isHaveBody( int& idx ) {
	for ( SNAKE& snake : _snake ) {
		int target_idx = xYToStageIdx( snake.x, snake.y );
		if ( idx == target_idx ) {
			return true;
		}
	}
	return false;
}
*/
void Snake::free( ) {
	Snake_type::iterator iter = _snake->begin( );
	while ( iter != _snake->end( ) ) 	{
		delete* iter;
		_snake->erase( iter );
		iter++;
	}
	delete _snake;
}
