// ChessPiece.cpp
# include <string> /* std::string */

# include "Types.h"
# include "ChessPiece.h"

using namespace std;

ChessPiece::ChessPiece( colour_t _col, string _cp, SquareID _loc )
: colour( _col ), charpiece( _cp )
{}

colour_t ChessPiece::getColour()
{
  return colour;
}

SquareID ChessPiece::getCurrentLoc()
{
  return currentLoc;
}

void ChessPiece::setCurrentLoc( SquareID destSq )
{
  currentLoc = destSq;
}

ChessPiece::~ChessPiece(){}
