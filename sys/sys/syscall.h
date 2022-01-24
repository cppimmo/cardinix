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
 * sys/syscall.h - System call numbers.
 */
#ifndef _SYS_SYSCALL_H_
#define _SYS_SYSCALL_H_

#define SYS_access
#define SYS_creat
#define SYS_fsync
#define SYS_stat
#define SYS_fcntl
#define SYS_link
#define SYS_lseek
#define SYS_mkdir
#define SYS_mknod
#define SYS_open
#define SYS_opendir
#define SYS_poll
#define SYS_read
#define SYS_readdir
#define SYS_readlink
#define SYS_rename
#define SYS_rmdir
#define SYS_chmod
#define SYS_chown
#define SYS_utime
#define SYS_symlink
#define SYS_unlink
#define SYS_write

asmlinkage long sys_access(void);
asmlinkage long sys_creat(void);

#endif /* !_SYS_SYSCALL_H_ */
