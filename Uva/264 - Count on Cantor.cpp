#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int xie;
		for(xie=1;;xie++){if(n<=xie*(xie+1)/2)break;}
		int x,y,i;
		if(xie%2==0){x=1,y=xie;}
			else{x=xie,y=1;}
		for(i=(xie*(xie-1)/2)+1;i<n;i++)
		{
			if(xie%2==0)
			{
				x++;y--;
				}
			else{x--;y++;}
			}
		printf("TERM %d IS %d/%d\n",n,x,y);
		}
	return 0;
	}
