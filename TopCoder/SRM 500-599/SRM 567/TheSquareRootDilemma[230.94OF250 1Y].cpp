// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Consider the function SSR (Squared Sum of square Roots) defined on two positive integer parameters: SSR(A, B) = (sqrt(A)+sqrt(B))^2. We are interested in the cases when the value of the function is also an integer.

Given ints N and M, return the number of ordered pairs (A, B) such that 1 <= A <= N, 1 <= B <= M and SSR(A, B) is an integer.

DEFINITION
Class:TheSquareRootDilemma
Method:countPairs
Parameters:int, int
Returns:int
Method signature:int countPairs(int N, int M)


NOTES
-The answer to the problem is guaranteed to fit into signed 32-bit integer type under the given constraints.


CONSTRAINTS
-N will be between 1 and 77,777, inclusive.
-M will be between 1 and 77,777, inclusive.


EXAMPLES

0)
2
2

Returns: 2

Out of the four possible pairs (A, B), only two yield an integer result: SSR(1, 1) = 4 and SSR(2, 2) = 8.
On the other hand, SSR(1, 2) = SSR(2, 1) = 3+2*sqrt(2), which is not an integer.

1)
10
1

Returns: 3

SSR(1, 1), SSR(4, 1) and SSR(9, 1) are integers.

2)
3
8

Returns: 5

The valid pairs are (1, 1), (1, 4), (2, 2), (2, 8) and (3, 3).

3)
100
100

Returns: 310



*/
// END CUT HERE
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

class TheSquareRootDilemma {
public:
  int countPairs (int N, int M) {
  	cout<<N<<" "<<M<<endl;
    int ret=0;
    LL n=N,m=M,i,j;
    for(i=1;i<=n;i++){
			LL tp=1,nn=n;
			n=i;
			for(j=2;j*j<=n;j++){
				if(n%j)continue;
				int tot=0;
				while(!(n%j))n/=j,tot++;
				if(tot&1)tp*=j;
			}
			tp*=n;
			n=nn;
//			cout<<i<<"+="<<(1e-8+1.0*m/tp)<<endl;
			ret+=sqrt(1e-8+m/tp);
    }
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
			int N                     = 2;
			int M                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 10;
			int M                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int M                     = 8;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 100;
			int M                     = 100;
			int expected__            = 310;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSquareRootDilemma().countPairs( N, M );
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
