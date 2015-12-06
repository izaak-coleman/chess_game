#ifndef CHESSPIECE_H
#define CHESSPIECE_H
# include <string> /* std::string */


enum colour_t { BLACK, WHITE };

class ChessPiece{
private:
  /* Class attributes */
  colour_t colour;
public:
  std::string charpiece;

  ChessPiece( colour_t _col, std::string _cp );
  
  colour_t getColour();
  
};
#endif
