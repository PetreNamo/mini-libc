// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long a;
	a = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (a < 0)
	{
		errno = -a;
		return MAP_FAILED;
	}
	return (void *)a;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long a;
	a = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (a < 0)
	{
		errno = -a;
		return MAP_FAILED;
	}
	return (void *)a;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long a;
	a = syscall(__NR_munmap, addr, length);
	if (a < 0)
	{
		errno = -a;
		return -1;
	}
	return 0;
}
