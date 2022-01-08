#!/bin/sh
#
# Copyright (C) 2022 Brian hoffpauir
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# tools/config.sh - Set environment variables used all throughout the project.
#

SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"
# Get the root directory of the cardinix project (used in other scripts):
export CARDINIXDIR="$(pwd)"
export TOOLSDIR=$CARDINIXDIR/tools

export MAKE=${MAKE:-make}
export HOST=${HOST:-$($TOOLSDIR/default-host.sh)}

# Toolchain environment setup:
export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc

export PREFIX=/usr
export EXEC_PREFIX=$PREFIX
export BOOTDIR=/boot
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

# Default cross-compiler flags:
export CFLAGS='-O2 -g'
export CPPFLAGS=''

# Make the cross-compiler use a set system root directory:
export SYSROOT="($pwd)/sysroot"
export CC="$CC --sysroot=$SYSROOT"

# Work around incase the -elf target for GCC was configured with options:
# --without-headers instead of --with-sysroot
if echo "$HOST" | grep -Eq -- '-elf($|-)'; then
    export CC="$CC -isystem=$INCLUDEDIR"
fi

