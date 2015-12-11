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

  /* Member functions */


  bool isNotBlocked( const SquareID destSq, SquareID nextSq, 
                     const SquareID direction, const Board &chessboard );
  /* Recursive function that checks if the path for the ChessPiece from 
   * currentLoc to destSq is not blocked by another ChessPiece. 
   * The blocking ChessPiece could be of either colour. */
  
  SquareID movingDir( SquareID destSq );   // isNotBlocked helper function
  /* Determine direction ChessPiece is moving and outputs a string encoding
   * direction */


public:
  virtual bool tryMove( SquareID destSq, const Board &chessboard ) = 0;
  /* Checks if destSq is reachable from the current position, currentLoc,
   * of the chesspiece. Movement is constrained to derived type. Returns
   * true if destSq in range. */

  std::string charpiece;               // string code for visualizer

  ChessPiece( colour_t _col, std::string _cp, SquareID _loc );
  /* Initialize colour, charpeice and currentLoc of chess peice */
  
  colour_t getColour();
  /* Return colour_t of the chess piece */

  SquareID getCurrentLoc();
  /* Returns the current location of the chess piece */
  
  void setCurrentLoc( SquareID destSq );
  /* currentLoc will be changed to destSq parameter */

  virtual ~ChessPiece();
  /* Virtual destructor to destroy derived classes */

};
#endif
