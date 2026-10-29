// #include <stdio.h>
// #include <stdlib.h>
#include "libft.h"






void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *temp;

    if (!(*lst) || !del)
    {
        return ;
    }
    while(*lst)
    {
        temp=(*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst=temp;
    }
}

// void    del_content(void *content)
// {
//     free(content);
// }



// int main(void)
// {
//     t_list  *lst;
//     t_list  *node2;
//     t_list  *node3;

//     lst = ft_lstnew(malloc(sizeof(int)));
//     node2 = ft_lstnew(malloc(sizeof(int)));
//     node3 = ft_lstnew(malloc(sizeof(int)));

//     if (!lst || !node2 || !node3)
//         return (1);

//     *(int *)lst->content = 10;
//     *(int *)node2->content = 20;
//     *(int *)node3->content = 30;

//     lst->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     printf("Before ft_lstclear:\n");
//     printf("Node 1: %d\n", *(int *)lst->content);
//     printf("Node 2: %d\n", *(int *)node2->content);
//     printf("Node 3: %d\n", *(int *)node3->content);

//     ft_lstclear(&lst, del_content);

//     printf("\nAfter ft_lstclear:\n");
//     if (lst == NULL)
//         printf("The list is NULL. SUCCESS!\n");
//     else
//         printf("The list is not NULL. FAIL!\n");

//     return (0);
// }