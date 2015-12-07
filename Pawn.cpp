# include <iostream>
# include <string> /* std::string */
# include <utility> /* std::pair::first, std::pair::second*/

# include "Pawn.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Pawn::Pawn( colour_t _col, string _cp, SquareID _loc )
          : ChessPiece( _col, _cp, _loc )
{}

bool Pawn::tryMove( SquareID destSq, const Board &chessboard )
{
  int destRank;
  destRank = destSq.first;

  if( colour == WHITE && currentLoc.first == 2 ){ // WHITE Pawn at start
    if( destRank == 3 || destRank == 4 ){         // can move two places
      return true;                                // return move valid
    }
  }

  else if( colour == BLACK && currentLoc.first == 7 ){//BLACK Pawn at start
    if( destRank == 6 || destRank == 5 ){             // can move two sq's 
      return true;                                    // return move valid
    }
  } 
  
  else if( destRank == ( currentLoc.first+1 ) ){  // if anywhere else
    return true;                                  // move one sq
  }

  // else
  return false;                                   // no other legal move
}

Pawn::~Pawn(){}
/* Destructor for Pawn*/
