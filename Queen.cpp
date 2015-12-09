# include <iostream>
# include <string> /* std::string */
# include <utility>
# include <cmath>

# include "Queen.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Queen::Queen( colour_t _col, string _cp, SquareID _loc )
            : ChessPiece( _col, _cp, _loc )
{}

bool Queen::tryMove( SquareID destSq, const Board &chessboard )
{
  int destRank, destFile, deltaRank, deltaFile;
  destRank = destSq.first;  destFile = destSq.second;
  string dir = movingDir( destSq );         // get direction


  /* Constrain movement directly forward or backward */
  if( currentLoc.second == destFile ){            // constant file
      cout << "Forward_Backward run" << endl;
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;                                // valid move
    }
  }
  /* Constrain movement to directly left or right */
  else if( currentLoc.first == destRank ){        // constant rank
      cout << "Left-Right run" << endl;
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;                                // valid move
    }
  }

  /* Constrain movement to diagonal */
  deltaRank = abs( destRank - currentLoc.first );
  deltaFile = abs( destFile - currentLoc.second );
  if( deltaRank == deltaFile ){
      cout << "Diagonal run" << endl;
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;                  // valid move
    }
  }
 
  /* Otherwise, move is illegal */ 
  return false;
}
