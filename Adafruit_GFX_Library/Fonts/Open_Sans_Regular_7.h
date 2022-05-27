// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Open_Sans_Regular_7Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0x92,0x00, // '!'
	0xC0, // '"'
	0x17,0x95,0xE2,0x00, // '#'
	0x66,0x18,0xA6,0x00, // '$'
	0xD2,0xCF,0x8E,0x58, // '%'
	0x61,0x86,0x24,0x78, // '&'
	0x80, // '''
	0x52,0x48,0x80, // '('
	0x89,0x25,0x00, // ')'
	0x03,0x08, // '*'
	0x07,0x80, // '+'
	0x20, // ','
	0x00, // '-'
	0x00, // '.'
	0x24,0x48,0x80, // '/'
	0x64,0xA5,0x26,0x00, // '0'
	0xAA,0x80, // '1'
	0xE0,0x88,0x8F,0x00, // '2'
	0xE0,0x98,0x2E,0x00, // '3'
	0x23,0x19,0xE2,0x00, // '4'
	0x64,0x18,0x2E,0x00, // '5'
	0x44,0x3D,0x26,0x00, // '6'
	0xF1,0x08,0x84,0x00, // '7'
	0x64,0x99,0x2E,0x00, // '8'
	0x64,0xBC,0x22,0x00, // '9'
	0x00,0x00, // ':'
	0x00,0x80, // ';'
	0x26,0x08, // '<'
	0x60, // '='
	0x41,0x98, // '>'
	0xE2,0x40,0x40, // '?'
	0x38,0xAA,0xB5,0xA4,0x86,0x00, // '@'
	0x23,0x15,0x69,0x00, // 'A'
	0xEA,0xCA,0xE0, // 'B'
	0x74,0x21,0x07,0x00, // 'C'
	0xE4,0xA5,0x2E,0x00, // 'D'
	0xD3,0x4C, // 'E'
	0xD3,0x48, // 'F'
	0x72,0x09,0xA2,0x78, // 'G'
	0xAA,0xEA,0xA0, // 'H'
	0x92,0x48, // 'I'
	0x49,0x24,0x80, // 'J'
	0xAC,0x8C,0xA0, // 'K'
	0x92,0x4C, // 'L'
	0x8A,0x6D,0xBA,0xA8, // 'M'
	0x94,0xB5,0x69,0x00, // 'N'
	0x72,0x28,0xA2,0x70, // 'O'
	0xEA,0xC8,0x80, // 'P'
	0x72,0x28,0xA2,0x70,0x40, // 'Q'
	0xEA,0xCC,0xA0, // 'R'
	0x64,0x18,0x2E,0x00, // 'S'
	0xF2,0x10,0x84,0x00, // 'T'
	0xAA,0xAA,0xE0, // 'U'
	0x94,0x98,0xC2,0x00, // 'V'
	0x95,0x69,0xB2,0x44,0x80, // 'W'
	0x93,0x08,0xC9,0x00, // 'X'
	0x93,0x18,0x84,0x00, // 'Y'
	0xF1,0x10,0x8F,0x00, // 'Z'
	0xAA,0xA0, // '['
	0x88,0x44,0x20, // '\'
	0x49,0x24,0x80, // ']'
	0x43,0x24, // '^'
	0x40, // '_'
	0x40, // '`'
	0x62,0xEE, // 'a'
	0x8C,0xAA,0xE0, // 'b'
	0x68,0x84, // 'c'
	0x13,0xA5,0x27,0x00, // 'd'
	0x64,0xB8,0x80, // 'e'
	0x4C,0x44,0x40, // 'f'
	0x75,0x18,0xC9,0x30, // 'g'
	0x8C,0xAA,0xA0, // 'h'
	0x02,0x48, // 'i'
	0x0A,0xA8, // 'j'
	0x8C,0x88,0xC0, // 'k'
	0x92,0x48, // 'l'
	0xDA,0xAA,0xAA, // 'm'
	0xCA,0xAA, // 'n'
	0x64,0xA4,0xE0, // 'o'
	0xCA,0xAE,0x80, // 'p'
	0x74,0xA4,0xE1,0x08, // 'q'
	0x52,0x40, // 'r'
	0x6C,0x2E, // 's'
	0x1A,0x44, // 't'
	0x2A,0xAE, // 'u'
	0x85,0x18,0x80, // 'v'
	0xA2,0xAD,0x94, // 'w'
	0x83,0x11,0x40, // 'x'
	0x85,0x18,0x84,0x40, // 'y'
	0xE2,0x4C, // 'z'
	0x49,0x24,0x80, // '{'
	0x12,0x49,0x00, // '|'
	0x89,0x24,0x80 // '}'
};
const GFXglyph Open_Sans_Regular_7Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   3,    0,    0 }, // ' '
	  {     1,   3,   5,   3,    0,   -5 }, // '!'
	  {     3,   3,   2,   4,    0,   -5 }, // '"'
	  {     4,   5,   5,   6,    0,   -5 }, // '#'
	  {     8,   5,   5,   5,    0,   -5 }, // '$'
	  {    12,   6,   5,   7,    0,   -5 }, // '%'
	  {    16,   6,   5,   6,    0,   -5 }, // '&'
	  {    20,   2,   2,   3,    0,   -5 }, // '''
	  {    21,   3,   6,   3,    0,   -5 }, // '('
	  {    24,   3,   6,   3,    0,   -5 }, // ')'
	  {    27,   5,   3,   5,    0,   -5 }, // '*'
	  {    29,   5,   3,   5,    0,   -4 }, // '+'
	  {    31,   2,   2,   3,    0,   -1 }, // ','
	  {    32,   3,   2,   3,    0,   -3 }, // '-'
	  {    33,   3,   1,   3,    0,   -1 }, // '.'
	  {    34,   4,   5,   4,    0,   -5 }, // '/'
	  {    37,   5,   5,   5,    0,   -5 }, // '0'
	  {    41,   2,   5,   5,    1,   -5 }, // '1'
	  {    43,   5,   5,   5,    0,   -5 }, // '2'
	  {    47,   5,   5,   5,    0,   -5 }, // '3'
	  {    51,   5,   5,   5,    0,   -5 }, // '4'
	  {    55,   5,   5,   5,    0,   -5 }, // '5'
	  {    59,   5,   5,   5,    0,   -5 }, // '6'
	  {    63,   5,   5,   5,    0,   -5 }, // '7'
	  {    67,   5,   5,   5,    0,   -5 }, // '8'
	  {    71,   5,   5,   5,    0,   -5 }, // '9'
	  {    75,   3,   4,   3,    0,   -4 }, // ':'
	  {    77,   2,   5,   3,    0,   -4 }, // ';'
	  {    79,   5,   3,   5,    0,   -4 }, // '<'
	  {    81,   5,   1,   5,    0,   -3 }, // '='
	  {    82,   5,   3,   5,    0,   -4 }, // '>'
	  {    84,   4,   5,   4,    0,   -5 }, // '?'
	  {    87,   7,   6,   7,    0,   -5 }, // '@'
	  {    93,   5,   5,   5,    0,   -5 }, // 'A'
	  {    97,   4,   5,   6,    1,   -5 }, // 'B'
	  {   100,   5,   5,   5,    0,   -5 }, // 'C'
	  {   104,   5,   5,   6,    1,   -5 }, // 'D'
	  {   108,   3,   5,   5,    1,   -5 }, // 'E'
	  {   110,   3,   5,   5,    1,   -5 }, // 'F'
	  {   112,   6,   5,   6,    0,   -5 }, // 'G'
	  {   116,   4,   5,   6,    1,   -5 }, // 'H'
	  {   119,   3,   5,   3,    0,   -5 }, // 'I'
	  {   121,   3,   6,   3,   -1,   -5 }, // 'J'
	  {   124,   4,   5,   5,    1,   -5 }, // 'K'
	  {   127,   3,   5,   5,    1,   -5 }, // 'L'
	  {   129,   6,   5,   7,    1,   -5 }, // 'M'
	  {   133,   5,   5,   6,    1,   -5 }, // 'N'
	  {   137,   6,   5,   6,    0,   -5 }, // 'O'
	  {   141,   4,   5,   5,    1,   -5 }, // 'P'
	  {   144,   6,   6,   6,    0,   -5 }, // 'Q'
	  {   149,   4,   5,   5,    1,   -5 }, // 'R'
	  {   152,   5,   5,   5,    0,   -5 }, // 'S'
	  {   156,   5,   5,   5,    0,   -5 }, // 'T'
	  {   160,   4,   5,   6,    1,   -5 }, // 'U'
	  {   163,   5,   5,   5,    0,   -5 }, // 'V'
	  {   167,   7,   5,   7,    0,   -5 }, // 'W'
	  {   172,   5,   5,   5,    0,   -5 }, // 'X'
	  {   176,   5,   5,   5,    0,   -5 }, // 'Y'
	  {   180,   5,   5,   5,    0,   -5 }, // 'Z'
	  {   184,   2,   6,   3,    1,   -5 }, // '['
	  {   186,   4,   5,   4,    0,   -5 }, // '\'
	  {   189,   3,   6,   3,    0,   -5 }, // ']'
	  {   192,   5,   3,   5,    0,   -5 }, // '^'
	  {   194,   4,   2,   4,    0,    0 }, // '_'
	  {   195,   3,   1,   5,    1,   -5 }, // '`'
	  {   196,   4,   4,   5,    0,   -4 }, // 'a'
	  {   198,   4,   5,   5,    1,   -5 }, // 'b'
	  {   201,   4,   4,   4,    0,   -4 }, // 'c'
	  {   203,   5,   5,   5,    0,   -5 }, // 'd'
	  {   207,   5,   4,   5,    0,   -4 }, // 'e'
	  {   210,   4,   5,   3,    0,   -5 }, // 'f'
	  {   213,   5,   6,   5,    0,   -4 }, // 'g'
	  {   217,   4,   5,   5,    1,   -5 }, // 'h'
	  {   220,   3,   5,   3,    0,   -5 }, // 'i'
	  {   222,   2,   7,   3,    0,   -5 }, // 'j'
	  {   224,   4,   5,   5,    1,   -5 }, // 'k'
	  {   227,   3,   5,   3,    0,   -5 }, // 'l'
	  {   229,   6,   4,   8,    1,   -4 }, // 'm'
	  {   232,   4,   4,   5,    1,   -4 }, // 'n'
	  {   234,   5,   4,   5,    0,   -4 }, // 'o'
	  {   237,   4,   6,   5,    1,   -4 }, // 'p'
	  {   240,   5,   6,   5,    0,   -4 }, // 'q'
	  {   244,   3,   4,   4,    1,   -4 }, // 'r'
	  {   246,   4,   4,   4,    0,   -4 }, // 's'
	  {   248,   3,   5,   3,    0,   -5 }, // 't'
	  {   250,   4,   4,   5,    1,   -4 }, // 'u'
	  {   252,   5,   4,   5,    0,   -4 }, // 'v'
	  {   255,   6,   4,   6,    0,   -4 }, // 'w'
	  {   258,   5,   4,   5,    0,   -4 }, // 'x'
	  {   261,   5,   6,   5,    0,   -4 }, // 'y'
	  {   265,   4,   4,   4,    0,   -4 }, // 'z'
	  {   267,   3,   6,   4,    0,   -5 }, // '{'
	  {   270,   3,   7,   5,    1,   -5 }, // '|'
	  {   273,   3,   6,   4,    0,   -5 } // '}'
};
const GFXfont Open_Sans_Regular_7 PROGMEM = {
(uint8_t  *)Open_Sans_Regular_7Bitmaps,(GFXglyph *)Open_Sans_Regular_7Glyphs,0x20, 0x7E, 11};