# include <iostream>
# include <map>
# include <utility>

# include "ChessBoard.h"
# include "ChessPiece.h"
# include "Rook.h"

using namespace std;

int main()
{
  cout << endl << endl << " ------------ Board ----------- " << endl;
  ChessBoard cb;
  cb.display_board( cb.getBoard() );

  cout << endl << endl << "Next turn: " << cb.getTurn() << endl;

  cb.submitMove( "A2", "A4" );
  cout << endl << endl << " Pawn moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "A1", "A8" );
  cout << endl << endl << " Rook moved " << endl;
  cb.display_board( cb.getBoard() );
  return 0;
}
