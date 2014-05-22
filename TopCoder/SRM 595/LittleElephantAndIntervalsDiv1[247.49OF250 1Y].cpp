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

class LittleElephantAndIntervalsDiv1 {
public:
  long long getNumber (int M, vector <int> L, vector <int> R) {
    long long ret;
    int cnt=0;
    int i,j;
    set<int>S;
    for(i=1;i<=M;i++)S.insert(i);
    for(i=L.SZ-1;i>=0;i--){
			int now=0;
			for(j=L[i];j<=R[i];j++)if(S.count(j))now++,S.erase(S.find(j));
			if(now)cnt++;
    }
    return 1LL<<cnt;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int M                     = 4;
			int L[]                   = {1, 2, 3};
			int R[]                   = {1, 2, 3};
			long long expected__      = 8LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int M                     = 3;
			int L[]                   = {1, 1, 2};
			int R[]                   = {3, 1, 3};
			long long expected__      = 4LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int M                     = 1000;
			int L[]                   = {47};
			int R[]                   = {747};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int M                     = 42;
			int L[]                   = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16, 28, 13, 27, 9, 18, 4, 10, 3, 4, 4, 3, 4, 1, 18, 18, 2, 38, 4, 10, 12, 3, 30, 11, 38, 2, 13, 1, 13, 18, 16, 13, 2, 14, 27, 13, 3, 26, 19, 5, 10};
			int R[]                   = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19, 31, 28, 35, 27, 30, 13, 31, 5, 8, 25, 40, 10, 3, 26, 23, 9, 40, 8, 40, 23, 12, 37, 35, 39, 11, 34, 10, 21, 22, 21, 24, 5, 39, 27, 17, 16, 26, 35, 25, 36};
			long long expected__      = 256LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int M                     = ;
			int L[]                   = ;
			int R[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int M                     = ;
			int L[]                   = ;
			int R[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int M                     = ;
			int L[]                   = ;
			int R[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof L[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
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
