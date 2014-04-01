#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int a[300];
		int i,j;
		for(i=0;i<n;i++)a[i]=-1;
		int dp[300][300];
		for(i=0;i<n;i++)for(j=0;j<n;j++)dp[i][j]=0;
		int k,z,flag=1;
		scanf("%d",&z);
		for(k=1;k<=z;k++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			dp[u][v]=1;
			dp[v][u]=1;
			}
		int sum[300],psum=0,um=-1;
		for(i=0;i<n;i++)
		{
			sum[i]=0;
			for(j=0;j<n;j++)sum[i]+=dp[i][j];
			if(sum[i]>um&&sum[i]>0){um=sum[i];psum=i;}
			}
		char had[300];
		for(i=0;i<n;i++)had[i]=0;
		int left[300],nl=0,right[300],nr=0;
		nl++;left[1]=psum;had[psum]='l';
		for(int pq=1;pq<=n;pq++)
		{
			for(i=1;i<=nl;i++)
			{
				for(j=0;j<n;j++)
				{
					if(dp[left[i]][j]&&!had[j]){right[++nr]=j;had[j]='r';}
					if(dp[left[i]][j]&&had[j])
					{
						if(had[j]+had[left[i]]!='r'+'l')flag=0;
						}
					}
				}
			for(i=1;i<=nr;i++)
			{
				for(j=0;j<n;j++)
				{
					if(dp[right[i]][j]&&!had[j]){left[++nl]=j;had[j]='l';}
					if(dp[right[i]][j]&&had[j])
					{
						if(had[j]+had[right[i]]!='r'+'l')flag=0;
						}
					}
				}
			}
		if(flag)printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
		}
	return 0;
	}
