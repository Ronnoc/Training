// BEGIN CUT HERE
/*
PROBLEM STATEMENT
John and Brus play a game with a number.
The game starts with a positive integer n.
The two players take alternating turns, John starts.
Each move looks as follows:
Let C be the current value of the integer.
The current player has to choose a positive divisor of the number C, other than 1 and C.
Once he chooses the divisor, he has to subtract it from C.
The result is the new number with which the other player now starts his move.
If a player cannot make a valid move, he loses the game.


For example, if they start with n=15, one possible gameplay can look as follows:

John takes the number 15, chooses its divisor 3, and decreases the number to 15-3 = 12.
Brus takes the number 12, chooses its divisor 4, and decreases the number to 12-4 = 8.
John takes the number 8, chooses its divisor 2, and decreases the number to 8-2 = 6.
Brus takes the number 6, chooses its divisor 3, and decreases the number to 6-3 = 3.
John takes the number 3, and as there are no divisors other than 1 and 3, he has no valid move and thus he loses the game.



You are given the long long n.
Assume that both players use the optimal strategy while playing the game.
Return "John" (quotes for clarity) if John wins the game and "Brus" otherwise.


DEFINITION
Class:TheNumberGameDivOne
Method:find
Parameters:long long
Returns:string
Method signature:string find(long long n)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.


EXAMPLES

0)
6

Returns: "John"

John has two possible moves: either decrease 6 by 2 or decrease 6 by 3.
If he chooses the second option, Brus will have no possible moves, hence John will win the game.

1)
2

Returns: "Brus"



2)
747

Returns: "Brus"



3)
128

Returns: "Brus"



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


class TheNumberGameDivOne {
public:
  string find (long long n) {
    string ret=string("Brus");
    if(!(n&1)){
			LL m=n;
			while(m){
				if(m==2)return ret;
				if(m%4)break;
				m/=4;
			}return string("John");
    }else return ret;
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
			long long n               = 6LL;
			string expected__         = "John";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			long long n               = 2LL;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			long long n               = 747LL;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			long long n               = 128LL;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			long long n               = LL;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			long long n               = LL;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			long long n               = LL;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find( n );
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
