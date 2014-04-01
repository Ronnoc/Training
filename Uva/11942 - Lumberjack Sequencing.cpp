#include<stdio.h>
int main()
{
	int z,x;
	scanf("%d",&z);
	printf("Lumberjacks:\n");
	for(x=1;x<=z;x++)
	{
		int a[12];
		int i;
		for(i=1;i<=10;i++)scanf("%d",&a[i]);
		int flag=1;
		if(a[1]>a[2])
		{
			for(i=2;i<=9;i++)if(a[i]<a[i+1]){flag=0;break;} 
			}
		else if(a[1]<a[2])for(i=2;i<=9;i++)if(a[i]>a[i+1]){flag=0;break;} 
		if(flag)printf("Ordered\n");
		else printf("Unordered\n");
		}
	return 0; 
	}
