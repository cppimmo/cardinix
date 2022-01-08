/* cardinix, file: cat.c */
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
#include <stdio.h>
#include <stdlib.h>

#define PROGNAME "cat"
#define DEFAULT_MAX_BUF 256
#define ABSOLUTE_MAX_BUF 1024

#define SUPPORTED_FLAGS ""

enum flags {
    FLAG_NUMBER, /* */
    FLAG_NUMBER_LONG,
    FLAG_SHOW_TAB, /* */
    FLAG_SHOW_TAB_LONG, /* */
    FLAG_HELP, /* */
    FLAG_HELP_LONG, /* */
    FLAG_VERSION, /* */
    FLAG_VERSION_LONG /* */
};

static void usage(void);

int retcode = EXIT_SUCCESS;

int
main(int argc, char *argv[])
{
    
    return retcode;
}

void
usage(void)
{
    fprintf(stdout, "usage: "PROGNAME" [-");
    exit(EXIT_SUCCESS);
}

