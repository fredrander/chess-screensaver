#include <pawn.h>

#include <stddef.h>


static const uint64_t valid_destinations[ 2 ][ 64 ] = {

	{
		/*  0 */ 0x0000000000000000, /*  1 */ 0x0000000000000000,
		/*  2 */ 0x0000000000000000, /*  3 */ 0x0000000000000000,
		/*  4 */ 0x0000000000000000, /*  5 */ 0x0000000000000000,
		/*  6 */ 0x0000000000000000, /*  7 */ 0x0000000000000000,
		/*  8 */ 0x0000000001010000, /*  9 */ 0x0000000002020000,
		/* 10 */ 0x0000000004040000, /* 11 */ 0x0000000008080000,
		/* 12 */ 0x0000000010100000, /* 13 */ 0x0000000020200000,
		/* 14 */ 0x0000000040400000, /* 15 */ 0x0000000080800000,
		/* 16 */ 0x0000000001000000, /* 17 */ 0x0000000002000000,
		/* 18 */ 0x0000000004000000, /* 19 */ 0x0000000008000000,
		/* 20 */ 0x0000000010000000, /* 21 */ 0x0000000020000000,
		/* 22 */ 0x0000000040000000, /* 23 */ 0x0000000080000000,
		/* 24 */ 0x0000000100000000, /* 25 */ 0x0000000200000000,
		/* 26 */ 0x0000000400000000, /* 27 */ 0x0000000800000000,
		/* 28 */ 0x0000001000000000, /* 29 */ 0x0000002000000000,
		/* 30 */ 0x0000004000000000, /* 31 */ 0x0000008000000000,
		/* 32 */ 0x0000010000000000, /* 33 */ 0x0000020000000000,
		/* 34 */ 0x0000040000000000, /* 35 */ 0x0000080000000000,
		/* 36 */ 0x0000100000000000, /* 37 */ 0x0000200000000000,
		/* 38 */ 0x0000400000000000, /* 39 */ 0x0000800000000000,
		/* 40 */ 0x0001000000000000, /* 41 */ 0x0002000000000000,
		/* 42 */ 0x0004000000000000, /* 43 */ 0x0008000000000000,
		/* 44 */ 0x0010000000000000, /* 45 */ 0x0020000000000000,
		/* 46 */ 0x0040000000000000, /* 47 */ 0x0080000000000000,
		/* 48 */ 0x0100000000000000, /* 49 */ 0x0200000000000000,
		/* 50 */ 0x0400000000000000, /* 51 */ 0x0800000000000000,
		/* 52 */ 0x1000000000000000, /* 53 */ 0x2000000000000000,
		/* 54 */ 0x4000000000000000, /* 55 */ 0x8000000000000000,
		/* 56 */ 0x0000000000000000, /* 57 */ 0x0000000000000000,
		/* 58 */ 0x0000000000000000, /* 59 */ 0x0000000000000000,
		/* 60 */ 0x0000000000000000, /* 61 */ 0x0000000000000000,
		/* 62 */ 0x0000000000000000, /* 63 */ 0x0000000000000000
	},
	{
		/*  0 */ 0x0000000000000000, /*  1 */ 0x0000000000000000,
		/*  2 */ 0x0000000000000000, /*  3 */ 0x0000000000000000,
		/*  4 */ 0x0000000000000000, /*  5 */ 0x0000000000000000,
		/*  6 */ 0x0000000000000000, /*  7 */ 0x0000000000000000,
		/*  8 */ 0x0000000000000001, /*  9 */ 0x0000000000000002,
		/* 10 */ 0x0000000000000004, /* 11 */ 0x0000000000000008,
		/* 12 */ 0x0000000000000010, /* 13 */ 0x0000000000000020,
		/* 14 */ 0x0000000000000040, /* 15 */ 0x0000000000000080,
		/* 16 */ 0x0000000000000100, /* 17 */ 0x0000000000000200,
		/* 18 */ 0x0000000000000400, /* 19 */ 0x0000000000000800,
		/* 20 */ 0x0000000000001000, /* 21 */ 0x0000000000002000,
		/* 22 */ 0x0000000000004000, /* 23 */ 0x0000000000008000,
		/* 24 */ 0x0000000000010000, /* 25 */ 0x0000000000020000,
		/* 26 */ 0x0000000000040000, /* 27 */ 0x0000000000080000,
		/* 28 */ 0x0000000000100000, /* 29 */ 0x0000000000200000,
		/* 30 */ 0x0000000000400000, /* 31 */ 0x0000000000800000,
		/* 32 */ 0x0000000001000000, /* 33 */ 0x0000000002000000,
		/* 34 */ 0x0000000004000000, /* 35 */ 0x0000000008000000,
		/* 36 */ 0x0000000010000000, /* 37 */ 0x0000000020000000,
		/* 38 */ 0x0000000040000000, /* 39 */ 0x0000000080000000,
		/* 40 */ 0x0000000100000000, /* 41 */ 0x0000000200000000,
		/* 42 */ 0x0000000400000000, /* 43 */ 0x0000000800000000,
		/* 44 */ 0x0000001000000000, /* 45 */ 0x0000002000000000,
		/* 46 */ 0x0000004000000000, /* 47 */ 0x0000008000000000,
		/* 48 */ 0x0000010100000000, /* 49 */ 0x0000020200000000,
		/* 50 */ 0x0000040400000000, /* 51 */ 0x0000080800000000,
		/* 52 */ 0x0000101000000000, /* 53 */ 0x0000202000000000,
		/* 54 */ 0x0000404000000000, /* 55 */ 0x0000808000000000,
		/* 56 */ 0x0000000000000000, /* 57 */ 0x0000000000000000,
		/* 58 */ 0x0000000000000000, /* 59 */ 0x0000000000000000,
		/* 60 */ 0x0000000000000000, /* 61 */ 0x0000000000000000,
		/* 62 */ 0x0000000000000000, /* 63 */ 0x0000000000000000

	}

};

