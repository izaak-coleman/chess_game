# ifndef KNIGHT_H
# define KNIGHT_H

# include <string> /* std::string */
# include "Types.h"
# include "ChessPiece.h"

class Knight: public ChessPiece{
public:
  Knight( colour_t _col, std::string _cp, SquareID _loc );
};
#endif
