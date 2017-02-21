#include <chessdefs.h>
#include <assert.h>


Color chessdefs_piece_color( Piece p )
{
	switch ( p ) {

	case WHITE_KING:
	case WHITE_QUEEN:
	case WHITE_ROOK:
	case WHITE_BISHOP:
	case WHITE_KNIGHT:
	case WHITE_PAWN:
		return WHITE;

	case BLACK_KING:
	case BLACK_QUEEN:
	case BLACK_ROOK:
	case BLACK_BISHOP:
	case BLACK_KNIGHT:
	case BLACK_PAWN:
		return BLACK;

	default:
		assert( 0 );
		break;
	}
}
