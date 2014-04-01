#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int max,a,time,i,s[10010];
		scanf("%d",&time);
		for(i=1;i<=time;i++)scanf("%d",&s[i]);
		max=s[1];
		for(i=1;i<=time;i++)max=max>s[i]?max:s[i];
		printf("Case %d: %d\n",x,max);
		}
	return 0;
	}
