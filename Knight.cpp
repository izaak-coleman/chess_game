# include <iostream>
# include <string> /* std::string */
# include <cmath>
# include <utility>

# include "Knight.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Knight::Knight( colour_t _col, string _cp, SquareID _loc )
              : ChessPiece( _col, _cp, _loc )
{}

bool Knight::tryMove( SquareID destSq, const Board &chessboard )
{
  int deltaFile, deltaRank;

  /* get change in rank and file */
  deltaRank = abs( destSq.first - currentLoc.first );
  deltaFile = abs( destSq.second - currentLoc.second );
  
  /* Constrain to jump two ranks, and one file */
  if( deltaRank == 2 && deltaFile == 1 ){
    return true;
  }
  
  /* Constrain to jump one rank, and two files */
  else if( deltaRank == 1 && deltaFile == 2 ){
    return true;
  }

  return false;
}
