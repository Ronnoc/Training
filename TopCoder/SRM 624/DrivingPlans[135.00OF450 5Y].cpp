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
const LL MOD = 1000000009;

int dp[2005];
int cnt[2005];
int vis[2005];
vector<PII>G[2005];
class DrivingPlans {
public:
	int count( int N, vector <int> A, vector <int> B, vector <int> C ) {
		int ret;
		int i,j;
		for ( i=1; i<=N; i++ )G[i].clear();
		for ( i=1; i<=N; i++ )dp[i]=MOD,cnt[i]=0,vis[i]=0;
		dp[1]=0,cnt[1]=1;
		for ( i=0; i<A.SZ; i++ )G[A[i]].PB( MP( B[i],C[i] ) );
		for ( i=0; i<A.SZ; i++ )G[B[i]].PB( MP( A[i],C[i] ) );
		set<PII>S;
		S.insert( MP( 0,1 ) );
		while ( !S.empty() ) {
			PII tp=*S.OP;
			S.erase( S.OP );
			int u=tp.BB;
			if ( tp.AA>dp[u] )continue;
			for ( i=0; i<G[u].SZ; i++ )if ( G[u][i].BB==0 )vis[u]|=1;
			for ( i=0; i<G[u].SZ; i++ ) {
				int v=G[u][i].AA;
				int d=G[u][i].BB;
				if ( dp[v]>dp[u]+d ) {
					dp[v]=dp[u]+d;
					cnt[v]=cnt[u];
					vis[v]=vis[u];
					if ( d==0 )vis[v]=1;
					S.insert( MP( dp[v],v ) );
				} else if ( dp[v]==dp[u]+d ) {
					cnt[v]=( cnt[v]+cnt[u] )%MOD;
					vis[v]|=vis[u];
					if ( d==0 )vis[v]=1;
				}
			}
		}
		return vis[N]?-1:cnt[N];
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

int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
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
				int N                     = 4;
				int A[]                   = {1,1,2,3};
				int B[]                   = {2,3,4,4};
				int C[]                   = {1,1,1,1};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = DrivingPlans().count( N, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( C, C + ( sizeof C / sizeof C[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int N                     = 4;
				int A[]                   = {1,1,2,3};
				int B[]                   = {2,3,4,4};
				int C[]                   = {1,1,1,0};
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = DrivingPlans().count( N, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( C, C + ( sizeof C / sizeof C[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int N                     = 7;
				int A[]                   = {1,1,2,3,4,4,5,6};
				int B[]                   = {2,3,4,4,5,6,7,7};
				int C[]                   = {1,1,2,2,3,3,4,4};
				int expected__            = 4;
				
				clock_t start__           = clock();
				int received__            = DrivingPlans().count( N, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( C, C + ( sizeof C / sizeof C[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		case 3: {
				int N                     = 4;
				int A[]                   = {1,4,2};
				int B[]                   = {4,2,3};
				int C[]                   = {1,1,0};
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = DrivingPlans().count( N, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( C, C + ( sizeof C / sizeof C[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		      case 4: {
					int N                     = 8;
					int A[]                   = {1,1,1,2,3,4,5,6,7};
					int B[]                   = {2,3,4,5,6,7,8,8,8};
					int C[]                   = {1,1,1,0,1,0,5,1,5};
					int expected__            = 1;
		
					clock_t start__           = clock();
					int received__            = DrivingPlans().count( N, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( C, C + ( sizeof C / sizeof C[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}
		/*      case 5: {
					int N                     = ;
					int A[]                   = ;
					int B[]                   = ;
					int C[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = DrivingPlans().count( N, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( C, C + ( sizeof C / sizeof C[0] ) ) );
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
