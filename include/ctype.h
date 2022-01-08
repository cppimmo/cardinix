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
 *
 * include/ctype.h
 */
#ifndef _LIBC_CTYPE_H
#define _LIBC_CTYPE_H

#if !defined(EOF)
/* Need to declare EOF here. */
#endif

/* Argumnent must be convertable to unsigned char. */
#define DECLARE_CTYPE_FUNCTION(func) int func(int c)

__BEGIN_DECLS

/* Character Class Types:
 * digits
 * hexadecimal digits
 * lowercase letters
 * uppercase letters
 * both lower and upper case letters
 * alphanumeric is digits, lowercase, & uppercase letters
 * punctuation characters
 * graphical chracters  alphanumeric chars, and punct chars
 * space characters  tab, newline, vertical tab, form feed, 
 * carriage return, and space
 * printable characters  alphanumeric chars, punct, and spaces
 * control characters  control chacters 000 throught 037 and 177(DEL)
 * blank characters  spaces and tabs
 * alpha characters  lower and uppercase letters
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

__END_DECLS

#endif /* !_LIBC_CTYPE_H */
