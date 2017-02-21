#include <chesspos.h>
#include <bitboard.h>
#include <chesslogic.h>

#include <stdio.h>


static void print_board( ChessPos* p );
static void print_destinations( Square from, uint64_t dest );


int main( int argc, char* argv[] )
{
	(void) argc;
	(void) argv;

	ChessPos p;

	chesspos_setup_start_pos( &p );

	chesspos_clear_square( &p, d2 );
	chesspos_set_square( &p, d4, WHITE_PAWN );

	chesspos_clear_square( &p, g8 );
	chesspos_set_square( &p, f6, BLACK_KNIGHT );

	print_board( &p );

	for ( Square from = a1; from <= h8; ++from ) {

		for ( Square to = a1; to <= h8; ++to ) {

			if ( chesslogic_is_legal_move( &p, from, to ) ) {

				printf( "%d -> %d\n", ( int ) from, ( int ) to );
			}
		}
	}


	return 0;
}


static void print_board( ChessPos* p )
{
	printf( "\n" );

	for ( int8_t r = 7; r >= 0; --r ) {

		for ( int8_t f = 0; f < 8; ++f ) {

			Square square = r * 8 + f;

			printf( "%c ", chesspos_get_square( p, square ) );
		}

		printf( "\n" );
	}
	printf( "\n" );

}

static void print_destinations( Square from, uint64_t dest )
{
	printf( "\n" );

	for ( int8_t r = 7; r >= 0; --r ) {

		for ( int8_t f = 0; f < 8; ++f ) {

			Square square = r * 8 + f;
			uint64_t mask = bitboard_square( square );

			if ( mask & dest ) {

				printf( "o " );

			} else if ( from == square ) {

				printf( "s " );

			} else {

				printf( ". " );
			}
		}

		printf( "\n" );
	}
	printf( "\n" );
}
