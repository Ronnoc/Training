#include<stdio.h>   //Case #1: 120 = 12 * 10 = 6 * 20
void op();
int main()
{
    int x,i;
    scanf("%d",&x);
    for(i=1;i<=x;i++){printf("Case #%d: ",i);op();}
    return 0;}
void op()
{
     int x;
     scanf("%d",&x);
     int q,w,e,r;
     int i,m=0,flag=0;
     for(i=2;2*i<=x;i++)
     {
                        if(flag&&x%i==0){e=i;r=x/i;break;}
                        else if(x%i==0){q=i;w=x/i;flag=1;}
                        }
     printf("%d = %d * %d = %d * %d\n",x,q,w,e,r);
     }
