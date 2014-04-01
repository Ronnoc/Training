#include<stdio.h>
int t(int x,int y)
{
	if(x<y)return x;
	return y+t(x-y+1,y);
	}
int main()
{
	int z,x,e,f,c;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		scanf("%d%d%d",&e,&f,&c);
		printf("%d\n",t(e+f,c)-e-f);
		}
	return 0;
	}
