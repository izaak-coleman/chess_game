//ChessBoard.h

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>
#include <utility>

#include "ChessPiece.h"

static const int MAX_RANK = 8;
static const int MAX_FILE = 8;

class ChessBoard{
/* Describe ChessBoard in here */
public:
  typedef std::pair< int, int > SquareID;
  typedef std::map< SquareID, ChessPiece* > Board;

private:

  /* Attributes */
  colour_t turn;

  Board chessboard;

   
  /* Member Functions */
  ChessBoard();
  /* Calls loadStartPositions, sets move to WHITE */

  void loadStartPositions();
  /* PreCondition:  chessboard member empty.
     PostCondition: chessboard member contains squares mapped
     to ChessPieces in the usual chess configuration. */

  std::pair< SquareID, ChessPiece* > allocatePiece( SquareID square );
  /* Pairs together a square and a ChessPiece. Each square passed in
     has a rank and file. The Subclass of ChessPiece assigned to the
     square corresponds to this rank and file. */

  void display_board( const Board &cb );
  void print_frame();
  void print_row( const Board &cb, int rank );
  /* Prints the chessboard to the screen. */
  /* Sets up board with mapped chess pieces */
 // bool submitMove( char* sourceSq, char* destSq );
 // /*void updateBoard( ... ); */
 // bool displayGameStatus();
 // int  checkGameStatus();
 // Board updateBoard;
};
#endif
