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
#include <stdexcept>
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
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;

int dp[55][2300];
int vis[55][2300];
map<int,int>DP[55];
map<int,int>::iterator it;
class TypoCoderDiv1 {
public:
	int getmax( vector <int> D, int X ) {
		int i,j;
		int ret=0;
		for(i=0;i<=D.SZ;i++)DP[i].clear();
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		vis[0][X]=1;
		for ( i=0; i<D.SZ; i++ ){
			for(j=0;j<2200;j++)if(vis[i][j]){
				int now=j;
				int tp=dp[i][j];
				int win=now+D[i];
				int lose=max(now-D[i],0);
				if(win<2200)cmax(dp[i+1][win],tp),vis[i+1][win]=1;
				else cmax(DP[i+1][win],tp+1);
				cmax(dp[i+1][lose],tp);
				vis[i+1][lose]=1;
			}
			for(it=DP[i].OP;it!=DP[i].ED;++it){
				int now=(*it).AA;
				int tp=(*it).BB;
				int lose=max(now-D[i],0);
				if(lose>=2200)continue;
				vis[i+1][lose]=1;
				cmax(dp[i+1][lose],tp+1);
			}
		}
		for(it=DP[D.SZ].OP;it!=DP[D.SZ].ED;++it)
			cmax(ret,(*it).BB);
		for(j=0;j<2200;j++)if(vis[D.SZ][j])cmax(ret,dp[D.SZ][j]);
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
				int D[]                   = {100,200,100,1,1};
				int X                     = 2000;
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int D[]                   = {0,0,0,0,0};
				int X                     = 2199;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int D[]                   = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
				int X                     = 0;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int D[]                   = {1000000000,1000000000,10000,100000,2202,1};
				int X                     = 1000;
				int expected__            = 4;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int D[]                   = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
				int X                     = 2199;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 5: {
				int D[]                   = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
				int X                     = 1223;
				int expected__            = 29;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 6: {
				int D[]                   = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
				int X                     = 1328;
				int expected__            = 20;
				
				clock_t start__           = clock();
				int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 7: {
					int D[]                   = ;
					int X                     = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 8: {
					int D[]                   = ;
					int X                     = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 9: {
					int D[]                   = ;
					int X                     = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = TypoCoderDiv1().getmax( vector <int>( D, D + ( sizeof D / sizeof D[0] ) ), X );
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
