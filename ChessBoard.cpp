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
    else if( rank == 2 && ( file >= 1 && file <= 8 ) ){
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
    else if( rank == 7 && ( file >=1 && file <= 8 ) ){
      SquareID currentLoc ( rank, file );
      cp = new Pawn( BLACK, "BP", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
  }
  else{ /* Throw error*/}

}

bool ChessBoard::submitMove( const string source, const string dest )
{
  bool validMove = false;
  SquareID sourceSq ( (source.at(1)-48), (source.at(0)-64) );  // get source ID
  SquareID destSq   ( (dest.at(1)-48), (dest.at(0)-64) );      // get dest ID

  /* Returns false, if the players move is incorrect. Does not 
   * take into account the validity of the move according to the 
   * specific chesspiece */
  if( invalidSourceSq( sourceSq, chessboard ) || 
      invalidDestSq( destSq, chessboard ) ) {
      cout << "Not a valid move" << endl;
     return validMove;
  }

  /* Otherwise, see if chesspiece at source can reach dest, taking into account
   * its movement constraints */

  ChessPiece *movingPiece;          // will be assigned to the piece as source
  movingPiece = chessboard.find( sourceSq )->second;
  
  /* Try and move ChessPiece to destination square. If it can move to 
   * destination, check if king is put in check */
  if( movingPiece->tryMove( destSq, getBoard() ) ){   // if can move to destSq
  
    ChessPiece *detachedPiece;          
    detachedPiece = detachPiece( destSq );    // detach the peice at destination
    movePiece( movingPiece, destSq );         // move the piece
    cout << "Displayed from submitMove: " << endl;
    display_board( chessboard );

    if( turn == WHITE ){
      if( sourceSq == whiteKing ){
        whiteKing == sourceSq;                // update white king when moved
      }
      if( inCheck( whiteKing, chessboard ) ){
        cout << "White cannot put own King in check " << endl;
        movePiece( movingPiece, sourceSq );   // move piece back to source
        chessboard.find( destSq )->second = detachedPiece;  // reattach piece
        return validMove;                     // return false for validMove
      }
      else{                                   // if valid, delete piece at dest
        delete detachedPiece;
        detachedPiece = NULL;
        validMove = true;
      }
    }
    cout << "Get passed first check, but fail afterwards " << endl;

    if( turn == BLACK ){
      cout << "not eneterking black check" << endl;
      if( sourceSq == blackKing ){
        blackKing == sourceSq;
      }
      if( inCheck( blackKing, chessboard ) ){
        cout << "Black cannot put own King in check " << endl;
        movePiece( movingPiece, sourceSq );
        chessboard.find( destSq )->second = detachedPiece; 
      }
      else{
        delete detachedPiece;
        detachedPiece = NULL;
        validMove = true;
      }
    }
  }

  if( validMove ){ 

    if( turn == BLACK ){
      if( inCheckMate( whiteKing ) ){        // check if oponent is in checkmate
        cout << "White is in checkmate";
        /* resetboard()*/
       return true;
      }
      else if( inCheck( whiteKing, chessboard ) ){     // or check
        cout << "White is in check" << endl << endl;
      }
    }

    if( turn == WHITE ){
      cout << "Start on black in here, so problem with check mate" << endl;
      if( inCheckMate( blackKing ) ){
        cout << "Black is in checkmate";
        /* resetboard()*/
      }
      else if( inCheck( blackKing, chessboard ) ){
        cout << "Black is in check" << endl;
      }
    }
  }

  // turn =  ( ( turn == WHITE ) ? BLACK : WHITE );     // switch turns
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

bool ChessBoard::inCheck( const SquareID kingSq, const Board &cb )
{
  SquareID searchSq;
  bool inCheck = false;

  ChessPiece *enemyPiece, *kingPiece;
  kingPiece = cb.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();

  /* Return true if enemy can attack king */
  for( int rank=1; rank <= 8; rank++ ){
    for( int file=1; file <= 8; file++ ){
      searchSq.first = rank;
      searchSq.second = file; 
      cout << "Rank: " << rank << "File: " << file << endl;

      /* If empty square or not an enemy chesspeice continue searching  */
      if( emptySquare( searchSq, cb ) || ownsPiece( searchSq, kingCol, cb ) ){
        continue;
      }
      else{
        enemyPiece = cb.find( searchSq )->second;
        
        cout << "Rank: " << rank << "File: " << file << " with enemy" << endl;
        if( enemyPiece->tryMove( kingSq, cb ) ){ 
          cout << "enemyPiece reached king " << endl;

          inCheck = true;
          return inCheck;
        }
      }
    }
  }
 return false;
}

bool ChessBoard::inCheckMate( const SquareID kingSq ){

  ChessPiece *friendlyPiece, *kingPiece;
  kingPiece = chessboard.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();

  SquareID friendSq, moveToSq;
  bool checkMate = true;

  /* Loop through board and find all friendly pieces */
  for( int rank=1; rank <= 8; rank++ ){
    for( int file=1; file <= 8; file++ ){
      friendSq.first = rank;
      friendSq.second = file; 
    
      /* If square is empty or non-friendly or the king itself, continue */ 
      if( emptySquare( friendSq, chessboard ) ||
          !ownsPiece( friendSq, kingCol, chessboard ) ||
          friendSq == kingSq ){
        continue;
      }
      else{                                       // must be a friendly
        cout << "rank :" << rank << "file :" << file << "with friends in chmt" << endl;
  
        friendlyPiece = chessboard.find( friendSq )->second;
        /* Loop through all positions, and see if friendlyPiece can move
           to a position that protects the king */
        for( int rank=1; rank <= 8; rank++ ){
          for( int file=1; file <= 8; file++ ){
            moveToSq.first = rank;        // get next sqaure coordinates
            moveToSq.second = file; 
            if( pieceCanProtectKing( friendlyPiece, moveToSq, friendSq, kingSq ) ){
              checkMate = false;
              return checkMate;      // finish loop when found first
            }                             // friendly that can help
          }
        }
      }
    }
  }
  return checkMate;        // no pieces can help king, so it is check mate
}

bool ChessBoard::pieceCanProtectKing( ChessPiece *friendly, 
                                         const SquareID moveToSq,
                                         const SquareID moveFromSq,
                                         const SquareID kingSq ){

  ChessPiece *detached, *kingPiece;
  kingPiece = chessboard.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();
  bool notOwnPiece = false;

  /* If the square the friendly will move to is not the same colour as the
   * friendly, set notOwnPiece to true */
  if( emptySquare( moveToSq, chessboard ) || 
      !ownsPiece( moveToSq, kingCol, chessboard ) ){
      notOwnPiece = true;
  }

  /* If friendly peice can be moved into position */
  if( friendly->tryMove( moveToSq, chessboard ) && 
      (moveToSq != moveFromSq) && notOwnPiece ){
    /* Detatch and store any enemy piece that may be there */
    detached = detachPiece( moveToSq );
    movePiece( friendly, moveToSq );     // move the friendly peice
    display_board( chessboard );

    /* If the friendly can thwart check from new position, no check mate */
    if( inCheck( kingSq, chessboard ) ){ 
      movePiece( friendly, moveFromSq );        // return friendly piece
      chessboard.find( moveToSq )->second = detached; // return detached piece
      return true;     // can evade checkmate
    }
    else{
      movePiece( friendly, moveFromSq );         // return friendly piece 
      chessboard.find( moveToSq )->second = detached; // return detached piece
      return false;   // friendly piece cannot help king esc check
    }
  }
  return false;
}

ChessPiece* ChessBoard::detachPiece( const SquareID detachFromSq )
{
  ChessPiece *detachedPiece = chessboard.find( detachFromSq )->second;
  chessboard.find( detachFromSq )->second = NULL;
  return detachedPiece;
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

bool ChessBoard::ownsPiece( const SquareID sq, const colour_t player, 
                            const Board &cb )
{
  ChessPiece *piece;
  piece = chessboard.find( sq )->second;
  if( piece->getColour() == player ){ 
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
