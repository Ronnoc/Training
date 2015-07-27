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
#include<bits/stdc++.h>
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
class AliceGame {
public:
  long long findMinimumValue (long long x, long long y) {
    long long ret=-1;
    int i,j;
    long long n=0;
    while(n*n<x+y)n++;
    if(n*n!=x+y)return -1;
    if(x==2||y==2)return -1;
    LL ans=0;
    for(i=n;i>=1;i--){
        if(x>=2*i-1){
            if(x-(2*i-1)!=2)x-=2*i-1,ans++;
        }
    }
    return x==0?ans:-1;
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
			long long x               = 8LL;
			long long y               = 17LL;
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			long long x               = 17LL;
			long long y               = 8LL;
			long long expected__      = 3LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			long long x               = 0LL;
			long long y               = 0LL;
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			long long x               = 9LL;
			long long y               = 9LL;
			long long expected__      = -1LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			long long x               = 500000LL;
			long long y               = 500000LL;
			long long expected__      = 294LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: { 
			long long x               = 932765767597LL;
			long long y               = 67234232403LL;
			long long expected__      = -1LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			long long x               = LL;
			long long y               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			long long x               = LL;
			long long y               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = AliceGame().findMinimumValue( x, y );
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
