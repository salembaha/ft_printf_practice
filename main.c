#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("%p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("\n");
	ft_printf("%p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("%p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);

	return (0);	
}
