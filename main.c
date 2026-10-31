#include "libft.h"
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	memset(dest, 0, 30);
	dest[0] = 'B';
	
	printf("ft_strlcat(dest, src, 0):%zu\n",ft_strlcat(dest, src, 3));
	printf("strlen(src):%lu\n",ft_strlen(src));
	printf("strcmp(dest, B):%d\n",strcmp(dest, "BBBB"));
	printf("strcmp(dest, B):%s\n",dest);
	// printf("dest[strlen(src) + 1] == 'A':%c\n",dest[ft_strlen(src) + 1] );
	return (0);
}
