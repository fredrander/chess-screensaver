#ifndef __chesslogic_h__
#define __chesslogic_h__


#include <chessdefs.h>
#include <chesspos.h>
#include <stdbool.h>


/* check if a move is legal */
bool chesslogic_is_legal_move( ChessPos* pos, Square from, Square to );


#endif /* __chesslogic_h__ */
