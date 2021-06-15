#pragma once
#include "Stage.h"
#include <vector>

/***
修改，以当前设计更改移动函数
只对蛇头做方向更改并根据方向做xy变更
***/

class Snake {
public:
	enum class DIR 	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};
	struct SNAKE_BASE {
		int x;
		int y;
	};

	struct SNAKE_HEAD : public SNAKE_BASE {
		int x;
		int y;
		DIR dir;
	};

	struct SNAKE_BODY : public SNAKE_BASE {
		int x;
		int y;
	};
private:
	typedef std::vector<SNAKE_BASE*> Snake_type;
	//typedef static_cast< SNAKE_HEAD* > Head;
#define Head static_cast< Snake::SNAKE_HEAD* >
#define Body static_cast< Snake::SNAKE_BODY* >
public:
	Snake( /*Stage& stage*/ );
	virtual ~Snake( );
public:
	void snakeMove( );
	void snakeEat( );
	Snake_type getSnake( ) const;
	DIR& setMoveDir( );
	DIR getMoveDir( ) const;
	int moveTarget( ) const;
	//void snakeBodyLinkProcess( );
private:
	void initSnake( );
	int xYToStageIdx( int& x, int& y ) const;
	void snakeMoveProcess( SNAKE_BASE* snake );
	//void snakeGrowthProcess( SNAKE_BASE& snake );
	int moveTargetXYToIdx( const SNAKE_HEAD& snake ) const;
	//bool isChangeDir( SNAKE_BASE& snake );
	//bool isHaveBody( int& idx );
	//蛇节之间坐标交替
	void changeBodyXY( Snake_type::iterator& base1, SNAKE_BASE* base2 );
	void free( );
private:
	Snake_type* _snake;
	/*Stage* _stage;*/
};

