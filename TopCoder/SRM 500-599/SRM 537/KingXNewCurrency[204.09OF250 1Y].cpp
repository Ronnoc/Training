// BEGIN CUT HERE
/*
PROBLEM STATEMENT
King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

Kingdom of Ducks has a pretty strange currency system. There are only two coin types: one with value A and one with value B, where A and B are different. This currency system is denoted by {A, B}. These two coin types are sufficient for daily transactions, because all prices in this kingdom are in the form of (A*p + B*q) for some non-negative integers p and q. Therefore, slimes and ducks can pay for any goods with a combination of the two coin types.

Bored with the current system, King Dengklek considered another currency system with two coin types: one with value X and one with value Y, where X and Y are different. Of course, with this new system, combinations of the two new coin types must make it possible to pay all the prices one could pay with currency system {A, B}. (Note that the new coin types may also make it possible to pay some additional prices.)

You are given ints A, B, and X. Return the number of different positive integers Y (other than X) such that the currency system {X, Y} can be used to replace the currency system {A, B}. If there is an infinite number of possible values for Y, return -1 instead.

DEFINITION
Class:KingXNewCurrency
Method:howMany
Parameters:int, int, int
Returns:int
Method signature:int howMany(int A, int B, int X)


CONSTRAINTS
-A, B, and X will each be between 1 and 200, inclusive.
-A and B will be different.


EXAMPLES

0)
5
8
5

Returns: 5

These are the 5 possible currency systems: {5, 1}, {5, 2}, {5, 3}, {5, 4}, and {5, 8}.

1)
8
4
2

Returns: -1

All prices are multiples of four. Since a coin type with value 2 alone can pay any price that is a multiple of four, there is an infinite number of possible values of Y.

2)
7
4
13

Returns: 1

The only possible currency system is {13, 1}.

3)
47
74
44

Returns: 2

The two possible currency systems are {44, 1} and {44, 3}.

4)
128
96
3

Returns: 65



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


class KingXNewCurrency {
public:
  int howMany (int A, int B, int X) {
    int ret=0,i,j;
    int C=__gcd(A,B);
    if(C%X==0)return -1;
    for(i=1;i<=A*B/C;i++)if(C%__gcd(X,i)==0){
			int fa=0,fb=0;
			for(j=0;j*X<=A;j++)if((A-j*X)%i==0)fa=1;
			for(j=0;j*X<=B;j++)if((B-j*X)%i==0)fb=1;
			if(fa&&fb)ret++;
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
			int A                     = 5;
			int B                     = 8;
			int X                     = 5;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int A                     = 8;
			int B                     = 4;
			int X                     = 2;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int A                     = 7;
			int B                     = 4;
			int X                     = 13;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int A                     = 47;
			int B                     = 74;
			int X                     = 44;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int A                     = 128;
			int B                     = 96;
			int X                     = 3;
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany( A, B, X );
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
