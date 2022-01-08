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
 * sys/panic.h
 */
#ifndef _SYS_PANIC_H_
#define _SYS_PANIC_H_

#include <stdarg.h>

#define KERN_PANIC(error) \
    kpanic(error, __FILE__, __LINE__)
#define KERN_PANICF(format, ...) \
    kpanicf(format, __FILE__, __LIINE__, __VA_ARGS__)

__attribute__((noreturn))
void kpanic(const char *error, const char *file, uint32_t line);
__attribute__((noreturn))
void kpanicf(const char *format, const char *file, uint32_t line, ...);

#endif /* !_SYS_PANIC_H_ */
