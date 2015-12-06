#ifdef CHESSPIECE_H
#define CHESSPIECE_H

class ChessPiece{
private:
  enum colour_t { BLACK, WHITE };
  colour_t colour;
  char charPiece;
public:
  ChessPiece( colour_t _col, char _cp );
};
#endif
