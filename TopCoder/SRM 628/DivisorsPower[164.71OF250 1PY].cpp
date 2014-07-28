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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.OP,p.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos( -1 );
const LL MOD = 1000000007;


vector<pair<LL,int> >L;
long long ret;
int c[1111];
LL llpow( LL a,LL b ) {
	LL ret=1;
	while ( b ) {
		if ( b&1 )ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
void dfs( int h,LL now ) {
	int i;
	if ( h==L.SZ ) {
		cout<<h<<" "<<now<<endl;
		for(i=0;i<h;i++)cout<<c[i]<<" ";
		cout<<endl;
		int C[111];
		for ( i=0; i<h; i++ )C[i]=c[i];
		for ( i=0; i<h; i++ )for ( int j=0; j<h; j++ )
				C[j]*=c[i]+1;
		for ( i=0; i<h; i++ )if ( C[i]!=L[i].BB )return;
		if ( ret==-1 )ret=now;
		else cmin( ret,now );
		return;
	}
	for ( i=1; i<=L[h].BB; i++ ) {
		int mul=i*( i+1 );
		if ( L[h].BB%mul )continue;
		c[h]=i;
		dfs( h+1,now*llpow( L[h].AA,i ) );
	}
}
class DivisorsPower {
public:
	long long findArgument( long long n ) {
		int i,j;
		L.clear();
		for ( i=2; i<=1000000; i++ )if ( n%i==0 ) {
				int cnt=0;
				while ( n%i==0 )cnt++,n/=i;
				L.PB( MP( i,cnt ) );
			}
		if ( n>1 ) {
			LL w=sqrt( n+eps );
			if ( SQ( w )==n )L.PB( MP( w,2 ) ),n=1;
			if ( SQ( w-1 )==n )L.PB( MP( w,2 ) ),n=1;
			if ( SQ( w+1 )==n )L.PB( MP( w,2 ) ),n=1;
			if ( n>1 )L.PB( MP( n,1 ) );
		}
		for ( i=0; i<L.SZ; i++ )if ( L[i].BB==1 )return -1;
		for ( i=0; i<L.SZ; i++ )cout<<L[i].AA<<"^"<<L[i].BB<<" ";
		ret=-1;
		dfs( 0,1 );
		return ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case( int );
void run_test( int casenum = -1, bool quiet = false ) {
	if ( casenum != -1 ) {
		if ( run_test_case( casenum ) == -1 && !quiet )
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for ( int i=0;; ++i ) {
		int x = run_test_case( i );
		if ( x == -1 ) {
			if ( i >= 100 ) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if ( total == 0 ) {
		cerr << "No test cases run." << endl;
	} else if ( correct < total ) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case( int casenum, const long long &expected, const long long &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( expected == received ) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if ( !info.empty() ) {
		cerr << " (";
		for ( int i=0; i<( int )info.size(); ++i ) {
			if ( i > 0 ) cerr << ", ";
			cerr << info[i];
		}
		cerr << ")";
	}
	cerr << endl;
	
	if ( verdict == "FAILED" ) {
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				long long n               = 4LL;
				long long expected__      = 2LL;
				
				clock_t start__           = clock();
				long long received__      = DivisorsPower().findArgument( n );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				long long n               = 10LL;
				long long expected__      = -1LL;
				
				clock_t start__           = clock();
				long long received__      = DivisorsPower().findArgument( n );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				long long n               = 64LL;
				long long expected__      = 4LL;
				
				clock_t start__           = clock();
				long long received__      = DivisorsPower().findArgument( n );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				long long n               = 10000LL;
				long long expected__      = 10LL;
				
				clock_t start__           = clock();
				long long received__      = DivisorsPower().findArgument( n );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				long long n               = 2498388559757689LL;
				long long expected__      = 49983883LL;
				
				clock_t start__           = clock();
				long long received__      = DivisorsPower().findArgument( n );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					long long n               = LL;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = DivisorsPower().findArgument( n );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					long long n               = LL;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = DivisorsPower().findArgument( n );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					long long n               = LL;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = DivisorsPower().findArgument( n );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		default:
			return -1;
	}
}
}


int main( int argc, char *argv[] ) {
	if ( argc == 1 ) {
		moj_harness::run_test();
	} else {
		for ( int i=1; i<argc; ++i )
			moj_harness::run_test( atoi( argv[i] ) );
	}
}
// END CUT HERE
