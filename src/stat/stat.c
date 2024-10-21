// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int res = syscall(__NR_stat, path, buf);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return res;
}
