#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
int main(void)
{
	
	char * s = ft_substr("tripouille", 0, 42000);
	
	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	printf("\n");
	// /* 13  dfarhi */ check(!strcmp(s, "LES HARICOTS !"));
	// s = ft_substr("tripouille", 1, 1);
	printf("ft_substr(tripouille, 1, 1):%d\n",strcmp(s, "LES HARICOTS !"));
	// printf("strlen(tripouille) + 1:%s\n",s+ft_strlen("tripouille") + 1);
	printf("s:%s\n",s);
	return (0);
}
