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
typedef long long LL;
typedef pair<int, int> PII;

int sg[55][55];
class SplitStoneGame {
public:
	string winOrLose( vector <int> W ) {
		memset(sg,0,sizeof sg);
		int i,j;
		for ( i=3; i<=W.SZ; i++ ) for ( j=0; j<=i; j++ ) {
				int p=j,q=i-j;
				sg[i][j]=0;
				if ( q>=1&&p>=2 )
					sg[i][j]|=!sg[i-1][p-2];
				if ( q>=2&&p>=1 )
					sg[i][j]|=!sg[i-1][p-1];
				if ( q>=3&&p>=0 )
					sg[i][j]|=!sg[i-1][p];
			}
		int t=0;
		for ( i=0; i<W.SZ; i++ )if ( W[i]==1 )t++;
		if ( sg[W.SZ][t] )return "WIN";
		else return "LOSE";
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

int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) {
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
		cerr << "    Expected: \"" << expected << "\"" << endl;
		cerr << "    Received: \"" << received << "\"" << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				int number[]              = {1, 1, 1};
				string expected__         = "LOSE";
				
				clock_t start__           = clock();
				string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int number[]              = {2, 2};
				string expected__         = "LOSE";
				
				clock_t start__           = clock();
				string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int number[]              = {1, 1, 2};
				string expected__         = "WIN";
				
				clock_t start__           = clock();
				string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int number[]              = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
				string expected__         = "WIN";
				
				clock_t start__           = clock();
				string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int number[]              = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
				string expected__         = "LOSE";
				
				clock_t start__           = clock();
				string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		case 5: {
				int number[]              = {4, 2, 2, 9, 18, 3, 18, 9};
				string expected__         = "LOSE";
				
				clock_t start__           = clock();
				string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		/*      case 6: {
					int number[]              = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					int number[]              = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = SplitStoneGame().winOrLose( vector <int>( number, number + ( sizeof number / sizeof number[0] ) ) );
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
