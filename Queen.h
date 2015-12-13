# ifndef QUEEN_H
# define QUEEN_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class Queen: public ChessPiece{
public:
  Queen( colour_t _col, std::string _cp, SquareID _loc );

  bool tryMove( SquareID destSq, const Board &chessboard );
  /* Returns true if the Queen can reach destSq, under the queen
   * movement contraints. */

  ~Queen();
};

#endif 
