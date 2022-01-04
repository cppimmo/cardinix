#!/bin/sh
#
# cardinix, file: default-host.sh
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

PROGNAME="$(basename "$0")"
USERCHOICE=
DEFAULTCHOICE=i386-elf

usage() {
    echo "$PROGNAME: usage: $PROGNAME arch"
    return    
}

# arguments less than 1
if [ $# -lt 1 ]; then
    echo $DEFAULTCHOICE
else
    USERCHOICE="$1"
    export HOST="$USERCHOICE"
    echo "Current host successfully set to $USERCHOICE."
fi

