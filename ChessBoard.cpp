# include <iostream>/* std::cin, std::cout, std::cerr */
# include <utility> /* std::pair */
# include <string>  /* std::string */

# include "Types.h" 
# include "ChessBoard.h"
# include "ChessPiece.h"

# include "Pawn.h"
# include "Rook.h"
# include "Knight.h"
# include "Bishop.h"
# include "King.h"
# include "Queen.h"

using namespace std;

ChessBoard::ChessBoard()
{
  loadStartPositions();
  turn = WHITE; 
}

void ChessBoard::loadStartPositions()
{
  pair< Board::iterator, bool > validInsert;   // Info: validity of last insert
  
  for( int rank=1; rank <= MAX_RANK; rank++ ){ // cycle board allocating pieces
    for( int file=1; file <= MAX_FILE; file++ ){  

      SquareID square ( rank, file );             // Generate a square 
      validInsert = chessboard.insert( allocatePiece( square ) );

      if( validInsert.second == false ){          // check validty, handle fail
      }
    }
  }

}

pair< SquareID, ChessPiece* > ChessBoard::allocatePiece( SquareID square )
{
  /* Get rank and file allocated to square. */
  int rank = square.first;
  int file = square.second;
  ChessPiece *cp;

  
  /* Allocate Pieces for 'White Side' of the chessboard; ranks 1-2 */
    if( rank == 1 && (file == 1 || file == 8) ){
      SquareID currentLoc ( rank, file );
      cp = new Rook( WHITE, "WR", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 2 || file == 7) ){
      SquareID currentLoc ( rank, file );
      cp = new Knight( WHITE, "WH", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 3 || file == 6) ){
      SquareID currentLoc ( rank, file );
      cp = new Bishop( WHITE, "WB", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 4 ) ){
      SquareID currentLoc ( rank, file );
      cp = new King( WHITE, "WK", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 5 ) ) {
      SquareID currentLoc ( rank, file );
      cp = new Queen( WHITE, "WQ", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
   if( rank == 2 && ( file >= 1 && file <= 8 ) ){
    SquareID currentLoc ( rank, file );
    cp = new Pawn( WHITE, "WP", currentLoc );
    return pair< SquareID, ChessPiece* > ( square, cp );
  }


  /* Allocate no peices (NULL) to ranks 3 - 6. */
  if( (rank > 2 && rank < 7) && (file >= 1 && file <= 8) ){
    cp = NULL;
    return pair< SquareID, ChessPiece* > ( square, cp );
  }


    /* Allocate ChessPeices for 'Black Side' of chessboard; ranks 7-8. */
    if( rank == 8 && (file == 1 || file == 8) ){
      SquareID currentLoc ( rank, file );
      cp = new Rook( BLACK, "BR", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 2 || file == 7) ){
      SquareID currentLoc ( rank, file );
      cp = new Knight( BLACK, "BH", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 3 || file == 6) ){
      SquareID currentLoc ( rank, file );
      cp = new Bishop( BLACK, "BB", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 4 ) ){
      SquareID currentLoc ( rank, file );
      cp = new King( BLACK, "BK", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 5 ) ){
      SquareID currentLoc ( rank, file );
      cp = new Queen( BLACK, "BQ", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
  if( rank == 7 && ( file >=1 && file <= 8 ) ){
    SquareID currentLoc ( rank, file );
    cp = new Pawn( BLACK, "BP", currentLoc );
    return pair< SquareID, ChessPiece* > ( square, cp );
  }
  else{ /* Throw error*/}
}

bool ChessBoard::submitMove( const string source, const string dest )
{
  bool valid;
  SquareID sourceSq ( (source.at(1)-48), (source.at(0)-64) );  // get source ID
  SquareID destSq   ( (dest.at(1)-48), (dest.at(0)-64) );      // get dest ID

  invalidSourceSq( sourceSq );            // check turn owns piece to be moved
  invalidDestSq( destSq );         // check turn's does not have peice at dest

  ChessPiece *movingPiece;          // will be assigned to the piece as source
  movingPiece = chessboard.find( sourceSq )->second;
  cout << movingPiece->charpiece << endl;
  valid =  movingPiece->tryMove( destSq, getBoard() );   // try to move piece to destination square

  if ( valid )
  {
    movePiece( movingPiece, destSq );
  }
  else{ cout << "Not Valid Move" << endl; }
  
  // turn =  ( ( turn == WHITE ) ? BLACK : WHITE );

  return true;

}

void ChessBoard::movePiece( ChessPiece* movingPiece, SquareID destSq )
{
  ChessPiece *destPiece;
  destPiece = chessboard.find( destSq )->second;
  
  if( destPiece == NULL )                            // if destSq is empty
  {
    chessboard[ destSq ] = movingPiece;              // move ChessPiece
    chessboard[ movingPiece->getCurrentLoc() ] = NULL; // set source to empty
    movingPiece->setCurrentLoc( destSq );            // update pieces position
  }
  else if( destPiece->getColour() != turn )
  {
    delete chessboard[ destSq ];                     // take piece
    chessboard[ destSq ] = movingPiece;              // move ChessPiece
    chessboard[ movingPiece->getCurrentLoc() ] = NULL; // set source to empty
    movingPiece->setCurrentLoc( destSq );            // update pieces position
  }

}

void ChessBoard::invalidSourceSq( const SquareID &sourceSq )
{
  ChessPiece *piece;
  piece = chessboard.find( sourceSq )-> second; // return pointer to ChessPiece

  /* Need some range checking*/

  if( piece != NULL && piece->getColour() != turn )
  {
    cerr << (( turn == WHITE ) ? "White" : "Black") << " cannot move"
         << " chess piece at "<< static_cast<char> (sourceSq.second+64)
         << static_cast<char> (sourceSq.first+48) << "." << endl
         << "This piece is owned by the opposite player." << endl;
  }
  else if( piece == NULL )
  {
    cerr << "Invalid move from " << (( turn == WHITE ) ? "White." : "Black." )
         << endl << "No chess piece located at "
         << static_cast<char> (sourceSq.second+64)
         << static_cast<char> (sourceSq.first+48) << "." << endl;
  }
}

void ChessBoard::invalidDestSq( const SquareID &destSq )
{
  ChessPiece *piece;
  piece = chessboard.find( destSq )-> second;  // return pointer to ChessPiece

  /* Need some range checking */

  if( piece != NULL && piece->getColour() == turn ){
    cerr << "Invalid move from " << (( turn == WHITE ) ? "White." : "Black." )
         << endl << "Cannot take your own chess piece located at "
         << static_cast<char> (destSq.second+64)
         << static_cast<char> (destSq.first+48) << "." << endl;
  }
}


Board ChessBoard::getBoard()
{
  return chessboard;
}

colour_t ChessBoard::getTurn()
{
  return turn;
}



/* internal helper function */
void ChessBoard::print_frame() {
    cout << "  +===========+===========+" << endl;
}

/* internal helper function */
void ChessBoard::print_row( const Board &cb, int rank ) {
  cout << static_cast< char > ( 48+rank ) << " ";
  for ( int file = 1; file <= MAX_FILE; file++ ) {
    cout << "|";
    SquareID square ( rank, file );
    ChessPiece *piece = cb.find( square )->second;
    if( ( piece != NULL ) ){
      cout << piece->charpiece;
    }
    else{
      cout << "e ";
    }
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void ChessBoard::display_board( const Board &cb ){
  cout << "   ";
  for (int file = 1; file <= MAX_FILE; file++) 
    cout << static_cast<char> (64+file) << "  ";
  cout << endl;
  for (int rank = 1; rank <= MAX_RANK; rank++) {
    print_frame();
    print_row( cb, rank );
  }
  print_frame();
}
