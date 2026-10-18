#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char  *new_dest;
    const unsigned char *new_src;
    size_t i;

    new_dest=dest;
    new_src=src;
    i=0;
    printf("dest:%s/src:%s nsize: %ld\n",(char *) dest,(char *) src,n);
    while(i<n){
        new_dest[i]=new_src[i];
        i++;
    }
    printf("dest:%s/src:%s\n",(char *) dest,(char *) src);
    return dest;
}

int main(void)
{
    int passed = 0;
    int failed = 0;

    // // TEST 1: Copy an integer
    {
        int a = 20;
        int b = 10;

        ft_memcpy(&b, &a, sizeof(int));

        if (b == 20)
        {
            printf("TEST 1: Integer copy: PASS\n");
            passed++;
        }
        else
        {
            printf("TEST 1: Integer copy: FAIL\n");
            failed++;
        }
    }

    // TEST 2: Copy a string, including the '\0'
    {
        char src[] = "Hello";
        char dest[6] = {0};

        ft_memcpy(dest, src, sizeof(src));

        if (memcmp(dest, src, sizeof(src)) == 0)
        {
            printf("TEST 2: String copy: PASS\n");
            passed++;
        }
        else
        {
            printf("TEST 2: String copy:%s FAIL\n",dest);
            failed++;
        }
    }

    // TEST 3: Copy an array
    {
        int src[] = {1, 2, 3, 4, 5};
        int dest[5] = {0};

        ft_memcpy(dest, src, sizeof(src));

        if (memcmp(dest, src, sizeof(src)) == 0)
        {
            printf("TEST 3: Array copy: PASS\n");
            passed++;
        }
        else
        {
            printf("TEST 3: Array copy: FAIL\n");
            failed++;
        }
    }

    // TEST 4: Copy only part of an array
    {
        char src[] = "ABCDE";
        char dest[] = "xxxxx";

        ft_memcpy(dest, src, 3);

        if (dest[0] == 'A' &&
            dest[1] == 'B' &&
            dest[2] == 'C' &&
            dest[3] == 'x' &&
            dest[4] == 'x')
        {
            printf("TEST 4: Partial copy: PASS\n");
            passed++;
        }
        else
        {
            printf("TEST 4: Partial copy: FAIL\n");
            failed++;
        }
    }

    // TEST 5: Zero bytes
    {
        char src[] = "Hello";
        char dest[] = "World";

        ft_memcpy(dest, src, 0);

        if (strcmp(dest, "World") == 0)
        {
            printf("TEST 5: Zero-byte copy: PASS\n");
            passed++;
        }
        else
        {
            printf("TEST 5: Zero-byte copy: FAIL\n");
            failed++;
        }
    }

    // TEST 6: Copy individual bytes
    {
        unsigned char src[] = {0x12, 0x34, 0x56, 0x78};
        unsigned char dest[4] = {0};

        ft_memcpy(dest, src, 4);

        if (memcmp(dest, src, 4) == 0)
        {
            printf("TEST 6: Byte copy: PASS\n");
            passed++;
        }
        else
        {
            printf("TEST 6: Byte copy: FAIL\n");
            failed++;
        }
    }

    printf("\nResults: %d passed, %d failed\n", passed, failed);

    return (failed != 0);
}