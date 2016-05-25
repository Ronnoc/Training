// BEGIN CUT HERE
/*
PROBLEM STATEMENT

This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

Little Rudolph had an important sequence of positive integers. The sequence consisted of N positive integers a0, a1, .., aN-1.

Rudolph wrote the sequence onto the blackboard in the classroom. While Rudolph had gone out, little Arthur came into the classroom and saw the sequence. Arthur likes to play with numbers as much as he likes to give his friends puzzles. So he did the following:

First, he wrote a '+' or a '-' between each pair of consecutive numbers (possibly using different signs for different pairs of numbers).
	
Next, for each sign he computed the result of the corresponding operation and wrote it under the sign.
I.e., if he used the '+' sign between ai and ai+1, he would write the sum ai+ai+1 under this '+' sign.
Similarly, if he used the '-' sign between ai and ai+1, he would write the difference ai-ai+1. In this way he obtained a new sequence of N-1 numbers b0, b1, .., bN-2.
Finally, he erased the original sequence. Now there was only the operator sequence o0, o1, .., oN-2 and the resulting number sequence b0, b2, .., bN-2 left on the blackboard.

For example, if the original sequence was {1, 2, 3, 4}, and Arthur wrote operators {+, -, +}, then the content of the blackboard changed like this:

1   2   3   4    ->    1 + 2 - 3 + 4    ->    1 + 2 - 3 + 4    ->     +  -  +
                                                3  -1   7             3 -1  7

When Rudolph returned, he was shocked as his important sequence had disappeared. Arthur quickly told him what operations he had performed and that Rudolph has to simply reconstruct the orginal sequence.

Unfortunately, little Arthur did not realize that it is not necessarily possible to determine the original sequence uniquely. For example, both original sequences {1, 2, 3, 4} and {2, 1, 2, 5} lead to the same sequence {3, -1, 7} when operator sequence is {+, -, +}.

The only thing Rudolph remembers about his original sequence is that all the integers were positive. Rudolph now wants to count all sequences of positive integers that match the blackboard. You are given vector <int> B and string operators  both containing N-1 elements. The i-th element of B is the number bi and i-th element of operators will be '+' or '-', meaning that the i-th operator is + or -, respectively. Return the number of different positive integer sequences A that lead to sequence B when operators operators are used in the way described. If there are infinitely many such sequences, return -1. Note that there may be test cases where no valid sequence A exists. For such test cases the correct return value is 0.

DEFINITION
Class:ImportantSequence
Method:getCount
Parameters:vector <int>, string
Returns:int
Method signature:int getCount(vector <int> B, string operators)


NOTES
-It is guaranteed that the correct answer will always fit into the 32-bit signed integer type.
-The integer 0 (zero) is not positive. It may not occur in Rudolph's original sequence.


CONSTRAINTS
-B will contain between 1 and 50 elements, inclusive.
-operators will contain the same number of characters as the number of elements in B.
-Each element of B will be between -1000000000 (-109) and 1000000000 (109), inclusive.
-Each character in operators will be either '+' or '-' (quotes for clarity).


EXAMPLES

0)
{3, -1, 7}
"+-+"

Returns: 2

From the problem statement.

1)
{1}
"-"

Returns: -1

There are infinitely many pairs of positive integers that differ by one.

2)
{1}
"+"

Returns: 0

Note that all numbers ai have to be positive integers.

3)
{10}
"+"

Returns: 9

4)
{540, 2012, 540, 2012, 540, 2012, 540}
"-+-+-+-"

Returns: 1471

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


class ImportantSequence {
public:
  int getCount (vector <int> B, string s) {
    int ret=-1;
    int i;
    int sign[55];
    LL add[55];
    LL ts=1,ta=0;
    for(i=0;i<s.SZ;i++){
			if(s[i]=='-'){
				sign[i]=ts;
				ta-=B[i];
				add[i]=ta;
			}else {
				ts*=-1;
				sign[i]=ts;
				ta=-ta+B[i];
				add[i]=ta;
			}
			printf(" %cx+(%I64d)\n",ts>0?'+':'-',ta);
    }
    LL lb=1;
    LL rb=20000000000011LL;
    for(i=0;i<s.SZ;i++){
			if(sign[i]>0)lb=max(lb,1LL-add[i]);
			else rb=min(rb,add[i]-1LL);
    }
    if(rb<lb)return 0;
    if(rb==20000000000011LL)return -1;
    return int(rb-lb)+1;
  }
};

// BEGIN CUT HERE
/*
{7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311}, "-------+--"}

*/
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
			int B[]                   = {3, -1, 7};
			string operators          = "+-+";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int B[]                   = {1};
			string operators          = "-";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int B[]                   = {1};
			string operators          = "+";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int B[]                   = {10};
			string operators          = "+";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int B[]                   = {540, 2012, 540, 2012, 540, 2012, 540};
			string operators          = "-+-+-+-";
			int expected__            = 1471;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int B[]                   = {7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311};
			string operators          = "-------+--";
			int expected__            = 999994453;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount( vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), operators );
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
