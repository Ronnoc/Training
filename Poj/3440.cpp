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
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int m,n;
	double c,t;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%d%d%lf%lf",&m,&n,&c,&t );
		if ( CA>1 )printf( "\n" );
		t/=2;
		if ( m<n )swap( m,n ); //m>=n
		double Sall=c*c*m*n;
		double S1=0,S2=0,S3=0,S4=0;
		if ( n==1 ) {
			if ( m==1 )
				S1+=Sall;
			else {
				S2=2*c*t*( m-1 );
				S1=Sall-S2;
			}
		} else {
			int bian=2*( m+n-4 );
			int nei=( m-2 )*( n-2 );
			S1+=4.0*SQ( c-t );
			S2+=8.0*t*( c-t );
			S3+=SQ( 2*t )-PI*SQ( t );
			S4+=PI*SQ( t );
			if ( bian ) {
				S1+=( c-2*t )*( c-t )*bian;
				S2+=t*( 3*c-4*t )*bian;
				S3+=( SQ( 2*t )-PI*SQ( t ) )/2*bian;
				S4+=PI*SQ( t )/2*bian;
			}
			if ( nei ) {
				S1+=SQ( c-2*t )*nei;
				S2+=4*t*( c-2*t )*nei;
				S3+=( SQ( 2*t )-PI*SQ( t ) )*nei;
				S4+=PI*SQ( t )*nei;
			}
		}
		printf( "Case %d:\n",CA );
		printf( "Probability of covering 1 tile  = %.4f%%\n",S1*100/Sall );
		printf( "Probability of covering 2 tiles = %.4f%%\n",S2*100/Sall );
		printf( "Probability of covering 3 tiles = %.4f%%\n",S3*100/Sall );
		printf( "Probability of covering 4 tiles = %.4f%%\n",S4*100/Sall );
	}
	return 0;
}
