#include <king.h>
#include <bitboard.h>


static const uint64_t valid_destinations[ 64 ] = {

	/*  0 */ 0x81412111090503FE, /*  1 */ 0x02824222120A07FD,
	/*  2 */ 0x0404844424150EFB, /*  3 */ 0x08080888492A1CF7,
	/*  4 */ 0x10101011925438EF, /*  5 */ 0x2020212224A870DF,
	/*  6 */ 0x404142444850E0BF, /*  7 */ 0x8182848890A0C07F,
	/*  8 */ 0x412111090503FE03, /*  9 */ 0x824222120A07FD07,
	/* 10 */ 0x04844424150EFB0E, /* 11 */ 0x080888492A1CF71C,
	/* 12 */ 0x101011925438EF38, /* 13 */ 0x20212224A870DF70,
	/* 14 */ 0x4142444850E0BFE0, /* 15 */ 0x82848890A0C07FC0,
	/* 16 */ 0x2111090503FE0305, /* 17 */ 0x4222120A07FD070A,
	/* 18 */ 0x844424150EFB0E15, /* 19 */ 0x0888492A1CF71C2A,
	/* 20 */ 0x1011925438EF3854, /* 21 */ 0x212224A870DF70A8,
	/* 22 */ 0x42444850E0BFE050, /* 23 */ 0x848890A0C07FC0A0,
	/* 24 */ 0x11090503FE030509, /* 25 */ 0x22120A07FD070A12,
	/* 26 */ 0x4424150EFB0E1524, /* 27 */ 0x88492A1CF71C2A49,
	/* 28 */ 0x11925438EF385492, /* 29 */ 0x2224A870DF70A824,
	/* 30 */ 0x444850E0BFE05048, /* 31 */ 0x8890A0C07FC0A090,
	/* 32 */ 0x090503FE03050911, /* 33 */ 0x120A07FD070A1222,
	/* 34 */ 0x24150EFB0E152444, /* 35 */ 0x492A1CF71C2A4988,
	/* 36 */ 0x925438EF38549211, /* 37 */ 0x24A870DF70A82422,
	/* 38 */ 0x4850E0BFE0504844, /* 39 */ 0x90A0C07FC0A09088,
	/* 40 */ 0x0503FE0305091121, /* 41 */ 0x0A07FD070A122242,
	/* 42 */ 0x150EFB0E15244484, /* 43 */ 0x2A1CF71C2A498808,
	/* 44 */ 0x5438EF3854921110, /* 45 */ 0xA870DF70A8242221,
	/* 46 */ 0x50E0BFE050484442, /* 47 */ 0xA0C07FC0A0908884,
	/* 48 */ 0x03FE030509112141, /* 49 */ 0x07FD070A12224282,
	/* 50 */ 0x0EFB0E1524448404, /* 51 */ 0x1CF71C2A49880808,
	/* 52 */ 0x38EF385492111010, /* 53 */ 0x70DF70A824222120,
	/* 54 */ 0xE0BFE05048444241, /* 55 */ 0xC07FC0A090888482,
	/* 56 */ 0xFE03050911214181, /* 57 */ 0xFD070A1222428202,
	/* 58 */ 0xFB0E152444840404, /* 59 */ 0xF71C2A4988080808,
	/* 60 */ 0xEF38549211101010, /* 61 */ 0xDF70A82422212020,
	/* 62 */ 0xBFE0504844424140, /* 63 */ 0x7FC0A09088848281
};


uint64_t king_valid_destinations( Square from, Color color,
		bool shortCastlingValid, bool longCastlingValid )
{
	uint64_t dest = valid_destinations[ from ];

	switch ( color ) {

	case WHITE:

		if ( from == e1 ) {

			if ( shortCastlingValid ) {

				dest |= bitboard_square( g1 );
			}
			if ( longCastlingValid ) {

				dest |= bitboard_square( c1 );
			}
		}
		break;

	case BLACK:

		if ( from == e8 ) {

			if ( shortCastlingValid ) {

				dest |= bitboard_square( g8 );
			}
			if ( longCastlingValid ) {

				dest |= bitboard_square( c8 );
			}
		}
		break;
	}

	return dest;
}
