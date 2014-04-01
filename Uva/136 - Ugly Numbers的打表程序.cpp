#include<stdio.h>
bool a[999999999]={0};
int main()
{
	freopen("out.txt","w",stdout);
    a[0]=a[1]=a[2]=a[5]=a[3]=1;
    int b[2000];int i,n,count=1;
    n=1500;
    for(i=1;;i++)
    {
                        if((i%2==0 && a[i/2]) || (i%3==0 && a[i/3]) || (i%5==0 && a[i/5]) || a[i]){a[i]=1;b[count++]=i;}
                        if(count==n+1)break;
                        }
    for(i=1;i<=n;i++)
    {
		printf("b[%d]=%d;\n",i,b[i]);
		}
    return 0;
    }
