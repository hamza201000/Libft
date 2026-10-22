
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


char *ft_strdup(const char *s)
{
    int i;
    char *copy;

    copy=malloc((ft_strlen((char *)s)+1)*sizeof(char));
    i=0;
    while(s[i]!=0)
    {
        copy[i]=s[i];
        i++;
    }
    copy[i]=0;
    return copy;
}



// int main(void)
// {
//     const char *tests[] = {
//         "Hello",
//         "",
//         "42",
//         "This is a longer string!",
//         "1234567890"
//     };

//     int count = sizeof(tests) / sizeof(tests[0]);
//     int passed = 0;

//     for (int i = 0; i < count; i++)
//     {
//         char *original = strdup(tests[i]);
//         char *mine = ft_strdup(tests[i]);
        

//         printf("Test %d: \"%s\"\n", i + 1, tests[i]);

//         if (original == NULL || mine == NULL)
//         {
//             printf("  FAIL: allocation failed\n");
//         }
//         else if (strcmp(original, mine) != 0)
//         {
//             printf("  FAIL: strings are different\n");
//             printf("  Original: \"%s\"\n", original);
//             printf("  Mine:     \"%s\"\n", mine);
//         }
//         else if (original == mine)
//         {
//             printf("  FAIL: same address\n");
//         }
//         else
//         {
//             printf("  PASS: strings match, addresses differ\n");
//             passed++;
//         }
        
//         free(original);
//         free(mine);
        
//     }

//     printf("\nResult: %d/%d tests passed\n", passed, count);

//     return (passed == count) ? 0 : 1;
// }
