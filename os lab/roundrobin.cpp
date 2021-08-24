#include<bits/stdc++.h>


int main()
{
    int n,q,c;
    printf("How many task you want: ");
    scanf("%d",&n);
    int a[n],w[n]={0},cl[n]={0};
    int temp=0,sum=0,p_temp=0,pt;
    float avg;

    printf("Enter %d brust time.... \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("Enter Quantum time: ");
    scanf("%d",&q);
    printf("\nGrant chart: %d ",temp);

    while(temp!=sum){
        for(int j=0;j<n;j++)
        {
            if(a[j]<=0)
                continue;

            else if(a[j]>0 && a[j]<q)
            {
                pt=temp;
                temp=temp+a[j];
                a[j]=a[j]-q;
                printf("p%d ",j+1);
                printf("%d ",temp);

                if(p_temp==0){
                    p_temp++;
                    cl[j]=temp;
                    continue;
                }
                else{
                    c = temp-cl[j];
                    if(c<=q)
                        continue;
                    else{
                        c=pt-cl[j];
                        w[j]+=c;
                        cl[j]=temp;
                    }

                }

            }

            else
            {
                pt=temp;
                temp=temp+q;
                a[j]=a[j]-q;
                printf("p%d ",j+1);
                printf("%d ",temp);

                if(p_temp==0){
                    p_temp++;
                    cl[j]=temp;
                    continue;
                }
                else{
                    c = temp-cl[j];
                    if(c<=q){
                        cl[j]=temp;
                        continue;
                    }
                    else{
                        c=pt-cl[j];
                        w[j]+=c;
                        cl[j]=temp;
                    }
                }

            }

        }
    }
    sum=0;
    for(int i=0;i<n;i++)
        sum+=w[i];
    avg= (float) sum/n;
    printf("\n\nAverage waiting time: %.2f\n",avg);
return 0;
}
