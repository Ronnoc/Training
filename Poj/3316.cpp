#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define PB push_back
#define MP make_pair
#define AA first
#define SZ size()
#define BB second
#define OP begin()
#define ED end()
char s[222][222];
int ff[222][222];
int cut[222][222];
int w,h;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
bool valid( int x,int y ) {
	if ( x<0||x>=h )return 0;
	if ( y<0||y>=w )return 0;
	return 1;
}
void FF( int x,int y,int id ) {
	if ( !valid( x,y ) )return;
	if(ff[x][y])return;
	cut[x][y]++;
	if ( s[x][y]!='1' )return;
	ff[x][y]=id;
	for ( int i=0; i<4; i++ )
		FF( x+dx[i],y+dy[i],id );
}
int got[44444];
int nb[222][222];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d%d",&h,&w ) ) {
		if(!h&&!w)break;
		for ( i=0; i<h; i++ )scanf( "%s",s[i] );
		memset( ff,0,sizeof ff );
		memset( cut,0,sizeof cut );
		memset( got,0,sizeof got );
		memset( nb,0,sizeof nb );
		int cnt=0;
		for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )if ( s[i][j]=='1'&&!ff[i][j] )
					FF( i,j,++cnt );
		for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )if ( ff[i][j] ) {
					for ( k=0; k<4; k++ )if ( valid( i+dx[k],j+dy[k] ) )
							if ( ff[i][j]==ff[i+dx[k]][j+dy[k]] )
								nb[i][j]++;
					if ( nb[i][j]>2 )got[ff[i][j]]=1;
				}
//		for(i=0;i<h;i++,printf("\n"))for(j=0;j<w;j++)printf("%d ",ff[i][j]);
//		for(i=0;i<h;i++,printf("\n"))for(j=0;j<w;j++)printf("%d ",cut[i][j]);
//		for(i=0;i<h;i++,printf("\n"))for(j=0;j<w;j++)printf("%d ",nb[i][j]);
		map<int,vector<pair<int,int> > >S;
		for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )if ( ff[i][j] )if ( !got[ff[i][j]] )
						if ( nb[i][j]<2 )S[ff[i][j]].PB( MP( i,j ) );
		map<int,vector<pair<int,int> > >::iterator it;
		int ans=0;
		for ( it=S.OP; it!=S.ED; ++it ) {
			vector<pair<int,int> >&L=( *it ).BB;
			if ( L.SZ>2 )continue;
			int flag=0;
			for ( i=0; i<L.SZ; i++ ) {
				int x=L[i].AA;
				int y=L[i].BB;
				for ( k=0; k<4; k++ ) {
					int xx=x+dx[k];
					int yy=y+dy[k];
					if ( !valid( xx,yy ) )continue;
					if ( ff[xx][yy] )continue;
					if ( cut[xx][yy]<2 )flag=1;
//					cout<<x<<","<<y<<" "<<xx<<","<<yy<<" "<<flag<<endl;
				}
			}
			if ( !flag )ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 3
011
101
111
*/
