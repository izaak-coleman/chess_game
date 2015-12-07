# include <iostream>
# include <string> /* std::string */

# include "Queen.h"
# include "Types.h"
# include "ChessPiece.h"

using namespace std;

Queen::Queen( colour_t _col, string _cp, SquareID _loc )
            : ChessPiece( _col, _cp, _loc )
{}

bool Queen::tryMove( SquareID destSq, const Board &chessboard )
{
 /* constrain */
 return false;
}
