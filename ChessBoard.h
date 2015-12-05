
class ChessBoard{
/* Describe ChessBoard in here */
private:

  /* Attributes */
  enum moves { BLACK, WHITE };
  moves move;
  typedef std::pair< int, int > SquareID;

  typedef std::map< SquareID, ChessPiece* > Board;
  Board chessboard;

   
  /* Member Functions */
  ChessBoard();
  /* Calls loadStartPositions, sets move to WHITE */

  void loadStartPositions();
  /* PreCondition:  chessboard member empty.
     PostCondition: chessboard member contains squares mapped
     to ChessPieces in the usual chess configuration. */

  std::pair< SquareID, *ChessPiece > allocatePiece( SquareID square );
  /* Pairs together a square and a ChessPiece. Each square passed in
     has a rank and file. The Subclass of ChessPiece assigned to the
     square corresponds to this rank and file. */

  void displayBoard();
  /* Prints the chessboard to the screen. */
  /* Sets up board with mapped chess pieces */
 // bool submitMove( char* sourceSq, char* destSq );
 // /*void updateBoard( ... ); */
 // bool displayGameStatus();
 // int  checkGameStatus();
 // Board updateBoard;
  
  
  
  
  
}
