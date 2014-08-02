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
int a[33][33];
int ans;
int L[4][33][33];
int sum[33][33];
int vis[33][33];
void add( int k,int f,int n,int m ) {
	for ( int i=0; i<n; i++ )for ( int j=0; j<m; j++ ) {
			if ( f==0 )sum[i][j]+=L[k][i][j],vis[i][j]=1;
			if ( f==1 )sum[j][n-1-i]+=L[k][i][j],vis[j][n-1-i]=1;
			if ( f==2 )sum[n-1-i][m-1-j]+=L[k][i][j],vis[n-1-i][m-1-j]=1;
			if ( f==3 )sum[m-1-j][i]+=L[k][i][j],vis[m-1-j][i]=1;
		}
}
void gao( int n,int m ) {
	int q[5],i,j,k;
//	cout<<n<<"~"<<m<<endl;
//	for ( k=0; k<4; k++ ) {
//		for ( i=0; i<n; i++,printf( "~~" ) )for ( j=0; j<m; j++ )printf( " %d",L[k][i][j] );
//		printf( "\n" );
//	}
	for ( q[0]=0; q[0]<4; q[0]++ )
		for ( q[1]=0; q[1]<4; q[1]++ )
			for ( q[2]=0; q[2]<4; q[2]++ )
				for ( q[3]=0; q[3]<4; q[3]++ ) {
					memset( sum,0,sizeof sum );
					memset( vis,0,sizeof vis );
					for ( i=0; i<4; i++ )add( i,q[i],n,m );
					int tn=0,tm=0;
					while ( vis[tn][0] )tn++;
					while ( vis[0][tm] )tm++;
					if ( tn*tm!=n*m )continue;
					int now=sum[0][0];
					for ( i=0; i<tn; i++ )for ( j=0; j<tm; j++ )
							cmin( now,sum[i][j] );
					cmax( ans,now );
				}
}
void solve( int n,int m ) {
	int i,j,tn,tm;
//	cout<<n<<"!"<<m<<endl;
	if ( n%2==0&&m%2==0 ) {
		tn=n/2,tm=m/2;
		for ( i=0; i<tn; i++ )for ( j=0; j<tm; j++ )L[0][i][j]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=tm; j<m; j++ )L[1][i][j-tm]=a[i][j];
		for ( i=tn; i<n; i++ )for ( j=0; j<tm; j++ )L[2][i-tn][j]=a[i][j];
		for ( i=tn; i<n; i++ )for ( j=tm; j<m; j++ )L[3][i-tn][j-tm]=a[i][j];
//		cout<<1<<endl;
		gao( tn,tm );
	}
	if ( n%4==0 ) {
		tn=n/4,tm=m;
		for ( i=0*tn; i<1*tn; i++ )for ( j=0; j<m; j++ )L[0][i-0*tn][j]=a[i][j];
		for ( i=1*tn; i<2*tn; i++ )for ( j=0; j<m; j++ )L[1][i-1*tn][j]=a[i][j];
		for ( i=2*tn; i<3*tn; i++ )for ( j=0; j<m; j++ )L[2][i-2*tn][j]=a[i][j];
		for ( i=3*tn; i<4*tn; i++ )for ( j=0; j<m; j++ )L[3][i-3*tn][j]=a[i][j];
//		cout<<2<<endl;
		gao( tn,tm );
	}
	if ( n==2*m ) {
		tn=n/4,tm=m;
		for ( i=0; i<tn; i++ )for ( j=0; j<tm; j++ )L[0][i][j]=a[i][j];
		for ( i=tn; i<tn*2; i++ )for ( j=0; j<tm; j++ )L[1][i-tn][j]=a[i][j];
		for ( i=tn*2; i<tn*2+tm; i++ )for ( j=0; j<tn; j++ )L[2][j][i-tn*2]=a[i][j];
		for ( i=tn*2; i<tn*2+tm; i++ )for ( j=tn; j<tn*2; j++ )L[3][j-tn][i-tn*2]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[2][i][j],L[2][i][tm-1-j] );
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[3][i][j],L[3][i][tm-1-j] );
//		cout<<31<<endl;
		gao( tn,tm );
		
		for ( i=0; i<tn; i++ )for ( j=0; j<tm; j++ )L[0][i][j]=a[i][j];
		for ( i=tn; i<tn+tm; i++ )for ( j=0; j<tm; j++ )L[1][j][i-tn]=a[i][j];
		for ( i=tn; i<tn+tm; i++ )for ( j=tn; j<tn*2; j++ )L[2][j-tn][i-tn]=a[i][j];
		for ( i=tn+tm; i<tn*2+tm; i++ )for ( j=0; j<tm; j++ )L[3][i-tn-tm][j]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[0][i][j],L[0][i][tm-1-j] );
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[3][i][j],L[3][i][tm-1-j] );
//		cout<<32<<endl;
		gao( tn,tm );
		
		for ( i=0; i<tm; i++ )for ( j=0; j<tn; j++ )L[0][j][i]=a[i][j];
		for ( i=0; i<tm; i++ )for ( j=tn; j<tn*2; j++ )L[1][j-tn][i]=a[i][j];
		for ( i=tm; i<tn+tm; i++ )for ( j=0; j<tm; j++ )L[2][i-tm][j]=a[i][j];
		for ( i=tm+tn; i<tn*2+tm; i++ )for ( j=0; j<tm; j++ )L[3][i-tn-tm][j]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[0][i][j],L[0][i][tm-1-j] );
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[1][i][j],L[1][i][tm-1-j] );
//		cout<<33<<endl;
		gao( tn,tm );
	}
	if ( n*3==m*4 ) {
		tn=m/3,tm=m;
		for ( i=0; i<tm; i++ )for ( j=tn*0; j<tn*1; j++ )L[0][j-tn*0][i]=a[i][j];
		for ( i=0; i<tm; i++ )for ( j=tn*1; j<tn*2; j++ )L[1][j-tn*1][i]=a[i][j];
		for ( i=0; i<tm; i++ )for ( j=tn*2; j<tn*3; j++ )L[2][j-tn*2][i]=a[i][j];
		for ( i=m; i<n; i++ )for ( j=0; j<m; j++ )L[3][i-m][j]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[3][i][j],L[3][i][tm-1-j] );
