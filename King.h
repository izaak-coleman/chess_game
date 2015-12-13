# ifndef KING_H
# define KING_H

# include <string> 

# include "Types.h"
# include "ChessPiece.h"

class King: public ChessPiece{
/* King can move one place in any direction. The King class defines
 * these constraints. */
public:
  King( colour_t _col, std::string _cp, SquareID _loc );

  bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if the King can move to destSq, under king 
   * movement constraints. */

  ~King();
};
#endif
