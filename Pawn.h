# ifndef PAWN_H
# define PAWN_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Pawn: public ChessPiece{
public:
  Pawn( colour_t _col, std::string _cp, SquareID _loc );

  virtual bool tryMove( SquareID destSq, const Board &chessboard );
  /* Check if destSq is accessable for Pawn, moving from
   * its currentLoc. Movement is constrained to Pawn
   * movement. */
  
  ~Pawn();
  /* Destructor */
};
#endif
