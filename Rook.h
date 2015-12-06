#ifndef ROOK_H
#define ROOK_H

# include <string> /* std::string */
# include "ChessPiece.h"

class Rook: public ChessPiece{
public:
  Rook( colour_t _col, std::string _charPiece );
};
#endif
