#include "Stage.h"

const int STAGE_WIDTH = 17;
const int STAGE_HEIGHT = 17;

const char STAGE[ STAGE_HEIGHT * STAGE_WIDTH + 1 ] = { "================="
                                                       "=000000000000000="
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "=000000000000000=" 
                                                       "================="};

Stage::Stage( ) :
_width( STAGE_WIDTH ),
_height( STAGE_HEIGHT ) {
    initStage( );
}

Stage::~Stage( ) {

}

int Stage::getStageWidth( ) const {
    return _width;
}

int Stage::getStageHeight( ) const {
    return _height;
}

Stage::Stage_type Stage::getStage( ) const {
    return _stage;
}

void Stage::initStage( ) {
    for ( char ch : STAGE ) {
        _stage.push_back( ch );
    }
}

void Stage::clearSnake( ) {
    Stage_type::iterator iter     = _stage.begin( );
    Stage_type::iterator iter_end = _stage.end( );
    while ( iter != iter_end ) 	{
        if ( *iter == '=' ||
             *iter == '*') {
            continue;
        }
        *iter = '0';
        ++iter;
    }
}

inline int Stage::xYToIndx( const int& x, const int& y ) {
    int idx = y * getStageWidth( ) + x;
    return idx;
}

char& Stage::getClipOfStage( const int& x, const int& y ) {
    int idx = xYToIndx( x, y );
    return _stage[ idx ];
}


Stage& Stage::operator+=( Snake& snake ) {
    clearSnake( );
    for ( int i = 0; i < snake.getSnake( ).size( ); ++i ) {
        int x = snake.getSnake( )[ i ].x;
        int y = snake.getSnake( )[ i ].y;
    }
}
