#include<stdio.h>
void op();
int main()
{
    int s;
    scanf("%d",&s);
    int i;
    for(i=1;i<=s;i++)op();
    return 0;
    }
void op()
{
     int i,n,a,b,c;
     long long sum=0;
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
        scanf("%d%d%d",&a,&b,&c);
        sum+=a*c;
     }
     printf("%lld\n",sum);
}
