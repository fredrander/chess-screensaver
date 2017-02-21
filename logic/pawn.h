#ifndef __pawn_h__
#define __pawn_h__


#include <chessdefs.h>
#include <stdint.h>
#include <stdbool.h>


/* get bitmask with valid destinations from a square */
uint64_t pawn_valid_destinations( Square from, Color color, bool capture );


#endif /* __pawn_h__ */

