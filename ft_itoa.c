
size_t nmb_len(long n)
{
    size_t cou;

    cou=0;
    if (n<0){
        cou++;
        n*=-1;
    }else if(n==0){
        cou++;
    }
    while(n>0)
    {
        n/=10; 
        cou++;
    }
    return cou;
}

char *ft_cnv(char *nmb ,long n,size_t n_len)
{
    size_t i;

    i=n_len-1;
    if (n<0)
    {
        n*=-1;
        nmb[0]='-';
    }else if (n==0){
        nmb[0]='0';
    }
    while(n>0)
    {
        nmb[i]=n%10+'0';
        n/=10;
        i--;
    }
    nmb[n_len]=0;
    return nmb;
}


char *ft_itoa(int n)
{
    char *nmb;
    size_t n_len;
    
    n_len=nmb_len(n);
    nmb=malloc((n_len+1)*(sizeof(char)));
    if (nmb==NULL)
    {
        return NULL;
    }
    return ft_cnv(nmb ,(long) n,n_len);
}

// static void test_itoa(int n, const char *expected)
// {
//     char *result = ft_itoa(n);

//     if (result == NULL)
//     {
//         printf("FAIL: ft_itoa(%d) returned NULL\n", n);
//         return;
//     }

//     if (strcmp(result, expected) == 0)
//         printf("PASS: ft_itoa(%d) = \"%s\"\n", n, result);
//     else
//         printf("FAIL: ft_itoa(%d): expected \"%s\", got \"%s\"\n",
//             n, expected, result);

//     free(result);
// }

// int main(void)
// {
//     test_itoa(0, "0");
//     test_itoa(1, "1");
//     test_itoa(-1, "-1");
//     test_itoa(9, "9");
//     test_itoa(10, "10");
//     test_itoa(-10, "-10");
//     test_itoa(99, "99");
//     test_itoa(100, "100");
//     test_itoa(-99, "-99");
//     test_itoa(-100, "-100");
//     test_itoa(101, "101");
//     test_itoa(1001, "1001");
//     test_itoa(-1001, "-1001");
//     test_itoa(1000000000, "1000000000");
//     test_itoa(-1000000000, "-1000000000");
//     test_itoa(INT_MAX, "2147483647");
//     test_itoa(INT_MIN, "-2147483648");

//     return 0;
// }