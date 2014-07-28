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
int n,m;
map<PII,long double>S;
long double comb( int n,int k ) {
	if ( !k )return 1;
	if ( S.find( MP( n,k ) )!=S.ED )return S[MP( n,k )];
	return S[MP( n,k )]=comb( n,k-1 )*( n-k+1 )/k;
}
long double gao( int t ) {
	long double ret=comb( ( n-1 )*m,n-t )*comb( m-1,t-1 );
//	cout<<t<<" "<<ret<<endl;
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		//x[i]<=m, sigma x[i]=n
		long double ans=0;
		swap( n,m );
		long double all=comb( n*m,n );
		for ( i=1; i<=n&&i<=m; i++ )
			ans+=gao( i )*i;
//		cout<<all<<endl;
		ans/=all;
		double a=ans;
		printf( "%.16f\n",a );
	}
	return 0;
}
