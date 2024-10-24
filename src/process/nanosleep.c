#include <internal/syscall.h>
#include <stdlib.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
	int a;
	a = syscall(__NR_nanosleep, req, rem);
	if (a < 0)
	{
		errno = -a;
		return -1;
	}
	return 0;
}
