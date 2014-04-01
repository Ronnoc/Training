#include<stdio.h>
int main()
{
	int z;
	while(scanf("%d",&z)==1 && z!=0)
	{
		int i,j;int a[20];char temp;
		for(i=1;i<=z;i++)a[i]=0;
		for(i=1;i<=z;i++)
		{
			for(j=1;j<=26;j++)
			{
				temp=getchar();
				if(temp==' ')a[i]++;
				}
			}
		//for(i=1;i<=z;i++)printf("%d\n",a[i]);
		int b[20];
		for(i=1;i<=z;i++)b[i]=a[i]-a[1];
		int min=0;
		for(i=1;i<=z;i++)if(b[i]<min)min=b[i];
		int sum=-z*min;
		for(i=1;i<=z;i++)sum+=b[i];
		printf("%d\n",sum);
		}
	return 0;
	} 
