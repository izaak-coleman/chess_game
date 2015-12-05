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
  typedef pair< int, int > squareID;             // Square given rank and file.
  pair< Board::iterator, bool > validInsert;     // Stores last insertion info.
  
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){
      squareID square ( rank, file );   // Assign rank and file as ID.
      validInsert = chessboard.insert( pair< square, *ChessPiece );
//    validInsert = chessboard.insert( allocatePiece( square ) );
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
  else if( rank == 8 && (file == 5 ) ) {
    cp = new Queen( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
  else if( rank == 9 && ( file >=1 && file <= 8 ) ){
    cp = new Pawn( BLACK );
    return pair< SquareID, *ChessPiece > ( square, cp );
  }
}



///* internal helper function */
//void print_frame(int row) {
//  if (!(row % 3))
//    cout << "  +===========+===========+===========+" << endl;
//  else
//    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
//}
//
///* internal helper function */
//void print_row(const char *data, int row) {
//  cout << (char) ('A' + row) << " ";
//  for (int i=0; i<9; i++) {
//    cout << ( (i % 3) ? ':' : '|' ) << " ";
//    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
//  }
//  cout << "|" << endl;
//}
//
///* pre-supplied function to display a Sudoku board */
//void display_board(const char board[9][9]) {
//  cout << "    ";
//  for (int r=0; r<9; r++) 
//    cout << (char) ('1'+r) << "   ";
//  cout << endl;
//  for (int r=0; r<9; r++) {
//    print_frame(r);
//    print_row(board[r],r);
//  }
//  print_frame(9);
//}
