# include <iostream>
# include <map>
# include <utility>

# include "ChessBoard.h"
# include "ChessPiece.h"

using namespace std;

int main()
{
  cout << endl << endl << " ------------ Board ----------- " << endl;
  ChessBoard cb;
  cb.display_board( cb.getBoard() );

  cout << endl << endl << "Next turn: " << cb.getTurn() << endl;

  cb.submitMove( "D2", "D4" );
  
  cb.display_board( cb.getBoard() );

  cb.submitMove( "D4", "D5" );
  cb.display_board( cb.getBoard() );
  cb.submitMove( "D5", "D6" );
  cb.display_board( cb.getBoard() );
  cb.submitMove( "D6", "D7" );
  cb.display_board( cb.getBoard() );
  cb.submitMove( "D7", "D8" );
  cb.display_board( cb.getBoard() );


  return 0;
}
