#include <cstdio>
#include <cstring>
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
char map[1010][1010];
int main()
{
	int m,n;
	while ( scanf( "%d%d",&n,&m )!=EOF )
	{
		int i,j;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=m; j++ )
				map[i][j]=0;
		int tot=0;
		int p=0,x=1,y=1;
		while ( tot<m*n )
		{
			map[x][y]='A'+tot%26;
			int xx=x+dx[p],yy=y+dy[p];
			if ( xx>n||xx<1||yy>m||yy<1||map[xx][yy] )
				p++;
			p%=4;
			x+=dx[p],y+=dy[p];
			tot++;
		}
		for ( i=1; i<=n; i++ )
		{
			for ( j=1; j<=m; j++ )
				printf( "   %c",map[i][j] );
			printf( "\n" );
		}
	}
	return 0;
}
