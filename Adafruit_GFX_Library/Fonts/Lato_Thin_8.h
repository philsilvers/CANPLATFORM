// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Lato_Thin_8Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0x92,0x41,0x00, // '!'
	0xA0, // '"'
	0x32,0x9C,0xAF,0x30, // '#'
	0x4E,0x88,0x66,0xA4, // '$'
	0xE9,0x52,0xC3,0x43,0x4B,0x80, // '%'
	0x71,0x04,0x2A,0x91,0xE0, // '&'
	0xA0, // '''
	0x52,0x49,0x10, // '('
	0x89,0x24,0xA0, // ')'
	0xD8, // '*'
	0x21,0x3C,0x40, // '+'
	0x90, // ','
	0x80, // '-'
	0x80, // '.'
	0x22,0x44,0x48, // '/'
	0x74,0xA5,0x29,0x38, // '0'
	0x4C,0x44,0x4E, // '1'
	0xEA,0x24,0x8E, // '2'
	0x74,0x84,0x41,0x78, // '3'
	0x11,0x15,0x2F,0x08, // '4'
	0xE8,0xC2,0x2E, // '5'
	0x44,0xCA,0xAE, // '6'
	0xE2,0x24,0x48, // '7'
	0xEA,0xA4,0xAE, // '8'
	0xEA,0xA4,0x48, // '9'
	0x80,0x40, // ':'
	0x80,0x44, // ';'
	0x68,0x60, // '<'
	0xEE, // '='
	0xC2,0xC0, // '>'
	0xE2,0x24,0x04, // '?'
	0x72,0x2A,0xB6,0xF2,0x27,0x00, // '@'
	0x20,0x85,0x14,0x72,0x20, // 'A'
	0xEA,0xAC,0xAE, // 'B'
	0xF4,0x21,0x08,0x78, // 'C'
	0xF2,0x28,0xA2,0x8B,0xC0, // 'D'
	0xE8,0x8E,0x8E, // 'E'
	0xE8,0x8E,0x88, // 'F'
	0xF4,0x21,0x29,0x78, // 'G'
	0x94,0xA5,0xE9,0x48, // 'H'
	0x92,0x49,0x00, // 'I'
	0x49,0x25,0x80, // 'J'
	0x95,0x31,0x0E,0x48, // 'K'
	0x88,0x88,0x8E, // 'L'
	0x8A,0x29,0xB6,0xAA,0x20, // 'M'
	0x94,0xB5,0x69,0x48, // 'N'
	0xF2,0x28,0xA2,0x8B,0xC0, // 'O'
	0xEA,0xAC,0x88, // 'P'
	0xF2,0x28,0xA2,0x8B,0xC0,0x80, // 'Q'
	0xE5,0x29,0x8A,0x48, // 'R'
	0x74,0x18,0x21,0x78, // 'S'
	0xF1,0x08,0x42,0x10, // 'T'
	0x94,0xA5,0x29,0x78, // 'U'
	0x8A,0x25,0x14,0x20,0x80, // 'V'
	0x91,0x4C,0x96,0x8C,0xC2,0x62,0x20, // 'W'
	0x89,0x42,0x08,0x52,0x20, // 'X'
	0x89,0x46,0x08,0x20,0x80, // 'Y'
	0xF0,0x88,0x44,0x78, // 'Z'
	0xAA,0xAA, // '['
	0x84,0x44,0x22, // '\'
	0xAA,0xAA, // ']'
	0x4A, // '^'
	0xE0, // '_'
	0x80, // '`'
	0xE6,0xAE, // 'a'
	0x88,0xEA,0xAE, // 'b'
	0x68,0x86, // 'c'
	0x10,0x9D,0x29,0x78, // 'd'
	0x77,0xA0,0xE0, // 'e'
	0x64,0xC4,0x44, // 'f'
	0xF3,0x20,0xCF,0x00, // 'g'
	0x88,0xEA,0xAA, // 'h'
	0x82,0x49,0x00, // 'i'
	0x8A,0xA8, // 'j'
	0x88,0xC8,0xCA, // 'k'
	0xAA,0xA0, // 'l'
	0xFA,0xAA,0xAA, // 'm'
	0xEA,0xAA, // 'n'
	0x74,0xA4,0xE0, // 'o'
	0xEA,0xAE,0x80, // 'p'
	0x74,0xA5,0xE1,0x00, // 'q'
	0xD2,0x40, // 'r'
	0xEC,0x2E, // 's'
	0x44,0xC4,0x46, // 't'
	0xAA,0xAE, // 'u'
	0x94,0x98,0x80, // 'v'
	0xA5,0x69,0x62,0x40, // 'w'
	0xA4,0x4A, // 'x'
	0x93,0x18,0x84,0x00, // 'y'
	0xE2,0x4E, // 'z'
	0x52,0x28,0xA2, // '{'
	0x92,0x49,0x20, // '|'
	0x89,0x24,0x94 // '}'
};
const GFXglyph Lato_Thin_8Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   3,    0,    0 }, // ' '
	  {     1,   3,   6,   3,    0,   -6 }, // '!'
	  {     4,   2,   2,   4,    1,   -6 }, // '"'
	  {     5,   5,   6,   6,    0,   -6 }, // '#'
	  {     9,   4,   8,   6,    1,   -7 }, // '$'
	  {    13,   7,   6,   7,    0,   -6 }, // '%'
	  {    19,   6,   6,   7,    0,   -6 }, // '&'
	  {    24,   2,   2,   3,    0,   -6 }, // '''
	  {    25,   3,   7,   3,    0,   -6 }, // '('
	  {    28,   3,   7,   3,    0,   -6 }, // ')'
	  {    31,   3,   2,   4,    1,   -6 }, // '*'
	  {    32,   5,   4,   6,    0,   -5 }, // '+'
	  {    35,   3,   2,   3,    0,   -1 }, // ','
	  {    36,   2,   1,   4,    1,   -3 }, // '-'
	  {    37,   3,   1,   3,    0,   -1 }, // '.'
	  {    38,   4,   6,   4,    0,   -6 }, // '/'
	  {    41,   5,   6,   6,    0,   -6 }, // '0'
	  {    45,   4,   6,   6,    1,   -6 }, // '1'
	  {    48,   4,   6,   6,    1,   -6 }, // '2'
	  {    51,   5,   6,   6,    0,   -6 }, // '3'
	  {    55,   5,   6,   6,    0,   -6 }, // '4'
	  {    59,   4,   6,   6,    1,   -6 }, // '5'
	  {    62,   4,   6,   6,    1,   -6 }, // '6'
	  {    65,   4,   6,   6,    1,   -6 }, // '7'
	  {    68,   4,   6,   6,    1,   -6 }, // '8'
	  {    71,   4,   6,   6,    1,   -6 }, // '9'
	  {    74,   3,   4,   3,    0,   -4 }, // ':'
	  {    76,   3,   5,   3,    0,   -4 }, // ';'
	  {    78,   4,   3,   6,    1,   -4 }, // '<'
	  {    80,   4,   2,   6,    1,   -4 }, // '='
	  {    81,   4,   3,   6,    1,   -4 }, // '>'
	  {    83,   4,   6,   4,    0,   -6 }, // '?'
	  {    86,   6,   7,   8,    1,   -6 }, // '@'
	  {    92,   6,   6,   6,    0,   -6 }, // 'A'
	  {    97,   4,   6,   6,    1,   -6 }, // 'B'
	  {   100,   5,   6,   6,    1,   -6 }, // 'C'
	  {   104,   6,   6,   7,    1,   -6 }, // 'D'
	  {   109,   4,   6,   6,    1,   -6 }, // 'E'
	  {   112,   4,   6,   6,    1,   -6 }, // 'F'
	  {   115,   5,   6,   7,    1,   -6 }, // 'G'
	  {   119,   5,   6,   7,    1,   -6 }, // 'H'
	  {   123,   3,   6,   3,    0,   -6 }, // 'I'
	  {   126,   3,   6,   4,    0,   -6 }, // 'J'
	  {   129,   5,   6,   6,    1,   -6 }, // 'K'
	  {   133,   4,   6,   5,    1,   -6 }, // 'L'
	  {   136,   6,   6,   8,    1,   -6 }, // 'M'
	  {   141,   5,   6,   7,    1,   -6 }, // 'N'
	  {   145,   6,   6,   7,    1,   -6 }, // 'O'
	  {   150,   4,   6,   6,    1,   -6 }, // 'P'
	  {   153,   6,   7,   7,    1,   -6 }, // 'Q'
	  {   159,   5,   6,   6,    1,   -6 }, // 'R'
	  {   163,   5,   6,   5,    0,   -6 }, // 'S'
	  {   167,   5,   6,   6,    0,   -6 }, // 'T'
	  {   171,   5,   6,   7,    1,   -6 }, // 'U'
	  {   175,   6,   6,   6,    0,   -6 }, // 'V'
	  {   180,   9,   6,   9,    0,   -6 }, // 'W'
	  {   187,   6,   6,   6,    0,   -6 }, // 'X'
	  {   192,   6,   6,   6,    0,   -6 }, // 'Y'
	  {   197,   5,   6,   6,    0,   -6 }, // 'Z'
	  {   201,   2,   8,   3,    1,   -7 }, // '['
	  {   203,   4,   6,   4,    0,   -6 }, // '\'
	  {   206,   2,   8,   3,    0,   -7 }, // ']'
	  {   208,   4,   2,   6,    1,   -6 }, // '^'
	  {   209,   4,   1,   5,    0,    0 }, // '_'
	  {   210,   2,   1,   4,    1,   -6 }, // '`'
	  {   211,   4,   4,   5,    0,   -4 }, // 'a'
	  {   213,   4,   6,   5,    1,   -6 }, // 'b'
	  {   216,   4,   4,   5,    0,   -4 }, // 'c'
	  {   218,   5,   6,   5,    0,   -6 }, // 'd'
	  {   222,   5,   4,   5,    0,   -4 }, // 'e'
	  {   225,   4,   6,   4,    0,   -6 }, // 'f'
	  {   228,   5,   5,   5,    0,   -4 }, // 'g'
	  {   232,   4,   6,   5,    1,   -6 }, // 'h'
	  {   235,   3,   6,   3,    0,   -6 }, // 'i'
	  {   238,   2,   7,   3,    0,   -6 }, // 'j'
	  {   240,   4,   6,   5,    1,   -6 }, // 'k'
	  {   243,   2,   6,   3,    0,   -6 }, // 'l'
	  {   245,   6,   4,   7,    1,   -4 }, // 'm'
	  {   248,   4,   4,   5,    1,   -4 }, // 'n'
	  {   250,   5,   4,   5,    0,   -4 }, // 'o'
	  {   253,   4,   5,   5,    1,   -4 }, // 'p'
	  {   256,   5,   5,   5,    0,   -4 }, // 'q'
	  {   260,   3,   4,   4,    1,   -4 }, // 'r'
	  {   262,   4,   4,   4,    0,   -4 }, // 's'
	  {   264,   4,   6,   4,    0,   -6 }, // 't'
	  {   267,   4,   4,   5,    1,   -4 }, // 'u'
	  {   269,   5,   4,   5,    0,   -4 }, // 'v'
	  {   272,   7,   4,   7,    0,   -4 }, // 'w'
	  {   276,   4,   4,   5,    0,   -4 }, // 'x'
	  {   278,   5,   5,   5,    0,   -4 }, // 'y'
	  {   282,   4,   4,   5,    0,   -4 }, // 'z'
	  {   284,   3,   8,   3,    0,   -7 }, // '{'
	  {   287,   3,   7,   3,    0,   -6 }, // '|'
	  {   290,   3,   8,   3,    0,   -7 } // '}'
};
const GFXfont Lato_Thin_8 PROGMEM = {
(uint8_t  *)Lato_Thin_8Bitmaps,(GFXglyph *)Lato_Thin_8Glyphs,0x20, 0x7E, 10};