#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define NN 210
#define MAXN NN
#define inf int(1e9)
int mat[NN][NN];
int cost[NN][NN];
int flow[NN][NN];
int pre[NN],mn[NN],d[NN];
int mcmf( int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost )
{
	memset(d,0,sizeof(d));
	int i,j,t,tag;
	if (source==sink) return inf;
	for (i=0;i<n;i++)
		for (j=0;j<n;flow[i][j++]=0);
	for (netcost=0;;){
		for (i=0;i<n;i++)
			pre[i]=0,mn[i]=inf;
		//通过bellman_ford寻找最短路，即最小费用可改进路
		for (pre[source]=source+1,mn[source]=0,d[source]=inf,tag=1;tag;)
			for (tag=t=0;t<n;t++)
				if (d[t])
					for (i=0;i<n;i++)
						if (j=mat[t][i]-flow[t][i]&&mn[t]+cost[t][i]<mn[i])
							tag=1,mn[i]=mn[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
						else if (j=flow[i][t]&&mn[t]<inf&&mn[t]-cost[i][t]<mn[i])
							tag=1,mn[i]=mn[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if (!pre[sink])	break;
		for (netcost+=mn[sink]*d[i=sink];i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}
vector<pair<int,int> >H,M;
int main()
{
	int n,m;
	while ( scanf( "%d%d",&n,&m )!=EOF )
	{
		if ( !n&&!m )
			break;
		H.clear(),M.clear();
		memset(mat,0,sizeof(mat));
		memset(cost,0,sizeof(cost));
		char s[110];
		int i,j;
		for ( i=0; i<n; i++ )
		{
			scanf( "%s",s );
			for ( j=0; j<m; j++ )
				if ( s[j]=='H' )
					H.push_back( make_pair( i,j ) );
				else
					if ( s[j]=='m' )
						M.push_back( make_pair( i,j) );
		}
		n=H.size();
//		for(i=0;i<n;i++)printf("(%d,%d) ",H[i].first,H[i].second);printf("\n");
//		for(i=0;i<n;i++)printf("(%d,%d) ",M[i].first,M[i].second);printf("\n");
		for(i=1;i<=n;i++)mat[0][i]=1,cost[0][i]=0;
		for(i=1;i<=n;i++)mat[i+n][n*2+1]=1,cost[i+n][n*2+1]=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			int p=i-1,q=j-1;
			mat[i][j+n]=1;
			cost[i][j+n]=fabs(H[p].first-M[q].first)+fabs(H[p].second-M[q].second);
		}
		int ans;
		mcmf( 2*n+2,mat,cost,0,2*n+1,flow,ans );
		printf( "%d\n",ans );
	}
	return 0;
}
