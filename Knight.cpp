# include <iostream>
# include <string> /* std::string */

# include "Knight.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Knight::Knight( colour_t _col, string _cp, SquareID _loc )
              : ChessPiece( _col, _cp, _loc )
{}

bool Knight::tryMove( SquareID destSq, const Board &chessboard )
{
  /* Constrain */
  return false;
}
