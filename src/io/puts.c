#include <sys/stat.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int puts(const char *s)
{
	int a, i;
	int b = strlen(s);
	char *aux;
	aux = (char *)malloc((b + 1) * sizeof(char));
	char *aux2 = (char *)s;
	for (i = 0; i < (int)strlen(s); i++)
		aux[i] = aux2[i];
	a = syscall(__NR_write, 1, aux, strlen(aux));
	a = syscall(__NR_write, 1, "\n", 1);
	free(aux);
	if (a < 0)
	{
		errno = -a;
		return -1;
	}
	return a;
}
