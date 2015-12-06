# ifndef BISHOP_H
# define BISHOP_H

# include <string> /* std::string */

# include "ChessPiece.h"

class Bishop: public ChessPiece{

public:
  Bishop( colour_t _col, std::string _charPiece );
};

#endif
