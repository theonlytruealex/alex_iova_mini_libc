#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec duration, rem;
    duration.tv_sec = seconds;
    duration.tv_nsec = 0;
    int res = nanosleep(&duration, &rem);
    if (res == -1) {
        return rem.tv_sec;
    }
    return 0;
}
