#include<stdio.h>
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++) 
	{
		bool date[4000];
		int d,p;
		scanf("%d%d",&d,&p);
	//	printf("%d %d\n",d,p);
		int i,j;
		for(i=0;i<4000;i++)date[i]=0;
		int a[110];
		for(i=1;i<=p;i++)scanf("%d",&a[i]);
		for(i=1;i<=p;i++)
		{
			for(j=1;j*a[i]<=4000;j++)date[j*a[i]]=1;
			}
		for(i=1;i<=d;i++)if(i%7==6||i%7==0)date[i]=0;
	//	printf("\n");
	//	for(i=1;i<=d;i++){printf("%d ",date[i]);if(i%7==0)printf("\n");}
		int sum=0;
		for(i=1;i<=d;i++)sum+=date[i];
		printf("%d\n",sum);
		}
//	return main();
	return 0;
	}
