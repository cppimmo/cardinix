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
# tools/build.sh
#

PROGNAME="$(basename "$0")"
# SYSDIR=./sys
# INCLUDEDIR=./include
# TOOLSDIR=./tools
# RELEASEDIR=./
#
usage() {
    echo "$PROGNAME: usage: $PROGNAME ..."
    return    
}
#
# echo "Building cardinix..."
#
# if grub-file --is-x86-multiboot kernel/cardinal.bin; then
# 	echo "multiboot enabled"
# else
# 	echo "multiboot disabled" >&2
# fi
#
# if [[ ! -e "release/boot/grub" ]]; then
# 	mkdir -p release/boot/grub
# fi
# cp kernel/cardinal.bin release/boot/cardinal.bin
# cp grub.cfg release/boot/grub.cfg
# grub-mkrescue -o cardinal.iso release

# Stop scripts execution on any error:
set -e
"$TOOLSDIR"/install-headers.sh

echo "Building cardinix..."
for PROJECT in $PROJECTS; do
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done
