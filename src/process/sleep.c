#include <internal/syscall.h>
#include <stdlib.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    int a = nanosleep(&req, &rem);
    if (a == -1)
        return rem.tv_nsec;
    return 0;
}
