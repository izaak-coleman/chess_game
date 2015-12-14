OBJ=ChessMain.o ChessBoard.o ChessPiece.o Pawn.o Rook.o Knight.o Bishop.o King.o Queen.o
EXE=chess
CXX=g++
COMPFLAGS=-Wall -ggdb -MMD
OBJDIR=./objects/

$(EXE):$(OBJ)
	$(CXX) $(COMPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp
	$(CXX) $(COMPFLAGS) -c $< 

-include $(OBJ:.o=.d)	

.PHONY: clean

clean:
	echo cleaning...
	mv ./*.o $(OBJDIR)
	mv ./*.d $(OBJDIR)

