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

int dp[55][5055];
class AlbertoTheAviator {
public:
  int MaximumFlights (int F, vector <int> d, vector <int> r) {
    int ret=0;
    vector<PII>L,R;
    int i,j;
    for(i=0;i<d.SZ;i++)R.PB(MP(d[i]-r[i],-d[i]));
    SORT(R);
    memset(dp,0,sizeof dp);
    for(i=0;i<R.SZ;i++)L.PB(MP(-R[i].BB,-R[i].BB-R[i].AA));
    for(i=0;i<L.SZ;i++){
			for(j=0;j<=F;j++){
				cmax(dp[i+1][j],dp[i][j]);
				if(j>=L[i].AA)cmax(dp[i+1][j-L[i].AA+L[i].BB],dp[i][j]+1);
			}
    }
    for(i=0;i<=L.SZ;i++)for(j=0;j<=F;j++)cmax(ret,dp[i][j]);
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int F                     = 10;
			int duration[]            = {10};
			int refuel[]              = {0};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int F                     = 10;
			int duration[]            = {8, 4};
			int refuel[]              = {0, 2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int F                     = 12;
			int duration[]            = {4, 8, 2, 1};
			int refuel[]              = {2, 0, 0, 0};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int F                     = 9;
			int duration[]            = {4, 6};
			int refuel[]              = {0, 1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int F                     = 100;
			int duration[]            = {101};
			int refuel[]              = {100};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int F                     = 1947;
			int duration[]            = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
			int refuel[]              = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int F                     = ;
			int duration[]            = ;
			int refuel[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int F                     = ;
			int duration[]            = ;
			int refuel[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int F                     = ;
			int duration[]            = ;
			int refuel[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlbertoTheAviator().MaximumFlights( F, vector <int>( duration, duration + ( sizeof duration / sizeof duration[0] ) ), vector <int>( refuel, refuel + ( sizeof refuel / sizeof refuel[0] ) ) );
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
