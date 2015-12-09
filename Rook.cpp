# include <iostream>
# include <string> /* std::string */
# include <utility>
# include <map>

# include "Rook.h"
# include "Types.h"
# include "ChessPiece.h"


using namespace std;

Rook::Rook( colour_t _col, string _cp, SquareID _loc )
          : ChessPiece( _col, _cp, _loc )
{}

bool Rook::tryMove( SquareID destSq, const Board &chessboard )
{
  int destRank, destFile;
  destRank = destSq.first;  destFile = destSq.second;  
  string dir = movingDir( destSq );     // find direction to dest


  /* Constrain movement to directly forward or backward */
  if( currentLoc.second == destFile ){            // constant file
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;                                // valid move
    }
  }
  
  /* Constrain movement to left or right */
  else if( currentLoc.first == destRank ){        // constant rank
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;                                // valid move
    }
  }

  /* Otherwise, move is illegal*/
  return false;
}

Rook::~Rook(){}
