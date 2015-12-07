# include <iostream>
# include <string> /* std::string */

# include "Rook.h"
# include "Types.h"
# include "ChessPiece.h"


using namespace std;

Rook::Rook( colour_t _col, string _cp, SquareId _loc )
          : ChessPiece( _col, _cp, _loc )
{}
