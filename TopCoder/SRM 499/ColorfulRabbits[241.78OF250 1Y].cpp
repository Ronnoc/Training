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

map<int,int>S;
map<int,int>::iterator it;
class ColorfulRabbits {
public:
  int getMinimum (vector <int> r) {
    int ret=0;
    int i;
    S.clear();
    for(i=0;i<r.SZ;i++)S[r[i]]++;
    for(it=S.OP;it!=S.ED;++it){
			int a=(*it).AA;
			int b=(*it).BB;
			int add=0;
			cout<<a<<" "<<b<<" ";
			while(b>0){
				add+=a+1;
				b-=a+1;
			}
			ret+=add;
			cout<<add<<endl;
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
			int replies[]             = { 1, 1, 2, 2 } ;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum( vector <int>( replies, replies + ( sizeof replies / sizeof replies[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int replies[]             = { 0 } ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum( vector <int>( replies, replies + ( sizeof replies / sizeof replies[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int replies[]             = { 2, 2, 44, 2, 2, 2, 444, 2, 2 } ;
			int expected__            = 499;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum( vector <int>( replies, replies + ( sizeof replies / sizeof replies[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int replies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum( vector <int>( replies, replies + ( sizeof replies / sizeof replies[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int replies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum( vector <int>( replies, replies + ( sizeof replies / sizeof replies[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int replies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum( vector <int>( replies, replies + ( sizeof replies / sizeof replies[0] ) ) );
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
