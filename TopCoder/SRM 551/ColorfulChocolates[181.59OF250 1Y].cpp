// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Beaver Bindu has some chocolates arranged in a row.
The wrapping of each chocolate has a single color.
Multiple chocolates can share the same color.
In this problem, each of the possible colors is represented by an uppercase letter.
You are given a string chocolates.
For each i, the i-th chocolate (0-based index) in the row has the color chocolates[i].


The spread of a row of chocolates is the maximum number of adjacent chocolates that all share the same color.
Formally, the spread can be defined as the maximum value of (j-i+1), where i <= j and all the chocolates in the positions between i and j, inclusive, have the same color.


You are also given an int maxSwaps.
Bindu can swap any two adjacent chocolates.
She has decided to make at most maxSwaps such swaps.


Return the maximum spread she can obtain.


DEFINITION
Class:ColorfulChocolates
Method:maximumSpread
Parameters:string, int
Returns:int
Method signature:int maximumSpread(string chocolates, int maxSwaps)


CONSTRAINTS
-chocolates will contain between 1 and 50 characters, inclusive.
-Each character in chocolates will be an uppercase letter ('A'-'Z').
-maxSwaps will be between 1 and 2500, inclusive.


EXAMPLES

0)
"ABCDCBC"
1

Returns: 2

One optimal solution is to swap chocolates at positions 2 and 3, obtaining the row "ABDCCBC", which has spread 2.


1)
"ABCDCBC"
2

Returns: 3

The only optimal solution is to produce the row "ABDCCCB".


2)
"ABBABABBA"
3

Returns: 4

The row "ABBBBAABA" can be produced with 3 swaps.

3)
"ABBABABBA"
4

Returns: 5

An optimal solution is to produce the row "AABBBBBAA".

4)
"QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"
77

Returns: 5

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


class ColorfulChocolates {
public:
  int maximumSpread (string c, int ms) {
  	cout<<c<<" "<<ms<<endl;
//  	system("pause");
    int ret=0;
    int i,j,k,ii;
    for(ii=0;ii<26;ii++){
			vector<int>L;
			for(j=0;j<c.SZ;j++)if(c[j]==ii+'A')L.PB(j);
			for(i=0;i<c.SZ;i++){
				for(j=0;j<L.SZ;j++){
					int used=abs(L[j]-i);
					int to=i+1;
					for(k=j+1;to<c.SZ&&k<L.SZ;k++){
						used+=abs(L[k]-to);
						to++;
						if(used>ms)break;
					}
//					if(k-j==3)cout<<L[j]<<" "<<j<<" "<<k<<endl;
					ret=max(ret,k-j);
				}
			}
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
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string chocolates         = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
			int maxSwaps              = 77;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread( chocolates, maxSwaps );
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
