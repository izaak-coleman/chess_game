# ifndef BISHOP_H
# define BISHOP_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Bishop: public ChessPiece{
/* Bishop can move any number of ranks or files in a diagonal direction.
 * The Bishop class sets these movement constraints */

public:
  Bishop( colour_t _col, std::string _cp, SquareID _loc );

  bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if the Bishop can move to destSq, under bishop
   * movement constraints. */

  ~Bishop();
};

#endif
