// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The knight is a chess piece that moves by jumping: two cells in one direction, one in the other.
Formally, a knight standing on the cell (x,y) can move to any of the following eight cells:
(x+2,y+1), (x+2,y-1), (x-2,y+1), (x-2,y-1), (x+1,y+2), (x+1,y-2), (x-1,y+2), and (x-1,y-2).
Of course, if the knight is close to the edge of the board, some of these cells might not be on the board.
It is not allowed to jump to a cell that is not on the board.

A knight circuit is a sequence of cells on a chessboard that starts and ends with the same cell.
Each consecutive pair of cells in the knight circuit must correspond to a single jump of the knight.
The knight circuit may visit each cell arbitrarily many times.
The size of a knight circuit is the number of different cells visited by the circuit.

You are given the ints w and h: the width (in columns) and the height (in rows) of a rectangular chessboard. Return the maximum knight circuit size that can be obtained on the given board.
You are free to choose any cell as the start of your circuit.

DEFINITION
Class:KnightCircuit2
Method:maxSize
Parameters:int, int
Returns:int
Method signature:int maxSize(int w, int h)


CONSTRAINTS
-w and h will each be between 1 and 45000, inclusive.


EXAMPLES

0)
1
1

Returns: 1

Note that a sequence that consists of a single cell is considered to be a valid knight circuit.

1)
15
2

Returns: 8

If you start at any corner of the board, it is possible to move the knight to visit 8 cells, and then do the same moves in reverse in order to return to the starting cell. One possibility for the first eight cells of an optimal knight circuit is shown below:


1...3...5...7..
..2...4...6...8


2)
100
100

Returns: 10000

It is possible to make a Knight circuit that contains all the cells on the board.

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


class KnightCircuit2 {
public:
  int maxSize (int w, int h) {
    if(w>h)swap(w,h);
    if(w==1)return 1;
    if(w==2)return (h-1)/2+1;
    if(w==3)
			if(h==3)return 8;
    return w*h;
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
			int w                     = 3;
			int h                     = 29038;
			int expected__            = 87114;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize( w, h );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int w                     = 3;
			int h                     = 25053;
			int expected__            = 75159;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize( w, h );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int w                     = 100;
			int h                     = 100;
			int expected__            = 10000;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize( w, h );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize( w, h );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize( w, h );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize( w, h );
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
