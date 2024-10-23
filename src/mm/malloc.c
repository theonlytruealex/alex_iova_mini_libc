// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	size_t len = size + sizeof(size_t);
	void *ret = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ret == MAP_FAILED) {
		return NULL;
	}
	size_t *free_support = (size_t *)ret;
	free_support[0] = size;
	return (void *)&free_support[1];
}

void *calloc(size_t nmemb, size_t size)
{
	size_t len = nmemb * size + sizeof(size_t);
	if (len == sizeof(size_t)) {
		return NULL;
	}
	void *ret = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	size_t *free_support = (size_t *)ret;
	free_support[0] = size;
	char *zeroer = (char *)ret;
	int i;
	for (i = sizeof(size_t); i < len; i++) {
		zeroer[i] = 0;
	}
	return (void *)&free_support[1];
}

void free(void *ptr)
{
	if (ptr == NULL) {
		return;
	}
	size_t *free_support = (size_t *)ptr;
	munmap((void *)&free_support[-1], free_support[-1]); 
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		malloc(size);
	}
	if (size == 0) {
		free(ptr);
	}
	size_t len = size + sizeof(size_t);
	size_t *old_size = (size_t *)ptr;
	void *ret = mremap((void *)&old_size[-1], old_size[-1], len, MREMAP_MAYMOVE);
	if (ret == MAP_FAILED) {
		return NULL;
	}
	size_t *free_support = (size_t *)ret;
	free_support[0] = len;
	return (void *)&free_support[1];
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb > 4294967295 / size) {
		return NULL;
	}
	return realloc(ptr, size * nmemb);
}
