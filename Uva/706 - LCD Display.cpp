#include<stdio.h>
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)==2 && (m!=0 || n!=0))
	{
		int a[20]={0},temp=m;
		int i;
		for(i=1;i<=10;i++)
		{
			a[i]=temp%10;
			temp/=10;
			}
		int len=1,j,k;
		for(i=1;i<=10;i++)
		{
			if(a[i]!=0 && a[i+1]==0)len=i;
			}
			
		int flag=1;										//第一部分 1
		for(i=len;i>=1;i--)
		{
			if(flag)flag=0;
			else printf(" ");
			if(a[i]==1 || a[i]==4)
			{
				printf(" ");
				for(j=1;j<=n;j++)printf(" ");
				printf(" ");
				}
			else 
			{
				printf(" ");
				for(j=1;j<=n;j++)printf("-");
				printf(" ");
				}
			}
			printf("\n"); 
			
		for(k=1;k<=n;k++)												//第二部分 2~1+n 
		{
			flag=1;
			for(i=len;i>=1;i--)
			{
				if(flag)flag=0;
				else printf(" ");
				if(a[i]==1 || a[i]==2|| a[i]==3|| a[i]==7)
				{
					printf(" ");
					for(j=1;j<=n;j++)printf(" ");
					printf("|");
					}
				else if(a[i]==5|| a[i]==6)
				{
					printf("|");
					for(j=1;j<=n;j++)printf(" ");
					printf(" ");
					}
				else 
				{
					printf("|");
					for(j=1;j<=n;j++)printf(" ");
					printf("|");
					}
				}
			printf("\n");
			}
			
		flag=1;										//第三部分 2+n 
		for(i=len;i>=1;i--)
		{
			if(flag)flag=0;
			else printf(" ");
			if(a[i]==1 || a[i]==7 || a[i]==0)
			{
				printf(" ");
				for(j=1;j<=n;j++)printf(" ");
				printf(" ");
				}
			else 
			{
				printf(" ");
				for(j=1;j<=n;j++)printf("-");
				printf(" ");
				}
			}
			printf("\n"); 
		
				for(k=1;k<=n;k++)												//第四部分 3+n~2+2n 
		{
			flag=1;
			for(i=len;i>=1;i--)
			{
				if(flag)flag=0;
				else printf(" ");
				if(a[i]==1 || a[i]==3|| a[i]==4|| a[i]==7|| a[i]==5|| a[i]==9)
				{
					printf(" ");
					for(j=1;j<=n;j++)printf(" ");
					printf("|");
					}
				else if(a[i]==2)
				{
					printf("|");
					for(j=1;j<=n;j++)printf(" ");
					printf(" ");
					}
				else 
				{
					printf("|");
					for(j=1;j<=n;j++)printf(" ");
					printf("|");
					}
				}
			printf("\n");
			}
		
				flag=1;										//第五部分 3+2n 
		for(i=len;i>=1;i--)
		{
			if(flag)flag=0;
			else printf(" ");
			if(a[i]==1 || a[i]==4 || a[i]==7)
			{
				printf(" ");
				for(j=1;j<=n;j++)printf(" ");
				printf(" ");
				}
			else 
			{
				printf(" ");
				for(j=1;j<=n;j++)printf("-");
				printf(" ");
				}
			}
		printf("\n");
		printf("\n");
		}
	return 0;
	} 
