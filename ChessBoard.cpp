# include <iostream>
# include <utility>
# include <string>
# include <cstdlib>

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
  cout << "A new chess game is started!" << endl;
  loadStartPositions();
  turn = WHITE; 
}

void ChessBoard::loadStartPositions()
{
  pair< Board::iterator, bool > validInsert;
  /* Allocate ChessPieces to Board. */
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){  
  
      /* Map ChessPieces to squares in chessboard. */
      SquareID square ( rank, file ); 
      validInsert = chessboard.insert( allocatePiece( square ) ); 

      if( validInsert.second == false ){    // check valid mapping, exit if fail 
        cerr << "Problem mapping chess pieces to chessboard." << endl;
        exit(1);
      }
    }
  }
}

void ChessBoard::resetBoard()
{
  ChessPiece *piece;

  /* Delete all remaining peices on board */
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){

      SquareID square ( rank, file );
      piece = chessboard.find( square )->second;    // get pointer val
      delete piece;
      chessboard.find( square )->second = NULL;
    }
  }

  /* Realocate the chesspieces*/
  pair< SquareID, ChessPiece* > newChessPiece;
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){

      SquareID square ( rank, file );
      newChessPiece = allocatePiece( square );
      chessboard.find( square )->second = newChessPiece.second;
    }
  }
  cout << "A new chess game is started!" << endl;

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
      cp = new Rook( WHITE, "Rook", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 2 || file == 7) ){
      SquareID currentLoc ( rank, file );
      cp = new Knight( WHITE, "Knight", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 3 || file == 6) ){
      SquareID currentLoc ( rank, file );
      cp = new Bishop( WHITE, "Bishop", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 4 ) ) {
      SquareID currentLoc ( rank, file );
      cp = new Queen( WHITE, "Queen", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 1 && (file == 5 ) ){
      SquareID currentLoc ( rank, file );
      cp = new King( WHITE, "King", currentLoc );
      whiteKing = currentLoc;                   // Keep track of white king
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 2 && ( file >= 1 && file <= 8 ) ){
      SquareID currentLoc ( rank, file );
      cp = new Pawn( WHITE, "Pawn", currentLoc );
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
      cp = new Rook( BLACK, "Rook", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 2 || file == 7) ){
      SquareID currentLoc ( rank, file );
      cp = new Knight( BLACK, "Knight", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 3 || file == 6) ){
      SquareID currentLoc ( rank, file );
      cp = new Bishop( BLACK, "Bishop", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 4 ) ){
      SquareID currentLoc ( rank, file );
      cp = new Queen( BLACK, "Queen", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 8 && (file == 5 ) ){
      SquareID currentLoc ( rank, file );
      cp = new King( BLACK, "King", currentLoc );
      blackKing = currentLoc;                   // keep track of black king
      return pair< SquareID, ChessPiece* > ( square, cp );
    }
    else if( rank == 7 && ( file >=1 && file <= 8 ) ){
      SquareID currentLoc ( rank, file );
      cp = new Pawn( BLACK, "Pawn", currentLoc );
      return pair< SquareID, ChessPiece* > ( square, cp );
  }
  // else, error
  cp = NULL;
  return pair< SquareID, ChessPiece* > ( square, cp );
}

bool ChessBoard::submitMove( const string source, const string dest )
{
  bool validMove = false;

  /* Load inputs into SquareID format*/
  SquareID sourceSq ( (source.at(1)-48), (source.at(0)-64) );
  SquareID destSq   ( (dest.at(1)-48), (dest.at(0)-64) );

  if( invalidSourceSq( sourceSq, chessboard ) || 
      invalidDestSq( destSq, chessboard ) ) {
     return validMove;
  }
  
  /* Access the chess piece the player wishes to move. */
  ChessPiece *movingPiece;          
  movingPiece = chessboard.find( sourceSq )->second;    
  
  /* Determine if chesspiece at source can reach dest, taking into account
   * its movement constraints */
  if( movingPiece->tryMove( destSq, getBoard() ) ){ // if can move to destSq...
  
    ChessPiece *detachedPiece;          
    detachedPiece = detachPiece( destSq ); // detach the peice at destination...
    movePiece( movingPiece, destSq );      // move the piece at source...

    if( turn == WHITE ){                   // if moving the king, update pos
      if( sourceSq == whiteKing ){
        whiteKing = destSq;
      }
      if( inCheck( whiteKing, chessboard ) ){ // if move endangers king...
        movePiece( movingPiece, sourceSq );   // move piece back to source...
        chessboard.find( destSq )->second = detachedPiece;  // reattach piece...
        if( whiteKing == destSq ){            // return the king if moved
          whiteKing = sourceSq;
        }
        /* Display invalid move message */
        cout << "White's " << movingPiece->charpiece << " cannot move "
             << "to " << static_cast<char> (destSq.second+64)
             << destSq.first << "!" << endl;
      }
      else{ // move does not endanger king, so valid. 
        /* Display valid move message */
        cout << "White's " << movingPiece->charpiece << " moves from "
             << static_cast<char> (sourceSq.second+64) << sourceSq.first
             << " to " << static_cast<char> (destSq.second+64)
             << destSq.first;
        if( detachedPiece != NULL ){
          cout << " taking Black's " << detachedPiece->charpiece << endl;
        }
        else{
          cout << endl;
        }
        delete detachedPiece;                 // take enemy chesspiece at dest
        detachedPiece = NULL;
        validMove = true;
      }
    }

    if( turn == BLACK ){          // perform same actions if turn is black
      if( sourceSq == blackKing ){
        blackKing = destSq;
      }
      if( inCheck( blackKing, chessboard ) ){
        movePiece( movingPiece, sourceSq );
        chessboard.find( destSq )->second = detachedPiece; 
        if( blackKing == destSq ){
          blackKing = sourceSq;
        }
        cout << "Black's " << movingPiece->charpiece << " cannot move "
             << "to " << static_cast<char> (destSq.second+64)
             << destSq.first << "!" << endl;
      }
      else{
        cout << "Black's " << movingPiece->charpiece << " moves from "
             << static_cast<char> (sourceSq.second+64) << sourceSq.first
             << " to " << static_cast<char> (destSq.second+64)
             << destSq.first;
        if( detachedPiece != NULL ){
          cout << " taking White's " << detachedPiece->charpiece << endl;
        }
        else{
          cout << endl;
        }

        delete detachedPiece;
        detachedPiece = NULL;
        validMove = true;
      }
    }
  }
  else{   // ChessPiece cannot reach dest, display invalid move 
    cout << ( ( movingPiece->getColour() == WHITE ) ? "White's " : "Black's " ) 
         << movingPiece->charpiece << " cannot move "
         << "to " << static_cast<char> (destSq.second+64)
         << destSq.first << "!" << endl;
  }


  if( validMove ){ 
  
    /* Check if opponent is in check, checkmate or stalemate */
    if( turn == BLACK && inCheck( whiteKing, chessboard ) ){
      if( inCheckMate( whiteKing ) ){           
        cout << "White is in checkmate" << endl;
       return true;
      }
      else{
        cout << "White is in check" << endl;
      }
    }
    else if( turn == BLACK && staleMate( whiteKing ) ){
      cout << "White to move is in stalemate" << endl;
      return true;
    }

    if( turn == WHITE && inCheck( blackKing, chessboard ) ){
      if( inCheckMate( blackKing ) ){
        cout << "Black is in checkmate" << endl;
        return true;
      }
      else {
        cout << "Black is in check" << endl;
      }
    }
    else if( turn == WHITE && staleMate( blackKing ) ){
      cout << "Black to move is in stalemate" << endl;
      return true;
    }
  }

  turn = ( ( turn == WHITE ) ? BLACK : WHITE );     // switch turns
  return true;
}

bool ChessBoard::staleMate( SquareID kingSq ){

  bool staleMate = true;
  ChessPiece *kingPiece;
  kingPiece = chessboard.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();        // get the colour of king
  ChessPiece *friendly, *detached;

  /* Find all pieces of player */
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){
      SquareID friendSq( rank, file );

      if( emptySquare( friendSq, chessboard ) ||
          !ownsPiece( friendSq, kingCol, chessboard ) ){
        continue;
      }
      else{ // piece belongs to player

        friendly = chessboard.find( friendSq )->second;
        for( int rank=1; rank <= MAX_RANK; rank++ ){
          for( int file=1; file <= MAX_FILE; file++ ){
            SquareID destSq( rank, file );
            
            /* Determine if the moving the friendly piece is possible */
            if( (emptySquare( destSq, chessboard ) || 
                !ownsPiece( destSq, kingCol, chessboard ) ) &&
                friendly->tryMove( destSq, chessboard ) ){ 

              detached = detachPiece( destSq );
              movePiece( friendly, destSq );         // move the friendly 
              if( friendSq == kingSq ){              // if king, update position
                kingSq = destSq;
              }

              if( !inCheck( kingSq, chessboard ) ){  // if king not endangered...
                movePiece( friendly, friendSq );
                chessboard.find( destSq )->second = detached;
                staleMate = false;                   // then not stalemate
                return staleMate;
              }
              else{                        // reattach pieces and keep searching
                movePiece( friendly, friendSq );
                chessboard.find( destSq )->second = detached;
              }
              if( destSq == kingSq ){     // if king, return to position in game
                kingSq = friendSq;
              }
            }
          }
        }
      }
    }
  }
  return staleMate;
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

  if( outOfRange( sourceSq ) ){
    cout << "Position " << static_cast<char> (sourceSq.second+64)
         << sourceSq.first << " does not exist!" << endl;
    return true;
  }
  if( emptySquare( sourceSq, chessboard ) ){
    cout << "There is no piece at position " 
         << static_cast<char> (sourceSq.second+64) << sourceSq.first
         << "!" << endl;
    return true;
  }
  if( !ownsPiece( sourceSq, chessboard ) ){
    cout << "It is not " << ( (turn == WHITE) ? "Black's" : "White's" )
         << " turn to move!" << endl;
    return true;
  }
  // else valid source square
    return false;
}

