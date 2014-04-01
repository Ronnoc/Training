#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		if(p>q)printf(">\n");
		if(p==q)printf("=\n");
		if(p<q)printf("<\n");
		}
	return 0;
	}
