#include <iostream>
#include "Game.h"
#include "Stage.h"
#include "Snake.h"
#include "Controller.h"
#include "ViewStage.h"

int main( void ) {
	Stage* stage = new Stage( );
	Snake* snake = new Snake( );
	Controller* controller = new Controller( );
	ViewStage* view_stage = new ViewStage( stage );
	Game* game = new Game( controller, view_stage, stage, snake );

	while ( true ) 	{
		system( "cls" );
		game->update( );
	}

	delete game;
	delete controller;
	delete snake;
	delete stage;

	return 0;
}