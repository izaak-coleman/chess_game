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
    cout << "===========================" << endl;
    cout << "White checkmate test" << endl;
    cout << "===========================" << endl;
    cout << endl; 

    cb.submitMove("F2","F3");
    cout << "* Valid" << endl;
    cout << endl;   cout << endl;
    cb.display_board( cb.getBoard() );

    cb.submitMove("E7","E5");
    cout << "* Valid" << endl;
    cout << endl;   cout << endl;
    cb.display_board( cb.getBoard() );

    cb.submitMove("G2","G4");
    cout << "* Valid" << endl;
    cout << endl;   cout << endl;
    cb.display_board( cb.getBoard() );

    cb.submitMove("D8","H4");
    cout << "* Valid" << endl;
    cout << endl;   cout << endl;
    cb.display_board( cb.getBoard() );


//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A2", "A4" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//

  return 0;
}
