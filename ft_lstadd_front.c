// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "libft.h"




void ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next=*lst;
    *lst=new;
}


// static t_list *new_node(void *content)
// {
//     t_list *node = malloc(sizeof(t_list));
//     if (!node)
//         return NULL;
//     node->content = content;
//     node->next = NULL;
//     return node;
// }

// static void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%s -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }



// static int list_size(t_list *lst)
// {
//     int size = 0;
//     while (lst)
//     {
//         size++;
//         lst = lst->next;
//     }
//     return size;
// }

// static void free_nodes(t_list *lst)
// {
//     t_list *tmp;

//     while (lst)
//     {
//         tmp = lst->next;
//         free(lst);
//         lst = tmp;
//     }
// }

// static void check(int condition, const char *test)
// {
//     printf("%s: %s\n", condition ? "PASS" : "FAIL", test);
// }

// int main(void)
// {
//     t_list *lst;
//     t_list *node;
//     t_list *original_first;

//     /* TEST 1: Add to an empty list */
//     lst = NULL;
//     node = new_node("A");
//     ft_lstadd_front(&lst, node);

//     check(lst == node && lst->next == NULL,
//         "Add to empty list");
//     free_nodes(lst);

//     /* TEST 2: Add to a non-empty list */
//     lst = new_node("B");
//     lst->next = new_node("C");
//     node = new_node("A");
//     // B -> C -> A -> NULL
//     original_first = lst;
//     ft_lstadd_front(&lst, node);

//     check(lst == node && lst->next == original_first,
//         "New node becomes first");
//     check(list_size(lst) == 3,
//         "List size increases by one");
//     print_list(lst);
//     free_nodes(lst);

//     /* TEST 3: Add several nodes in succession */
//     lst = NULL;
//     ft_lstadd_front(&lst, new_node("C"));
//     ft_lstadd_front(&lst, new_node("B"));
//     ft_lstadd_front(&lst, new_node("A"));

//     check(list_size(lst) == 3,
//         "Multiple insertions");
//     check(strcmp(lst->content, "A") == 0
//         && strcmp(lst->next->content, "B") == 0
//         && strcmp(lst->next->next->content, "C") == 0,
//         "Insertion order is correct");
//     print_list(lst);
//     free_nodes(lst);

//     /* TEST 4: Preserve the entire original chain */
//     lst = new_node("C");
//     lst->next = new_node("D");
//     original_first = lst;
//     node = new_node("A");
//     ft_lstadd_front(&lst, node);

//     check(node->next == original_first
//         && original_first->next != NULL
//         && original_first->next->next == NULL,
//         "Original chain remains intact");
//     free_nodes(lst);

//     /* TEST 5: Verify exact node identity */
//     lst = new_node("OLD");
//     node = new_node("NEW");
//     ft_lstadd_front(&lst, node);

//     check(lst == node,
//         "Head points to the exact new node");
//     check(lst->content == node->content,
//         "Content pointer is preserved");
//     free_nodes(lst);

//     /* TEST 6: Add a node with NULL content */
//     lst = new_node("B");
//     node = new_node(NULL);
//     ft_lstadd_front(&lst, node);

//     check(lst == node && lst->next != NULL,
//         "NULL content is accepted");
//     check(lst->content == NULL,
//         "NULL content remains NULL");
//     free_nodes(lst);

//     return 0;
// }












// // int main ()
// // {
// //     t_list *Node;
// //     t_list *new_node;
// //     Node=malloc(sizeof(t_list));
// //     if (Node==NULL){
// //         return 0;
// //     }
// //     (*Node).content="hello";
// //     (*Node).next=NULL;
// //     new_node=malloc(sizeof(t_list));
// //     if (new_node==NULL){
// //         return 0;
// //     }
// //     (*new_node).content="world";
// //     (*new_node).next=NULL;
// //     ft_lstadd_front(&Node,new_node);
// //     while((*Node).content!=NULL)
// //     {
// //         printf("*Node.content:%s\n",(char *)(*Node).content);
// //         *Node=*(*Node).next;
// //     }
// //     return 0;
// //}