
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"



t_list *ft_lstlast(t_list *lst)
{
    if (lst==NULL)
    {
        return NULL;
    }
    while(lst->next!=NULL){
        lst=lst->next;
    }
    return lst;
}



#define TEST_PTR(name, expected, actual) do { \
    t_list *exp = (expected); \
    t_list *got = (actual); \
    if (exp == got) \
        printf("[OK]   %s\n", name); \
    else \
        printf("[FAIL] %s\n", name); \
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

static t_list *make_list(int count)
{
    t_list *head;
    t_list *current;
    t_list *node;
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

int main(void)
{
    t_list *lst;
    t_list *last;
    t_list *middle;
    t_list *saved_head_next;
    t_list *saved_middle_next;
    t_list *expected;
    int     i;

    /* 1. Empty list */
    TEST_PTR("NULL list", NULL, ft_lstlast(NULL));

    /* 2. One node */
    lst = new_node("hello");
    TEST_PTR("Single node", lst, ft_lstlast(lst));
    clear_list(lst);

    /* 3. Two nodes */
    lst = make_list(2);
    expected = lst->next;
    TEST_PTR("Two nodes", expected, ft_lstlast(lst));
    clear_list(lst);

    /* 4. Three nodes */
    lst = make_list(3);
    expected = lst->next->next;
    TEST_PTR("Three nodes", expected, ft_lstlast(lst));
    clear_list(lst);

    /* 5. Last node has NULL content */
    lst = new_node("first");
    lst->next = new_node("second");
    lst->next->next = new_node(NULL);
    expected = lst->next->next;
    TEST_PTR("Last content is NULL", expected, ft_lstlast(lst));
    clear_list(lst);

    /* 6. All node contents are NULL */
    lst = make_list(5);
    expected = lst;
    while (expected->next)
        expected = expected->next;
    TEST_PTR("All contents NULL", expected, ft_lstlast(lst));
    clear_list(lst);

    /* 7. Large list: 10,000 nodes */
    lst = make_list(10000);
    expected = lst;
    while (expected->next)
        expected = expected->next;
    TEST_PTR("10,000 nodes", expected, ft_lstlast(lst));
    clear_list(lst);

    /* 8. Very large list: 100,000 nodes */
    lst = make_list(100000);
    expected = lst;
    while (expected->next)
        expected = expected->next;
    TEST_PTR("100,000 nodes", expected, ft_lstlast(lst));
    clear_list(lst);

    /* 9. Verify the list links aren't modified */
    lst = make_list(4);
    middle = lst->next;
    last = middle->next->next;
    saved_head_next = lst->next;
    saved_middle_next = middle->next;
    expected = lst;
    while (expected->next)
        expected = expected->next;

    TEST_PTR("Correct last pointer", expected, ft_lstlast(lst));
    if (lst->next == saved_head_next
        && middle->next == saved_middle_next
        && last->next == NULL)
        printf("[OK]   Links unchanged\n");
    else
        printf("[FAIL] Links modified\n");
    clear_list(lst);

    /* 10. Repeated calls */
    lst = make_list(10);
    expected = lst;
    while (expected->next)
        expected = expected->next;
    for (i = 0; i < 1000; i++)
    {
        if (ft_lstlast(lst) != expected)
        {
            printf("[FAIL] Repeated call %d\n", i);
            clear_list(lst);
            return (1);
        }
    }
    printf("[OK]   1,000 repeated calls\n");
    clear_list(lst);

    /* 11. Last node after removing the tail */
    lst = make_list(5);
    middle = lst;
    while (middle->next->next)
        middle = middle->next;
    free(middle->next);
    middle->next = NULL;
    TEST_PTR("Updated last after tail removal",
        middle, ft_lstlast(lst));
    clear_list(lst);

    printf("\nAll tests finished.\n");
    return (0);
}
