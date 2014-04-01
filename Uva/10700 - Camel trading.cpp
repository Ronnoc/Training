#include<stdio.h>
int main()
{
	int a[100];
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%d",&a[1]);
		char c[10000];
		int i=2,j=1;
		while(1)
		{
			c[i-1]=getchar();
			if(c[i-1]=='\n')break;
			scanf("%d",&a[i]);
			i++;
			}
		i--;
		int m;
		m=i;
		int b[30];
		for(i=1;i<=20;i++)b[i]=0;
		i=1;
		for(j=1;j<=m;j++)
		{
			b[i]+=a[j]; 
			if(c[j]=='*'){i++;}
			}
		int n;
		long long max,min=0;
		if(c[i]!=0)n=i;else n=i-1;
		max=1;
		for(i=1;i<=n;i++)max*=b[i];
		long long d[30];
		for(i=1;i<=20;i++)d[i]=1;
		i=1;
		for(j=1;j<=m;j++)
		{
			d[i]*=a[j];
			if(c[j]=='+'){min+=d[i];i++;}
			}
		min+=d[i];
		printf("The maximum and minimum are %lld and %lld.\n",max,min);
		}
	return 0;
	} 
