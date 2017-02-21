#ifndef __BITBOARD_H__
#define __BITBOARD_H__


#include <chessdefs.h>
#include <stdint.h>


uint64_t bitboard_square( Square square );
uint64_t bitboard_rank( Rank rank );


#endif /* __BITBOARD_H__ */
