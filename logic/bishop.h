#ifndef __bishop_h__
#define __bishop_h__


#include <chessdefs.h>
#include <stdint.h>


/* get bitmask with valid destinations from a square */
uint64_t bishop_valid_destinations( Square from );


#endif /* __bishop_h__ */

