# include <iostream>
# include <string> /* std::string */

# include "King.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

King::King( colour_t _col, string _cp, SquareID _loc )
          : ChessPiece( _col, _cp, _loc )
{}

bool King::tryMove( SquareID destSq, const Board &chessboard )
{
  /* constrain */
  return false;
}
