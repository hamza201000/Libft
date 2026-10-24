


void ft_lstadd_front(t_list **lst, t_list *new)
{   

    (**lst).next=new;




}

int main ()
{
    t_list *Node;
    t_list *new_node;
    Node=malloc(sizeof(t_list));
    if (Node==NULL){
        return NULL;
    }
    (*Node.content)="hello";
    (*Node.next)=NULL;
    new_node=malloc(sizeof(t_list));
    if (new_node==NULL){
        return NULL;
    }
    (*new_node.content)="world";
    (*new_node.next)=NULL;
    ft_lstadd_front(&Node.content, );

    return 0;
}