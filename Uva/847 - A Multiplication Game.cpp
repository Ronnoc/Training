#include<stdio.h>
int main()
{
	unsigned long long a[100];
	int i;
	a[1]=1;
	for(i=2;i<=30;i++)
	{
		if(i%2==1)a[i]=a[i-1]*2;
		else a[i]=a[i-1]*9;
		}
//	for(i=1;i<=30;i++)printf("%d:%I64u\n",i,a[i]);
	unsigned long long n;
	while(scanf("%llu",&n)!=EOF)
	{
		int flag;
		for(i=1;i<=29;i++)
		{
			if(a[i]<n&&a[i+1]>=n&&i%2==1)flag=1;
			if(a[i]<n&&a[i+1]>=n&&i%2==0)flag=2;
			}
		if(flag==1)printf("Stan wins.\n");
		else if(flag==2)printf("Ollie wins.\n");
		}
	return 0;
	}
