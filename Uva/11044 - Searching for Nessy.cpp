#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		printf("%d\n",(p/3)*(q/3));
		}
	return 0;
	}
