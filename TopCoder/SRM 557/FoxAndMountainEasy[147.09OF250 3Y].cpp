// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Ciel lives in a beautiful countryside.
She loves climbing mountains.
Yesterday, she went hiking in the mountains.



Her trip can be described as a sequence of (n+1) integers: h[0], h[1], ..., h[n].
These values represent altitudes visited by Fox Ciel during the trip, in order.
Fox Ciel does not remember the precise sequence, but she remembers the following:

for each i, h[i] >= 0
h[0] = h0
h[n] = hn
for each i, abs(h[i+1]-h[i]) = 1




The last condition means that in each step the altitude of Fox Ciel either increased by 1, or decreased by 1.
We will call the two types of steps "steps up" and "steps down", respectively.
Steps up will be denoted 'U' and steps down will be denoted 'D'.



You are given the ints n, h0, and hn: the length of the trip, the altitude at the beginning, and the altitude at the end.
In addition to these, Fox Ciel remembers some contiguous segment of her trip.
You are given this segment as a string history.
Each character of history is either 'U' or 'D'.



Check whether there is a valid trip that matches everything Fox Ciel remembers.
Return "YES" (quotes for clarity) if there is at least one such trip, or "NO" if there is none.

DEFINITION
Class:FoxAndMountainEasy
Method:possible
Parameters:int, int, int, string
Returns:string
Method signature:string possible(int n, int h0, int hn, string history)


CONSTRAINTS
-n will be between 1 and 100,000, inclusive.
-history will contain between 1 and min(50,n) characters, inclusive.
-Each character in history will be either 'U' or 'D'.
-h0 will be between 0 and 100,000, inclusive.
-hn will be between 0 and 100,000, inclusive.


EXAMPLES

0)
4
0
4
"UU"

Returns: "YES"

The only solution is: h[] = {0, 1, 2, 3, 4}, the history of the entire trip will be "UUUU".

1)
4
0
4
"D"

Returns: "NO"

Based on n, h0 and hn, the history of the entire trip must be "UUUU". There is no 'D' in this history.

2)
4
100000
100000
"DDU"

Returns: "YES"

We have the following solution: h[] = {100000, 100001, 100000, 99999, 100000}, the history of the entire trip is "UDDU".

3)
4
0
0
"DDU"

Returns: "NO"



4)
20
20
20
"UDUDUDUDUD"

Returns: "YES"



5)
20
0
0
"UUUUUUUUUU"

Returns: "YES"



6)
20
0
0
"UUUUUUUUUUU"

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


class FoxAndMountainEasy {
public:
	string possible (int n, int h0, int hn, string h) {
		cout<<n<<" "<<h0<<" "<<hn<<" "<<h<<endl;
		if (n&1) if (h0%2==hn%2) return "NO";
		if (n&1); else if (h0%2!=hn%2) return "NO";
		string ret="";
		int hh=0,i,mn=0;
		for (i=0; i<h.SZ; i++) {
			if (h[i]=='U') hh++; else hh--;
			mn=min(mn,hh);
		}
		while (h0+mn<0) ret+="U",h0++;
		ret+=h;
		h0+=hh;
		while (h0<hn) ret+="U",h0++;
		while (h0>hn) ret+="D",h0--;
		if (ret.SZ<=n) return "YES";
		return "NO";
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case (int);
void run_test (int casenum = -1, bool quiet = false) {
	if (casenum != -1) {
		if (run_test_case (casenum) == -1 && !quiet)
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for (int i=0;; ++i) {
		int x = run_test_case (i);
		if (x == -1) {
			if (i >= 100) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if (total == 0) {
		cerr << "No test cases run." << endl;
	} else if (correct < total) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case (int casenum, const string &expected, const string &received, clock_t elapsed) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if (elapsed > CLOCKS_PER_SEC / 200) {
		sprintf (buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
		info.push_back (buf);
	}
	
	if (expected == received) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if (!info.empty()) {
		cerr << " (";
		for (int i=0; i< (int) info.size(); ++i) {
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

int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				int n                     = 4;
				int h0                    = 0;
				int hn                    = 4;
				string history            = "UU";
				string expected__         = "YES";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				int n                     = 4;
				int h0                    = 0;
				int hn                    = 4;
				string history            = "D";
				string expected__         = "NO";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				int n                     = 4;
				int h0                    = 100000;
				int hn                    = 100000;
				string history            = "DDU";
				string expected__         = "YES";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				int n                     = 4;
				int h0                    = 0;
				int hn                    = 0;
				string history            = "DDU";
				string expected__         = "NO";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				int n                     = 20;
				int h0                    = 20;
				int hn                    = 20;
				string history            = "UDUDUDUDUD";
				string expected__         = "YES";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 5: {
				int n                     = 20;
				int h0                    = 0;
				int hn                    = 0;
				string history            = "UUUUUUUUUU";
				string expected__         = "YES";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 6: {
				int n                     = 20;
				int h0                    = 0;
				int hn                    = 0;
				string history            = "UUUUUUUUUUU";
				string expected__         = "NO";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
		case 7: {
				int n                     = 15046;
				int h0                    = 8;
				int hn                    = 6060;
				string history            = "DDDDDDDDUUUUUUUUUUDDUUDDDDDUDUDDDUDDDUDDUDUDDD";
				string expected__         = "YES";
				
				clock_t start__           = clock();
				string received__         = FoxAndMountainEasy().possible (n, h0, hn, history);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			/*      case 8: {
						int n                     = ;
						int h0                    = ;
						int hn                    = ;
						string history            = ;
						string expected__         = ;
			
						clock_t start__           = clock();
						string received__         = FoxAndMountainEasy().possible( n, h0, hn, history );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 9: {
						int n                     = ;
						int h0                    = ;
						int hn                    = ;
						string history            = ;
						string expected__         = ;
			
						clock_t start__           = clock();
						string received__         = FoxAndMountainEasy().possible( n, h0, hn, history );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
		default:
			return -1;
	}
}
}


int main (int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test (atoi (argv[i]));
	}
}
// END CUT HERE
