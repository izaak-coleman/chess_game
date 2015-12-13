# ifndef PAWN_H
# define PAWN_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Pawn: public ChessPiece{
/* WHITE and BLACK Pawns fill ranks 2 and 7 resepectively, at the start o
 * of the game. Pawn can check if the destination square can be reached given
 * pawn movement constraints. */

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
