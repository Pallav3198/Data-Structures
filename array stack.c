#include<stdio.h>
#define MAX 10
int st[MAX],top=-1;
//push into the array
int push(int st[],int num)
{
    if(top==MAX-1)
    {
        printf("Overflow condition\n");
        return -1;
    }
    else
    {
        top++;
        st[top]= num;
        return 0;
    }
}
//pop from the array
int pop(int st[])
{
    if(top==-1)
    {
        printf("Underflow condition\n");
        return -1;
    }
    else
    {
        printf("POPed Value: %d",st[top]);
        top--;
        return 0;
    }
}
// peek into the array
int peek(int st[])
{
    if(top==-1)
    {
        printf("Underflow Condition\n");
        return -1;
    }
    else
    {
        printf("The Topmost value in the array-stack is: %d",st[top]);
        return 0;
    }
}
// display the array stack
int display(int st[])
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("| %d |",st[i]);
    }
    return 0;
}

int main()
{
    int option,num;
    do{
    printf("\nMAIN MENU\n");
    printf("\n1.PUSH\n");
    printf("\n2.POP\n");
    printf("\n3.PEEK\n");
    printf("\n4.DISPLAY\n");
    printf("\n5.EXIT\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("Enter -1 to end\n");
        while(num!=-1)
        {
        printf("Enter the value to be pushed\n");
        scanf("%d",&num);
        push(st,num);
        }
        display(st);
        break;
    case 2:
        pop(st);
        break;
    case 3:
        peek(st);
        break;
    case 4 :
        display(st);
        break;
    case 5:
        exit(0);
    }
    }while(option!=5);
}
