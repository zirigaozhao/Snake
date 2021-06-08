#include "ViewStage.h"
#include "stdio.h"

ViewStage::ViewStage( Stage* stage ) :
_stage( stage ) {
}

ViewStage::~ViewStage( ) {
}

void ViewStage::draw( ) const {
	drawStage( );
}

void ViewStage::drawStage( ) const {
	int size_stage = _stage->getStage( ).size( );
	int width_stage = _stage->getStageWidth( );
	for ( int i = 0; i < size_stage; ++i ) {
		if ( i != 0 && i % width_stage == 0 ) {
			printf( "\n" );
		}
		char ch = _stage->getStage( )[ i ];
		if ( ch == '0' ) {
			putchar( ' ' );
			continue;
		}
		putchar( ch );
	}
}
