// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly and Kriss play a game. The game is played on a single row that consists of N cells; we will call it the board. The cells of the board are numbered 0 through N-1, from the left to the right. Each cell of the board is either empty or occupied by a single checker. The girls take alternating turns, until one of them cannot make a move. The girl who is unable to make a move loses the game.

In each move the current player selects a cell containing a checker and performs one of the following two types of moves:

A step, in which the checker is moved one cell to the right. The step can only be made if the target cell is empty.
A jump, in which the checker jumps three cells to the right. The jump can only be made if the target cell is empty and the cells it jumped over contain two other checkers.

Once a checker reaches the rightmost cell, it disappears immediately and no longer plays any role in the game.

The initial layout of the board will be given as a string board. The i-th character of board will be '.' (a period) if the i-th cell is empty at the
beginning, and it will be 'o' (lowercase letter o) if the i-th cell initially contains a checker. Assume that both girls play optimally. Return "YES" (quotes for clarity) if the first player wins the game and "NO" otherwise.

DEFINITION
Class:EllysCheckers
Method:getWinner
Parameters:string
Returns:string
Method signature:string getWinner(string board)


NOTES
-If there is a checker on the rightmost cell in the beginning of the game, it disappears instantly (before the first move is made), as if it were never there.
-The rules of the game ensure that each cell contains at most one checker at any time, and that no checker can jump beyond the last cell.


CONSTRAINTS
-board will contain between 1 and 20 characters, inclusive.
-Each character of board will be either '.' or 'o'.


EXAMPLES

0)
".o..."

Returns: "YES"

With only one checker it is pretty obvious who will win.

1)
"..o..o"

Returns: "YES"

Don't forget to ignore checkers on the rightmost cell.

2)
".o...ooo..oo.."

Returns: "NO"

Here one can jump the checker from cell 5 to cell 8.

3)
"......o.ooo.o......"

Returns: "YES"

4)
".o..o...o....o.....o"

Returns: "NO"

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

int dp[1<<21],n;
int dfs(int tp){
	if(tp>>(n-1)&1)return dfs(tp^(1<<(n-1)));
	if(dp[tp]!=-1)return dp[tp];
	int i;
	for(i=0;i<n;i++)if(tp>>i&1){
		if(i+1<n){
			if(tp>>(i+1)&1);
			else if(!dfs( tp^(1<<i)^(1<<(i+1)) ))return dp[tp]=1;
		}
		if(i+3<n){
			if(tp>>(i+1)&1)if(tp>>(i+2)&1){
				if(tp>>(i+3)&1);
				else if(!dfs( tp^(1<<i)^(1<<(i+3)) ))return dp[tp]=1;
			}
		}
	}
	return dp[tp]=0;
}
class EllysCheckers {
public:
  string getWinner (string b) {
  	n=b.SZ;
    string yes="YES",no="NO";
    int tp=0,i,j;
    memset(dp,-1,sizeof dp);
    for(i=0;i<b.SZ;i++)if(b[i]=='o')tp|=1<<i;
    if(dfs(tp))return yes;
    else return no;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string board              = ".o...";
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board              = "..o..o";
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board              = ".o...ooo..oo..";
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board              = "......o.ooo.o......";
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board              = ".o..o...o....o.....o";
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string board              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string board              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysCheckers().getWinner( board );
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
