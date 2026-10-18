#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    int i;
    unsigned char *new_s;
    unsigned char new_c;
    
    i=0;
    new_s=(unsigned char *)s;
    new_c=(unsigned char )c;
    printf("s:%c,",new_s[0]);
    while (i<n)
    {
        if (new_s[i]==new_c)
        {
            return ((void *)&new_s[i]);
        }
        i++;
    }
    printf("\n");
    if (new_c==0&& i<n){
        return ((void *)&new_s[i]);
    }
    return NULL;
}


void *ft_memchr(const void *s, int c, size_t n);

int main(void)
{
    char str[] = "Hello World";

    // 1. Character exists at the beginning
    assert(ft_memchr(str, 'H', 11) == str);

    // 2. Character exists in the middle
    assert(ft_memchr(str, 'W', 11) == str + 6);

    // 3. Character exists at the end of the searched range
    assert(ft_memchr(str, 'o', 5) == str + 4);

    // 4. Character exists, but outside the searched range
    assert(ft_memchr(str, 'W', 5) == NULL);

    // 5. Character does not exist
    assert(ft_memchr(str, 'z', 110) == NULL);

    // 6. Search zero bytes
    assert(ft_memchr(str, 'H', 0) == NULL);

    // 7. Search for the null terminator
    assert(ft_memchr(str, '\0', sizeof(str)) == str + 11);

    // 8. Search range excludes the null terminator
    assert(ft_memchr(str, '\0', 11) == NULL);

    // 9. Search for a null byte inside the memory
    char data[] = {'a', '\0', 'b', 'c'};
    assert(ft_memchr(data, '\0', 4) == data + 1);

    // 10. Repeated characters: return the first occurrence
    char repeated[] = "aaaab";
    assert(ft_memchr(repeated, 'a', 5) == repeated);
    assert(ft_memchr(repeated, 'b', 5) == repeated + 4);

    // 11. Unsigned byte values: 128 and 255
    unsigned char bytes[] = {0, 127, 128, 200, 255};
    printf("is:%d\n",ft_memchr(bytes, 127, 5) == bytes + 1);
    // printf("is:%d\n",ft_memchr(bytes, 128, 5) == bytes + 2);
    // printf("is:%d\n",ft_memchr(bytes, 200, 5) == bytes + 3);
    // printf("is:%d\n",ft_memchr(bytes, 255, 5) == bytes + 4);
    
    //
    assert(ft_memchr(bytes, 127, 5) == bytes + 1);
    assert(ft_memchr(bytes, 128, 5) == bytes + 2);
    assert(ft_memchr(bytes, 200, 5) == bytes + 3);
    assert(ft_memchr(bytes, 255, 5) == bytes + 4);

    // 12. Character value outside the byte range wraps to unsigned char
    assert(ft_memchr(bytes, 255 + 256, 5) == bytes + 4);

    // 13. Compare against the standard function
    assert(ft_memchr(bytes, 200, 5) == memchr(bytes, 200, 5));

    printf("All tests passed!\n");
    return 0;
}