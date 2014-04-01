#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		int i;
		for(i=1;i*i<n;i++);
		int xie=i;
		//printf("%d\n",xie);
		int x,y,change;
		if(xie%2==0){x=1,y=xie,change=1;}
		else {x=xie,y=1;change=-1;}
		for(i=(xie-1)*(xie-1)+1;i<n;i++)
		{
			if(change==-1)
			{
				if(y<xie)y++;else x--;
				}
			else
			{
				if(x<xie)x++;else y--;
				}
			}
		printf("%d %d\n",x,y);
		}
return 0;
} 
