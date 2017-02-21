#ifndef __CHESSDEFS_H__
#define __CHESSDEFS_H__


typedef enum {

	WHITE = 0,
	BLACK

} Color;

typedef enum {

	NONE = '.',

	WHITE_KING = 'K',
	BLACK_KING = 'k',

	WHITE_QUEEN = 'Q',
	BLACK_QUEEN = 'q',

	WHITE_ROOK = 'R',
	BLACK_ROOK = 'r',

	WHITE_BISHOP = 'B',
	BLACK_BISHOP = 'b',

	WHITE_KNIGHT = 'N',
	BLACK_KNIGHT = 'n',

	WHITE_PAWN = 'P',
	BLACK_PAWN = 'p',

} Piece;

typedef enum {

	a1 = 0, b1, c1, d1, e1, f1, g1, h1,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a8, b8, c8, d8, e8, f8, g8, h8

} Square;

typedef enum {

	Rank1 = 0, Rank2, Rank3, Rank4, Rank5, Rank6, Rank7, Rank8

} Rank;

typedef enum {

	a = 0, b, c, d, e, f, g, h

} File;


/* get color for piece */
Color chessdefs_piece_color( Piece p );

#endif /* __CHESSDEFS_H__ */
