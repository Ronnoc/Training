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

int pre[4005];
class BuildingHeights {
public:
	int minimum( vector <int> H ) {
		int ret=0;
		int i,j;
		SORT( H );
		pre[0]=H[0];
		for ( i=1; i<H.SZ; i++ )pre[i]=pre[i-1]+H[i];
		for ( i=1; i<=H.SZ; i++ ) {
			int now=1LL<<30;
			for ( j=i; j<=H.SZ; j++ ) { //j-i~j-1;
				int sum=pre[j-1];
				if ( j-i-1>=0 )sum-=pre[j-i-1];
				cmin( now,H[j-1]*i-sum );
			}
			ret^=now;
		}
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
				int heights[]             = {1, 5, 4, 3, 8};
				int expected__            = 22;
				
				clock_t start__           = clock();
				int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int heights[]             = {1, 2, 3};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int heights[]             = {3, 4, 1, 6, 8, 1};
				int expected__            = 21;
				
				clock_t start__           = clock();
				int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int heights[]             = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,  2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,  929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,  1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,  1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,  1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
				int expected__            = 56068;
				
				clock_t start__           = clock();
				int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 4: {
					int heights[]             = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 5: {
					int heights[]             = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int heights[]             = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = BuildingHeights().minimum( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
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
