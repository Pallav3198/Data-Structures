#include<stdio.h>
#define max 10
int arr[max];

int second_largest(int arr[])
{
    int i,lrg,slrg;
    lrg = arr[0];
    for(i=1;i<max;i++)
    {
        if(arr[i]>lrg)
        {
            lrg = arr[i];
        }
    }
    slrg = arr[1];
    for(i=0;i<max;i++)
    {
        if(arr[i]!=lrg)
        {
            if(arr[i]>slrg)
            {
                slrg = arr[i];
            }
        }
    }
    printf("Second Largest value is: | %d |\n",slrg);

}
int main()
{
    int i;
    printf("Enter the elements of the array\n");
    for(i=0;i<max;i++)
    {
        scanf("%d",&arr[i]);
    }
    second_largest(arr);
    return 0;
}
