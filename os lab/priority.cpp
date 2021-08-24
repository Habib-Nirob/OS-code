#include<stdio.h>
#include<string.h>


int main()
{
    int n;
    printf("How many task you want: ");
    scanf("%d",&n);
    int a[n],pr[n];
    char p[n][5];
    int temp;
    int pos,i,j;
    char dem[5];
    for(i=0;i<n;i++)
    {
        printf("Enter process : ");
        scanf("%s",&p[i]);
        printf("Enter Burst Time:");
        scanf("%d",&a[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);

    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;

        strcpy(dem,p[i]);
        strcpy(p[i],p[pos]);
        strcpy(p[pos],dem);
    }
    int av=0;
    temp=0;
    int arr[n];
    printf("\nGrant chart: ");
    printf("%d ",temp);
    for(i=0;i<n;i++){

        temp=temp+a[i];
        printf("P%s ",p[i]);
        printf("%d ",temp);
        arr[i]= temp;
        av= av+temp;

    }
    float avg=0;
    for(i=0;i<n-1;i++){
        avg+=arr[i];
    }
    printf("\n");


    printf("Average time is: %.2f", (avg/n));

    return 0;

}
