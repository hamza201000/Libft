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

int main(void)
{
    t_list *lst;
    t_list *node;
    t_list *last;
    t_list *original_first;

    /* TEST 1: Add to an empty list */
    lst = NULL;
    node = new_node("A");
    ft_lstadd_back(&lst, node);

    check(lst == node && lst->next == NULL,
        "Add to empty list");
    print_list(lst);
    free_nodes(lst);

    /* TEST 2: Add to a non-empty list */
    lst = new_node("A");
    lst->next = new_node("B");
    node = new_node("C");

    ft_lstadd_back(&lst, node);

    check(lst->next->next == node && node->next == NULL,
        "New node becomes the last node");
    check(list_size(lst) == 3,
        "List size increases by one");
    print_list(lst);
    free_nodes(lst);

    /* TEST 3: Add several nodes in succession */
    lst = NULL;
    ft_lstadd_back(&lst, new_node("A"));
    ft_lstadd_back(&lst, new_node("B"));
    ft_lstadd_back(&lst, new_node("C"));

    check(list_size(lst) == 3,
        "Multiple insertions");
    check(strcmp(lst->content, "A") == 0
        && strcmp(lst->next->content, "B") == 0
        && strcmp(lst->next->next->content, "C") == 0,
        "Insertion order is correct");
    print_list(lst);
    free_nodes(lst);

    /* TEST 4: Preserve the original head */
    lst = new_node("A");
    lst->next = new_node("B");
    original_first = lst;
    node = new_node("C");

    ft_lstadd_back(&lst, node);

    check(lst == original_first,
        "Original head remains unchanged");
    check(strcmp(lst->content, "A") == 0,
        "First node content remains unchanged");
    free_nodes(lst);

    /* TEST 5: Verify exact node identity */
    lst = new_node("A");
    node = new_node("B");

    ft_lstadd_back(&lst, node);

    last = lst;
    while (last->next)
        last = last->next;

    check(last == node,
        "Last node is the exact new node");
    check(last->content == node->content,
        "Content pointer is preserved");
    free_nodes(lst);

    /* TEST 6: Add a node with NULL content */
    lst = new_node("A");
    node = new_node(NULL);

    ft_lstadd_back(&lst, node);

    check(lst->next == node && node->next == NULL,
        "Node with NULL content is added");
    check(node->content == NULL,
        "NULL content remains NULL");
    free_nodes(lst);

    /* TEST 7: Add to a list containing one node */
    lst = new_node("A");
    node = new_node("B");

    ft_lstadd_back(&lst, node);

    check(lst->next == node && node->next == NULL,
        "Append to a single-node list");
    check(list_size(lst) == 2,
        "Single-node list size becomes two");
    free_nodes(lst);

    /* TEST 8: Verify the complete chain */
    lst = new_node("A");
    lst->next = new_node("B");
    lst->next->next = new_node("C");
    node = new_node("D");

    ft_lstadd_back(&lst, node);

    check(lst->next->next->next == node
        && node->next == NULL,
        "Complete chain remains intact");
    check(list_size(lst) == 4,
        "Complete chain has the correct size");
    print_list(lst);
    free_nodes(lst);

    return 0;
}
