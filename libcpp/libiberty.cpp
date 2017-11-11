#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "libiberty.h"

void fancy_abort(const char * file, int line, const char * func)
{
	fprintf(stderr, "abort @ %s:%d %s\n", file, line, func);
	abort();
}

const unsigned char _hex_value[_hex_array_size] =
{
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* NUL SOH STX ETX */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* EOT ENQ ACK BEL */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* BS  HT  LF  VT  */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* FF  CR  SO  SI  */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* DLE DC1 DC2 DC3 */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* DC4 NAK SYN ETB */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* CAN EM  SUB ESC */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* FS  GS  RS  US  */

	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* SP  !   "   #   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* $   %   &   '   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* (   )   *   +   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* ,   -   .   /   */
	0,        1,        2,        3,          /* 0   1   2   3   */
	4,        5,        6,        7,          /* 4   5   6   7   */
	8,        9,        _hex_bad, _hex_bad,   /* 8   9   :   ;   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* <   =   >   ?   */

	_hex_bad, 10,       11,       12,         /* @   A   B   C   */
	13,       14,       15,       _hex_bad,   /* D   E   F   G   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* H   I   J   K   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* L   M   N   O   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* P   Q   R   S   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* T   U   V   W   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* X   Y   Z   [   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* \   ]   ^   _   */

	_hex_bad, 10,       11,       12,         /* `   a   b   c   */
	13,       14,       15,       _hex_bad,   /* d   e   f   g   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* h   i   j   k   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* l   m   n   o   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* p   q   r   s   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* t   u   v   w   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* x   y   z   {   */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,   /* |   }   ~   DEL */

	/* The high half of unsigned char, all values are _hex_bad.  */
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,

	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,

	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,

	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
	_hex_bad, _hex_bad, _hex_bad, _hex_bad,
};
const unsigned char hex_value(unsigned char c)
{
	return _hex_value[c];
}

#define CHAR_BIT 8
#include "ansidecl.h"
#include "line-map.h"

expanded_location
linemap_client_expand_location_to_spelling_point(source_location loc)
{
	expanded_location xloc = { 0 };
	xloc.line = loc;
	return xloc;
}
