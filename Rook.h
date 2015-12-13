#ifndef ROOK_H
#define ROOK_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Rook: public ChessPiece{
/* Rook moves any distance along either a rank, or a file.
 * Rook class sets these constraints. */


public:
  Rook( colour_t _col, std::string _cp, SquareID _loc );

  virtual bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if the Rook can move to destSq, under the rook 
   * movement constraints. */

  ~Rook();
};
#endif
