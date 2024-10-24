// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int a;
	a = syscall(__NR_ftruncate, fd, length);
	if (a < 0)
	{
		errno = -a;
		return -1;
	}
	return a;
}
