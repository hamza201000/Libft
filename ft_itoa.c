#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



size_t nmb_len(int n)
{
    size_t cou;

    cou=0;
    while(n>0)
    {
        n/=10;   
        cou++;
    }
    return cou;
}

char *ft_itoa(int n)
{

    char *nmb;
    size_t i;
    size_t n_len;

    n_len=nmb_len(n);
    i=n_len-1;
    nmb=malloc((n_len+1)*(sizeof(char)));
    if (nmb==NULL)
    {
        return NULL;
    }
    //123
    while(n>0)
    {
        nmb[i]=n%10+'0';
        n/=10;   
        i--;
    }
    nmb[nmb_len(n)]=0;
    return nmb;

}



static void test_itoa(int n, const char *expected)
{
    char *result = ft_itoa(n);

    if (result == NULL)
    {
        printf("FAIL: ft_itoa(%d) returned NULL\n", n);
        return;
    }

    if (strcmp(result, expected) == 0)
        printf("PASS: ft_itoa(%d) = \"%s\"\n", n, result);
    else
        printf("FAIL: ft_itoa(%d): expected \"%s\", got \"%s\"\n",
            n, expected, result);

    free(result);
}

int main(void)
{
    test_itoa(0, "0");
    test_itoa(1, "1");
    test_itoa(-1, "-1");
    test_itoa(9, "9");
    test_itoa(10, "10");
    test_itoa(-10, "-10");
    test_itoa(99, "99");
    test_itoa(100, "100");
    test_itoa(-99, "-99");
    test_itoa(-100, "-100");
    test_itoa(101, "101");
    test_itoa(1001, "1001");
    test_itoa(-1001, "-1001");
    test_itoa(1000000000, "1000000000");
    test_itoa(-1000000000, "-1000000000");
    test_itoa(INT_MAX, "2147483647");
    test_itoa(INT_MIN, "-2147483648");

    return 0;
}
