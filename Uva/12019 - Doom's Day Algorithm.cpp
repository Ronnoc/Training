#include<stdio.h>
void pt(int x)
{
	if(x==1)printf("Monday\n");
	if(x==2)printf("Tuesday\n");
	if(x==3)printf("Wednesday\n");
	if(x==4)printf("Thursday\n");
	if(x==5)printf("Friday\n");
	if(x==6)printf("Saturday\n");
	if(x==7)printf("Sunday\n");
	}
int main()
{
	int a[366],i,j,x,z,t=1;
	a[1]=6;
	for(i=2;i<=365;i++){a[i]=a[i-1]+1;if(a[i]>7)a[i]-=7;}
	int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&z);
	int dp[13][32];
	for(i=1;i<=12;i++)
	{
		for(j=1;j<=b[i];j++)dp[i][j]=a[t++];
		}
	for(x=1;x<=z;x++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		pt(dp[p][q]);
		}
	}
