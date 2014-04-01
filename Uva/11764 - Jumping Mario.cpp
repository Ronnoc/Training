#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int time,i,s[10010];
		scanf("%d",&time);
		for(i=1;i<=time;i++)
		{
			scanf("%d",&s[i]);
			}
		int high=0,low=0;
		for(i=1;i<time;i++)
		{
			if(s[i]<s[i+1])high++; 
			if(s[i]>s[i+1])low++; 
			}
		printf("Case %d: %d %d\n",x,high,low);
		}
	return 0;
	}
