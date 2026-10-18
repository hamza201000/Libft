#include <stdio.h>
#include <string.h>
#include <stddef.h>



size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dest_len;
    size_t i;

    dest_len=0;
    i=0;
    while (dst[dest_len])
    {
        dest_len++;
    }
    if (size>0){
        while (src[i]&&dest_len<size-1){
            dst[dest_len]=src[i];
            dest_len++;
            i++;
        }
        dst[dest_len]=0;
        while (src[i]!=0){
            dest_len++;
            i++;
        }
    }
    return dest_len;
}


int main(void)
{
    int failures = 0;
    char dst[50];
    size_t ret;

    /* TEST 1: Normal concatenation */
    strcpy(dst, "Hello");
    ret = ft_strlcat(dst, " World", sizeof(dst));
    if (ret == 11 && strcmp(dst, "Hello World") == 0)
        printf("TEST 1: OK\n");
    else
    {
        printf("TEST 1: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 2: Truncation */
    strcpy(dst, "Hello");
    ret = ft_strlcat(dst, " World", 8);
    if (ret == 11 && strcmp(dst, "Hello W") == 0)
        printf("TEST 2: OK\n");
    else
    {
        printf("TEST 2: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 3: size == destination length */
    strcpy(dst, "Hello");
    ret = ft_strlcat(dst, "World", 5);
    if (ret == 10 && strcmp(dst, "Hello") == 0)
        printf("TEST 3: OK\n");
    else
    {
        printf("TEST 3: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 4: size == 0 */
    strcpy(dst, "Hello");
    ret = ft_strlcat(dst, "World", 0);
    if (ret == 5 && strcmp(dst, "Hello") == 0)
        printf("TEST 4: OK\n");
    else
    {
        printf("TEST 4: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 5: Empty source */
    strcpy(dst, "Hello");
    ret = ft_strlcat(dst, "", sizeof(dst));
    if (ret == 5 && strcmp(dst, "Hello") == 0)
        printf("TEST 5: OK\n");
    else
    {
        printf("TEST 5: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 6: Empty destination */
    strcpy(dst, "");
    ret = ft_strlcat(dst, "Hello", sizeof(dst));
    if (ret == 5 && strcmp(dst, "Hello") == 0)
        printf("TEST 6: OK\n");
    else
    {
        printf("TEST 6: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 7: Exact fit */
    strcpy(dst, "abc");
    ret = ft_strlcat(dst, "def", 7);
    if (ret == 6 && strcmp(dst, "abcdef") == 0)
        printf("TEST 7: OK\n");
    else
    {
        printf("TEST 7: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    /* TEST 8: Destination longer than size */
    strcpy(dst, "1234567");
    ret = ft_strlcat(dst, "XY", 4);
    if (ret == 6 && strcmp(dst, "1234567") == 0)
        printf("TEST 8: OK\n");
    else
    {
        printf("TEST 8: FAIL | ret=%zu, dst=%s\n", ret, dst);
        failures++;
    }

    printf("\n--------------------\n");
    printf("Tests passed: %d/8\n", 8 - failures);
    printf("Tests failed: %d/8\n", failures);

    return failures != 0;
}