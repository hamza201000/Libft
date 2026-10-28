#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void *content){
    t_list *Node;

    Node=malloc(sizeof(t_list));
    if (Node==NULL)
    {
        return NULL;
    }
    (*Node).content=content;
    (*Node).next=NULL;
    return Node;
}



// int main(void)
// {
//     char str[] = "Hello";
//     t_list *node = ft_lstnew(str);

//     if (node && node->content == str)
//     {
//         str[0] = 'Y';
//         if (((char *)node->content)[0] == 'Y')
//             printf("PASS: original pointer stored\n");
//         else
//             printf("FAIL: content was copied\n");
//     }
//     else
//         printf("FAIL: node creation\n");

//     free(node);
//     return (0);
// }


// int main ()
// {

//     t_list *node;
//     node=ft_lstnew("hello world");
//     printf("content:%s\n",(char *)node->content);
//     free(node);
// }