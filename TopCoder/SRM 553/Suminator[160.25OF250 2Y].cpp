// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Suminator is a very limited programming language.
A program in this language is simply a sequence of nonnegative integers.
The program is evaluated using a stack of nonnegative integers.
Initially, the stack is empty.
Trying to pop an element from an empty stack returns a zero.
(Alternately, you can imagine that the stack already contains a sufficient number of zeros in the beginning.)

A Suminator program is evaluated using the following algorithm:

for i = 0 to length(program) - 1 {
    if ( program[i] is 0) {
         Pop the top two elements from the stack, add them together
         and push the result to the top of the stack.
    } else {
         Push program[i] to the top of the stack.
    }
}
Pop the top element of the stack and print it.

For example, when executing the program {1}, we first push the 1 to the stack, and then we print it.
When executing the program {5,0,1,2,0}, we take the following steps:

We push the 5 to the top of the stack.
We pop the top two elements (5 and 0), add them together and push the result (5).
We push the 1 to the top of the stack.
We push the 2 to the top of the stack. At this moment, the stack contains the values 5, 1, and 2 (from bottom to top).
We pop the top two elements (2 and 1), add them together and push the result (3).
We print the top element of the stack: the number 3. Note that the stack also contains the value 5, which is ignored.


You are given a vector <int> program containing a Suminator program (a sequence of nonnegative integers), in which one of the elements of the sequence was changed to -1.
You are also given a int wantedResult.
Your task is to change the -1 back to a nonnegative integer X in such a way that the resulting program prints the number wantedResult.
Return X.
If there are multiple possible values of X, return the smallest one.
If there is no way to make the program print wantedResult, return -1 instead.

DEFINITION
Class:Suminator
Method:findMissing
Parameters:vector <int>, int
Returns:int
Method signature:int findMissing(vector <int> program, int wantedResult)


NOTES
-The return value always fits into an int. This follows from the constraints and the nature of the problem.


CONSTRAINTS
-program will contain between 1 and 50 elements, inclusive.
-Each element of program will be between -1 and 1000000000 (10^9), inclusive.
-program will contain -1 exactly once.
-wantedResult will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{7,-1,0}
10

Returns: 3



1)
{100, 200, 300, 0, 100, -1}
600

Returns: 0



2)
{-1, 7, 3, 0, 1, 2, 0, 0}
13

Returns: 0

We can replace the first element with many other values, but 0 is the smallest that achieves the wanted result.

3)
{-1, 8, 4, 0, 1, 2, 0, 0}
16

Returns: -1

It does not matter what value we use in the first element of the array, the result will always be 15.

4)
{1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}
1000000000

Returns: -1

It does not matter what we replace the -1 with, the result will be larger than 1000000000.

5)
{7, -1, 3, 0}
3

Returns: -1



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

LL solve (vector<int>p) {
	stack<LL>S;
	for (int i=0; i<p.SZ; i++) S.push (0),S.push (0),S.push (0);
	for (int i=0; i<p.SZ; i++) {
		if (p[i]==0) {
			LL u=S.top(); S.pop();
			LL v=S.top(); S.pop();
			S.push (u+v);
		} else S.push (p[i]);
	}
	return S.top();
}
class Suminator {
public:
	int findMissing (vector <int> p, int wr) {
		int ret=-47;
		int id=-1,i,j;
		for (i=0; i<p.SZ; i++) if (p[i]==-1) id=i;
		p[id]=0;
		if (solve (p) ==wr) return 0;
		LL f1,f2;
		p[id]=1;
		f1=solve (p);
		if (f1==wr) return 1;
		p[id]=2;
		f2=solve (p);
		if (f2==wr) return 2;
		LL df=f2-f1;
		cout<<f1<<" "<<f2<<" "<<wr<<endl;
		if (df==0) return -1;
		if (wr<f1) return -1;
		if ( (wr-f1) %df) return -1;
		int xx= (wr-f1) /df;
		if (1+xx>1000000000) return -1;
		p[id]=1+xx;
		if (solve (p) ==wr) return p[id];
		else return -1;
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
				int program[]             = {7,-1,0};
				int wantedResult          = 10;
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				int program[]             = {100, 200, 300, 0, 100, -1};
				int wantedResult          = 600;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				int program[]             = {-1, 7, 3, 0, 1, 2, 0, 0};
				int wantedResult          = 13;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				int program[]             = {-1, 8, 4, 0, 1, 2, 0, 0};
				int wantedResult          = 16;
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				int program[]             = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
				int wantedResult          = 1000000000;
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 5: {
				int program[]             = {7, -1, 3, 0};
				int wantedResult          = 3;
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
		case 6: {
				int program[]             = {845151429, 60888921, 349419441, 452722179, 698157266, 589688000, 0, 0, 614020210, 917738413, 0, 0, 984300555, 785675697, 623438381, 865773912, -1, 0, 0, 202538864, 576905676, 0, 320406658, 0, 634482942, 379832022, 241814338, 0, 0, 0, 0, 0, 815856524, 588150990, 672632541, 704357226, 0, 0, 205398249, 0, 0, 0, 0};
				int wantedResult          = 122233108;
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = Suminator().findMissing (vector <int> (program, program + (sizeof program / sizeof program[0])), wantedResult);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			/*      case 7: {
						int program[]             = ;
						int wantedResult          = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof program[0] ) ), wantedResult );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 8: {
						int program[]             = ;
						int wantedResult          = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof program[0] ) ), wantedResult );
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
