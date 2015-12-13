# include <iostream>
# include <string> /* std::string */
# include <cmath>
# include <utility>

# include "Bishop.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Bishop::Bishop( colour_t _col, string _cp, SquareID _loc)
              : ChessPiece( _col, _cp, _loc )
{}

bool Bishop::tryMove( SquareID destSq, const Board &chessboard )
{
  int destRank, destFile;
  destRank = destSq.first;  destFile = destSq.second;
  SquareID dir = movingDir( destSq );         // find direction to dest

  /* Get change in rank and file*/
  int deltaRank, deltaFile;
  deltaRank = abs( destRank - currentLoc.first );   // get change in rank
  deltaFile = abs( destFile - currentLoc.second );  // get change in file
  
  /* Constrain movement to diagonal only */
  if( deltaRank == deltaFile ){
    if( isNotBlocked( destSq, currentLoc, dir, chessboard ) ){
      return true;                  // valid move
    }
  }
  
  /* Otherwise, move was illegal */
  return false;
}

Bishop::~Bishop(){}
