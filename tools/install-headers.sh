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
# tools/install-headers.sh - Run make install-headers on every sub-project
#                            located in $SYSTEM_HEADER_PROJECTS
#

# Stop this script completely on error:
set -e
# Run config.sh to make sure the environment variabels are set:
$CARDINIXDIR/tools/config.sh

# Make sure the system root directory exists:
mkdir -p "$SYSROOT"

# Run make install-headers on every sub-project located in
# $SYSTEM_HEADER_PROJECTS
for PROJECT in $SYSTEM_HEADER_PROJECTS; do
    (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install-headers)
done

