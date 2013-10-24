// BEGIN CUT HERE
/*
PROBLEM STATEMENT

After selling goods all day, a salesman would like to determine the most desirable item in his inventory. You are given a vector <string> items, each element of which represents a single item that was sold during the day. Return the item that was sold the most number of times. In case of a tie, return the item that comes first alphabetically.



DEFINITION
Class:BestSeller
Method:findBestSeller
Parameters:vector <string>
Returns:string
Method signature:string findBestSeller(vector <string> items)


CONSTRAINTS
-items will contain between 1 and 50 elements, inclusive.
-Each element of items will contain between 1 and 50 characters, inclusive.
-Each element of items will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"table", "chair", "table", "table", "lamp", "door", "lamp", "table", "chair"}

Returns: "table"

The salesman sold four "table"s, two "chair"s, two "lamp"s, and one "door".  The "table" is his best-selling item.

1)
{"a", "a", "a", "b", "b", "b"}

Returns: "a"

There is a tie between "a" and "b", "a" is returned, because it comes first alphabetically.

2)
{"icecream", "peanuts", "peanuts", "chocolate", "candy", "chocolate", "icecream", "apple"}

Returns: "chocolate"

The salesman sold two of each of these items: "icecream", "peanuts", and "chocolate".  Since there is a tie, "chocolate" is returned because it comes first alphabetically. "apple" comes even earlier, but only tied items are considered.

3)
{"soul"}

Returns: "soul"

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
#define OP begin()
#define ED end()
typedef long long LL;
typedef pair<int, int> PII;


class BestSeller {
public:
  string findBestSeller (vector <string> items) {
		vector<string>L;
		int i,j;
		for(i=0;i<items.size();i++)L.PB(items[i]);
		sort(L.OP,L.ED);
		L.erase(unique(L.OP,L.ED),L.ED);
		int tot[111];
		memset(tot,0,sizeof tot);
		int ans=0,pans;
		for(j=0;j<L.size();j++){
				for(i=0;i<items.size();i++)if(items[i]==L[j])tot[j]++;
			if(tot[j]>ans)ans=tot[j],pans=j;
		}
    return L[pans];
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
			string items[]            = {"table", "chair", "table", "table", "lamp", "door", "lamp", "table", "chair"};
			string expected__         = "table";

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string items[]            = {"a", "a", "a", "b", "b", "b"};
			string expected__         = "a";

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string items[]            = {"icecream", "peanuts", "peanuts", "chocolate", "candy", "chocolate", "icecream", "apple"};
			string expected__         = "chocolate";

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string items[]            = {"soul"};
			string expected__         = "soul";

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			string items[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			string items[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string items[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BestSeller().findBestSeller( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
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
