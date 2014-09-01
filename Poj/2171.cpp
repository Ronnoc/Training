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
LL ten[33];
LL count( LL n,LL m ) {
	if ( m==0 )return 0;
	char sn[22],sm[22];
	sprintf( sn,"%I64d",n );
	sprintf( sm,"%I64d",m );
	int ln=strlen( sn ),lm=strlen( sm );
	LL ret=0;
	for ( int i=lm; i<=ln; i++ ) {
		LL l=m*ten[i-lm];
		LL r=( m+1 )*ten[i-lm]-1;
		cmin( r,n );
		if ( r>=l )ret+=r-l+1;
	}
//	cout<<n<<" "<<m<<" "<<ret<<endl;
	return ret;
}
LL get( LL n,LL m ) {
//	assert( n>=m );
	char sn[22],sm[22];
	sprintf( sn,"%I64d",n );
	sprintf( sm,"%I64d",m );
	int ln=strlen( sn ),lm=strlen( sm );
	if ( m==ten[lm-1] )return lm;
//	LL n0=min( n,m*ten[ln-lm] );
//	LL sum=0;
//	for ( int i=0; i<=ln-lm-1; i++ )sum+=ten[i];
//	return ( m*ten[ln-lm]-ten[ln-1] )*sum+n0-ten[ln-1]+1+m-ten[lm-1];
	int i,j;
	LL now=0;
	LL ret=0;
	for ( i=0; i<lm; i++ ) {
		ret++;
		for ( j=0; j+'0'<sm[i]; j++ )
			ret+=count( n,now*10+j );
		now=now*10+sm[i]-'0';
	}
//	cout<<n<<" "<<m<<" "<<ret<<endl;;
	return ret;
}
int main() {
//	freopen( "amusing.in","r",stdin );
//	freopen( "amusing.out","w",stdout );
	int i,j;
	ten[0]=1;
	for ( i=1; i<=20; i++ )ten[i]=ten[i-1]*10;
	for ( i=1; i<=10; i++ )get( 10,i );
	LL n,m,k;
//	cout<<get(11,2)<<endl;
	while ( cin>>k>>m ) {
		LL l=k,r=ten[18]+ten[10];
		while ( r>l ) {
			if ( r-l==1 ) {
				if ( get( l,k )== m )r=l;
				else l=r;
				break;
			}
			LL mid=( l+r )/2;
			if ( get( mid,k )>=m )r=mid;
			else l=mid;
		}
		if ( get( l,k )==m )cout<<l<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
/*
2 4
2 1
100000001 1000000000
1000000000 11
1 1
2 2
10 2
*/
