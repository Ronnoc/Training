#include<stdio.h>
int pow(int s)
{
	int i,res=1;
	for(i=1;i<=s;i++)res*=10;
	return res;
	}
bool check(int a)
{
	int s=a*a;
	int x,y,i;
	x=s;y=0;
	for(i=0;i<=9;i++)
	{
		if(x&&y&&x+y==a)return 1;
//		printf("%d %d %d\n",x,y,a);
		y+=(x%10)*pow(i);
		x/=10;
		}
	return 0;
	}
int main()
{
	int k,z;
//	printf("%d\n",check(45));
//	printf("%d\n",check(55));
//	printf("%d\n",pow(2));
	scanf("%d",&z);
	bool b[40010];
	int i;
	for(i=2;i<=40000;i++)b[i]=check(i);
	for(k=1;k<=z;k++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		printf("case #%d\n",k);
		int flag=1,f=1;
		int first=1;
		for(i=p;i<=q;i++)
		{
			if(b[i])
			{
			//	if(first)first=0;else printf(" ");
				printf("%d\n",i);
				flag=0;
				}
			}
		if(flag)printf("no kaprekar numbers\n");
		if(k!=z)printf("\n");
		}
	return 0;
	} 
