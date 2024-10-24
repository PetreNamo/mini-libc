// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int a = syscall(__NR_close, fd);
	if (a < 0)
	{
		errno = -a;
		return -1;
	}
	return a;
}
