#include<stdio.h>
int f(int x,int y)
{
	if(x<y)return x;
	if(y==0)return x;
	int s=x/y;
	return s*y+f(x-s*y+s,y);
	}
int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)==2)
	{
		printf("%d\n",f(x,y));
		}
	return 0;}
