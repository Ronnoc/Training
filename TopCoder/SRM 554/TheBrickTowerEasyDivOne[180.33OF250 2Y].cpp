// BEGIN CUT HERE
/*
PROBLEM STATEMENT

John and Brus are building towers using toy bricks.
They have two types of bricks: red and blue ones.
The number of red bricks they have is redCount and each of them has a height of redHeight.
The number of blue bricks they have is blueCount and each of them has a height of blueHeight.



A tower is built by placing bricks one atop another.
A brick can be placed either on the ground, or on a brick of a different color.
(I.e., you are not allowed to put two bricks of the same color immediately on one another.)
A tower has to consist of at least one brick.
The height of a tower is the sum of all heights of bricks that form the tower.
Two towers are considered to be different if they have different heights.
(Two towers of the same height are considered the same, even if they differ in the number and colors of bricks that form them.)



You are given the ints redCount, redHeight, blueCount and blueHeight.
Return the number of different towers that John and Brus can build.



DEFINITION
Class:TheBrickTowerEasyDivOne
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int redCount, int redHeight, int blueCount, int blueHeight)


CONSTRAINTS
-redCount will be between 1 and 474,747,474, inclusive.
-redHeight will be between 1 and 474,747,474, inclusive.
-blueCount will be between 1 and 474,747,474, inclusive.
-blueHeight will be between 1 and 474,747,474, inclusive.


EXAMPLES

0)
1
2
3
4

Returns: 4

John and Brus have 1 red brick of height 2 and 3 blue bricks of height 4. Using these bricks, it's possible to build 4 towers:
red (height 2);
blue (height 4);
red, blue (height 6);
blue, red, blue (height 10).

1)
4
4
4
7

Returns: 12

2)
7
7
4
4

Returns: 13

3)
47
47
47
47

Returns: 94

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


class TheBrickTowerEasyDivOne {
public:
  int find (int rc, int rh, int bc, int bh) {
		if(rc>bc)rc=bc+1;
		if(bc>rc)bc=rc+1;
		cout<<rc<<" "<<rh<<","<<bc<<" "<<bh<<endl;
    int ret=0;
    vector<pair<PII,PII> >L;
    L.PB(MP(MP(rh+bh,0) ,MP(1,min(rc,bc)+1)));
    L.PB(MP(MP(rh+bh,rh),MP(0,min(rc-1,bc)+1)));
    L.PB(MP(MP(rh+bh,bh),MP(0,min(rc,bc-1)+1)));
    ret+=L[0].BB.BB-L[0].BB.AA;
    if(rh==bh)ret+=max(L[2].BB.BB-L[2].BB.AA,L[1].BB.BB-L[1].BB.AA);
    else {
			ret+=L[2].BB.BB-L[2].BB.AA;
			ret+=L[1].BB.BB-L[1].BB.AA;
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
			int redCount              = 1;
			int redHeight             = 2;
			int blueCount             = 3;
			int blueHeight            = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int redCount              = 4;
			int redHeight             = 4;
			int blueCount             = 4;
			int blueHeight            = 7;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int redCount              = 7;
			int redHeight             = 7;
			int blueCount             = 4;
			int blueHeight            = 4;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int redCount              = 47;
			int redHeight             = 47;
			int blueCount             = 47;
			int blueHeight            = 47;
			int expected__            = 94;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			int redCount              = 1;
			int redHeight             = 2;
			int blueCount             = 2;
			int blueHeight            = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 5: {
			int redCount              = ;
			int redHeight             = ;
			int blueCount             = ;
			int blueHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int redCount              = ;
			int redHeight             = ;
			int blueCount             = ;
			int blueHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBrickTowerEasyDivOne().find( redCount, redHeight, blueCount, blueHeight );
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
