#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f(int a)
{
    if(a==-1)return 1;
    else return 0;
    }
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,count=1,first=1;
    while(scanf("%d%d",&a,&b)==2 && (a!=0 || b!=0))
    {
                                 if(first)first=0;
                                 else printf("\n\n"); 
                                 int i,j;char s[110][110];int h[110][110]={0};
                                 for(i=0;i<=a;i++)gets(s[i]);
                                 for(i=1;i<=a;i++)
                                 {
                                                  for(j=1;j<=b;j++)
                                                  {
                                                                   if(s[i][j-1]=='*')h[i][j]=-1;
                                                                   else h[i][j]=0;
                                                                   }
                                                  }
                                 for(i=1;i<=a;i++)
                                 {
                                                  for(j=1;j<=b;j++)
                                                  {
                                                                   if(h[i][j]!=-1)
                                                                   {
h[i][j]=f(h[i-1][j-1])+f(h[i-1][j])+f(h[i-1][j+1])+f(h[i][j-1])+f(h[i][j+1])+f(h[i+1][j-1])+f(h[i+1][j])+f(h[i+1][j+1]);
                                                                                  }
                                                                   }
                                                  }
                                 printf("Field #%d:\n",count++);
                                 for(i=1;i<=a;i++)  
                                 {
                                                    for(j=1;j<=b;j++)
                                                    {
                                                                     if(h[i][j]==-1)printf("*");
                                                                     else printf("%d",h[i][j]);
                                                                     }
                                                    if(i!=a)printf("\n");
                                                    }
                                 }
printf("\n");
    return 0;} 
