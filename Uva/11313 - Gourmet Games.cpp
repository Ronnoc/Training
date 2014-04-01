#include<stdio.h>		//n个人参加，每场比赛上m个人出冠军进入下一轮
int main()
{
	int n,m;
	int z,k;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%d%d",&n,&m);
		int res=1;
		while(n>m){res++;n-=m-1;} 
		if(n==m)printf("%d\n",res); 
		else printf("cannot do this\n");
		} 
	return 0;
	} 
