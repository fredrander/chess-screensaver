#ifndef __block_h__
#define __block_h__


#include <chessdefs.h>
#include <stdint.h>


/* get bitmask with blocking squares for from -> to */
uint64_t block_mask( Square from, Square to );


#endif /* __block_h__ */
