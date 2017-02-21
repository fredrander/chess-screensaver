#ifndef __knight_h__
#define __knight_h__


#include <chessdefs.h>
#include <stdint.h>


/* get bitmask with valid destinations from a square */
uint64_t knight_valid_destinations( Square from );


#endif /* __knight_h__ */
