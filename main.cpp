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

  cb.submitMove( "D2", "D4" );
  cout << endl << endl << " Pawn moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "A1", "A3" );
  cout << endl << endl << " Rook moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "A3", "F3" );
  cout << endl << endl << " Rook moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "B1", "C3" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "C3", "D5" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "D5", "E7" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "E7", "C8" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );
  
  cb.submitMove( "C8", "C6" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "D1", "D2" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "D2", "D3" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "D3", "E3" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  cb.submitMove( "E3", "F3" );
  cout << endl << endl << " Knight moved " << endl;
  cb.display_board( cb.getBoard() );

  


  

  return 0;
}
