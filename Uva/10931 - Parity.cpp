#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1 && n!=0)
	{
		int m=n;
		int  a[40];
		int i,weizhi=1;
		for(i=1;i<40;i++)a[i]=0;
		int sum=0;
		while(1)
		{
			if(m==0)break;
			if(m%2==0)a[weizhi++]=0;
			else {a[weizhi++]=1;m-=1;sum++;}
			m/=2;
			}
		weizhi--;
		printf("The parity of ");
		for(i=weizhi;i>=1;i--)printf("%d",a[i]);
		printf(" is %d (mod 2).\n",sum); 
		}
	return 0;
	} 
