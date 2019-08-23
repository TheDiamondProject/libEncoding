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

#include <stdint.h>
#include <sys/types.h>

#if !defined(libEncoding_UTF8)
#define libEncoding_UTF8

/* Semantic type representing a Unicode Code Point. */
typedef uint32_t codepoint_t;

/* Construct a new UTF-8 string from the provided array of codepoints. The result returned
 * must be free'd by the caller when it is no longer required. */
const char *utf8_construct_from_codepoints(codepoint_t *cp, size_t len);

/* Construct a new UTF-8 Codepoint array from the string provided. The result returned
 * must be free'd by the caller when it is no longer required/ */
codepoint_t *utf8_convert_to_codepoints(const char *restrict str, size_t *len);

#endif
