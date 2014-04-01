#include<stdio.h>
#include<string.h>
char s[1000010];
int re[1000010];
int main()
{
	int c=1;
	while(gets(s))
	{
		int n,i,len=strlen(s);
		if(len==0)break;
		printf("Case %d:\n",c);
		scanf("%d",&n);
		c++;
		for(i=0;i<len-1;i++)
		{
			if(s[i]==s[i+1])re[i]=1;
			else re[i]=0;
			}
		int j;
		for(i=1;i<=n;i++)
		{
			int a,b,t;
			scanf("%d%d",&a,&b);
			if(a>b){t=a;a=b;b=t;}
			int flag=1;
			for(j=a;j<b;j++)
			{
				if(re[j]==0){flag=0;break;}
				}
			if(flag)printf("Yes\n");
			else printf("No\n");
			getchar();
			}	
		}
	return 0;
	}
