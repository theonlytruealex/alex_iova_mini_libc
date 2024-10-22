#include <internal/syscall.h>
#include <time.h>

int nanosleep(const struct timespec *duration, struct timespec *rem) {
    int res = syscall(__NR_nanosleep, duration, rem);
    return res;
}
