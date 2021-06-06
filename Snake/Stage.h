#pragma once
#include <vector>
#include "Snake.h"

class Stage {
typedef std::vector<char> Stage_type;
public:
	Stage( );
	virtual ~Stage( );
public:
	int getStageWidth( ) const;
	int getStageHeight( ) const;
	Stage_type getStage( ) const;
private:
	void initStage( );
	void clearSnake( );
	int xYToIndx( const int& x, const int& y );
	char& getClipOfStage( const int& x, const int& y );
	Stage& operator+=( Snake& snake );
private:
	Stage_type _stage;
	int _width;
	int _height;
};

