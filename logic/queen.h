#ifndef __queen_h__
#define __queen_h__


#include <chessdefs.h>
#include <stdint.h>


/* get bitmask with valid destinations from a square */
uint64_t queen_valid_destinations( Square from );


#endif /* __queen_h__ */

