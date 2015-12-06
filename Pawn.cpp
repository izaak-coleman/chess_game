# include <iostream>
# include <string> /* std::string */

# include "ChessPiece.h"
# include "Pawn.h"

using namespace std;

Pawn::Pawn( colour_t _col, string _cp ): ChessPiece( _col, _cp ){}
