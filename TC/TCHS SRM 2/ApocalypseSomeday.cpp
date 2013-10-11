// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The number 666 is considered to be the occult "number of the beast" and is a well used number in all major apocalypse themed blockbuster movies. However the number 666 can't always be used in the script so numbers such as 1666 are used instead. Let us call the numbers containing at least three contiguous sixes beastly numbers. The first few beastly numbers are 666, 1666, 2666, 3666, 4666, 5666...

Given a 1-based index n, your program should return the n-th beastly number.

DEFINITION
Class:ApocalypseSomeday
Method:getNth
Parameters:int
Returns:int
Method signature:int getNth(int n)


CONSTRAINTS
-n will be between 1 and 10000, inclusive


EXAMPLES

0)
2

Returns: 1666

1)
3

Returns: 2666

2)
6

Returns: 5666

3)
187

Returns: 66666

4)
500

Returns: 166699

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

typedef long long LL;
typedef pair<int, int> PII;


class ApocalypseSomeday {
public:
  int getNth (int n) {
		vector<int>ans;
		int i;
		for(i=666;ans.size()<n;i++){
			char s[1111];
			sprintf(s,"%d",i);
			int len=strlen(s);
			int flag=0;
			int j;
			for(j=0;j+2<len;j++)if(s[j]=='6'&&s[j+1]=='6'&&s[j+2]=='6'){flag=1;break;}
			if(flag)ans.PB(i);//,cout<<i<<endl;
		}
    return int(ans.back());
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
			int n                     = 2;
			int expected__            = 1666;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 3;
			int expected__            = 2666;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 6;
			int expected__            = 5666;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 187;
			int expected__            = 66666;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 500;
			int expected__            = 166699;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ApocalypseSomeday().getNth( n );
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
