// ChessPiece.cpp
# include <string> /* std::string */

# include "ChessPiece.h"

using namespace std;

ChessPiece::ChessPiece( colour_t _col, string _cp )
              : colour( _col ), charpiece( _cp )
{}

colour_t ChessPiece::getColour()
{
  return colour;
}
