#include "Stage.h"
#include "Snake.h"
#include "time.h"
#include <iostream>

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

void Stage::snakeHeadOrBody( const int& idx, Snake* snake, int& x, int& y ) {
    if ( idx == 0 ) {
        x = Head( snake->getSnake( ).at( 0 ) )->x;
        y = Head( snake->getSnake( ).at( 0 ) )->y;
    } else {
        x = Body( snake->getSnake( ).at( idx ) )->x;
        y = Body( snake->getSnake( ).at( idx ) )->y;
    }
}


void Stage::snakeIntoTheStage( Snake* snake ) {
    clearSnake( );
    for ( unsigned int i = 0; i < snake->getSnake( ).size( ); ++i ) {
        int x = -1;
        int y = -1;
        snakeHeadOrBody( i, snake, x, y );
        if ( x < 0 || y < 0 ) {
            std::domain_error( "蛇类内坐标数据异常！！" );
        }
        int idx = xYToIndx( x, y );
        char ch = '@';
        if ( i == 0 ) {
            ch = '%';
        }
        _stage[ idx ] = ch;
    }
}

void Stage::produceFruits( ) {
    srand( ( unsigned int )time( NULL ) );
    int idx;
    do {
        idx = rand( ) % ( _width * _height );
    } while ( _stage[ idx ] != '0' );
    _stage[ idx ] = '*';
}
