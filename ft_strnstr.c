#include "linft"


char *ft_strnstr(const char *big, const char *little, size_t len)
{


    size_t i_b;
    size_t i_l;
    char *ptr;
    int find;

    i_b=0;
    i_l=0;
    find=0;
    
    if(!little[i_l]){
        return (char *)big;
    }
    while(little[i_l] && big[i_b] )
    {   
        i_l=0;
        while (little[i_l] && big[i_b]&&little[i_l]==big[i_b]&& i_b<len)
        {
            if (!find){
                ptr=(char *)&big[i_b];
                find=1;
            }
            i_b++;
            i_l++;
        }
        i_b++;
    }
    if (little[i_l]){
        return NULL;
    }
    return ptr;
}


void test_strnstr(const char *big, const char *little, size_t len)
{
    char *expected;
    char *result;

    expected = strnstr(big, little, len);
    result = ft_strnstr(big, little, len);

    if (expected == result)
        printf("PASS | big: \"%s\" | little: \"%s\" | len: %zu\n",
            big, little, len);
    else
    {
        printf("FAIL | big: \"%s\" | little: \"%s\" | len: %zu\n",
            big, little, len);
        printf("  Expected: %s\n",
            expected ? expected : "NULL");
        printf("  Got:      %s\n",
            result ? result : "NULL");
    }
}

int main(void)
{
    test_strnstr("Hello World", "World", 11);
    test_strnstr("Hello World", "World", 10);
    test_strnstr("Hello World", "Hello", 5);
    test_strnstr("Hello World", "Hello", 4);
    test_strnstr("Hello World", "xyz", 11);
    test_strnstr("Hello World", "", 11);
    test_strnstr("", "", 0);
    test_strnstr("", "Hello", 5);
    test_strnstr("aaaaa", "aaa", 5);
    test_strnstr("aaaaa", "aaaaaa", 5);
    test_strnstr("abcdef", "def", 6);
    test_strnstr("abcdef", "def", 5);
    test_strnstr("abcabc", "cab", 6);
    test_strnstr("abcabc", "abc", 3);
    test_strnstr("abcabc", "abc", 2);
    test_strnstr("42 school", "school", 9);
    test_strnstr("42 school", "school", 8);
    test_strnstr("abcdef", "cd", 0);
    test_strnstr("abc", "abcd", 3);

    return 0;
}
