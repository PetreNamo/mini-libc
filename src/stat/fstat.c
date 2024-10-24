// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int a;
	a = syscall(__NR_fstat, fd, st);
	if (a < 0)
	{
		errno = -a;
		return -1;
	}
	return a;
}
