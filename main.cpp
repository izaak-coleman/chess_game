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
//  cb.display_board( cb.getBoard() );
//    cout << "===========================" << endl;
//    cout << "White checkmate test" << endl;
//    cout << "===========================" << endl;
//    cout << endl; 
//
//  cb.submitMove("F2","F3");
//  cout << "* Valid" << endl;
//  cout << endl;   cout << endl;
//  cout << "NEXT BOARD BELOW FROM MAIN: " << endl;
//  cb.display_board( cb.getBoard() );
//
//  cb.submitMove("E7","E5");
//  cout << "* Valid" << endl;
//  cout << endl;   cout << endl;
//  cout << "NEXT BOARD BELOW FROM MAIN: " << endl;
//  cb.display_board( cb.getBoard() );
//
//  cb.submitMove("G2","G4");
//  cout << "* Valid" << endl;
//  cout << endl;   cout << endl;
//  cout << "NEXT BOARD BELOW FROM MAIN: " << endl;
//  cb.display_board( cb.getBoard() );
//
//  cb.submitMove("D8","H4");
//  cout << "* Valid" << endl;
//  cout << endl;   cout << endl;
//  cout << "NEXT BOARD BELOW FROM MAIN: " << endl;
//  cb.display_board( cb.getBoard() );


cout << "===========================" << endl;
cout << "Black checkmate test" << endl;
cout << "===========================" << endl;
cout << endl; 

cb.submitMove("B1","C3");
cout << "* Valid" << endl;
cout << endl;   cout << endl;

cb.submitMove("H7","H6");
cout << "* Valid" << endl;
cout << endl;   cout << endl;

cb.submitMove("E2","E4");
cout << "* Valid" << endl;
cout << endl;   cout << endl;

cb.submitMove("G7","G5");
cout << "* Valid" << endl;
cout << endl;   cout << endl;
                                                                   
cb.submitMove("D2","D4");
cout << "* Valid" << endl;
cout << endl;   cout << endl;

cb.submitMove("F7","F6");
cout << "* Valid" << endl;
cout << endl;   cout << endl;

cb.submitMove("D1","H5");
cout << "* Valid" << endl;
cout << endl;   cout << endl;


//  cb.submitMove( "F2", "F3" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "A7", "A5" );
//  cout << endl << endl << " Pawn moved " << endl;
//  cb.display_board( cb.getBoard() );
//
//
//  cb.submitMove( "G2", "G4" );
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
