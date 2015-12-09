#ifndef ROOK_H
#define ROOK_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Rook: public ChessPiece{

public:
  Rook( colour_t _col, std::string _cp, SquareID _loc );

  void coutHello();

  virtual bool tryMove( SquareID destSq, const Board &chessboard );
  /* Check if destSq is accessable to Rook. Rook movement constrained
   * to usual Rook rules. */

  ~Rook();
  /* Destructor*/
  

};
#endif
