#pragma once
#include <vector>

class Snake;

class Stage {
typedef std::vector<char> Stage_type;
public:
	Stage( );
	virtual ~Stage( );
public:
	int getStageWidth( ) const;
	int getStageHeight( ) const;
	Stage_type getStage( ) const;
	void snakeIntoTheStage( Snake* snake );
	void produceFruits( );
private:
	void initStage( );
	void clearSnake( );
	int xYToIndx( const int& x, const int& y );
	char& getClipOfStage( const int& x, const int& y );
private:
	Stage_type _stage;
	int _width;
	int _height;
};

