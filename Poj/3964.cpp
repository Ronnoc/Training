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
LL gao( LL n,LL p ) {
	if ( n<p )return 0;
	return gao( n/p,p )+n/p;
}
int isp[10005];
int p[20005],np;
int a[1322],b[1322];
int A[1322],B[1322];
bool check( int x ) {
	int i;
	for ( i=0; i<np; i++ )if ( ( B[i]=gao( x,p[i] ) )>A[i] )return 0;
	return 1;
}
int isprime( int x ) {
	for ( int i=2; i*i<=x; i++ )if ( x%i==0 )return 0;
	return 1;
}
int main() {
	int i,j;
	np=0;
	for ( i=2; i<=10007; i++ )if ( isprime( i ) )p[np++]=i;
//	cout<<isprime( 10007 )<<endl;
//	freopen( "factorial.in", "r", stdin );
//	freopen( "factorial.out", "w", stdout );
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		memset( A,0,sizeof A );
		memset( B,0,sizeof B );
		for ( i=0; i<n; i++ )scanf( "%d",&a[i] );
		for ( i=0; i<m; i++ )scanf( "%d",&b[i] );
		for ( i=0; i<n; i++ )for ( j=0; j<np; j++ )
				A[j]+=gao( a[i],p[j] );
		for ( i=0; i<m; i++ )for ( j=0; j<np; j++ )
				B[j]+=gao( b[i],p[j] );
		int flag=0;
		for ( i=0; i<np; i++ )
			if ( A[i]<B[i] )flag=1;
			else A[i]-=B[i];
		if ( flag ) {printf( "-1\n" ); continue;}
		map<int,int>L;
		while ( 1 ) {
			int ff=0;
			for ( i=0; i<np; i++ )
				if ( A[i] )ff=1;
			if ( !ff )break;
			int l=2,r=10007;
			while ( r>=l ) {
				if ( r-l<=1 ) {
					if ( check( r ) )l=r;
					else r=l;
					break;
				}
				int mid=( l+r )/2;
				if ( check( mid ) )l=mid;
				else r=mid;
			}
			if ( check( l ) ) {
				for ( i=0; i<np; i++ )A[i]-=B[i];
				L[l]++;
			} else break;
		}
		printf( "%d\n",L.SZ );
		map<int,int>::iterator it=L.ED;
		while ( L.SZ ) {
			--it;
			printf( "%d %d\n",( *it ).AA,( *it ).BB );
			if ( it==L.OP )break;
		}
	}
	return 0;
}
/*
2 1
10000 10000
*/
