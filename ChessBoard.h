
class ChessBoard{
/* Describe ChessBoard in here */
private:

  /* Attributes */
  enum moves { BLACK, WHITE };
  moves move;
  typedef std::map< std::pair<int, int>, ChessPiece* > Board;
  Board chessboard;

   
  /* Member Functions */
  ChessBoard();
  /* Calls loadStartPositions, sets move to WHITE */
  void loadStartPositions();
  /* Sets up board with mapped chess pieces */
 // bool submitMove( char* sourceSq, char* destSq );
 // /*void updateBoard( ... ); */
 // bool displayGameStatus();
 // int  checkGameStatus();
 // Board updateBoard;
  
  
  
  
  
}
