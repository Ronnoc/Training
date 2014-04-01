#include<stdio.h>
#include<stdlib.h>  //bgc
/*
long long max(long long a,long long b)
{
     if(a>b)return b;
     else return a;
     }
*/
void p(int x)
{
     if(x==1)printf("B");
     if(x==2)printf("C");
     if(x==3)printf("G");
     }
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long a[4][4];
    while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a[1][1],&a[1][3],&a[1][2],&a[2][1],&a[2][3],&a[2][2],&a[3][1],&a[3][3],&a[3][2])==9) 
    {
         int i,j,l;
         long long sum=0,ret=0;
         int z=1,x=2,c=3;
         for(i=1;i<=3;i++)
         {
                          for(j=1;j<=3;j++)
                          {
                                       if(j==i)continue;
                                       l=6-i-j;        
                                       sum=a[1][i]+a[2][j]+a[3][l];
                                       if(i==1&&j==2&&l==3)ret=sum;
                                       if(ret<sum){ret=sum;z=i;x=j;c=l;}
                                       }
                          }
         sum=a[1][1]+a[1][2]+a[1][3]+a[2][1]+a[2][2]+a[2][3]+a[3][1]+a[3][2]+a[3][3];
         sum-=a[1][z]+a[2][x]+a[3][c];
         p(z);p(x);p(c);
         printf(" %lld\n",sum);
         }
    return 0;
    }
