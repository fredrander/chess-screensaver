#include <bitboard.h>


uint64_t bitboard_square( Square square )
{
	return ( 1ull << square );
}

uint64_t bitboard_rank( Rank rank )
{
	return ( 0xffull << ( rank * 8 ) );
}
