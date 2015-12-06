#ifndef PAWN_H
#define PAWN_H
  
#include "ChessPiece.h"

class Pawn: public ChessPiece{
public:
  Pawn( colour_t _col, char _charPiece );
};
#endif
