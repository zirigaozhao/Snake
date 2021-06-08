#pragma once
#include "Stage.h"

class ViewStage {
public:
	ViewStage( Stage* stage  );
	virtual ~ViewStage( );
public:
	void draw( ) const;
private:
	void drawStage( ) const;
private:
	Stage* _stage;
};

