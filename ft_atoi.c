/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:12 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:13 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int ft_atoi(const char *nptr)
{
    int i;
    int value;
    int sng;

    i=0;
    sng=0;
    value=0;
    while ((nptr[i]>=9&&nptr[i]<=13) || nptr[i]==' ')
        i++;
    if (nptr[i]=='-' || nptr[i]=='+')
    {
        if (nptr[i]=='-' )
            sng=-1;
        i++;
    }
    while(nptr[i]>='0'&&nptr[i]<='9')
    {
        value=nptr[i]-'0'+(value*10);
        i++;
    }
    if (sng != 0)
        return sng * value;
    return value;
}

// int main()
// {

//     printf("ft_atoi:%d\n",ft_atoi("42"));


// }

// static int test_count = 0;
// static int fail_count = 0;

// void test_atoi(const char *str)
// {
//     int real_result;
//     int ft_result;

//     real_result = atoi(str);
//     ft_result = ft_atoi(str);
//     test_count++;

//     if (real_result == ft_result)
//         printf("\033[32mPASS\033[0m | \"%s\" | result: %d\n",
//             str, ft_result);
//     else
//     {
//         printf("\033[31mFAIL\033[0m | \"%s\"\n", str);
//         printf("  real atoi:    %d\n", real_result);
//         printf("  ft_atoi:      %d\n", ft_result);
//         fail_count++;
//     }
// }

// int main(void)
// {
//     /* Basic numbers */
//     test_atoi("0");
//     test_atoi("-111111111144444441111");
//     test_atoi("44444444444444444444442");
//     test_atoi("123456");
//     test_atoi("987654321");

//     /* Positive and negative signs */
//     test_atoi("+123");
//     test_atoi("-123");
//     test_atoi("+0");
//     test_atoi("-0");
//     test_atoi("++123");
//     test_atoi("--123");
//     test_atoi("+-123");
//     test_atoi("-+123");
//     test_atoi("+");
//     test_atoi("-");

//     /* Whitespace at the beginning */
//     test_atoi(" 123");
//     test_atoi("   123");
//     test_atoi("\t123");
//     test_atoi("\n123");
//     test_atoi("\v123");
//     test_atoi("\f123");
//     test_atoi("\r123");
//     test_atoi(" \t\n 42");
//     test_atoi("  -42");
//     test_atoi("  +42");

//     /* Whitespace after the number */
//     test_atoi("123 ");
//     test_atoi("123 456");
//     test_atoi("42\t99");

//     /* Letters and other characters */
//     test_atoi("abc");
//     test_atoi("abc123");
//     test_atoi("123abc");
//     test_atoi("123b4");
//     test_atoi("42xyz99");
//     test_atoi("12.34");
//     test_atoi("12-34");
//     test_atoi("12+34");
//     test_atoi("!123");
//     test_atoi("  abc123");
//     test_atoi("  -abc123");

//     /* Empty strings */
//     test_atoi("");
//     test_atoi(" ");
//     test_atoi("\t\n");

//     /* Zeros */
//     test_atoi("000");
//     test_atoi("000123");
//     test_atoi("-000123");
//     test_atoi("+000123");
//     test_atoi("000abc");

//     /* Numbers near int limits */
//     {
//         char min_str[50];
//         char max_str[50];

//         snprintf(min_str, sizeof(min_str), "%d", INT_MIN);
//         snprintf(max_str, sizeof(max_str), "%d", INT_MAX);
//         test_atoi(min_str);
//         test_atoi(max_str);
//     }

//     printf("\n-------------------------\n");
//     printf("Total tests: %d\n", test_count);
//     printf("Passed:      %d\n", test_count - fail_count);
//     printf("Failed:      %d\n", fail_count);
//     printf("-------------------------\n");

//     return (fail_count != 0);
// }
