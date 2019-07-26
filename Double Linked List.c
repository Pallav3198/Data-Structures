#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
// defining the structure of the node
typedef struct node
{
    struct node * prev;
    int data;
    struct node * next;
}node;
// pointer of struct nodetype: list
typedef struct node * list;
// root pointer
list start = NULL;
//***TO CREATE A DOUBLE LINKED LIST
list create_list(list start)
{
    int num;
    list new_node,ptr;
    printf("\nEnter -1 to end\n");
    do{
            printf("Enter the data in the new node\n");
            scanf("%d",&num);
            new_node = (list)malloc(sizeof(node));
            new_node->data = num;
            if(start==NULL)
            {
                new_node->next = NULL;
                new_node->prev = NULL;
                start = new_node;
            }
            else
            {
                ptr = start;
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->prev = ptr;
                new_node->next = NULL;
            }

    }while(num!=-1);
  return start;
}
// display the list
list display(list start)
{
    list ptr;
    ptr = start;
    while(ptr->next!=NULL)
    {
        printf("| %d |",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
// insert at the beginning of the list
list insert_beg(list start)
{
    int num;
    list new_node;
    printf("Enter the data in the new node\n");
    scanf("%d",&num);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    new_node->prev = NULL;
    start->prev = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}
// insert at the end
list insert_end(list start)
{
    int num;
    list new_node,ptr;
    printf("Enter the data in the new node\n");
    scanf("%d",&num);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    ptr = start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    new_node->next = NULL;
    new_node->prev = ptr;
    ptr->next = new_node;
    return start;
}
// insert before a given node
list insert_bef(list start)
{
    int num,cmp;
    list new_node,ptr;
    printf("Enter the data in the new node\n");
    scanf("%d",&num);
    printf("Enter the data in the node before which the new node has to be inserted\n");
    scanf("%d",&cmp);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    ptr = start;
    while(ptr->data!=cmp)
        ptr = ptr->next;
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return start;
}
// insert after a given node
list insert_after(list start)
{
    int num,cmp;
    list new_node,ptr;
    printf("Enter the data in the new node\n");
    scanf("%d",&num);
    printf("Enter the data in the node after which the new node has to be inserted\n");
    scanf("%d",&cmp);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    ptr = start;
    while(ptr->data!=cmp)
        ptr = ptr->next;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    new_node->prev = ptr;
    ptr->next = new_node;
    return start;
}
// delete from the beginning of the list
list del_beg(list start)
{
    list ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}
// delete from the end of the list
list del_end(list start)
{
    list  ptr;
    ptr = start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}
// delete after a given node
list del_after(list start)
{
    list ptr,temp;
    int num;
    printf("Enter the data of the node,after which has to be deleted\n");
    scanf("%d",&num);
    ptr = start;
    while(ptr->data!=num)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return start;
}
//delete before a given node
list del_bef(list start)
{
    list ptr,temp;
    int num;
    printf("Enter the data of the node before which the node has to be deleted\n");
    scanf("%d",&num);
    ptr = start;
    while(ptr->data!=num)
        ptr=ptr->next;
    temp = ptr->prev;
    if(temp==start)
        start = del_beg(start);
    else
    {
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
    }
    free(temp);
    return start;
}
// Delete the entire list
list del_list(list start)
{
    list ptr;
    ptr = start;
    while(ptr->next!=NULL)
        start = del_beg(start);
    return start;
}
int main()
{
    int option;
    printf("\nMain Menu\n");
    printf("\n1.Create the list\n");
    printf("\n2.Display the list\n");
    printf("\n3.Insert at the beginning of the list\n");
    printf("\n4.Insert at the end of the list\n");
    printf("\n5.Insert after a given node\n");
    printf("\n6.Insert before a given node\n");
    printf("\n7.Delete from the beginning of the list\n");
    printf("\n8.Delete from the end of the list\n");
    printf("\n9.Delete after a given node\n");
    printf("\n10.Delete before a given node\n");
    printf("\n11.Delete the entire list\n");
    printf("\nEnter your choice\n");
    scanf("%d",&option);
    while(option!=12)
    {

    switch(option)
    {
        case 1: start = create_list(start);
        break;

        case 2: start = display(start);
        break;

        case 3: start = insert_beg(start);
        break;

        case 4: start = insert_end(start);
        break;

        case 5: start = insert_after(start);
        break;

        case 6: start = insert_bef(start);
        break;

        case 7: start = del_beg(start);
        break;

        case 8: start = del_end(start);
        break;

        case 9: start = del_after(start);
        break;

        case 10: start = del_bef(start);
        break;

        case 11: start = del_list(start);
        break;

    }
  }
    return 0;
    clrscr();
}


