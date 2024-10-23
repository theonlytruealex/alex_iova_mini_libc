// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	if ((flags & MAP_ANONYMOUS) == 0) {
		int ok_files = syscall(__NR_fcntl, fd, 1);
		if (ok_files < 0) {
			errno = EBADF;
			return MAP_FAILED;
		}
	}
	if (((flags & MAP_PRIVATE) ^ (flags & MAP_SHARED)) == 0) {
		errno = EINVAL;
		return MAP_FAILED;
	}
	void *res = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	return res;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	void *res = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	return res;
}

int munmap(void *addr, size_t length)
{
	int res = syscall(__NR_munmap, addr, length);
	return res;
}
