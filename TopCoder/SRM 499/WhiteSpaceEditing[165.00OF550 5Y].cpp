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
#define cmin(x,y) (x=min(x,(y)))
typedef long long LL;
typedef pair<int, int> PII;

int dp[55][55];
int aabs( int x ) {return x>0?x:-x;}
vector<int>y;
int dfs( int l,int r,int k ) {
	int &tp=dp[l][k];
	if ( tp!=-1 )return tp;
	if ( l==r )return 0;
	int z=y[l];
	if ( z>y[k] )
		tp=aabs( z-y[k] )+dfs( l+1,r,l );
	else
		tp=dfs( l+1,r,l );
	return tp;
}
class WhiteSpaceEditing {
public:
	int getMinimum( vector <int> x ) {
		if ( x.SZ==1 )return x[0];
		x.PB( 0 );
		int ret=0,i,j;
		for ( i=x.SZ-1; i>=1; i-- ) {
			int t=x[i]; x[i]=x[i-1];
			x[i-1]=t;
		}
		y=x;
		for ( i=1; i<x.SZ; i++ )ret+=aabs( x[i]-x[i-1] );
		memset( dp,-1,sizeof dp );
		ret=dfs( 1,x.SZ,0 );
		return ret+x.SZ-2;
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
				int lines[]               = { 3, 2, 3 };
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int lines[]               = {881621};
				int expected__            = 881621;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int lines[]               = { 4,3,2,1 } ;
				int expected__            = 7;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int lines[]               = { 250, 105, 155, 205, 350 } ;
				int expected__            = 499;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		case 4: {
				int lines[]               = {1,2,3,4,5};
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 5: {
//				int lines[]               = {0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,8,8,8,8,8,9,9,9,9,9};
//				int expected__            = 49+9;
				int lines[]               = {0};
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 6: {
				int lines[]               = {1,2,0};
				int expected__            = 4;
				
				clock_t start__           = clock();
				int received__            = WhiteSpaceEditing().getMinimum( vector <int>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
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
