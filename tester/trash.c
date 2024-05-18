#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

int main()
{
	int *array = calloc(ULONG_MAX,sizeof(int));
	perror(strerror(errno));
	puts(" ");
	perror(strerror(ENOMEM));
	//free(array);
}
