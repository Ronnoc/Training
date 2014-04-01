#include<stdio.h>
int main()
{
    int n,k=0;
    while(scanf("%d",&n)==1 && n!=0)
    {
                            k++;
                            int a[60],i,sum=0;
                            for(i=1;i<=n;i++){scanf("%d",&a[i]);sum+=a[i];}                          
                            int avg=sum/n;
                            int kum=0;
                            for(i=1;i<=n;i++)
                            {
                                             if(a[i]<avg)kum+=avg-a[i];
                                             }
                            printf("Set #%d\nThe minimum number of moves is %d.\n\n",k,kum);
                            }
    return 0;
    }
