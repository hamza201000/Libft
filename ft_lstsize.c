#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


int ft_lstsize(t_list *lst)
{
    int size;

    size=0;
    while(lst!=NULL)
    {
        size++;
        lst=lst->next;
    }
    return size;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

#define TEST(name, expected, actual) do { \
    int exp = (expected); \
    int got = (actual); \
    if (exp == got) \
        printf("[OK]   %s: expected %d, got %d\n", \
            name, exp, got); \
    else \
        printf("[FAIL] %s: expected %d, got %d\n", \
            name, exp, got); \
} while (0)

static t_list *new_node(void *content)
{
    t_list *node = malloc(sizeof(t_list));

    if (!node)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    node->content = content;
    node->next = NULL;
    return (node);
}

static void clear_list(t_list *lst)
{
    t_list *next;

    while (lst)
    {
        next = lst->next;
        free(lst);
        lst = next;
    }
}

static t_list *make_list(int count)
{
    t_list  *head;
    t_list  *current;
    t_list  *node;
    int     i;

    head = NULL;
    current = NULL;
    i = 0;
    while (i < count)
    {
        node = new_node(NULL);
        if (!head)
            head = node;
        else
            current->next = node;
        current = node;
        i++;
    }
    return (head);
}

int main(void)
{
    t_list  *lst;
    t_list  *second;
    t_list  *third;
    t_list  *saved_next;
    int     i;

    /* 1. Empty list */
    TEST("NULL list", 0, ft_lstsize(NULL));

    /* 2. One node */
    lst = new_node("hello");
    TEST("One node", 1, ft_lstsize(lst));
    clear_list(lst);

    /* 3. Two nodes */
    lst = make_list(2);
    TEST("Two nodes", 2, ft_lstsize(lst));
    clear_list(lst);

    /* 4. Three nodes */
    lst = make_list(3);
    TEST("Three nodes", 3, ft_lstsize(lst));
    clear_list(lst);

    /* 5. Large list */
    lst = make_list(10000);
    TEST("10,000 nodes", 10000, ft_lstsize(lst));
    clear_list(lst);

    /* 6. Very large list */
    lst = make_list(100000);
    TEST("100,000 nodes", 100000, ft_lstsize(lst));
    clear_list(lst);

    /* 7. NULL content is still a node */
    lst = new_node(NULL);
    lst->next = new_node(NULL);
    lst->next->next = new_node(NULL);
    TEST("Nodes with NULL content", 3, ft_lstsize(lst));
    clear_list(lst);

    /* 8. Mixed content */
    lst = new_node("text");
    lst->next = new_node(NULL);
    lst->next->next = new_node((void *)42);
    TEST("Mixed content", 3, ft_lstsize(lst));
    clear_list(lst);

    /* 9. Verify links aren't modified */
    lst = make_list(3);
    second = lst->next;
    third = second->next;
    saved_next = lst->next;
    TEST("Before link check", 3, ft_lstsize(lst));
    if (lst->next == saved_next
        && lst->next == second
        && second->next == third
        && third->next == NULL)
        printf("[OK]   Links remain unchanged\n");
    else
        printf("[FAIL] Links were modified\n");
    clear_list(lst);

    /* 10. Repeated calls */
    lst = make_list(5);
    for (i = 0; i < 1000; i++)
    {
        if (ft_lstsize(lst) != 5)
        {
            printf("[FAIL] Repeated call at iteration %d\n", i);
            clear_list(lst);
            return (1);
        }
    }
    printf("[OK]   1,000 repeated calls\n");
    clear_list(lst);

    /* 11. Long list with one node removed */
    lst = make_list(1000);
    second = lst;
    while (second->next)
        second = second->next;
    free(second);

    /* Rebuild this test safely instead of leaving a dangling link. */
    clear_list(lst);

    lst = make_list(1000);
    second = lst;
    while (second->next->next)
        second = second->next;
    free(second->next);
    second->next = NULL;
    TEST("999 nodes after removing tail", 999, ft_lstsize(lst));
    clear_list(lst);

    printf("\nAll tests finished.\n");
    return (0);
}
