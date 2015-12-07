//ChessBoard.h

# ifndef CHESSBOARD_H
# define CHESSBOARD_H

# include <map>       /* std::map */
# include <utility>   /* std::pair */
# include <string>    /* std::string */

# include "Types.h"
# include "ChessPiece.h"

static const int MAX_RANK = 8;
static const int MAX_FILE = 8;

class ChessBoard{
/* Describe ChessBoard in here */ public:

  ChessBoard();
  /* Calls loadStartPositions, sets move to WHITE */

  bool submitMove( const std::string source, const std::string dest );
  /* Moves ChessPiece from source to dest. Main gameplay function.
   * Check piece at source, belongs to player whose turn it is to move.
   * Checks if move is legal. If chesspiece at dest belongs to player 
   * whos turn it is not, the peice will be taken (deleted) */

  void movePiece( ChessPiece* movingPiece, SquareID destSq );
  /* Helper function to submitMove. If submitMove identifies
   * move as valid, then movePiece configures chessboard map
   * to move the piece. If a is located at destSq, it is 
   * deleted. */

  void display_board( const Board &cb );
  /* Visual display of the chessboard. */

  Board getBoard();
  /* Returns the chessboard */
  
  colour_t getTurn();
  /* Returns who needs to make the next move. */

private:

  /* Attributes */
  colour_t turn;          // Switches after each successful turn
  Board chessboard;       // Chessboard maps squares to chesspieces
  SquareID sourceSq;      // Current location of the next piece to be moved
  SquareID destSq;        // Destination of the next piece to be moved
   
  /* Member Functions */

  void loadStartPositions();
  /* PreCondition:  chessboard member empty.
     PostCondition: chessboard member contains squares mapped
     to ChessPieces in the usual chess configuration. */

  std::pair< SquareID, ChessPiece* > allocatePiece( SquareID square );
  /* Pairs together a square and a ChessPiece. Each square passed in
     has a rank and file. The Subclass of ChessPiece assigned to the
     square corresponds to this rank and file. */

  void print_row( const Board &cb, int rank );
  /* Prints the chessboard to the screen. */
  /* Sets up board with mapped chess pieces */

  void print_frame();


  
  void invalidSourceSq( const SquareID &sourceSq );   // Helper SubmitMove
  /* Throws error if the colour_t of the chessPiece at square sourceSq
   * matches does not match turn. */

  void invalidDestSq( const SquareID &destSq );       // Helper SubmitMove
  /* Throws error if a chess piece is located at destSq, and this chess piece
   * is of the same colour_t as turn*/

 // /*void updateBoard( ... ); */
 // bool displayGameStatus();
 // int  checkGameStatus();
 // Board updateBoard;
};
#endif
