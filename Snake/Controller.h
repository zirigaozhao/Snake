#pragma once
#include "BaseClass.h"

const int TIME_TO_MOVE = 4;

class Controller : public BaseClass {
public:
	Controller( );
	virtual ~Controller( );
public:
	enum class KEY 	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};
public:
	void update( ) override;
	inline KEY getHitKey( ) const {
		return _key;
	}
	inline int isTimeToMove( ) const {
		return _time % TIME_TO_MOVE == 0;
	}
private:
	void inputProcess( );
private:
	KEY _key;
	unsigned int _time;
};

