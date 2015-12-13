// ChessPiece.cpp

# include <iostream>
# include <string>
# include <map>
# include <utility>
# include <string>

# include "Types.h"
# include "ChessPiece.h"

static const int UP = 1;
static const int DOWN = -1;
static const int RIGHT = 1;
static const int LEFT = -1;

using namespace std;

ChessPiece::ChessPiece( colour_t _col, string _cp, SquareID _loc )
: colour( _col ), currentLoc( _loc ), charpiece( _cp )
{}

colour_t ChessPiece::getColour()
{
  return colour;
}

SquareID ChessPiece::getCurrentLoc()
{
  return currentLoc;
}

void ChessPiece::setCurrentLoc( SquareID destSq )
{
  currentLoc = destSq;
}



bool ChessPiece::isNotBlocked( const SquareID destSq, SquareID nextSq, 
                               const SquareID direction, const Board &chessboard )
{
  
  /* If reached destination, return true */
  if( destSq == nextSq ){
    return true;
  }
  
  /* Return false if out of range */
  if( nextSq.first == 9 || nextSq.second == 9 ||
      nextSq.first == 0 || nextSq.second == 0 ){
    return false;
  }

  /* Switch to stop recursive function checking the start location */
  bool start = false;
  if( nextSq == currentLoc ){
      start = true;
  }

  /* Return false if square we are checking contains a piece*/
  if( chessboard.find( nextSq )->second != NULL && start != true ) {
    return false;
  }
  
  /* Iterate to the next square*/ 
  nextSq.first += direction.first;  nextSq.second += direction.second;
  if( isNotBlocked( destSq, nextSq, direction, chessboard) ){
    return true;
  }

  return false;
}

SquareID ChessPiece::movingDir( SquareID destSq )
{
  int destRank = destSq.first;
  int destFile = destSq.second;

  if( destRank > currentLoc.first ){                // traveling forwards ...

    if( destFile == currentLoc.second ){
      SquareID direction ( UP, 0 );
      return direction;
    
    } 
    else if( destFile > currentLoc.second ){
      SquareID direction ( UP, RIGHT );                  // and to the right
      return direction;
    }
    else if( destFile < currentLoc.second ){
      SquareID direction ( UP, LEFT );                 // and to the left
      return direction;
    }
  }

  else if( destRank < currentLoc.first ){           // traveling backwards ...
    
    if( destFile == currentLoc.second ){
      SquareID direction ( DOWN, 0 ); 
      return direction;
    }
    else if( destFile > currentLoc.second ){
      SquareID direction ( DOWN, RIGHT );            // and to the right
      return direction;
    }
    else if( destFile < currentLoc.second ){
      SquareID direction ( DOWN, LEFT );             // and to the left
      return direction;
    }
  }
  
  /* Moving right */
  else if( (destRank == currentLoc.first) && (destFile > currentLoc.second) ){
    SquareID direction ( 0, RIGHT );
    return direction;
  }

  /* Moving left */
  else if( ( destRank == currentLoc.first) && (destFile < currentLoc.second) ){
    SquareID direction ( 0, LEFT );
    return direction;
  }
}

ChessPiece::~ChessPiece(){}
