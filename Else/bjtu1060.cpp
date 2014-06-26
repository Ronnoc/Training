#include <stdio.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
const double eps=1e-8;
const double INF=1e20;
const int MXN = 50;
const LL MOD = 1000000007;
bool vis[101][101][101];
int dx[]= {0,0,0,0,1,-1};
int dy[]= {0,0,1,-1,0,0};
int dz[]= {1,-1,0,0,0,0};
int X,Y,Z;
bool inner( int x,int y,int z ) {
	if ( x<0||y<0||z<0 )return 0;
	if ( x>=X||y>=Y||z>=Z )return 0;
	return 1;
}
int qx[3000001];
int qy[3000001];
int qz[3000001];
int qd[3000001];
int qf,qb;
char s[55];
int input() {
	scanf( "%s",s );
	int x=0;
	for ( int i=0; s[i]; i++ )x=x*10+s[i]-'0';
	return x;
}
int main() {
	int i,j,k;
	while ( ~scanf( "%d%d%d",&X,&Y,&Z ) ) {
		qf=0,qb=0;
		int sx,sy,sz;
		scanf( "%d%d%d",&sx,&sy,&sz );
		int tx,ty,tz;
		scanf( "%d%d%d",&tx,&ty,&tz );
		qx[qb]=sx; qy[qb]=sy; qz[qb]=sz; qd[qb]=0;
		qb++;
		for ( i=0; i<X; i++ )for ( j=0; j<Y; j++ )for ( k=0; k<Z; k++ )
					vis[i][j][k]=0;
		int n;
		scanf( "%d",&n );
		while ( n-- ) {
			int p=input();
			int q=input();
			int r=input();
			vis[p][q][r]=1;
		}
		int ans=-1;
		while ( qf<qb ) {
			int x=qx[qf],y=qy[qf],z=qz[qf],d=qd[qf];
			qf++;
			if ( vis[x][y][z] )continue;
			vis[x][y][z]=1;
			if ( x==tx&&y==ty&&z==tz ) {ans=d; break;}
			for ( k=0; k<6; k++ ) {
				int xx=x+dx[k],yy=y+dy[k],zz=z+dz[k];
				if ( inner( xx,yy,zz )&&!vis[xx][yy][zz] ) {
					qx[qb]=xx; qy[qb]=yy; qz[qb]=zz; qd[qb]=d+1;
					qb++;
				}
			}
		}
		printf( "%d\n",ans );
	}
	return 0;
}
