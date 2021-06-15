#include "Game.h"

Game::Game( Controller* controller, ViewStage* viewStage, Stage* stage, Snake* snake ) :
_controller( controller ),
_view_stage( viewStage ),
_stage( stage ),
_snake( snake ) {
	_list.push_back( controller );
	_stage->snakeIntoTheStage( snake );
	_stage->produceFruits( );
}

Game::~Game( ) {
}

void Game::update( ) {
	inputProcess( );
	snakeProcess( );
	stageProcess( );
	drawStage( );
}

void Game::drawStage( ) const {
	_view_stage->draw( );
}

void Game::snakeProcess( ) {
	snakeMoveProcess( );
	//_snake->snakeBodyLinkProcess( );
	bool to_move = _controller->isTimeToMove( );
	if ( !to_move ) {
		return;
	}
	//collisionProcess( );
	_snake->snakeMove( );
}

void Game::stageProcess( ) {
	_stage->snakeIntoTheStage( _snake );
}

void Game::snakeMoveProcess( ) {
	Snake::DIR dir = _snake->getMoveDir( );
	Controller::KEY input_key = _controller->getHitKey( );
	switch ( input_key ) {
	case Controller::KEY::NONE:
		break;
	case Controller::KEY::UP:
		dir = Snake::DIR::UP;
		break;
	case Controller::KEY::DOWN:
		dir = Snake::DIR::DOWN;
		break;
	case Controller::KEY::LEFT:
		dir = Snake::DIR::LEFT;
		break;
	case Controller::KEY::RIGHT:
		dir = Snake::DIR::RIGHT;
		break;
	default:
		break;
	}
	_snake->setMoveDir( ) = dir;
}

void Game::inputProcess( ) {
	std::list<BaseClass*>::iterator iter = _list.begin( );
	while ( iter != _list.end( ) ) 	{
		( *iter )->update( );
		iter++;
	}
}

void Game::collisionProcess( ) {
	int snake_move_target = _snake->moveTarget( );
	switch ( _stage->getStage( )[ snake_move_target ] ) 	{
	case '*':
		_snake->snakeEat( );
		_stage->produceFruits( );
		break;
	default:
		break;
	}
}
