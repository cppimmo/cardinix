/* cardinix, file: ctype.h */
/*
 * Copyright (C) 2022 Brian hoffpauir
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CTYPE_H
#define CTYPE_H

// argumnent must be convertable to unsigned char
#define DECLARE_CTYPE_FUNCTION(name) int name(int c)

#ifdef __cplusplus
extern "C"
{
#endif

// Use ASCII character ranges instead
/*
static const int digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

static const unsigned char hex_digits[21] = { '0', '1', '2', '3', '4', '5'
	'6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	// user tolower to check for lower case digits as well

static const unsigned char lower[26] = { 'a', 'b', 'c', 'e', 'd', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

static const unsigned char upper[26] = { 'A', 'B', 'C', 'E', 'D', 'F', 'G',
	'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
	'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

static const unsigned char punct[] = { '!', '"', '#', '$', '%', '&', '\'', 
	'(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=',
	'>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}',
	'~' };
*/

/* Character Class Types
 // digits
 // hexadecimal digits
 // lowercase letters
 // uppercase letters
 // both lower and upper case letters
 // alphanumeric is digits, lowercase, & uppercase letters
 // punctuation characters
 // graphical chracters  alphanumeric chars, and punct chars
 // space characters  tab, newline, vertical tab, form feed, 
 // 		carriage return, and space
 // printable characters  alphanumeric chars, punct, and spaces
 // control characters  control chacters 000 throught 037 and 177(DEL)
 // blank characters  spaces and tabs
 // alpha characters  lower and uppercase letters
*/

DECLARE_CTYPE_FUNCTION(isalnum); 
DECLARE_CTYPE_FUNCTION(isalpha);
DECLARE_CTYPE_FUNCTION(iscntrl);
DECLARE_CTYPE_FUNCTION(isdigit); 
DECLARE_CTYPE_FUNCTION(isgraph);
DECLARE_CTYPE_FUNCTION(islower);
DECLARE_CTYPE_FUNCTION(isprint);
DECLARE_CTYPE_FUNCTION(ispunct);
DECLARE_CTYPE_FUNCTION(isspace);
DECLARE_CTYPE_FUNCTION(isupper);
DECLARE_CTYPE_FUNCTION(isxdigit);
DECLARE_CTYPE_FUNCTION(tolower);
DECLARE_CTYPE_FUNCTION(toupper);

#ifdef __cplusplus
}
#endif

#endif // CTYPE_H
