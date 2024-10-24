// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *aux = destination;
	while (*source != '\0')
	{
		*aux = *source;
		aux++;
		source++;
	}
	*aux = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *aux = destination;
	while (*source != '\0' && len != 0)
	{
		*aux = *source;
		aux++;
		source++;
		len--;
	}
	if (len > 0)
		*aux = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *aux = destination;
	while (*aux != '\0')
		aux++;
	while (*source != '\0')
	{
		*aux = *source;
		aux++;
		source++;
	}
	*aux = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *aux = destination;
	while (*aux != '\0')
		aux++;
	while (*source != '\0' && len != 0)
	{
		*aux = *source;
		aux++;
		source++;
		len--;
	}
	*aux = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	const char *s1 = str1;
	const char *s2 = str2;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 < *s2)
			return -1;
		else if (*s1 > *s2)
			return 1;
		s1++;
		s2++;
	}
	return 0;

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	const char *s1 = str1;
	const char *s2 = str2;
	while (*s1 != '\0' && *s2 != '\0' && len != 0)
	{
		if (*s1 < *s2)
			return -1;
		else if (*s1 > *s2)
			return 1;
		s1++;
		s2++;
		len--;
	}
	return 0;

	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char *aux = (char *)str;
	while (*aux != '\0')
	{
		if (*aux == c)
			return aux;
		aux++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *aux = (char *)str;
	char *a = NULL;
	while (*aux != '\0')
	{
		if (*aux == c)
			a = aux;
		aux++;
	}
	return a;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	char *s1 = (char *)haystack;
	char *s2 = (char *)needle;
	int ok = 0;
	char *p = NULL;
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			ok = 1;
			p = s1;
			while (ok == 1 && *s2 != '\0')
			{
				if (*s1 != *s2)
					ok = 0;
				s1++;
				s2++;
			}
			if (*s2 != '\0')
				ok = 0;
			if (ok == 0)
				s2 = (char *)needle;
		}
		s1++;
	}
	if (*s2 == '\0')
		return p;
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *s1 = (char *)haystack;
	char *s2 = (char *)needle;
	int ok = 0;
	char *p = NULL, *q = NULL;
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			ok = 1;
			p = s1;
			while (ok == 1 && *s2 != '\0')
			{
				if (*s1 != *s2)
					ok = 0;
				s1++;
				s2++;
			}
			if (ok == 1 && *s2 == '\0')
				q = p;
			s2 = (char *)needle;
		}
		s1++;
	}
	return q;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	size_t i;
	char *aux = (char *)destination;
	char *aux2 = (char *)source;
	for (i = 0; i < num; i++)
		aux[i] = aux2[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *aux;
	int b = strlen(source);
	aux = malloc((b + 1) * sizeof(char));
	char *aux1 = (char *)destination;
	char *aux2 = (char *)source;
	size_t i;
	for (i = 0; i < num; i++)
		aux[i] = aux2[i];
	for (i = 0; i < num; i++)
		aux1[i] = aux[i];
	free(aux);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *aux = (char *)ptr1;
	char *aux2 = (char *)ptr2;
	size_t i = 0;
	while (i < num - 1)
	{
		if (aux[i] < aux2[i])
			return -1;
		else if (aux[i] > aux2[i])
			return 1;
		i++;
	}
	return 0;
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *aux = (char *)source;
	size_t i;
	for (i = 0; i < num; i++)
		aux[i] = value;
	return source;
}
