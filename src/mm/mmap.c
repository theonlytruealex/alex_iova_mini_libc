// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	void * res = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
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
