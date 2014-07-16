#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

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
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
//二分图最大匹配,hungary算法,邻接阵形式,复杂度O(m*m*n)
//返回最大匹配数,传入二分图大小m,n和邻接阵mat,非零元素表示有边
//match1,match2返回一个最大匹配,未匹配顶点match值为-1
#define MAXN 444
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)
int mat[1666][1666];
int hungary( int m,int n,int* match1,int* match2 ) {
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for ( _clr( match1 ),_clr( match2 ),i=0; i<m; ret+=( match1[i++]>=0 ) )
		for ( _clr( t ),s[p=q=0]=i; p<=q&&match1[i]<0; p++ )
			for ( k=s[p],j=0; j<n&&match1[i]<0; j++ )
				if ( mat[k][j]&&t[j]<0 ) {
					s[++q]=match2[j],t[j]=k;
					if ( s[q]<0 )
						for ( p=j; p>=0; j=p )
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}
char s[44][44];
int id[44][44];
int ma[1666],mb[1666];
int n,m;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d%d",&n,&m );
		for ( i=0; i<n; i++ )scanf( "%s",s[i] );
		int pi=0,qi=0;
		memset( id,0,sizeof id );
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( s[i][j]=='*' )
					if ( ( i+j )%2 )id[i][j]=++pi;
					else id[i][j]=++qi;
		for ( i=0; i<=pi; i++ )for ( j=0; j<=qi; j++ )mat[i][j]=0;
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( id[i][j]&&( i+j )%2 ) {
					for ( int k=0; k<4; k++ ) {
						int x=i+dx[k],y=j+dy[k];
						if ( x<0||x>=n )continue;
						if ( y<0||y>=m )continue;
						if ( !id[x][y] )continue;
						mat[id[i][j]-1][id[x][y]-1]=1;
					}
				}
		int ans=hungary( pi,qi,ma,mb );
		ans=pi+qi-ans;
		cout<<ans<<endl;
	}
	return 0;
}
