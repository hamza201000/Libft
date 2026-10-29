// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "libft.h"



void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while(lst)
    {   
        f(lst->content);
        lst=lst->next;
    }
}




// static void print_content(void *content)
// {
//     printf("%s\n", (char *)content);
// }

// static void increment_int(void *content)
// {
//     (*(int *)content)++;
// }

// static void set_to_null(void *content)
// {
//     (void)content;
// }

// static void count_calls(void *content)
// {
//     int *count = (int *)content;
//     (*count)++;
// }

// int main(void)
// {
//     t_list  *lst;
//     t_list  *node2;
//     t_list  *node3;
//     int     a = 10;
//     int     b = 20;
//     int     c = 30;

//     lst = ft_lstnew(&a);
//     node2 = ft_lstnew(&b);
//     node3 = ft_lstnew(&c);

//     if (!lst || !node2 || !node3)
//         return (printf("Allocation failed\n"), 1);

//     lst->next = node2;
//     node2->next = node3;

//     printf("Before ft_lstiter:\n");
//     ft_lstiter(lst, print_content);

//     ft_lstiter(lst, increment_int);

//     printf("After increment:\n");
//     printf("%d %d %d\n", a, b, c);

//     /* Expected: 11 21 31 */

//     (void)set_to_null;
//     (void)count_calls;

//     /* Free nodes according to your libft implementation. */
//     free(node3);
//     free(node2);
//     free(lst);
//     return (0);
// }
