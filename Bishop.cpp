# include <iostream>
# include <string> /* std::string */

# include "Bishop.h"
# include "Type.h"
# include "ChessPiece.h"

using namespace std;

Bishop::Bishop( colour_t _col, string _cp, SquareID _loc)
              : ChessPiece( _col, _cp, _loc )
{}
