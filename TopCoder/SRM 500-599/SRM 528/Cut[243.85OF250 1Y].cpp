// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Ciel wants to eat eels as a celebration of this year's end.

Initially, Ciel has some eels of various lengths. She only likes to eat eels of length exactly 10, no more, no less.
Before she eats, she may cut the eels to prepare pieces of desired length. However, she only has the time to make at most maxCuts cuts. A single cut looks as follows:

Fox Ciel chooses one of the eels. Let its length be x. She can only choose an eel of length greater than 1.
She chooses an integer y such that 0 < y < x.
She cuts the eel into two pieces so that one of them measures exactly y.
In other words, instead of one eel of length x she now has two eels of lengths y and (x-y), respectively.


You are given a vector <int> eelLengths. Each element of eelLengths is the length of one of the eels Ciel has at the beginning.
You are also given the int maxCuts.
Return the maximum number of eels of length exactly 10 she can produce.

DEFINITION
Class:Cut
Method:getMaximum
Parameters:vector <int>, int
Returns:int
Method signature:int getMaximum(vector <int> eelLengths, int maxCuts)


CONSTRAINTS
-eelLengths will contain between 1 and 50 elements, inclusive.
-Each element of eelLengths will be between 1 and 1,000, inclusive.
-maxCuts will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{13, 20, 13}
2

Returns: 3

One optimal solution looks as follows:

First, cut eel 0 into two pieces of lengths 10 and 3. Next, cut eel 1 into two equal parts of length 10 each. This produces a total of 3 eels whose length is 10.



1)
{5, 5, 5, 5}
2

Returns: 0

There are four eels whose length is 5.
As you cannot combine eels, it is impossible to make an eel of length 10.

2)
{34, 10, 48}
4

Returns: 5

She already has one eel of length 10. By cutting the other two eels she can produce four more eels of the desired length.

3)
{30, 50, 30, 50}
350

Returns: 16

She may cut eels at most 350 times, but in this case she doesn't have to cut them so many times.

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


class Cut {
public:
  int getMaximum (vector <int> a, int m) {
    int ret=0;
    vector<int>l,r;
    for(int i=0;i<a.SZ;i++)if(a[i]%10)l.PB(a[i]);else r.PB(a[i]);
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    for(int i=0;i<r.SZ;i++){
			if(r[i]==10){ret++;}
			else {
				while(m&&r[i]>10){ret++;m--;r[i]-=10;}
				if(r[i]==10)ret++;
			}
    }
    for(int i=0;i<l.SZ;i++){
			while(l[i]>10&&m){m--;l[i]-=10;ret++;}
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
			int eelLengths[]          = {13, 20, 13};
			int maxCuts               = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int eelLengths[]          = {5, 5, 5, 5};
			int maxCuts               = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int eelLengths[]          = {34, 10, 48};
			int maxCuts               = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int eelLengths[]          = {30, 50, 30, 50};
			int maxCuts               = 350;
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int eelLengths[]          = ;
			int maxCuts               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int eelLengths[]          = ;
			int maxCuts               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int eelLengths[]          = ;
			int maxCuts               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Cut().getMaximum( vector <int>( eelLengths, eelLengths + ( sizeof eelLengths / sizeof eelLengths[0] ) ), maxCuts );
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