bool ChessBoard::invalidDestSq( const SquareID destSq, const Board &cb )
{
  if( outOfRange( destSq ) ){
    cout << "Position " << static_cast<char> (destSq.second+64)
         << destSq.first << " does not exist!" << endl;
    return true;
  }
  if( !emptySquare( destSq, cb ) && ownsPiece( destSq, cb ) ){
    cout << ( (turn == WHITE) ? "White" : "Black" ) << " cannot "
         << "take own piece. " << endl;
      return true;
  }
  // else
    return false;
}

bool ChessBoard::inCheck( const SquareID kingSq, const Board &cb )
{
  bool inCheck = false;

  ChessPiece *enemyPiece, *kingPiece;
  kingPiece = cb.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();

  /* Seach board for an enemy that can attack king */
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){
      SquareID searchSq ( rank, file );

      if( emptySquare( searchSq, cb ) || ownsPiece( searchSq, kingCol, cb ) ){
        continue;
      }
      else{
        enemyPiece = cb.find( searchSq )->second;
        if( enemyPiece->tryMove( kingSq, cb ) ){   // if enemy can reach king...
          inCheck = true;
          return inCheck;                          // king in check
        }
      }
    }
  }
 return inCheck;    // not in check, nothing can attack king
}

bool ChessBoard::inCheckMate( SquareID kingSq ){

  ChessPiece *friendlyPiece, *kingPiece;
  kingPiece = chessboard.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();      // get king colour

  bool checkMate = true;

  /* Find all friendly pieces */
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){

      SquareID friendSq ( rank, file );
      if( emptySquare( friendSq, chessboard ) ||
          !ownsPiece( friendSq, kingCol, chessboard ) ){
        continue;
      }
      else{                                       // must be a friendly
  
        /* Loop through all positions, and see if friendlyPiece can move
           to a position that protects the king */
        friendlyPiece = chessboard.find( friendSq )->second;
        for( int rank=1; rank <= MAX_RANK; rank++ ){
          for( int file=1; file <= MAX_FILE; file++ ){

            SquareID moveToSq ( rank, file );
            if( pieceCanProtectKing( friendlyPiece, moveToSq, friendSq, kingSq ) ){
              checkMate = false;
              return checkMate;      // finish loop when found first
            }                        // friendly that can help
          }
        }
      }
    }
  }
  return checkMate;        // no pieces can help king, so it is check mate
}

bool ChessBoard::pieceCanProtectKing( ChessPiece *friendly, 
                                         SquareID moveToSq,
                                         const SquareID moveFromSq,
                                         SquareID kingSq ){

  ChessPiece *detached, *kingPiece;
  kingPiece = chessboard.find( kingSq )->second;
  colour_t kingCol = kingPiece->getColour();
  bool notOwnPiece = false;

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

    /* If it is the king moving, temporarily update king position*/
    if( moveFromSq == kingSq ){
        kingSq = moveToSq;
    } 

    /* If the friendly can thwart check from new position, no check mate */
    if( !inCheck( kingSq, chessboard ) ){ 
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

ChessBoard::~ChessBoard()
{
  ChessPiece *piece;
  /* Delete all remaining peices on board */
  for( int rank=1; rank <= MAX_RANK; rank++ ){
    for( int file=1; file <= MAX_FILE; file++ ){
      SquareID square ( rank, file );
      piece = chessboard.find( square )->second;
      delete piece;
      chessboard.find( square )->second = NULL;
    }
  }
}
