#ifndef __KING_H__
#define __KING_H__


#include <chessdefs.h>
#include <stdint.h>
#include <stdbool.h>


uint64_t king_valid_destinations( Square from, Color color,
		bool shortCastlingValid, bool longCastlingValid );


#endif
