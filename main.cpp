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

  cb.submitMove( "A1", "A3" );
  cout << endl << endl << " Rook moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "B1", "C3" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "E1", "E5" );
  cout << endl << endl << " Queen moved " << endl;
  cb.display_board( cb.getBoard() );

  return 0;
}
