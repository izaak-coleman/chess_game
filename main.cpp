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

  cout << cb.submitMove( "A7", "H8" );
  cout << cb.submitMove( "A8", "H8" );
  cout << cb.submitMove( "H7", "H8" );
  cout << cb.submitMove( "H8", "H8" );
  cout << cb.submitMove( "D1", "E1" );
  cout << cb.submitMove( "B3", "H8" );


  return 0;
}
