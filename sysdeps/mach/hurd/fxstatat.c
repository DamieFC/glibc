/* Get information about file named relative to open directory.  Hurd version.
   Copyright (C) 2006-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <hurd.h>
#include <shlib-compat.h>

#if SHLIB_COMPAT(libc, GLIBC_2_4, GLIBC_2_33)

int
__fxstatat (int vers, int fd, const char *filename, struct stat *buf, int flag)
{
  if (vers != _STAT_VER)
    return __hurd_fail (EINVAL);

  return __fstatat (fd, filename, buf, flag);
}

#endif
