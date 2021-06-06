#pragma once

class Controller {
public:
	enum class KEY 	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};
public:
	Controller( );
	virtual ~Controller( );
public:
	void update( );
	KEY getHitKey( ) const;
private:
	void inputProcess( );
private:
	KEY _key;
};

