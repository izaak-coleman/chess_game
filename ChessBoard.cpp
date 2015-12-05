# include <iostream>/* std::cin, std::cout, std::cerr */
# include <map>     /* std::map */
# include <vector>  /* std::vector */
# include <utility> /* std::pair */

# include "ChessPiece.h"

using namespace std;

ChessBoard::ChessBoard
{
  loadStartPositions();
  move = WHITE; 
}

void ChessBoard::loadStartPositions()
{
  pair< Board::iterator, bool > validInsert;      // Stores last insertion info.
  
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){  

      SquareID square ( rank, file );             // Generate a square 
      validInsert = chessboard.insert( allocatePiece( square ) );

      if( validInsert.second == false ){          // handle insert fail 
        /* Throw an error */
      }
    }
  }

}

pair< SquareID, *ChessPiece > ChessBoard::allocatePiece( SquareID square )
{
  /* Get rank and file allocated to square. */
  int rank = square.first();
  int file = square.second();
  ChessPiece *cp;

  
  /* Allocate Pieces for 'White Side' of the chessboard; ranks 1-2 */
  if( rank == 1 && (file == 1 || file == 8) ){
    cp = new Rook( WHITE );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 1 && (file == 2 || file == 7) ){
    cp = new Knight( WHITE );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 1 && (file == 3 || file == 6) ){
    cp = new Bishop( WHITE );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 1 && (file == 4 ) ){
    cp = new King( WHITE );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 1 && (file == 5 ) ) {
    cp = new Queen( WHITE );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 2 && ( file >= 1 && file <= 8 ) ){
    cp = new Pawn( WHITE );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }


  /* Allocate no peices (NULL) to ranks 3 - 6. */
  if( (rank > 2 && rank < 8) && (file >= 1 && file <= 8){
    cp = NULL;
    return pair< SquareID, *ChessPiece > ( square, cp );
  }


  /* Allocate ChessPeices for 'Black Side' of chessboard; ranks 7-8. */
  if( rank == 8 && (file == 1 || file == 8) ){
    cp = new Rook( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 8 && (file == 2 || file == 7) ){
    cp = new Knight( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 8 && (file == 3 || file == 6) ){
    cp = new Bishop( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 8 && (file == 4 ) ){
    cp = new King( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 8 && (file == 5 ) ){
    cp = new Queen( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 9 && ( file >=1 && file <= 8 ) ){
    cp = new Pawn( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  
  else{ // Given rank and file out of range. Throw exptn.
    /* Throw exptn */
  }
}



/* internal helper function */
void ChessBoard::print_frame() {
    cout << "  +===========+===========+===========+" << endl;
}

/* internal helper function */
void ChessBoard::print_row( const Board &cb, int rank ) {
  cout << static_cast< char > ( rank ) << " ";
  for ( int file = 1; file <= MAX_FILE; file++ ) {
    cout << "|" << " ";
    if( cb.find( rank, file)->charpiece != NULL ){
      cout << cb[ make_pair(rank,file) ]->charpiece;
    }
    else{
      cout << " ";
    }
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void ChessBoard::display_board( const Board &cb ){
  cout << "    ";
  for (int rank = 1; r <= MAX_RANK; rank++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int rank = 1; r < MAX_RANK; rank++) {
    print_frame();
    print_row( cb );
  }
  print_frame();
}
