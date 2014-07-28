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
	int i,j;
	int k,n1,n2,n3,t1,t2,t3;
	while ( ~scanf( "%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3 ) ) {
		set<pair<int,int> >S1,S2,S3;
		for ( i=1; i<=n1; i++ )S1.insert( MP( 0,i ) );
		for ( i=1; i<=n2; i++ )S2.insert( MP( 0,i ) );
		for ( i=1; i<=n3; i++ )S3.insert( MP( 0,i ) );
		int T=0;
		while ( k-- ) {
			int i1=( *S1.OP ).BB;
			int i2=( *S2.OP ).BB;
			int i3=( *S3.OP ).BB;
			int f1=( *S1.OP ).AA;
			int f2=( *S2.OP ).AA-t1;
			int f3=( *S3.OP ).AA-t1-t2;
			int f=f1;
			cmax( f,f2 );
			cmax( f,f3 );
			cmax( T,f+t1+t2+t3 );
			S1.erase( S1.OP ); S1.insert( MP( f+t1,i1 ) );
			S2.erase( S2.OP ); S2.insert( MP( f+t1+t2,i2 ) );
			S3.erase( S3.OP ); S3.insert( MP( f+t1+t2+t3,i3 ) );
		}
		cout<<T<<endl;
	}
	return 0;
}
