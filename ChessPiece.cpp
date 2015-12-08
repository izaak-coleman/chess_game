// ChessPiece.cpp

# include <iostream>
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

bool ChessPiece::isNotBlocked( const SquareID destSq, SquareID nextSq,
                   const Board &chessboard, string dir )
{
  /* Get ranks and files */
  int nextRank, nextFile, destRank, destFile;
  nextRank = nextSq.first;  nextFile = nextSq.second;
  destRank = destSq.first;  destFile = destSq.second;
  cout << "The value of nextSq: " << nextSq.first << " " << nextSq.second << endl;

  /* Switch to stop recursive function checking the start location */
  bool start = false;
  if( nextSq == currentLoc ){
      cout << "Start switched on:" << endl;
      start = true;
  }

  /* If reached destSq without blocking, return true */
  cout << "Valuue of DestSq in isnb: " << destSq.first << destSq.second << endl;
  if( nextSq == destSq ){
    cout << "NextSq == destSq comp not working " << endl;
    return true;
  }

  /* Return false if square we are checking contains a piece*/
  if( chessboard.find( nextSq )->second != NULL && start != true ) {
    return false;
  }


  /* Otherwise move to next square and recursively check! */

  /* ChessPiece piece is moving forwards */
  if( dir == "Forward" ){
    nextSq.first = ( nextRank+1 );          // move forward one rank
    cout << " Entered forward condition " << endl;
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){ // Check next square
      return true;
    }
  }

  /* ChessPiece piece is moving backwards */
  else if( dir == "Backward" ){
    nextSq.first = ( nextRank-1 );
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  /* ChessPiece piece has been moved to the right */
  else if( dir == "Right" ){
    nextSq.second = ( nextFile+1 );
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  /* ChessPiece piece has been moved to the left */
  else if( dir == "Left" ){
    nextSq.second = ( nextFile-1 );
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  /* ChessPiece piece has been moved up and to right */
  else if( dir == "UpRight" ){
    nextSq.first =  ( nextRank+1 );        // move one rank and one file fwd
    nextSq.second = ( nextFile+1 );
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  /* ChessPiece piece has been moved down and to right */
  else if( dir == "DownRight" ){
    nextSq.first =  ( nextRank-1 );           
    nextSq.second = ( nextFile+1 );           
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  /* ChessPiece piece has been moved up and to left */
  else if( dir == "UpLeft" ){
    nextSq.first =  ( nextRank+1 );            
    nextSq.second = ( nextFile-1 );            
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  /* ChessPiece piece has been moved forward */
  else if( dir == "DownLeft" ){
    nextSq.first =  ( nextRank-1 );            
    nextSq.second = ( nextRank-1 );            
    if( isNotBlocked( destSq, nextSq, chessboard, dir ) ){
      return true;
    }
  }

  else {// direction error
    cout << "Direction error, in isNotBlocked " << endl;
  }
  return false;

}

string ChessPiece::movingDir( SquareID destSq )
{
  string direction;
  int destRank, destFile;
  destRank = destSq.first;
  destFile = destSq.second;

  if( destRank > currentLoc.first ){       // traveling forwards ...

    if( destFile == currentLoc.second ){
      direction = "Forward";
    } 
    else if( destFile > currentLoc.second ){
      direction = "UpRight";              // and to the right
    }
    else if( destFile < currentLoc.second ){
      direction = "UpLeft";               // and to the left
    }
  }

  else if( destRank < currentLoc.first ){ // traveling backwards ...
    
    if( destFile == currentLoc.second ){
      direction = "Backward";
    }
    else if( destFile > currentLoc.second ){
      direction = "DownRight";            // and to the right
    }
    else if( destFile < currentLoc.second ){
      direction = "DownLeft";             // and to the left
    }
  }
  
  else if( (destRank == currentLoc.first) && (destFile > currentLoc.second) ){
    direction = "Right";
  }

  else if( (destRank == currentLoc.first) && (destFile < currentLoc.second) ){
    direction = "Left";
  }

  else{ // tried to move nowhere
    /* Throw move nowhere error*/
  }

  return direction;
}

ChessPiece::~ChessPiece(){}
