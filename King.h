# ifndef KING_H
# define KING_H

# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

class King: public ChessPiece{
public:
  King( colour_t _col, std::string _cp, SquareID _loc );
};
#endif
