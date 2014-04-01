#include<stdio.h>
#include<string.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		printf("Case #%d:\n",x);
		char a[12][110];
		int aa[12];
		int i;
		for(i=1;i<=10;i++)scanf("%s%d",a[i],&aa[i]);
		int max=aa[1];
		for(i=1;i<=10;i++)max=max>aa[i]?max:aa[i];
		for(i=1;i<=10;i++)if(aa[i]==max)printf("%s\n",a[i]); 
		}
	return 0;
	} 
