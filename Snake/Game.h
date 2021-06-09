#pragma once
#include "Controller.h"
#include "ViewStage.h"
#include "Stage.h"
#include "Snake.h"
#include "BaseClass.h"
#include <list>

class Controller;

class Game {
public:
	Game( Controller* controller, ViewStage* viewStage, Stage* stage, Snake* snake );
	virtual ~Game( );
public:
	void update( );
private:
	void drawStage( ) const;
	void snakeProcess( );
	void stageProcess( );
	void snakeMoveProcess( );
	void inputProcess( );
	void collisionProcess( );
private:
	Controller* _controller;
	ViewStage* _view_stage;
	Stage* _stage;
	Snake* _snake;
	std::list<BaseClass*> _list;
};

