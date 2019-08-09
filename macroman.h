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

#include <sys/types.h>
#include <stdint.h>

#if !defined(libEncoding_MacRoman)
#define libEncoding_MacRoman

/* Convert a MacRoman encoded string into a sequence of Unicode Code Points. These
 * Code Points are all 2 bytes wide to make for consistent/easy calculations. The
 * generated Code Points will then need to be converted to UTF-8. */
size_t unicode_from_macroman(codepoint_t **cp, const char *restrict macroman, size_t len);

/* Convert a MacRoman encoded string into a UTF-8 encoded string. The result should be
 * free'd by the caller. */
const char *utf8_from_macroman(const char *restrict macroman, size_t len);

#endif

