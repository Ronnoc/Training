#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		int s;
		scanf("%d",&s);
		s*=63;s+=7492;s*=5;s-=498;
		if(s<0)s=-s;
		s=s%100;
		s-=s%10;
		s/=10;
		printf("%d\n",s);
		}
	return 0;
	}

