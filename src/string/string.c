// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		if (source[i] == '\0') {
			break;
		}
		destination[i] = source[i];
	}
	for (; i < len; i++) {
		destination[i] = '\0';
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	int i = 0, len = strlen(destination);
	while (source[i] != '\0') {
		destination[len + i] = source[i];
		i++;
	}
	destination[i + len] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t i = 0, len2 = strlen(destination);
	while (source[i] != '\0' && i < len) {
		destination[len2 + i] = source[i];
		i++;
	}
	destination[i + len2] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] !='\0') {
		if (str1[i] > str2[i]) {
			return 1;
		}
		if (str1[i] < str2[i]) {
			return -1;
		}
		i++;
	}
	if (str1[i] > str2[i]) {
		return 1;
	}
	if (str1[i] < str2[i]) {
		return -1;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while (str1[i] != '\0' && str2[i] !='\0' && i < len) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		if (str1[i] < str2[i]) {
			return -1;
		}
		i++;
	}
	if (i == len) {
		return 0;
	}
	if (str1[i] > str2[i]) {
		return 1;
	}
	if (str1[i] < str2[i]) {
		return -1;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == c) {
			return (char *)(str + i);
		}
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	int i = strlen(str) - 1;
	while (i >= 0) {
		if (str[i] == c) {
			return (char *)(str + i);
		}
		i--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	int i = 0;
	while (haystack[i] != '\0') {
		int j = 0;
		while (haystack[i + j] != '\0' && needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0') {
			return (char *)(haystack + i);
		}
		i++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int i = strlen(haystack), needle_len = strlen(needle);
	while (i >= 0) {
		int j = 0;
		while (i + j >= 0 && needle_len + j > 1 && haystack[i + j] == needle[needle_len - 1 + j])
			j--;
		if (needle_len + j == 1) {
			return (char *)(haystack + i - needle_len + 1);
		}
		i--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	size_t i;
	char* string_dst = (char*)destination;
	char* string_src = (char*)source;

	// The function does not check for any terminating null character in source -
	//it always copies exactly num bytes.
	for (i = 0; i < num; i++) {
		string_dst[i] = string_src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	size_t i;
	char* string_dst = (char*)destination;
	char* string_src = (char*)source;

	// The function does not check for any terminating null character in source -
	//it always copies exactly num bytes.
	if (destination < source) {
		for (i = 0; i < num; i++) {
			string_dst[i] = string_src[i];
		}
	} else {
		for (i = num - 1; i + 1 > 0; i--) {
			string_dst[i] = string_src[i];
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i = 0;
	char* str1 = (char*)ptr1;
	char* str2 = (char*)ptr2;
	while (i < num) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		if (str1[i] < str2[i]) {
			return -1;
		}
		i++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char c = (char)value;
	char* str = (char*)source;
	for (size_t i = 0; i < num; i++) {
		str[i] = c;
	}
	return source;
}
