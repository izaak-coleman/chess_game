# include <iostream>
# include <string> /* std::string */

# include "Bishop.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Bishop::Bishop( colour_t _col, string _cp, SquareID _loc)
              : ChessPiece( _col, _cp, _loc )
{}

bool Bishop::tryMove( SquareID destSq, const Board &chessboard )
{
  /* Constrain */
  return false;
}
