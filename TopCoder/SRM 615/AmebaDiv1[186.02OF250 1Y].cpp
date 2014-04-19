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


class AmebaDiv1 {
public:
	int count( vector <int> X ) {
		int i,j;
		int ret=0;
		set<int>S,D;
		set<int>::iterator it;
		for(i=0;i<X.SZ;i++){
			int tp=X[i];
			S.insert(X[i]);
			while(tp%2==0){
				tp/=2;
				S.insert(tp);
			}
		}
		for(it=S.OP;it!=S.ED;++it){
			int now=*(it);
			for(i=0;i<X.SZ;i++)if(now==X[i])now*=2;
			D.insert(now);
		}
		for(it=D.OP;it!=D.ED;++it)if(S.count(*it))ret++;
		return S.SZ-ret;
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
				int X[]                   = {3,2,1};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int X[]                   = {2,2,2,2,2,2,4,2,2,2};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int X[]                   = {1,2,4,8,16,32,64,128,256,1024,2048};
				int expected__            = 11;
				
				clock_t start__           = clock();
				int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int X[]                   = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562};
				int expected__            = 7;
				
				clock_t start__           = clock();
				int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 4: {
					int X[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 5: {
					int X[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int X[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = AmebaDiv1().count( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ) );
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
