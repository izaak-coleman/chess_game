#ifndef CHESSPIECE_H
#define CHESSPIECE_H
# include <string> /* std::string */

# include "Types.h"

class ChessPiece{
private:
protected:
  /* Class attributes */

  colour_t colour;                     // colour of chess piece
  SquareID currentLoc;                 // current location of piece

public:
  std::string charpiece;               // string code for visualizer

  ChessPiece( colour_t _col, std::string _cp, SquareID _loc );
  /* Initialize colour, charpeice and currentLoc of chess peice */
  
  colour_t getColour();
  /* Return colour_t of the chess piece */

  SquareID getCurrentLoc();
  /* Returns the current location of the chess piece */
  
  void setCurrentLoc( SquareID destSq );
  /* currentLoc will be changed to destSq parameter */

  virtual bool tryMove( SquareID destSq, const Board &chessboard ) = 0;
  /* Checks if destSq is reachable from the current position, currentLoc,
   * of the chesspiece. Movement is constrained to derived type. Returns
   * true if destSq in range. */

  virtual ~ChessPiece();
  /* Virtual destructor to destroy derived classes */

};
#endif
