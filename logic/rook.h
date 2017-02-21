#ifndef __rook_h__
#define __rook_h__


#include <chessdefs.h>
#include <stdint.h>


/* get bitmask with valid destinations from a square */
uint64_t rook_valid_destinations( Square from );


#endif /* __rook_h__ */
