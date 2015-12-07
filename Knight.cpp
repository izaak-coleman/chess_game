# include <iostream>
# include <string> /* std::string */

# include "Knight.h"
# include "Type.h"
# include "ChessPiece.h"

using namespace std;

Knight::Knight( colour_t _col, string _cp, SquareID _loc )
              : ChessPiece( _col, _cp, _loc )
{}

