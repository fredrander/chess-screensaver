#ifndef __chesspos_h__
#define __chesspos_h__


#include <chessdefs.h>
#include <stdint.h>


// a chess position
typedef struct
{
	uint64_t white;
	uint64_t black;
	uint64_t king;
	uint64_t queen;
	uint64_t rook;
	uint64_t bishop;
	uint64_t knight;
	uint64_t pawn;

	uint64_t castling;
	uint64_t en_passant;
	
} ChessPos;


// set piece at square
void chesspos_set_square( ChessPos* pos, Square square, Piece piece );

// get piece at square
Piece chesspos_get_square( ChessPos* pos, Square square );

// clear one square
void chesspos_clear_square( ChessPos* pos, Square square );

// setup start position
void chesspos_setup_start_pos( ChessPos* pos );


#endif // __chesspos_h__

