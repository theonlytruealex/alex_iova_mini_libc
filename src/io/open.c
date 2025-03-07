// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	va_list valist;
	long a;
	va_start(valist, flags);
	a = va_arg(valist, long);
	va_end(valist);
	long res = syscall(2, filename, flags, a);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return res;
}
