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
  SquareID dir = movingDir( destSq );         // get direction
  cout << "Queens traveling direction " << dir.first << " - " << dir.second << endl;


  /* Constrain movement directly forward or backward */
  if( currentLoc.second == destFile ){            // constant file
    if( isNotBlocked( destSq, currentLoc, dir, chessboard ) ){
      return true;                                // valid move
    }
  }
  /* Constrain movement to directly left or right */
  else if( currentLoc.first == destRank ){        // constant rank
    if( isNotBlocked( destSq, currentLoc, dir, chessboard ) ){
      return true;                                // valid move
    }
  }

  /* Constrain movement to diagonal */
  deltaRank = abs( destRank - currentLoc.first );
  deltaFile = abs( destFile - currentLoc.second );
  if( deltaRank == deltaFile ){
    if( isNotBlocked( destSq, currentLoc, dir, chessboard ) ){
      cout << "Queen can move to position" << destRank << " - " << destFile << endl;
      return true;                  // valid move
    }
  }
 
  /* Otherwise, move is illegal */ 
  return false;
}
