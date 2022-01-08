/* cardinix, file: cdefs.h */
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
#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_

/* use the following for cplusplus extern decls
 */
#if defined(__cplusplus)
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS };
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

/* diffrentiate library functions for hosted programs
 * 0 false 1 true
 * should be modified for hosted library
 */
#define __IS_LIBK 1

#endif /* !_SYS_CDEFS_H_ */
