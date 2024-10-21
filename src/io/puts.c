#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char *s)
{
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
	int res = write(1, s, len);
    write(1, '\n', 1);
	return res;
}