#include <king.h>
#include <queen.h>
#include <rook.h>
#include <bishop.h>
#include <knight.h>
#include <pawn.h>
#include <bitboard.h>
#include <block.h>
#include <chesslogic.h>

/**************************************************************************/

static uint64_t chesslogic_valid_destinations( ChessPos* pos, Square from );
static bool chesslogic_in_check( ChessPos* pos, Color color );

/**************************************************************************/

bool chesslogic_is_legal_move( ChessPos* pos, Square from, Square to )
{
	/* get all posible destinations from square */
	uint64_t destinations = chesslogic_valid_destinations( pos, from );
	/* check that desired destination is among possible destinations */
	uint64_t destMask = bitboard_square( to );
	if ( ( destinations & destMask ) == 0 ) {

		return false;
	}

	/* perform move to verify that we do not step in to a check */
	ChessPos tmpPos = ( *pos );

	Piece piece = chesspos_get_square( &tmpPos, from );

	/* handle capture */
	Piece destPiece = chesspos_get_square( &tmpPos, to );

	if ( destPiece == NONE ) {

		/* en passant capture? */
		if ( piece == WHITE_PAWN ) {

			if ( ( destMask & tmpPos.en_passant ) != 0 ) {

				/* clear en passant mask */
				tmpPos.en_passant = 0;
				Square captureSquare = to - 8;
				chesspos_clear_square( &tmpPos, captureSquare );
			}

		} else if ( piece == BLACK_PAWN ) {

			if ( ( destMask & tmpPos.en_passant ) != 0 ) {

				/* clear en passant mask */
				tmpPos.en_passant = 0;
				Square captureSquare = to + 8;
				chesspos_clear_square( &tmpPos, captureSquare );
			}
		}

	} else {

		chesspos_clear_square( &tmpPos, to );
	}

	chesspos_clear_square( &tmpPos, from );
	chesspos_set_square( &tmpPos, to, piece );

	Color color = chessdefs_piece_color( piece );
	if ( chesslogic_in_check( &tmpPos, color ) ) {

		return false;
	}

	return true;
}

/**************************************************************************/

static uint64_t chesslogic_valid_destinations( ChessPos* pos, Square from )
{

	Piece piece = chesspos_get_square( pos, from );

	uint64_t destinations = 0;

	switch ( piece ) {

	case WHITE_KING:
		{
			bool shortCastlingValid = ( pos->castling | bitboard_square( g1 ) ) != 0;
			bool longCastlingValid = ( pos->castling | bitboard_square( c1 ) ) != 0;
			destinations = king_valid_destinations( from, WHITE, shortCastlingValid, longCastlingValid );
		}
		break;

	case BLACK_KING:
		{
			bool shortCastlingValid = ( pos->castling | bitboard_square( g8 ) ) != 0;
			bool longCastlingValid = ( pos->castling | bitboard_square( c8 ) ) != 0;
			destinations = king_valid_destinations( from, BLACK, shortCastlingValid, longCastlingValid );
		}
		break;

	case WHITE_QUEEN:
	case BLACK_QUEEN:
		destinations = queen_valid_destinations( from );
		break;

	case WHITE_ROOK:
	case BLACK_ROOK:
		destinations = rook_valid_destinations( from );
		break;

	case WHITE_BISHOP:
	case BLACK_BISHOP:
		destinations = bishop_valid_destinations( from );
		break;

	case WHITE_KNIGHT:
	case BLACK_KNIGHT:
		destinations = knight_valid_destinations( from );
		break;

	case WHITE_PAWN:
		{
			uint64_t destinationsCapture = pawn_valid_destinations( from, WHITE, true );
			destinationsCapture &= ( pos->black | pos->en_passant );

			uint64_t destinationsNoCapture = pawn_valid_destinations( from, WHITE, false );
			destinationsNoCapture &= ~pos->black;

			destinations = destinationsCapture | destinationsNoCapture;
		}
		break;

	case BLACK_PAWN:
		{
			uint64_t destinationsCapture = pawn_valid_destinations( from, BLACK, true );
			destinationsCapture &= ( pos->white | pos->en_passant );

			uint64_t destinationsNoCapture = pawn_valid_destinations( from, BLACK, false );
			destinationsNoCapture &= ~pos->white;

			destinations = destinationsCapture | destinationsNoCapture;
		}
		break;

	default:
		destinations = 0;
		break;
	}

	/* cannot capture own piece */
	switch ( piece ) {

	case WHITE_KING:
	case WHITE_QUEEN:
	case WHITE_ROOK:
	case WHITE_BISHOP:
	case WHITE_KNIGHT:
	case WHITE_PAWN:
		destinations &= ~pos->white;
		break;

	case BLACK_KING:
	case BLACK_QUEEN:
	case BLACK_ROOK:
	case BLACK_BISHOP:
	case BLACK_KNIGHT:
	case BLACK_PAWN:
		destinations &= ~pos->black;
		break;

	default:
		break;
	}

	/* check if blocked */
	if ( piece != WHITE_KNIGHT && piece != BLACK_KNIGHT ) {

		for ( uint8_t to = 0; to < 64; ++to ) {

			uint64_t mask = bitboard_square( to );

			if ( destinations & mask ) {

				uint64_t block = block_mask( from, to );

				if ( ( pos->white & block ) || ( pos->black & block ) ) {

					/* blocked */
					destinations &= ~mask;
				}
			}
		}

	}

	return destinations;
}


static bool chesslogic_in_check( ChessPos* pos, Color color )
{
	uint64_t kingMask = 0;
	uint64_t enemyMask = 0;
	if ( color == WHITE ) {

		kingMask = ( pos->white & pos->king );
		enemyMask = pos->black;

	} else {

		kingMask = ( pos->black & pos->king );
		enemyMask = pos->white;
	}

	/* find all enemy pieces and check if any have my king position */
	/* as a valid destination */
	for ( Square s = a1; s <= h8; ++s ) {

		uint64_t squareMask = bitboard_square( s );

		if ( ( squareMask & enemyMask ) != 0 ) {

			uint64_t destinations = chesslogic_valid_destinations( pos, s );

			if ( ( destinations & kingMask ) != 0 ) {

				return true;
			}
		}
	}

	return false;
}

