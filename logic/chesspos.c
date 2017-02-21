#include <chesspos.h>
#include <chessdefs.h>
#include <bitboard.h>

#include <assert.h>
#include <stddef.h>


static uint64_t* chesspos_color_mask( ChessPos* pos, Piece piece );
static uint64_t* chesspos_piece_mask( ChessPos* pos, Piece piece );


void chesspos_set_square( ChessPos* pos, Square square, Piece piece )
{
	assert( NULL != pos );

	uint64_t* color_mask = chesspos_color_mask( pos, piece );
	uint64_t* piece_mask = chesspos_piece_mask( pos, piece );

	assert( NULL != color_mask );	
	assert( NULL != piece_mask );

	uint64_t square_mask = bitboard_square( square );

	*color_mask |= square_mask;
	*piece_mask |= square_mask;
}

Piece chesspos_get_square( ChessPos* pos, Square square )
{
	assert( NULL != pos );

	uint64_t mask = bitboard_square( square );

	Piece piece = NONE;

	if ( ( pos->king & mask ) && ( pos->white & mask ) ) {
		piece = WHITE_KING;
	} else if ( ( pos->king & mask ) && ( pos->black & mask ) ) {
		piece = BLACK_KING;
	} else if ( ( pos->queen & mask ) && ( pos->white & mask ) ) {
		piece = WHITE_QUEEN;
	} else if ( ( pos->queen & mask ) && ( pos->black & mask ) ) {
		piece = BLACK_QUEEN;
	} else if ( ( pos->rook & mask ) && ( pos->white & mask ) ) {
		piece = WHITE_ROOK;
	} else if ( ( pos->rook & mask ) && ( pos->black & mask ) ) {
		piece = BLACK_ROOK;
	} else if ( ( pos->bishop & mask ) && ( pos->white & mask ) ) {
		piece = WHITE_BISHOP;
	} else if ( ( pos->bishop & mask ) && ( pos->black & mask ) ) {
		piece = BLACK_BISHOP;
	} else if ( ( pos->knight & mask ) && ( pos->white & mask ) ) {
		piece = WHITE_KNIGHT;
	} else if ( ( pos->knight & mask ) && ( pos->black & mask ) ) {
		piece = BLACK_KNIGHT;
	} else if ( ( pos->pawn & mask ) && ( pos->white & mask ) ) {
		piece = WHITE_PAWN;
	} else if ( ( pos->pawn & mask ) && ( pos->black & mask ) ) {
		piece = BLACK_PAWN;
	}

	return piece;
}

void chesspos_clear_square( ChessPos* pos, Square square )
{
	assert( NULL != pos );

	uint64_t mask = ~bitboard_square( square );

	pos->king &= mask;
	pos->queen &= mask;
	pos->rook &= mask;
	pos->bishop &= mask;
	pos->knight &= mask;
	pos->pawn &= mask;
	pos->white &= mask;
	pos->black &= mask;
}

void chesspos_setup_start_pos( ChessPos* pos )
{
	assert( NULL != pos );

	pos->king = bitboard_square( e1 ) | bitboard_square( e8 );
	pos->queen = bitboard_square( d1 ) | bitboard_square( d8 );
	pos->rook = bitboard_square( a1 ) | bitboard_square( h1 ) |
			bitboard_square( a8 ) | bitboard_square( h8 );
	pos->bishop = bitboard_square( c1 ) | bitboard_square( f1 ) |
			bitboard_square( c8 ) | bitboard_square( f8 );
	pos->knight = bitboard_square( b1 ) | bitboard_square( g1 ) |
			bitboard_square( b8 ) | bitboard_square( g8 );
	pos->pawn = bitboard_rank( Rank2 ) | bitboard_rank( Rank7 );
	pos->white = bitboard_rank( Rank1 ) | bitboard_rank( Rank2 );
	pos->black = bitboard_rank( Rank7 ) | bitboard_rank( Rank8 );

	pos->castling = bitboard_square( c1 ) | bitboard_square( g1 ) |
			bitboard_square( c8 ) | bitboard_square( g8 );
	pos->en_passant = 0;

}


static uint64_t* chesspos_color_mask( ChessPos* pos, Piece piece )
{
	assert( NULL != pos );

	uint64_t* result = NULL;

	if ( WHITE == chessdefs_piece_color( piece ) ) {

		result = &( pos->white );

	} else {

		result = &( pos->black );
	}

	return result;
}

static uint64_t* chesspos_piece_mask( ChessPos* pos, Piece piece )
{
	assert( NULL != pos );

	uint64_t* result = NULL;

	switch ( piece ) {

	case WHITE_KING:
	case BLACK_KING:
		result = &( pos->king );
		break;

	case WHITE_QUEEN:
	case BLACK_QUEEN:
		result = &( pos->queen );
		break;

	case WHITE_ROOK:
	case BLACK_ROOK:
		result = &( pos->rook );
		break;

	case WHITE_BISHOP:
	case BLACK_BISHOP:
		result = &( pos->bishop );
		break;

	case WHITE_KNIGHT:
	case BLACK_KNIGHT:
		result = &( pos->knight );
		break;

	case WHITE_PAWN:
	case BLACK_PAWN:
		result = &( pos->pawn );
		break;

	default:
		result = NULL;
		break;
	}

	return result;
}

