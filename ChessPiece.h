#ifndef CHESSPIECE_H
#define CHESSPIECE_H
# include <string> /* std::string */

# include "Types.h"

class ChessPiece{
private:
  /* Class attributes */

  colour_t colour;                     // colour of chess piece
  SquareID currentLoc;                 // current location of piece

public:
  std::string charpiece;               // string code for visualizer

  ChessPiece( colour_t _col, std::string _cp, SquareID _loc );
  /* Initialize colour, charpeice and currentLoc of chess peice */
  
  colour_t getColour();
  /* Return colour_t of the chess piece */

  virtual bool tryMove( SquareID destSq, const Board &chessboard ) = 0;
  /* Checks if destSq is reachable from the current position, currentLoc,
   * of the chesspiece. Movement is constrained to derived type. Returns
   * true if destSq in range. */

};
#endif
