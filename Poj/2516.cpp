#include <cstdio>
#include <cstring>
//求网络最小费用最大流,邻接阵形式
//返回最大流量,flow返回每条边的流量,netcost返回总费用
//传入网络节点数n,容量mat,单位费用cost,源点source,汇点sink

#define MAXN 110
#define inf int(2e9)
int min_cost_max_flow( int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost )
{
	int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
	if ( source==sink )
		return inf;
	for ( i=0; i<n; i++ )
		for ( j=0; j<n; flow[i][j++]=0 )
			;
	for ( netcost=0;; )
	{
		for ( i=0; i<n; i++ )
			pre[i]=0,min[i]=inf;
		//通过bellman_ford寻找最短路，即最小费用可改进路
		for ( pre[source]=source+1,min[source]=0,d[source]=inf,tag=1; tag; )
			for ( tag=t=0; t<n; t++ )
				if ( d[t] )
					for ( i=0; i<n; i++ )
						if ( j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i] )
							tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
						else
							if ( j=flow[i][t]&&min[t]<inf&&min[t]-cost[i][t]<min[i] )
								tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if ( !pre[sink] )
			break;
		for ( netcost+=min[sink]*d[i=sink]; i!=source; )
			if ( pre[i]>0 )
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for ( j=i=0; i<n; j+=flow[source][i++] )
		;
	return j;
}
int mat[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
int sk[MAXN][MAXN],n;
int sp[MAXN][MAXN],m;
int mt[MAXN][MAXN][MAXN],k;
int main()
{
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	while ( scanf( "%d%d%d",&n,&m,&k )!=EOF )
	{
		if ( !n&&!m&&!k )
			break;
		int i,j,p;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=k; j++ )
				scanf( "%d",&sk[i][j] );
		for ( i=1; i<=m; i++ )
			for ( j=1; j<=k; j++ )
				scanf( "%d",&sp[i][j] );
		for ( p=1; p<=k; p++ )
			for ( i=1; i<=n; i++ )
				for ( j=1; j<=m; j++ )
					scanf( "%d",&mt[p][i][j] );
		int flag=0,sumcost=0;
		for ( p=1; p<=k; p++ )
		{
			memset( mat,0,sizeof( mat ) );
			memset( cost,0,sizeof( cost ) );
			for ( i=1; i<=m; i++ )
				mat[0][i]=sp[i][p],cost[0][i]=0;
			for ( j=1; j<=n; j++ )
				mat[j+m][n+m+1]=sk[j][p],cost[j+m][n+m+1]=0;
			for ( i=1; i<=m; i++ )
				for ( j=1; j<=n; j++ )
				{
					mat[i][j+m]=inf;
					cost[i][j+m]=mt[p][j][i];
				}
			int netcost;
			min_cost_max_flow( n+m+2,mat,cost,0,n+m+1,flow,netcost );
			sumcost+=netcost;
			for(j=1;j<=n;j++)if(flow[j+m][n+m+1]!=sk[j][p])flag=1;
		}
		if(flag)printf("-1\n");
		else printf( "%d\n",sumcost );
	}
	return 0;
}
