//ChessBoard.h

# ifndef CHESSBOARD_H
# define CHESSBOARD_H

# include <map>       /* std::map */
# include <utility>   /* std::pair */
# include <string>    /* std::string */
# include <vector>

# include "Types.h"
# include "ChessPiece.h"

static const int MAX_RANK = 8;
static const int MAX_FILE = 8;

class ChessBoard{
/* Describe ChessBoard in here */ 
private:

  /* Attributes */
  colour_t turn;          // Switches after each successful turn
  Board chessboard;       // Chessboard maps squares to chesspieces
  SquareID whiteKing;     // location of white king
  SquareID blackKing;     // location of black king

  /* Member Functions */

  void movePiece( ChessPiece* movingPiece, SquareID destSq );
  /* Helper function to submitMove. If submitMove identifies
   * move as valid, then movePiece configures chessboard map
   * to move the piece. If a is located at destSq, it is 
   * deleted. */

  void loadStartPositions();
  /* PreCondition:  chessboard member empty.
     PostCondition: chessboard member contains squares mapped
     to ChessPieces in the usual chess configuration. */

  std::pair< SquareID, ChessPiece* > allocatePiece( SquareID square );
  /* Pairs together a square and a ChessPiece. Each square passed in
     has a rank and file. The Subclass of ChessPiece assigned to the
     square corresponds to this rank and file. */

  bool invalidSourceSq( const SquareID sourceSq, const Board &cb );
  /* Returns false the chessPiece is not owned by the player. */

  bool invalidDestSq( const SquareID destSq, const Board &cb );
  /* Returns false if the player whos turn it is tries to move 
   * the ChessPiece to a position that already contains a ChessPiece of 
   * their colour. Also checks destSq is in range.  */

  bool inCheck( const SquareID kingSq, const Board &cb );
  /* determines whether a player is in check */

  bool inCheckMate( SquareID kingSq );
  /* Identifies whether player who owns KingSq is in checkmate */

  bool staleMate( SquareID kingSq );
  /* Returns true if the king at kingSq is in stalemate */

  bool pieceCanProtectKing( ChessPiece *friendly, SquareID moveToSq,
                            const SquareID moveFromSq, SquareID kingSq );
  /* If possible friendly piece to moveToSq. If an enemy piece is at
   * moveToSq, the piece is detached and a pointer to it is stored. 
   * If the piece has moved into a position that protects the king, 
   * true is returned */
  
  ChessPiece* detachPiece( const SquareID detachFromSq );
  /* Detaches a ChessPiece from the board at locatation detachFromSq.
   * Returns the location of the piece in a pointer and sets the
   * maps the detachFromSq with NULL in chessboard */
  
  bool ownsPiece( const SquareID sq, const Board &cb );
  /* Returns true if the ChessPiece at sq is owned by the player 
   * whos turn it is */

  bool ownsPiece( const SquareID sq, const colour_t player, 
                  const Board &cb );
  /* Returns true if the ChessPiece at sq is same colour as 
   * the function parameter player */

  bool outOfRange( const SquareID sq );
  /* Returns true if the rank and file of sq is not between 1-8 */

  bool emptySquare( const SquareID sq, const Board &cb );
  /* returns true of the sq contains no chesspieces */

  void print_row( const Board &cb, int rank );
  /* Prints the chessboard to the screen. */
  /* Sets up board with mapped chess pieces */

  void print_frame();

public:

  /* Member Functions */

  ChessBoard();
  /* Calls loadStartPositions, sets move to WHITE */

  bool submitMove( const std::string source, const std::string dest );
  /* Moves ChessPiece from source to dest. Main gameplay function.
   * Check piece at source, belongs to player whose turn it is to move.
   * Checks if move is legal. If chesspiece at dest belongs to player 
   * whos turn it is not, the peice will be taken (deleted) */

  void resetBoard();
  /* Function deletes any remaining chesspieces from memory from 
   * previous game and then creates and sets up the chessPieces 
   * for a new game */


  void display_board( const Board &cb );
  /* Visual display of the chessboard. */

  Board getBoard();
  /* Returns the chessboard */
  
  colour_t getTurn();
  /* Returns who needs to make the next move. */

  ~ChessBoard();
  /* Delete all ChessPiece on heap */

};
#endif
