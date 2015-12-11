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
       /* handler for fail */ 
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
      whiteKing = currentLoc;                   // Keep track of white king
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
      blackKing = currentLoc;                   // keep track of black king
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
  bool validMove;
  SquareID sourceSq ( (source.at(1)-48), (source.at(0)-64) );  // get source ID
  SquareID destSq   ( (dest.at(1)-48), (dest.at(0)-64) );      // get dest ID

  /* Returns false, if the players move is incorrect. Does not 
   * take into account the validity of the move according to the 
   * specific chesspiece */
  if( invalidSourceSq( sourceSq, chessboard ) || invalidDestSq( destSq, chessboard ) ) {
      cout << "Not a valid move" << endl;
     return false;
  }

  /* Otherwise, move piece if the move submitted is valid within the 
   * chesspiece constraints */

  ChessPiece *movingPiece;          // will be assigned to the piece as source
  movingPiece = chessboard.find( sourceSq )->second;
  cout << movingPiece->charpiece << endl;
  validMove =  movingPiece->tryMove( destSq, getBoard() );   // try to move piece to destination square

  if ( validMove )
  {
    movePiece( movingPiece, destSq );
    
    /* Keep track of kings movements */
    if( sourceSq == whiteKing ){
      whiteKing = destSq;
    }
    else if( sourceSq == blackKing ){
      blackKing = destSq;
    }
  
  }
  else{ 
    cout << "Not Valid Move" << endl;
    return false;
  }
  
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

bool ChessBoard::invalidSourceSq( const SquareID sourceSq, const Board &cb )
{

  if( outOfRange( sourceSq ) || 
      emptySquare( sourceSq, chessboard ) ||
      !ownsPiece( sourceSq, chessboard ) ){
    return true;
  }
  // else
    return false;
}

bool ChessBoard::invalidDestSq( const SquareID destSq, const Board &cb )
{
  if( outOfRange( destSq ) ){
    return true;
  }

  if( !emptySquare( destSq, cb ) && ownsPiece( destSq, cb ) ){
      return true;
  }

  // else
    return false;
}

bool ChessBoard::sqIsReachable( const SquareID sqToCheck, const bool attackSwitch,
                                const Board &cb )
{
  SquareID nextSq;
  bool reachable = false;

  /* Return true if a chesspiece can reach sqToCheck */
  for( int rank=1; rank <= 8; rank++ ){
    for( int file=1; file <= 8; file++ ){
      nextSq.first = rank;
      nextSq.second = file; 
  
      ChessPiece *movingPiece;
      movingPiece= cb.find( nextSq )->second;

      switch( attackSwitch ){
        case 0:{ // ATTACK
 
          /* If the attacking piece is the same colour as the king, check nextSq */
          if( movingPiece = NULL || movingPiece->colour == colour ){
            continue;
          }
          else{
            if( movingPiece->tryMove( kingSq, cb ) ){  // check enemy attack
              reachable = true;   // piece is attackable
              attackingLocations.push_back( sqToCheck );
            }
          }
        }
        
        case 1:{ // BLOCK
         /* If the blocking piece is not the same colour as the king
          * check nextSq*/ 
          if( movingPiece = NULL || movingPiece->colour != colour ){
            continue;
          }
          else{
            if( movingPiece->tryMove( kingSq, cb ) ){ // if blockable, return
              reachable = true;
              return reachable;
            }
          }

          return reachable;
        }
      }
    }

  }
}

bool ChessBoard::canBlock( const SquareID sqToCheck, const Board &cb )
{
 
  do {

    sqToCheck.first += dir.first;
    sqToCheck.second += dir.second;

    if( squareIsReachable( blockingSq, BLOCK, cb ){
      return true;      
    }

  }while( sqToCheck != attackSq )
}

bool ChessBoard::CheckMate( const SquareID kingSq, const Board &cb )
{
  bool checkmate = true;
  SquareID firstAttacker = attackingLocations[0];
 
  if( attackingLocations.size > 1 ){ // double check. Only esc is king move 
  }
  else if( attackingLocations.size == 1 ){
    if( sqIsReachable( firstAttacker, ATTACK, cb ) ){
      checkmate = false;
    }
  }
  else{
        SquareID dir = movingDir( firstAttacker, kingSq );
        SquareID blockSq = kingSq;

      do{
        blockSq.first += dir.first;
        blockSq.second += dir.second;
        if( sqIsReachable( blockSq, BLOCK, cb ) ){
          checkmate = false;
        }
      }while( blockSq != firstAttacker )
  }
    
  return checkmate;


}

SquareID ChessBoard::movingDir( const SquareID attackerSq, const SquareID kingSq )
{
  int attRank, attFile, kingRank, kingFile;

  attRank = attackerSq.first; attFile = attackerSq.second;
  kingRank = kingSq.first;  kingRank = kingSq.second;

  if( attRank > kingRank ){     // attacking from front 

    if( attFile == kingFile ){
      SquareID direction ( 1, 0 );
      return direction;
    
    } 
    else if( attFile > kingFile ){
      SquareID direction ( 1, 1 );                  // and to the right
      return direction;
    }
    else if( attFile < kingFile ){
      SquareID direction ( 1, -1 );                 // and to the left
      return direction;
    }
  }

  else if( attRank < kingRank ){ // attacking from behind
    
    if( attFile == kingFile ){
      SquareID direction ( -1, 0 ); 
      return direction;
    }
    else if( attFile > kingFile ){
      SquareID direction ( -1, 1 );            // and to the right
      return direction;
    }
    else if( attFile < kingFile ){
      SquareID direction ( -1, -1 );             // and to the left
      return direction;
    }
  }
  
  /* Attacking from right */
  else if( (attRank == kingRank) && (attFile > kingFile) ){
    SquareID direction ( 0, 1 );
    return direction;
  }

  /* Attacking from left */
  else if( (attRank == kingRank) && (attFile < kingFile) ){
    SquareID direction ( 0, -1 );
    return direction;
  }
}


bool ChessBoard::ownsPiece( const SquareID sq, const Board &cb )
{
  ChessPiece *piece;
  piece = chessboard.find( sq )->second;
  if( piece->getColour() == turn ){ 
    return true;
  }
  // else
    return false;
}

bool ChessBoard::emptySquare( const SquareID sq, const Board &cb )
{
  ChessPiece *piece;
  piece = chessboard.find( sq )->second;
  if( piece == NULL ){
     return true;
  }
  // else
    return false;
}

bool ChessBoard::outOfRange( const SquareID sq )
{
  /* return false if rank and file is between 1-8*/
  if( ( sq.first > 0 && sq.first < 9 ) &&
      ( sq.second > 0 && sq.second < 9 ) ){
      return false;
  }

  // else  out of range, return true
  return true;
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
