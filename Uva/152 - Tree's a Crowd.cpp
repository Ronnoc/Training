#include<stdio.h>
#include<math.h>
int p(int a)
{
	return a*a;
	} 
int main()
{
	int a[5100],b[5100],c[5100];
	int n,t[20],i;
	for(i=1;i<=10;i++)t[i]=0;
	n=1;
	while(scanf("%d%d%d",&a[n],&b[n],&c[n])!=EOF)
	{
		if(a[n]==0&&b[n]==0&&c[n]==0)break;
		n++;
		}
	int j;
	for(i=1;i<=n;i++)
	{
		int s=2147483640;
		for(j=1;j<=n;j++)
		{
			if(i==j)continue;
			int k=p(a[j]-a[i])+p(b[j]-b[i])+p(c[j]-c[i]);
			if(k<s)s=k;
			}
		for(j=1;j<=10;j++)
			{
				if(s>=p(j-1)&&s<p(j))t[j]++;
				}
		}
	for(i=1;i<=10;i++)printf("%4d",t[i]);printf("\n");
	return 0;
	} 
