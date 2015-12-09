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

void Rook::coutHello(){
  cout << "HELLLLLLLLLLLOOOOOO" << endl;
}

virtual bool Rook::tryMove( SquareID destSq, const Board &chessboard )
{
  cout << "Made it into the rook trymove " << endl;
  int destRank, destFile;
  destRank = destSq.first;  destFile = destSq.file;  
  string dir = movingDir( destSq );       // get direction of movement



  /* Rook can move directly forward or backward */
  if( currentLoc.second == destFile ){    // rank can be anywhere in range
  cout << "We made it to the forward move constraint " << endl;
    /* If path to destSq not blocked, return valid move*/
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;
    }
  }
  
  /* Rook can move left or right */
  else if( currentLoc.first == destRank ){ // file can be anywhere in range

    /* If path to destSq not blocked, return valid move*/
    if( isNotBlocked( destSq, currentLoc, chessboard, dir ) ){
      return true;
    }
  }

  /* Otherwise, Move is illegal*/

  return false;
}

Rook::~Rook(){}
