# ifndef PAWN_H
# define PAWN_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Pawn: public ChessPiece{
/* The Pawn can move forwards. It can move two spaces if at starting 
 * position, else one. It can also move diagonaly one space. Only when
 * taking an enemy piece. The Pawn class defined these constraints. */

public:
  Pawn( colour_t _col, std::string _cp, SquareID _loc );

  virtual bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if Pawn can move to destSq, 
   * under pawn movement constraints. */

  bool diagMov( SquareID destSq );
  /* Returns true if pawn make a valid diagonal attacking move. */
  
  ~Pawn();
};
#endif
