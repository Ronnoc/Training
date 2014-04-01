#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
bool a[1000100];
int f(int i)
{
	int sum=0,temp=i;
	while(temp>0)
	{
		sum+=temp%10;
		temp/=10;
		}
	return sum+i;
	}
int main()
{
	int i;
	memset(a,1,sizeof(a));
	for(i=1;i<=1000000;i++)
	{
		a[f(i)]=0;
		}
	//printf("%.2f",(double)clock()/(CLOCKS_PER_SEC));
	//system("pause");
	for(i=1;i<=1000000;i++)
	{
		if(a[i])printf("%d\n",i);
		}
	return 0;
	} 
