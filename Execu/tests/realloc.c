#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int	*arr;
	int	*keep;

	arr = malloc(sizeof(int) * 3);
	keep = arr;
	*(arr) = 1;
	*(arr + 1) = 2;
	*(arr + 2) = 3;
	arr += 3 ;
	arr	= malloc(sizeof(int));
	keep[3] = 5;
	int i = 0;
	while (i < 4)
		printf("%d\n", keep[i++]);
	return (0);
}
