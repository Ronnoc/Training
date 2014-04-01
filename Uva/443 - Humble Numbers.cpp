#include<stdio.h>
int m(int a,int b){if(a<b)return a;return b;}
int min(int q,int w,int e,int r)
{
	int max=q;
	max=m(max,w);
	max=m(max,e);
	max=m(max,r);
	return max;
	}
int main()
{
	long long x[6000];
	int i;
	int y2,y3,y5,y7;
	y2=y3=y5=y7=1;
	x[1]=1;
	for(i=2;i<=5842;i++)
	{
		x[i]=min(2*x[y2],3*x[y3],5*x[y5],7*x[y7]);
		if(x[i]==2*x[y2])y2++;
		if(x[i]==3*x[y3])y3++;
		if(x[i]==5*x[y5])y5++;
		if(x[i]==7*x[y7])y7++;
		}
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		printf("The %d",n);
		if(n%100>=11&&n%100<=19)printf("th");
		else if(n%10==1)printf("st");
		else if(n%10==2)printf("nd");
		else if(n%10==3)printf("rd");
		else printf("th");
		printf(" humble number is %lld.\n",x[n]);
		}
	return 0;
	}
