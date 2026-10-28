#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"



static t_list *new_node(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

static void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}



static int list_size(t_list *lst)
{
    int size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return size;
}

static void free_nodes(t_list *lst)
{
    t_list *tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

static void check(int condition, const char *test)
{
    printf("%s: %s\n", condition ? "PASS" : "FAIL", test);
}



void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (*lst==NULL){
        *lst=new;
        return;
    }
    temp=*lst;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=new;
    print_list(*lst);
    print_list(temp);
}
// t_link *h

// int main(void)
// {
//     t_list *lst;
//     t_list *node;

    

//     /* TEST 2: Add to a non-empty list */
//     lst = new_node("A");
//     lst->next = new_node("B");
//     node = new_node("C");
//     printf("here;;;");
//     print_list(lst);
//     ft_lstadd_back(lst, node);

//     check(lst->next->next == node && node->next == NULL,
//         "New node becomes the last node");
//     check(list_size(lst) == 3,
//         "List size increases by one");
//     print_list(lst);
//     free_nodes(lst);

    

//     return 0;
// }
