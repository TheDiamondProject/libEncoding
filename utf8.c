/*
 * Copyright (c) 2019 Tom Hancocks
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "utf8.h"
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

// MARK: - Unicode Codepoint Conversion Table

/* This structure represents a unicode conversion hint. It describes what might be seen
 * in a unicode code point, and then how to map the code point into a sequence of bytes. */
struct unicode_conv_hint {
	uint8_t mask;
	uint8_t lead;
	codepoint_t beg;
	codepoint_t end;
	size_t bits_stored;
};
typedef struct unicode_conv_hint unicode_hint_t;

/* This table contains the appropriate code point hints for UTF-8. */
unicode_hint_t *utf8[] = {
	/*             mask        lead        beg      end       bits */
	[0] = &(unicode_hint_t){0b00111111, 0b10000000, 0,       0,        6    },
	[1] = &(unicode_hint_t){0b01111111, 0b00000000, 0000,    0177,     7    },
	[2] = &(unicode_hint_t){0b00011111, 0b11000000, 0200,    03777,    5    },
	[3] = &(unicode_hint_t){0b00001111, 0b11100000, 04000,   0177777,  4    },
	[4] = &(unicode_hint_t){0b00000111, 0b11110000, 0200000, 04177777, 3    },
		  &(unicode_hint_t){0},
};


/* Returns the number of bytes in UTF-8 required to represent the specified unicode 
 * code point. */
static inline size_t utf8_length_for_codepoint(codepoint_t cp)
{
	size_t len = 0;
	for (unicode_hint_t **u = utf8; *u; ++u) {
		if ((cp >= (*u)->beg) && (cp <= (*u)->end)) {
			break;
		}
		++len;
	}
	
	if (len > 4) {
		abort();
	}
	
	return len;
}

const char *utf8_construct_from_codepoints(codepoint_t *cp, size_t len)
{
	// Before we proceed, determine how many bytes are going to be required to represent
	// the output. To do this we need to make a pass through the "string" and ask for the
	// sizes of each codepoint.
	//
	// We can specify an initial length of one as we need to include a NUL byte.
	size_t result_len = 1;
	for (int i = 0; i < len; ++i) {
		result_len += utf8_length_for_codepoint(cp[i]);
	}

	// Now allocate the memory for it, and then work through producing the UTF-8 string.
	char *str = calloc(result_len, 1);
	char *s = str;
	for (int i = 0; i < len; ++i) {
		const size_t n = utf8_length_for_codepoint(cp[i]);
		int shift = utf8[0]->bits_stored * (n - 1);
		*s++ = (cp[i] >> shift & utf8[n]->mask) | utf8[n]->lead;
		shift -= utf8[0]->bits_stored;
		for (int j = 1; j < n; ++j) {
			*s++ = (cp[i] >> shift & utf8[0]->mask) | utf8[0]->lead;
			shift -= utf8[0]->bits_stored;
		}
	}

	// Return the resulting string to the caller
	return str;
}

