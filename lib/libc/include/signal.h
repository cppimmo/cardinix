/* cardinix, file: signal.h */
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
#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef int sig_atomic_t;

#define SIG_DFL 0x0
#define SIG_ERR 0x1
#define SIG_IGN 0x2

#define SIGABRT 0x3
#define SIGFPE 0x4
#define SIGILL 0x5
#define SIGINT 0x6
#define SIGSEGV 0x7
#define SIGTERM 0x8

void (*signal(int sig, void (*func)(int)))(int);
int raise(int sig);

#ifdef __cplusplus
}
#endif

#endif // SIGNAL_H
