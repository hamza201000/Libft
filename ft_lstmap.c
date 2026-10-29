#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list *list;
    t_list *new_node;
    
    list=NULL;
    while(lst)
    {
        new_node=ft_lstnew(f(lst->content));
        if (!new_node)
        {
            ft_lstclear(&list,del);
            return NULL;
        }
        printf("here:%s\n",(char *)new_node->content);
        ft_lstadd_back(&list,new_node);
        lst=lst->next;
    }
    return list;
}



// /* Apply f: duplicate a string and convert it to uppercase */
// void    *ft_uppercase(void *content)
// {
//     char    *src;
//     char    *dst;
//     int     i;

//     src = (char *)content;
//     dst = malloc(strlen(src) + 1);
//     if (!dst)
//         return (NULL);
//     i = 0;
//     while (src[i])
//     {
//         if (src[i] >= 'a' && src[i] <= 'z')
//             dst[i] = src[i] - 32;
//         else
//             dst[i] = src[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (dst);
// }

// /* Delete the content of a node */
// void    ft_del(void *content)
// {
//     free(content);
// }

// /* Print the list */
// void    print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%s", (char *)lst->content);
//         if (lst->next)
//             printf(" -> ");
//         lst = lst->next;
//     }
//     printf("\n");
// }

// int main(void)
// {
//     t_list  *lst;
//     t_list  *new_lst;

//     lst = NULL;

//     ft_lstadd_back(&lst, ft_lstnew(strdup("hello")));
//     ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
//     ft_lstadd_back(&lst, ft_lstnew(strdup("42")));

//     printf("Original list:\n");
//     print_list(lst);

//     new_lst = ft_lstmap(lst, ft_uppercase, ft_del);

//     printf("\nMapped list:\n");
//     if (new_lst)
//         print_list(new_lst);
//     else
//         printf("NULL\n");

//     printf("\nOriginal list after mapping:\n");
//     print_list(lst);

//     ft_lstclear(&new_lst, ft_del);
//     ft_lstclear(&lst, ft_del);

//     lst = NULL;

//     ft_lstadd_back(&lst, ft_lstnew(strdup("42")));
//     ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
//     ft_lstadd_back(&lst, ft_lstnew(strdup("hello")));

//     printf("Original list:\n");
//     print_list(lst);

//     new_lst = ft_lstmap(lst, ft_uppercase, ft_del);

//     printf("\nMapped list:\n");
//     if (new_lst)
//         print_list(new_lst);
//     else
//         printf("NULL\n");

//     printf("\nOriginal list after mapping:\n");
//     print_list(lst);

//     ft_lstclear(&new_lst, ft_del);
//     ft_lstclear(&lst, ft_del);

//     return (0);
// }




