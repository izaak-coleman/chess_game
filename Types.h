# ifndef TYPES_H
# define TYPES_H

# include <map>
# include <utility>

class ChessPiece;  // forward declare for use in Board type

enum colour_t { BLACK, WHITE };

typedef std::pair< int, int > SquareID;        // used to ref each board square
typedef std::map< SquareID, ChessPiece* > Board; // holds board and pieces

# endif
