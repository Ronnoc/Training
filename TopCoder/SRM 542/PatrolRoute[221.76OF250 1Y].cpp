// BEGIN CUT HERE
/*
PROBLEM STATEMENT
There are exactly X*Y places in the Planar Kingdom: For each pair of integers (x, y) such that 0 <= x < X and 0 <= y < Y there is a place with coordinates (x, y). When a citizen of the kingdom wants to move from (x1, y1) to (x2, y2), the required time is |x1 - x2| + |y1 - y2| (where |t| denotes the absolute value of t).

In order to improve stability in the kingdom, the police wants to introduce a specific patrol route. The route will contain exactly three places A, B, and C.
A policeman will visit these three places and verify that everything is as it should be. The three places that determine a valid route must satisfy the following criteria::

x-coordinates of A, B and C are pairwise distinct.
y-coordinates of A, B and C are pairwise distinct.
Let T be the total time required to follow along the route: first from A to B, then from B to C and finally from C back to A. T must be between minT and maxT, inclusive.


You are given the ints X, Y, minT, and maxT. Return the number of different patrol routes that satisfy these criteria, modulo 1,000,000,007. Two routes are considered to be different if there is a place that belongs to one of them, but does not belong to the other one.

DEFINITION
Class:PatrolRoute
Method:countRoutes
Parameters:int, int, int, int
Returns:int
Method signature:int countRoutes(int X, int Y, int minT, int maxT)


CONSTRAINTS
-X and Y will each be between 3 and 4,000, inclusive.
-minT will be between 1 and 20,000, inclusive.
-maxT will be between minT and 20,000, inclusive.


EXAMPLES

0)
3
3
1
20000

Returns: 6

The time requirement is very flexible in this case. There are 6 patrol routes where both x and y coordinates of places are pairwise distinct.

1)
3
3
4
7

Returns: 0

The time of 7 is too small for any patrol route.

2)
4
6
9
12

Returns: 264



3)
7
5
13
18

Returns: 1212



4)
4000
4000
4000
14000

Returns: 859690013

Don't forget about the modulo!

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


class PatrolRoute {
public:
  int countRoutes (int X, int Y, int minT, int maxT) {
  	cout<<X<<"~"<<Y<<"~"<<minT<<"~"<<maxT<<endl;
    int ret=0;
    int i,j;
    int mod=1000000007;
    for(i=2;i<X;i++)for(j=2;j<Y;j++){
			int add=2*(i+j);
			if(add<minT||add>maxT)continue;
			LL pl=(X-i)*(Y-j);
			LL tp=6*(i-1)*(j-1);
			ret=(ret+tp*pl)%mod;
//			cout<<X-i<<" "<<Y-j<<endl;
//			cout<<i<<" "<<j<<" ->";
//			cout<<tp<<" "<<pl<<endl;
//			system("pause");
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
			int X                     = 3;
			int Y                     = 3;
			int minT                  = 1;
			int maxT                  = 20000;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int X                     = 3;
			int Y                     = 3;
			int minT                  = 4;
			int maxT                  = 7;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int X                     = 4;
			int Y                     = 6;
			int minT                  = 9;
			int maxT                  = 12;
			int expected__            = 264;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int X                     = 7;
			int Y                     = 5;
			int minT                  = 13;
			int maxT                  = 18;
			int expected__            = 1212;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int X                     = 4000;
			int Y                     = 4000;
			int minT                  = 4000;
			int maxT                  = 14000;
			int expected__            = 859690013;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int X                     = ;
			int Y                     = ;
			int minT                  = ;
			int maxT                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int X                     = ;
			int Y                     = ;
			int minT                  = ;
			int maxT                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int X                     = ;
			int Y                     = ;
			int minT                  = ;
			int maxT                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PatrolRoute().countRoutes( X, Y, minT, maxT );
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