static const uint64_t valid_destinations_capture[ 2 ][ 64 ] = {

	{
		/*  0 */ 0x0000000000000000, /*  1 */ 0x0000000000000000,
		/*  2 */ 0x0000000000000000, /*  3 */ 0x0000000000000000,
		/*  4 */ 0x0000000000000000, /*  5 */ 0x0000000000000000,
		/*  6 */ 0x0000000000000000, /*  7 */ 0x0000000000000000,
		/*  8 */ 0x0000000000020000, /*  9 */ 0x0000000000050000,
		/* 10 */ 0x00000000000A0000, /* 11 */ 0x0000000000140000,
		/* 12 */ 0x0000000000280000, /* 13 */ 0x0000000000500000,
		/* 14 */ 0x0000000000A00000, /* 15 */ 0x0000000000400000,
		/* 16 */ 0x0000000002000000, /* 17 */ 0x0000000005000000,
		/* 18 */ 0x000000000A000000, /* 19 */ 0x0000000014000000,
		/* 20 */ 0x0000000028000000, /* 21 */ 0x0000000050000000,
		/* 22 */ 0x00000000A0000000, /* 23 */ 0x0000000040000000,
		/* 24 */ 0x0000000200000000, /* 25 */ 0x0000000500000000,
		/* 26 */ 0x0000000A00000000, /* 27 */ 0x0000001400000000,
		/* 28 */ 0x0000002800000000, /* 29 */ 0x0000005000000000,
		/* 30 */ 0x000000A000000000, /* 31 */ 0x0000004000000000,
		/* 32 */ 0x0000020000000000, /* 33 */ 0x0000050000000000,
		/* 34 */ 0x00000A0000000000, /* 35 */ 0x0000140000000000,
		/* 36 */ 0x0000280000000000, /* 37 */ 0x0000500000000000,
		/* 38 */ 0x0000A00000000000, /* 39 */ 0x0000400000000000,
		/* 40 */ 0x0002000000000000, /* 41 */ 0x0005000000000000,
		/* 42 */ 0x000A000000000000, /* 43 */ 0x0014000000000000,
		/* 44 */ 0x0028000000000000, /* 45 */ 0x0050000000000000,
		/* 46 */ 0x00A0000000000000, /* 47 */ 0x0040000000000000,
		/* 48 */ 0x0200000000000000, /* 49 */ 0x0500000000000000,
		/* 50 */ 0x0A00000000000000, /* 51 */ 0x1400000000000000,
		/* 52 */ 0x2800000000000000, /* 53 */ 0x5000000000000000,
		/* 54 */ 0xA000000000000000, /* 55 */ 0x4000000000000000,
		/* 56 */ 0x0000000000000000, /* 57 */ 0x0000000000000000,
		/* 58 */ 0x0000000000000000, /* 59 */ 0x0000000000000000,
		/* 60 */ 0x0000000000000000, /* 61 */ 0x0000000000000000,
		/* 62 */ 0x0000000000000000, /* 63 */ 0x0000000000000000
	},
	{
		/*  0 */ 0x0000000000000000, /*  1 */ 0x0000000000000000,
		/*  2 */ 0x0000000000000000, /*  3 */ 0x0000000000000000,
		/*  4 */ 0x0000000000000000, /*  5 */ 0x0000000000000000,
		/*  6 */ 0x0000000000000000, /*  7 */ 0x0000000000000000,
		/*  8 */ 0x0000000000000002, /*  9 */ 0x0000000000000005,
		/* 10 */ 0x000000000000000A, /* 11 */ 0x0000000000000014,
		/* 12 */ 0x0000000000000028, /* 13 */ 0x0000000000000050,
		/* 14 */ 0x00000000000000A0, /* 15 */ 0x0000000000000040,
		/* 16 */ 0x0000000000000200, /* 17 */ 0x0000000000000500,
		/* 18 */ 0x0000000000000A00, /* 19 */ 0x0000000000001400,
		/* 20 */ 0x0000000000002800, /* 21 */ 0x0000000000005000,
		/* 22 */ 0x000000000000A000, /* 23 */ 0x0000000000004000,
		/* 24 */ 0x0000000000020000, /* 25 */ 0x0000000000050000,
		/* 26 */ 0x00000000000A0000, /* 27 */ 0x0000000000140000,
		/* 28 */ 0x0000000000280000, /* 29 */ 0x0000000000500000,
		/* 30 */ 0x0000000000A00000, /* 31 */ 0x0000000000400000,
		/* 32 */ 0x0000000002000000, /* 33 */ 0x0000000005000000,
		/* 34 */ 0x000000000A000000, /* 35 */ 0x0000000014000000,
		/* 36 */ 0x0000000028000000, /* 37 */ 0x0000000050000000,
		/* 38 */ 0x00000000A0000000, /* 39 */ 0x0000000040000000,
		/* 40 */ 0x0000000200000000, /* 41 */ 0x0000000500000000,
		/* 42 */ 0x0000000A00000000, /* 43 */ 0x0000001400000000,
		/* 44 */ 0x0000002800000000, /* 45 */ 0x0000005000000000,
		/* 46 */ 0x000000A000000000, /* 47 */ 0x0000004000000000,
		/* 48 */ 0x0000020000000000, /* 49 */ 0x0000050000000000,
		/* 50 */ 0x00000A0000000000, /* 51 */ 0x0000140000000000,
		/* 52 */ 0x0000280000000000, /* 53 */ 0x0000500000000000,
		/* 54 */ 0x0000A00000000000, /* 55 */ 0x0000400000000000,
		/* 56 */ 0x0000000000000000, /* 57 */ 0x0000000000000000,
		/* 58 */ 0x0000000000000000, /* 59 */ 0x0000000000000000,
		/* 60 */ 0x0000000000000000, /* 61 */ 0x0000000000000000,
		/* 62 */ 0x0000000000000000, /* 63 */ 0x0000000000000000
	}

};

uint64_t pawn_valid_destinations( Square from, Color color, bool capture )
{
	uint64_t result = 0;

	if ( capture ) {

		result = valid_destinations_capture[ color ][ from ];

	} else {

		result = valid_destinations[ color ][ from ];

	}

	return result;
}
