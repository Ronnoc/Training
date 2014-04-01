#include<stdio.h>
int abs(int x)
{
    if(x>0)return x;
    else return -x;
    }
bool check(int *b,int n)
{
     int i,j,flag=1,am=n,s,fa=0;
     int a[3100];
     for(i=1;i<=n;i++)a[i]=i;
     for(i=1;i<=n;i++)
     {
                      for(j=1;j<=am;j++)
                      {
                                       if(a[j]==b[i])
                                       {
                                                     for(s=j;s<am;s++)
                                                     {
                                                                       a[s]=a[s+1];
                                                                       }
                                                     am--;fa=1;
                                                     }
                                       }
                      if(fa!=1)return false;
                      fa=0;
                      }
     return true;
     }
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
                            int i,a[3100];
                            for(i=1;i<=n;i++)scanf("%d",&a[i]);
                            int b[3100];
                            for(i=1;i<=n-1;i++)
                            {
                                               b[i]=abs(a[i]-a[i+1]);
                                               }
                            if(check(b,n-1))printf("Jolly\n");
                            else printf("Not jolly\n");
                            }
    return 0;
    }
