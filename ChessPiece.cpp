// ChessPiece.cpp
# include <string> /* std::string */
# include <map>
# include <utility>
# include <string>

# include "Types.h"
# include "ChessPiece.h"

using namespace std;

ChessPiece::ChessPiece( colour_t _col, string _cp, SquareID _loc )
: colour( _col ), currentLoc( _loc ), charpiece( _cp )
{}

colour_t ChessPiece::getColour()
{
  return colour;
}

SquareID ChessPiece::getCurrentLoc()
{
  return currentLoc;
}

void ChessPiece::setCurrentLoc( SquareID destSq )
{
  currentLoc = destSq;
}

bool isNotBlocked( const SquareID destSq, SquareID nextSq,
                   const Board &chessboard, string dir )
{
  /* Get ranks and files */
  int nextRank, nextFile, destRank, destFile;
  nextRank = nextSq.first;  nextFile = nextSq.second;
  destRank = destSq.first;  destFile = destSq.second;

  /* If made to nextSq has reached destSq without blocking, return true */
  if( nextSq == destSq ){
    return true;
  }

  /* Otherwise, keep on checking! */

  /* ChessPiece piece is moving forwards */
  if( dir == "Forward" ){
    nextSq.first = ( nextRank+1 );            // move forward one rank
    if( chessboard[ nextSq ].second != NULL ) // if path is blocked
    {
      return false;                           // do not progress, return blocked
    }
    else{                                     // path empty so far, check next sq
      isNotBlocked( destSq, nextSq, chessboard, dir ); // Check next square
    }
  }
  /* ChessPiece piece is moving backwards */
  if else( dir == "Backward" ){
    nextSq.first = ( nextRank-1 );
    if( chessboard[ nextSq ].second != NULL )
    {
      return false;
    }
    else{
      isNotBlocked( destSq, nextSq, chessboard, dir );
    }
  }
  /* ChessPiece piece has been moved to the right */
  if( dir == "Right" ){
    nextSq.second = ( nextFile+1 );
    if( chessboard[ nextSq ].second != NULL )
    {
      return false;
    }
    else{
      isNotBlocked( destSq, nextSq, chessboard, dir );
    }
  }
  /* ChessPiece piece has been moved to the left */
  if( dir == "Left" ){
    nextSq.second = ( nextFile-1 );
    if( chessboard[ nextSq ].second != NULL )
    {
      return false;
    }
    else{
      isNotBlocked( destSq, nextSq, chessboard, dir );
    }
  }
  /* ChessPiece piece has been moved up and to right */
  if( dir == "UpRight" ){
    nextSq.first =  ( nextRank+1 );           // move one rank and one file fwd
    nextSq.second = ( nextFile+1 );
    if( chessboard[ nextSq ].second != NULL ) // if path is blocked
    {
      return false;                           // do not progress, return blocked
    }
    else{                                     // path empty so far, check next sq
      isNotBlocked( destSq, nextSq, chessboard, dir );
    }
  }
  /* ChessPiece piece has been moved down and to right */
  if( dir == "DownRight" ){
    nextSq.first =  ( nextRank-1 );           // move one rank back
    nextSq.second = ( nextFile+1 );           // move one file to right
    if( chessboard[ nextSq ].second != NULL ) // if path is blocked
    {
      return false;                           // do not progress, return blocked
    }
    else{                                     // path empty so far, check next sq
      isNotBlocked( destSq, nextSq, chessboard, dir ); // Check next square
    }
  }
  /* ChessPiece piece has been moved forward */
  if( dir == "Forward" ){
    nextSq.first = ( nextRank+1 );            // move forward one rank
    if( chessboard[ nextSq ].second != NULL ) // if path is blocked
    {
      return false;                           // do not progress, return blocked
    }
    else{                                     // path empty so far, check next sq
      isNotBlocked( destSq, nextSq, chessboard, dir ); // Check next square
    }
  }
  /* ChessPiece piece has been moved forward */
  if( dir == "Forward" ){
    nextSq.first = ( nextRank+1 );            // move forward one rank
    if( chessboard[ nextSq ].second != NULL ) // if path is blocked
    {
      return false;                           // do not progress, return blocked
    }
    else{                                     // path empty so far, check next sq
      isNotBlocked( destSq, nextSq, chessboard, dir ); // Check next square
    }
  }

}

string ChessPiece::movingDir( SquareID destSq )
{
  string direction;
  int destRank, destFile;
  destRank = destSq.first;
  destFile = destSq.second;

  /* Forward: Destination rank higher than current rank, no change in file*/
  if( (destRank > currentLoc.first) && (destFile == currentLoc.second) ){
    direction = "Forward";
  } 

  /* Backward: Destination rank lower than current rank, no change in file*/
  else if( (destRank < currentLoc.first) && (destFile == currentLoc.second) ){
    direction = "Backward";
  }
  
  /* Right: Destination file greater thank current file, no change in rank*/
  else if( (destRank == currentLoc.first) && (destFile > currentLoc.second) ){
    direction = "Right";
  }

  /* Left: Destination file lower than current file, no change in rank*/
  else if( (destRank == currentLoc.first) && (destFile < currentLoc.second) ){
    direction = "Left";
  }
  
  /* UpRight: Destination file and rank greater than current file and rank*/
  else if( (destRank > currrentLoc.first) && (destFile > currentLoc.second) ){
    direction = "UpRight";
  }

  /* DownRight: Destination file greater than current file, destination rank
   * less thank current rank */
  else if( (destRank < currentLoc.first) && (destFile > currentLoc.second) ){
    direction = "DownRight";
  }
  
  /* UpLeft: Destination file is less than current file, destination rank
   * greater than current rank*/
  else if( (destRank > currentLoc.first) && (destFile < currentLoc.second) ){
    direction = "UpLeft";
  } 
  
  /* DownLeft: Destination file and rank is less than current rank and file*/
  else if( ( destRank < currentLoc.first) && (destFile < currentLoc.second ) ){
    direction = "DownLeft";
  }
  else{
    /* Throw error */
    cout << "Impossible dest" << endl;
  }

  return direction;
}

ChessPiece::~ChessPiece(){}
