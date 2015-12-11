# ifndef KING_H
# define KING_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

/* Returned by inCheck() to report condition of King */
static const int NOT_IN_CHECK = 0;
static const int CHECK = 1;
static const int STALEMATE = 2;
static const int CHECKMATE = 3;

class King: public ChessPiece{
public:
  King( colour_t _col, std::string _cp, SquareID _loc );

  bool tryMove( SquareID destSq, const Board &chessboard );

};
#endif
