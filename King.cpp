# include <iostream>
# include <string> /* std::string */
# include <cmath>

# include "King.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

King::King( colour_t _col, string _cp, SquareID _loc )
          : ChessPiece( _col, _cp, _loc )
{}

bool King::tryMove( SquareID destSq, const Board &chessboard )
{
  int deltaRank, deltaFile;
  deltaRank = abs( destSq.first - currentLoc.first );
  deltaFile = abs( destSq.second - currentLoc.second );

  /* Constrain movement to one space forward or backward */
  if( deltaRank == 1 && deltaFile == 0 ){
    return true;
  }

  /* Constrain movement to one space left or right */
  if( deltaRank == 0 && deltaFile == 1 ){
    return true;
  }
  /* Constrain movement to onespace diagonal */
  if( deltaRank == 1 && deltaFile == 1 ){
    return true;
  }
  
  return false;
}

King::~King(){}


