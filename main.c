#include "ft_printf.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char c[] = "bombardeen 42 fundacion telefonica";
	void *s = c;
	int ret_ft = 0, ret_pr = 0;
	printf("---------------------------------CURRENT---------------------------------\n");
	ret_ft = ft_printf("Hola %s, numero=%i uwu\n caracter=%c;\npuntero:
							% p\tcontent
						: % s\nvalue = % u\thex
						: % X\thex
						: %
								x\n ", " jose ", 123, 'x',
								s,
							c,
							UINT32_MAX,
							UINT32_MAX,
							UINT32_MAX);
	printf("RET VALUE = %d\n", ret_ft);
	printf("---------------------------------EXPECTED---------------------------------\n");
	ret_pr = printf("Hola %s, numero=%i uwu\n caracter=%c;\npuntero:
						% p\tcontent
					: % s\nvalue = % u\thex
					: % X\thex
					: %
							x\n ", " jose ", 123, 'x',
							s,
						c,
						UINT32_MAX,
						UINT32_MAX,
						UINT32_MAX);
	printf("RET VALUE = %d\n", ret_pr);
}