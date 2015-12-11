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
  SquareID dir = movingDir( destSq );     // get direction

  
  /* If WHITE Pawn and destination is empty */
  if( colour == WHITE && chessboard.find( destSq )->second == NULL ){ 

    /* If Pawn is at start position*/
    if( currentLoc.first == 2 && destRank == 4 && destFile == destSq.second ){

        if ( isNotBlocked( destSq, currentLoc, dir, chessboard) ){
          return true;
        }
      }

    /* Otherwise, can only move one square forward*/
    else if( ( destSq.first == currentLoc.first+1 ) &&
             ( destFile == currentLoc.second ) ){
      return true;
    }
  }


  /* If BLACK Pawn and dest is empty */
  if( colour == BLACK && chessboard.find( destSq )->second == NULL ){

    /* If Pawn is at start position, moving two spaces backward is valid */
    if( currentLoc.first == 7 && destRank == 5 && destFile == destSq.second ){

      if ( isNotBlocked( destSq, currentLoc, dir, chessboard) ){
        return true;
      }
    }

    /* Otherwise, can only move one place backward*/
    else if( ( destSq.first == currentLoc.first-1 ) &&
             ( destFile == currentLoc.second ) ) {
      return true;
    }
  } 

  /* Valid diag move if moved only one space and contains oposite colour */ 
  if( chessboard.find( destSq )->second != NULL && diagMov( destSq ) ){
      return true;
  }

  // else
  return false;                                   // no other legal move
}

bool Pawn::diagMov( SquareID destSq )
{
  /* If WHITE, can only move diagonaly forward one space*/
  if( colour == WHITE ){

    if( destSq.first == currentLoc.first+1 &&
        ( destSq.second == currentLoc.second-1 ||
          destSq.second == currentLoc.second+1 ) ){
      return true;
    }
  }

  /* if BLACK, can only move diagonaly backward one space*/
  else if( colour == BLACK ){

    if( destSq.first == currentLoc.first-1 && 
        ( destSq.second == currentLoc.second-1 ||
          destSq.second == currentLoc.second+1 ) ){
      return true;
    }
  }
  return false;       // invalid diagonal move
}

Pawn::~Pawn(){}
