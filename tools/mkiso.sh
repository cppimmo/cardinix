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
# tools/mkiso.sh - 
#

PROGNAME=cardinix
RELEASEDIR="$CARDINIXDIR"/release

# Stop execution if any errors occur:
set -e
"$TOOLSDIR"/build.sh

mkdir -p "$CARDINIXDIR"/release
mkdir -p "$CARDINIXDIR"/release/boot
mkdir -p "$CARDINIXDIR"/release/boot/grub

cp "$CARDINIXDIR"/"$SYSROOT"/boot/"$PROGNAME".kern \
   "$CARDINIXDIR"/release/boot/"$PROGNAME".kern

cat > "$CARDINIXDIR"/release/boot/grub/grub.cfg << EOF
menuentry "cardinix" {
    multiboot /boot/cardinix.kern
}
EOF
grub-mkrescue -o "$PROGNAME".iso release

