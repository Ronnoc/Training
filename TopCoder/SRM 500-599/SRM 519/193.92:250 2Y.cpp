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

map<pair<LL,LL>,LL>S;
LL play(LL A,LL B){
	LL &tp=S[MP(A,B)];
	if(tp!=0)return tp;
	if(A==B)return A;
	LL now=1,cnt=0;
	while(now*2<=B)now*=2,cnt++;
	if(now<=A)return tp=now+play(A-now,B-now);
	return tp=max(max(play(A,now-1),play(now,B)),now*2-1);
}
class BinaryCards {
public:
  long long largestNumber (long long A, long long B) {
    return play(A,B);
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
			long long A               = 6LL;
			long long B               = 6LL;
			long long expected__      = 6LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			long long A               = 6LL;
			long long B               = 7LL;
			long long expected__      = 7LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			long long A               = 6LL;
			long long B               = 8LL;
			long long expected__      = 15LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			long long A               = 1LL;
			long long B               = 11LL;
			long long expected__      = 15LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			long long A               = 35LL;
			long long B               = 38LL;
			long long expected__      = 39LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			long long A               = 1125899906842630LL;
			long long B               = 1125899906842632LL;
			long long expected__      = 1125899906842639LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			long long A               = LL;
			long long B               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			long long A               = LL;
			long long B               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			long long A               = LL;
			long long B               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber( A, B );
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
