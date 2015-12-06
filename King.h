# ifndef KING_H
# define KING_H

# include <string> /* std::string */

# include "ChessPiece.h"

class King: public ChessPiece{
public:
  King( colour_t _col, std::string _charPiece );
};
#endif
