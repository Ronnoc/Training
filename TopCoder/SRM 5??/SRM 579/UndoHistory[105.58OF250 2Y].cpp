// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Bob is using a peculiar text editor to write a sequence of lines of text.
The editor consists of three parts: a results window, a text buffer and an undo history.
More details about the three parts follow.

The results window contains a sequence of strings: the lines of text you already wrote. Initially, the results window is empty.
The text buffer contains a string: the line you are writing at the moment. Initially, the string in the text buffer is empty.
The undo history contains a sequence of strings: all the past states of the text buffer. Initially, the undo history contains a single element: an empty string.


You are given a vector <string> lines.
Bob would like to print the contents of lines into the results window.
(At the end, the sequence of strings stored in the results window must be precisely equal to lines. Order of elements matters.)
Additionally, Bob would like to do so as quickly as possible.
He is able to take the following actions:


Bob may type a lowercase letter. The letter is appended to the text buffer. The new text buffer is then added as a new element of the undo history. (For example, if the text buffer currently contains "do", then pressing 'g' changes the text buffer to "dog" and then stores "dog" into the undo history.)
Bob may press Enter. When he does so, the current content of the text buffer is printed to the results window as a new line, after the lines that were printed earlier. The text buffer remains unmodified. (For example, if the text buffer contains "dog" and Bob presses Enter, "dog" will be appended to the results window, and the results buffer still contains "dog".)
Bob may use two mouse clicks to restore any entry from the undo history to the text buffer. This operation does not modify the undo history.


Return the minimum total number of button presses (keyboard and mouse) that Bob needs to print all the given lines into the results window.

DEFINITION
Class:UndoHistory
Method:minPresses
Parameters:vector <string>
Returns:int
Method signature:int minPresses(vector <string> lines)


CONSTRAINTS
-lines will contain between 1 and 50 elements, inclusive.
-Each element of lines will contain between 1 and 50 characters, inclusive.
-Each element of lines will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"tomorrow", "topcoder"}

Returns: 18


Type 't'. The text buffer now contains "t", and the undo history now contains "" and "t".
Type 'o'. The text buffer now contains "to", and the undo history now contains "", "t", and "to".
Using six more keypresses, type the letters in "morrow". The text buffer now contains "tomorrow" and the undo history contains all prefixes of "tomorrow". The results window is still empty.
Press Enter. The results window now contains one string: "tomorrow".
Click the mouse twice to restore "to" from undo history.
Using another six keypresses, type the letters in "pcoder".
Press Enter. The results window now contains "tomorrow" and "topcoder", in this order, and we are done.

The total number of button presses was 8 (typing "tomorrow") + 1 (Enter) + 2 (mouse) + 6 (typing "pcoder") + 1 (Enter) = 18.

1)
{"a","b"}

Returns: 6

After typing "a" and pressing enter, we need to restore the empty string (which is always present at the top of the undo buffer) before typing "b".

2)
{"a", "ab", "abac", "abacus" }

Returns: 10

There are times when it is not necessary to use the undo history at all.

3)
{"pyramid", "sphinx", "sphere", "python", "serpent"}

Returns: 39



4)
{"ba","a","a","b","ba"}

b,a,..,a,..,a
Returns: 13



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


class UndoHistory {
public:
	int minPresses (vector <string> li) {
		int ret=0;
		int i,j,k;
		ret+=li[0].SZ;
		for(i=1;i<li.SZ;i++){
			int len=-1,id=-1,now=0,p=i-1;
			for(j=0;j<i;j++){
				for(k=0;k<li[j].SZ&&k<li[i].SZ;k++)
					if(li[j][k]!=li[i][k])break;
				if(k>=len){
					len=k;
					id=j;
				}
			}
			for(k=0;k<li[p].SZ&&k<li[i].SZ;k++)
					if(li[p][k]!=li[i][k])break;
			now=k;
			if(now==li[p].SZ)
				ret+=min(li[i].SZ-li[p].SZ,2+li[i].SZ-len);
			else ret+=2+li[i].SZ-len;
		}
		return ret+li.SZ;
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

int verify_case (int casenum, const int &expected, const int &received, clock_t elapsed) {
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
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				string lines[]            = {"tomorrow", "topcoder"};
				int expected__            = 18;
				
				clock_t start__           = clock();
				int received__            = UndoHistory().minPresses (vector <string> (lines, lines + (sizeof lines / sizeof lines[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string lines[]            = {"a","b"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = UndoHistory().minPresses (vector <string> (lines, lines + (sizeof lines / sizeof lines[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string lines[]            = {"a", "ab", "abac", "abacus" };
				int expected__            = 10;
				
				clock_t start__           = clock();
				int received__            = UndoHistory().minPresses (vector <string> (lines, lines + (sizeof lines / sizeof lines[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string lines[]            = {"pyramid", "sphinx", "sphere", "python", "serpent"};
				int expected__            = 39;
				
				clock_t start__           = clock();
				int received__            = UndoHistory().minPresses (vector <string> (lines, lines + (sizeof lines / sizeof lines[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				string lines[]            = {"ba","a","a","b","ba"} ;
				int expected__            = 13;
				
				clock_t start__           = clock();
				int received__            = UndoHistory().minPresses (vector <string> (lines, lines + (sizeof lines / sizeof lines[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
		case 5: {
				string lines[]            = {"asdef","asd","asde"};
				int expected__            = 11;
				
				clock_t start__           = clock();
				int received__            = UndoHistory().minPresses (vector <string> (lines, lines + (sizeof lines / sizeof lines[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
						case 6: {
						string lines[]            = {"asdgef","asd","asdgef"};
						int expected__            = 13;
			
						clock_t start__           = clock();
						int received__            = UndoHistory().minPresses( vector <string>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}
			/*      case 7: {
						string lines[]            = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = UndoHistory().minPresses( vector <string>( lines, lines + ( sizeof lines / sizeof lines[0] ) ) );
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
