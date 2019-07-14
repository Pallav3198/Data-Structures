#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodetype
{
    int data;
    struct nodetype* next;
}node;
typedef struct nodetype* list;
list start = NULL;
//Create the List
list create_list(list start)
{
    list new_node,ptr;
    int num;
    printf("\nEnter -1 to end\n");
    do{
        printf("\nEnter the data in the new node\n");
        scanf("%d",&num);
        new_node = (list)malloc(sizeof(node));
        new_node->data = num;
        if(start==NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
             ptr = start;
             while(ptr->next!=NULL)
                ptr=ptr->next;
             ptr->next = new_node;
             new_node->next = NULL;
        }

    }while(num!=-1);

  return start;
}
//Display the list
list display(list start)
{
    list ptr;
    printf("\nDisplaying the Linked List\n");
    ptr = start;
    while(ptr->next!=NULL)
    {
        printf("\t%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d\t",ptr->data);
    return start;
}
// Insert at the Beginning
list insert_beg(list start)
{
    list new_node;
    int num;
    printf("\nEnter the data in the new node\n");
    scanf("%d",&num);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
//Insert at the end
list insert_end(list start)
{
    int num;
    list new_node,ptr,preptr;
    printf("\nEnter the data in the node\n");
    scanf("%d",&num);
    new_node=(list)malloc(sizeof(node));
    new_node->data = num;
    new_node->next = NULL;
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next = new_node;
    return start;
}
// Insert a node before a given node
list insert_bef(list start)
{
    list new_node,ptr,preptr;
    int num,cmp;
    printf("\nEnter the data in the new node\n");
    scanf("%d",&num);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    printf("\nEnter the data of the node before which the new node has to be inserted\n");
    scanf("%d",&cmp);
    ptr = start;
    preptr=ptr;
    while(ptr->data!=cmp)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next = new_node;
    new_node->next=ptr;

return start;
}
// Insert After a given node
list insert_after(list start)
{
    list new_node,ptr,preptr;
    int num,cmp;
    printf("\nEnter the data in the new node\n");
    scanf("%d",&num);
    new_node = (list)malloc(sizeof(node));
    new_node->data = num;
    printf("\nEnter the data of the node after which the new node has to be inserted\n");
    scanf("%d",&cmp);
    ptr = start;
    preptr=ptr;
    while(ptr->data!=cmp)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr=new_node;
    new_node->next = ptr;

return start;
}
//Delete Node from the Beginning
list del_beg(list start)
{
    list ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
//Delete the node from the end
list del_end(list start)
{
    list ptr,preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
   return start;
}
// Delete any Node
list del_node(list start)
{
    list new_node,ptr,preptr;
    int num;
    printf("Enter the value of the node which has to be deleted\n");
    scanf("%d",&num);
    ptr = start;
    preptr = ptr;
    while(ptr->data!=num)
    {
        preptr = ptr;
        ptr=ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}
// Delete Node after a given node
list del_after(list start)
{
    list ptr,preptr;
    int cmp;
    printf("Enter the value of the node before which the node has to be deleted\n");
    scanf("%d",&cmp);
    ptr=start;
    preptr = ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);

  return start;
}
// Delete the entire list
list del_list(list start)
{
    list ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        start = del_beg(start);
        ptr=ptr->next;
    }
return start;
}
int main()
{
      int option;
    do{
        printf("\n1. Create the List\n");
        printf("\n2. Display the List\n");
        printf("\n3. Add Node at the beginning\n");
        printf("\n4. Add Node at the end\n");
        printf("\n5. Add Node before a given node\n");
        printf("\n6. Add Node after a given node\n");
        printf("\n7. Delete Node from the Beginning\n");
        printf("\n8. Delete Node from the End\n");
        printf("\n9. Delete any Node\n");
        printf("\n10.Delete Node after a given Node\n");
        printf("\n11.Delete the Entire List\n");
        printf("\n**PRESS 12 to EXIT**\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start = create_list(start);
            break;

            case 2 : start = display(start);
            break;

            case 3: start = insert_beg(start);
            break;

            case 4: start = insert_end(start);
            break;

            case 5: start = insert_bef(start);
            break;

            case 6: start = insert_after(start);
            break;

            case 7:start = del_beg(start);
            break;

            case 8:start  = del_end(start);
            break;

            case 9:start = del_node(start);
            break;

            case 10: start = del_after(start);
            break;

            case 11: start = del_list(start);
            break;

        }
    }while(option!=12);

    return 0;
    clrscr();
}
