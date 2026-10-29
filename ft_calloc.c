


void *ft_calloc(size_t nmemb, size_t size)
{
    int *ptr;
    int i;
    
    i = 0;
    ptr = malloc(nmemb*size);
    if (!ptr)
        return NULL;
    while(ptr[i])
    {
        ptr[i]=0;
        i++;
    }
    return ptr;
}

// int main(void)
// {
//     size_t nmemb = 2;
//     size_t size = 1024;

//     int *my_ptr = ft_calloc(nmemb, size);
//     int *real_ptr = calloc(nmemb, size);

//     if (!my_ptr || !real_ptr)
//     {
//         printf("Allocation failed\n");
//         free(my_ptr);
//         free(real_ptr);
//         return (1);
//     }

//     printf("Testing ft_calloc:\n");
//     for (size_t i = 0; i < nmemb; i++)
//         printf("%d ", my_ptr[i]);

//     printf("\n\nTesting real calloc:\n");
//     for (size_t i = 0; i < nmemb; i++)
//         printf("%d ", real_ptr[i]);

//     printf("\n\nComparing memory: ");
//     if (memcmp(my_ptr, real_ptr, nmemb * size) == 0)
//         printf("OK\n");
//     else
//         printf("KO\n");

//     free(my_ptr);
//     free(real_ptr);
//     return (0);
// }





static int  check_zero(const void *ptr, size_t bytes)
{
    const unsigned char *p = ptr;
    size_t i;

    if (bytes == 0)
        return (1);
    if (ptr == NULL)
        return (0);
    i = 0;
    while (i < bytes)
    {
        if (p[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

static void test_case(const char *name, size_t nmemb, size_t size)
{
    void    *mine;
    void    *real;
    size_t  bytes;
    int     mine_ok;
    int     real_ok;
    int     same;

    printf("\n[TEST] %s\n", name);
    printf("nmemb = %zu, size = %zu\n", nmemb, size);

    /*
     * For nonzero inputs, test multiplication overflow before
     * calculating the expected byte count.
     */
    if (size != 0 && nmemb > SIZE_MAX / size)
    {
        mine = ft_calloc(nmemb, size);
        printf("ft_calloc returned: %s\n",
            mine == NULL ? "NULL (expected)" : "NON-NULL (FAIL)");
        if (mine != NULL)
            free(mine);
        printf("%s\n", mine == NULL ? "PASS" : "FAIL");
        return;
    }

    bytes = nmemb * size;
    mine = ft_calloc(nmemb, size);
    real = calloc(nmemb, size);

    /*
     * C permits calloc(0, ...) or calloc(..., 0) to return
     * NULL or a non-NULL pointer. Do not require equal pointers.
     */
    if (bytes == 0)
    {
        printf("ft_calloc: %s\n",
            mine == NULL ? "NULL" : "non-NULL");
        printf("calloc:    %s\n",
            real == NULL ? "NULL" : "non-NULL");
        printf("PASS (zero-size behavior is implementation-defined)\n");
        free(mine);
        free(real);
        return;
    }

    mine_ok = check_zero(mine, bytes);
    real_ok = check_zero(real, bytes);
    same = 0;
    if (mine != NULL && real != NULL)
        same = (memcmp(mine, real, bytes) == 0);

    printf("ft_calloc allocation: %s\n",
        mine != NULL ? "OK" : "NULL");
    printf("real calloc allocation: %s\n",
        real != NULL ? "OK" : "NULL");
    printf("ft_calloc zeroed: %s\n",
        mine_ok ? "YES" : "NO");
    printf("real calloc zeroed: %s\n",
        real_ok ? "YES" : "NO");
    printf("Memory comparison: %s\n",
        same ? "MATCH" : "NO MATCH");

    if (mine != NULL && real != NULL && mine_ok && real_ok && same)
        printf("RESULT: PASS\n");
    else if (mine == NULL && real == NULL)
        printf("RESULT: BOTH ALLOCATIONS FAILED (inconclusive)\n");
    else
        printf("RESULT: FAIL or allocation failure\n");

    free(mine);
    free(real);
}

int main(void)
{
    printf("====================================\n");
    printf("       FT_CALLOC TEST SUITE\n");
    printf("====================================\n");

    /* SIMPLE TESTS */
    test_case("One byte", 1, 1);
    test_case("One int", 1, sizeof(int));
    test_case("One char", 1, sizeof(char));
    test_case("One double", 1, sizeof(double));
    test_case("Five integers", 5, sizeof(int));
    test_case("Ten characters", 10, sizeof(char));
    test_case("One hundred integers", 100, sizeof(int));

    /* EDGE CASES */
    test_case("Zero elements", 0, sizeof(int));
    test_case("Zero element size", 5, 0);
    test_case("Both arguments zero", 0, 0);
    test_case("Large element size", 2, 1024);

    /* DIFFERENT ELEMENT COUNTS */
    test_case("Two elements", 2, sizeof(int));
    test_case("Three elements", 3, sizeof(int));
    test_case("Ten doubles", 10, sizeof(double));
    test_case("One thousand bytes", 1000, 1);

    /* OVERFLOW TESTS */
    test_case("SIZE_MAX elements of size 2", SIZE_MAX, 2);
    test_case("Multiplication overflow", SIZE_MAX / 2 + 1, 2);
    test_case("SIZE_MAX times SIZE_MAX", SIZE_MAX, SIZE_MAX);

    printf("\n====================================\n");
    printf("          TESTS FINISHED\n");
    printf("====================================\n");

    return (0);
}
