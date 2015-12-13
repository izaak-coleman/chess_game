# ifndef KNIGHT_H
# define KNIGHT_H

# include <string>
# include "Types.h"
# include "ChessPiece.h"

class Knight: public ChessPiece{
/* Knight moves to the closest squares that is not of the same
 * rank or file of its original position. Knight class sets these constraints */
public:
  Knight( colour_t _col, std::string _cp, SquareID _loc );
  
  
  bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if the Knight can move to destSq, under the knight
   * movement constraints. */

  ~Knight();
};
#endif
