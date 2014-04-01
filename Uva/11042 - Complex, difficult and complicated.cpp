#include<stdio.h>
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		int a,b;
		int out;
		scanf("%d%d",&a,&b);
		if(b==0)out=1;
		else if(a==0)out=2;
		else if(a==b || a==-b)out=4;
		else out=0;
		if(out)printf("%d\n",out);
		else printf("TOO COMPLICATED\n");
		}
	return 0;
	}
 
