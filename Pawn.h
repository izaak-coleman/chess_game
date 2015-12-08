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
  /* Check if destSq is accessable for Pawn, moving from
   * its currentLoc. Movement is constrained to pawn rules.
   * If move is a non-attacking move to an empty square,
   * or an attacking move to occupied square returns true.
   * Otherwise, returns false */

  bool diagMov( SquareID destSq );
  /* Returns true if a diagonal move is made by the Pawn, where
   * it moves one space diagonally "forward", and the destSq contains
   * a chesspiece. The piece at destSq is already known to be of oposite
   * colour, so this is an attacking move. */
  
  ~Pawn();
  /* Destructor */
};
#endif
