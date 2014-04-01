#include<stdio.h>
int main()
{
	int a,b,k=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0 && b==0)break;
		printf("Case %d: ",++k);
		if(a<=b)printf("0\n");
		else if(a<=27*b)printf("%d\n",(a-1)/b); 
		else printf("impossible\n");
		}
	return 0;
	} 
