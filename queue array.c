#include<stdio.h>
#define max 10
int q[max],front = 0,rear = 0;
int insert(int q[],int num)
{
    if(rear==max)
        printf("\nQueue is full\n");
    else
    {
        q[rear] = num;
        rear++;
    }
}
int delet(int q[])
{
    int del_val,i;
    if(front==rear)
        printf("\nQueue is empty\n");
    else
    {
        del_val = q[front];
        for(i=0;i<rear;i++)
        {
            q[i] = q[i+1];
        }
    }
}
int display(int q[])
{
    int i;
    for(i=0;i<rear;i++)
        printf("| %d |",q[i]);
}
int main()
{
    int option,val;
    do
    {
        printf("\nMAIN MENU\n");
        printf("\n1.Insert\n");
        printf("\n2.Delete\n");
        printf("\n3.Display\n");
        printf("\n4.EXIT\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter element in the array\n");
            scanf("%d",&val);
            insert(q,val);
            display(q);
            break;

        case 2:
            printf("Element deleted\n");
            delet(q);
            display(q);
            break;

        case 3:
            printf("Displaying the elements:\n");
            display(q);
            break;

        default:
            exit(0);
        }
    }while(option!=4);
    return 0;
}
