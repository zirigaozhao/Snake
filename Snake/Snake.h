#pragma once
#include "Stage.h"
#include <vector>

class Snake {
public:
	enum class DIR 	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};

	struct SNAKE 	{
		int x;
		int y;
		DIR dir;
	};
private:
	typedef std::vector<SNAKE> Snake_type;
public:
	Snake( /*Stage& stage*/ );
	virtual ~Snake( );
public:
	void snakeMove( );
	void snakeEat( );
	Snake_type getSnake( ) const;
	DIR& setMoveDir( );
	DIR getMoveDir( ) const;
private:
	void initSnake( );
	void snakeMoveProcess( SNAKE& snake );
	void snakeGrowthProcess( SNAKE& snake );
private:
	Snake_type _snake;
	/*Stage* _stage;*/
};

