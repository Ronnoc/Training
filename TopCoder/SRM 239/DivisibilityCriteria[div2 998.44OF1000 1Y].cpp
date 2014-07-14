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
const double PI = acos(-1);
const LL MOD = 1000000007;

class DivisibilityCriteria {
public:
  vector <int> multipliers (int N, int P) {
    vector <int> ret;
    int i=1;
    while(N--){
			ret.PB(i);
			i=i*10%P;
    }
    reverse(ret.OP,ret.ED);
    return ret;
  }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int N                     = 6;
			int P                     = 7;
			int expected__[]          = {5, 4, 6, 2, 3, 1 };

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			int N                     = 7;
			int P                     = 11;
			int expected__[]          = {1, 10, 1, 10, 1, 10, 1 };

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			int N                     = 5;
			int P                     = 13;
			int expected__[]          = {3, 12, 9, 10, 1 };

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			int N                     = 2;
			int P                     = 2;
			int expected__[]          = {0, 1 };

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 4: {
			int N                     = 16;
			int P                     = 97;
			int expected__[]          = {45, 53, 15, 50, 5, 49, 34, 81, 76, 27, 90, 9, 30, 3, 10, 1 };

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int P                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int P                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int P                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DivisibilityCriteria().multipliers( N, P );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
