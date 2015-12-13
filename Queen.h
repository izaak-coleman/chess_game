# ifndef QUEEN_H
# define QUEEN_H

# include <string>

# include "Types.h"
# include "ChessPiece.h"

class Queen: public ChessPiece{
/* Queen can move any number of ranks and files in a diagonal direction.
 * Or, it can move any number of squares along a single rank or file.
 * The Queen class sets these constraints */
public:
  Queen( colour_t _col, std::string _cp, SquareID _loc );

  bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if the Queen can reach destSq, under the queen
   * movement contraints. */

  ~Queen();
};

#endif 
