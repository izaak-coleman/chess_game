#ifndef CHESSPIECE_H
#define CHESSPIECE_H


enum colour_t { BLACK, WHITE };

class ChessPiece{
public:
  colour_t colour;
  char charpiece;
  ChessPiece( colour_t _col, char _cp );
};
#endif
