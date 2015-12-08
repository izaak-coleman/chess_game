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
  int destRank, destFile;
  destRank = destSq.first; destFile = destSq.second;

  cout << "Reached in here. currentLoc is " << currentLoc.first << " "
       << currentLoc.second << endl;

  if( colour == WHITE && currentLoc.first == 2 ){ // WHITE Pawn at start
    if( destRank == 3 || destRank == 4 ){         // can move two places
    cout << "White pawn returned true " << endl;
      return true;                                // return move valid
    }
  }

  else if( colour == BLACK && currentLoc.first == 7 ){//BLACK Pawn at start
    if( destRank == 6 || destRank == 5 ){             // can move two sq's 
      return true;                                    // return move valid
    }
  } 
  
  else if( destRank == ( currentLoc.first+1 ) &&     // if anywere but start
           chessboard[ destSq ].second == NULL ){    // move forward if empty
      return true;   
  }

  else if( destRank == ( currentLoc.first+1 ) &&     // if diagonaly forward
         ( destFile == currentLoc.second-1 ||        // and 
           destFile == currentLoc.decont+1 ){        
      return true;
  }

  // else
  return false;                                   // no other legal move
}

Pawn::~Pawn(){}
/* Destructor for Pawn*/
