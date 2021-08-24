#include<stdio.h>

int main(){

    int n;
    printf("How many task you want: ");
    scanf("%d",&n);
    int a[n];
    int temp=0;
    float avg=0;

    printf("Enter %d burst time....\n ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("\nGrant chart: ");
    printf("%d ",temp);
    for(int i=0;i<n;i++){

        temp=temp+a[i];
        printf("p%d ",i+1);
        printf("%d ",temp);
        avg+=temp;
    }
    avg-=temp;
    printf("\n");
    printf("Average time is: %.2f", (avg/n));

return 0;
}
