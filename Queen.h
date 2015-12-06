# ifndef QUEEN_H
# define QUEEN_H

# include <string> /* std::string */

# include "ChessPiece.h"

class Queen: public ChessPiece{
public:
  Queen( colour_t _col, std::string _charPiece );
};
#endif 
