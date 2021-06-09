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
	int moveTarget( ) const;
	void snakeBodyLinkProcess( );
private:
	void initSnake( );
	int xYToStageIdx( int& x, int& y ) const;
	void snakeMoveProcess( SNAKE& snake );
	void snakeGrowthProcess( SNAKE& snake );
	int moveTargetXYToIdx( const SNAKE& snake ) const;
	bool isChangeDir( SNAKE& snake );
	bool isHaveBody( int& idx );
private:
	Snake_type _snake;
	/*Stage* _stage;*/
};

