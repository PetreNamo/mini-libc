// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p;
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	mem_list_add(p, size);
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p;
	p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	char *c = (char *)p;
	size_t i;
	for (i = 0; i < nmemb * size; i++)
	{
		*c = 0;
		c++;
	}
	mem_list_add(p, nmemb * size);
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *p;
	p = mem_list_find(ptr);
	munmap(p->start, p->len);
	mem_list_del(p->start);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *p;
	p = mem_list_find(ptr);
	munmap(p->start, p->len);
	mem_list_del(p->start);

	void *q;
	q = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	mem_list_add(q, size);
	return q;
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	struct mem_list *p;
	p = mem_list_find(ptr);
	munmap(p->start, p->len);
	mem_list_del(p->start);

	void *q;
	q = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	char *c = (char *)q;
	size_t i;
	for (i = 0; i < nmemb * size; i++)
	{
		*c = 0;
		c++;
	}
	mem_list_add(q, nmemb * size);
	return q;
	return NULL;
}