//		cout<<41<<endl;
		gao( tn,tm );
		
		for ( i=tn; i<n; i++ )for ( j=tn*0; j<tn*1; j++ )L[0][j-tn*0][i-tn]=a[i][j];
		for ( i=tn; i<n; i++ )for ( j=tn*1; j<tn*2; j++ )L[1][j-tn*1][i-tn]=a[i][j];
		for ( i=tn; i<n; i++ )for ( j=tn*2; j<tn*3; j++ )L[2][j-tn*2][i-tn]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=0; j<m; j++ )L[3][i][j]=a[i][j];
		for ( i=0; i<tn; i++ )for ( j=0; j*2<tm; j++ )swap( L[3][i][j],L[3][i][tm-1-j] );
//		cout<<42<<endl;
		gao( tn,tm );
	}
}
int main() {
//	freopen("1004.in","r",stdin);
//	freopen("m1004.out","w",stdout);
	int i,j,k;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )scanf( "%d",&a[i][j] );
		ans=0;
		solve( n,m );
		int t=max( m,n );
		for ( i=0; i<t; i++ )for ( j=i; j<t; j++ )
				swap( a[i][j],a[j][i] );
		solve( m,n );
		printf( "%d\n",ans );
	}
	return 0;
}
/*
8 4
9  7  4 3
9  1  5 1
8  4  8 9
4  2  5 4
5  4  5 5
1  2  6 10
5  4  5 9
10 10 8 1
18
*/
