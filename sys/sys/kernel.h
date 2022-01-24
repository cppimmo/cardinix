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
 * sys/kernel.h
 */
#ifndef _SYS_KERNEL_H_
#define _SYS_KERNEL_H_

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0])))
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))

/* Kernel global variables & constants. */
#define MAXHOSTNAMELEN 64

#define K_DEADDEAD 0xDEADDEAD
#define K_DEADBEEF 0xDEADBEEF

/* Host and domain names */
extern long hostid;
extern char hostname[MAXHOSTNAMELEN];
extern int hostnamelen;
extern char domainname[MAXHOSTNAMELEN];
extern int domainnamelen;

extern int utc_offset; /* seconds east of UTC */

extern int tick; /* usec per tick (1000000 / hz) */
extern int tick_nsec; /* nsec per tick */
extern int ticks; /* number of hardclock ticks */
extern int syshz; /* system clock frequency */
extern int stathz; /* statistics clock frequency */
extern int profhz; /* profiling clock frequency */
extern int lbolt; /* once a second sleep address */

#endif /* !_SYS_KERNEL_H_ */
