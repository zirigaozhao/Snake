#include "Stage.h"
#include "Snake.h"

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
    for ( char& ch : _stage ) {
        if ( ch == '=' || ch == '*' ) {
            continue;
        }
        ch = '0';
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


void Stage::snakeIntoTheStage( Snake* snake ) {
    clearSnake( );
    for ( int i = 0; i < snake->getSnake( ).size( ); ++i ) {
        int idx = xYToIndx( snake->getSnake( )[ i ].x, snake->getSnake( )[ i ].y );
        char ch = '@';
        if ( i == 0 ) {
            ch = '%';
        }
        _stage[ idx ] = ch;
    }
}
