#include<stdio.h>

int main()
{
    int n;
    printf("How many task you want: ");
    scanf("%d",&n);
    int a[n];
    int b[n];
    int temp1=0;
    int temp=0;
    float avg;

    printf("Enter bust time: \n");

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=i;
    }
    for(int i=0;i<n-1;i++)
  {
    for (int j=0;j<n-i-1;j++)
    {
      if (a[j] > a[j+1])
     {
        int temp= a[j];
        a[j]= a[j+1];
        a[j+1] =temp;

        int temp1= b[j];
        b[j]= b[j+1];
        b[j+1] =temp1;
      }
    }
  }

  printf("GRAND CHART \n");

    avg=0;
    printf("%d " ,avg);


    for(int i=0;i<n;i++){

        temp1=temp1+a[i];
        printf("p%d ",b[i]+1);
        printf("%d ",temp1);
        avg=avg+temp1;

    }
    avg= avg-temp1;
    printf("\n");
    avg=avg/n;
    printf("Average time is: %.2f", avg);
return 0;
}
