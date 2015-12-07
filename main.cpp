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


  return 0;
}
