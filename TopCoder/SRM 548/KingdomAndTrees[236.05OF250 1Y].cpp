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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.begin(),X.end())
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

vector<int>h;
bool check(LL X){
	vector<LL>L;
	int i;
	for(i=0;i<h.SZ;i++)L.PB(h[i]);
	L[0]=max(1LL,L[0]-X);
	for(i=1;i<L.SZ;i++){
		LL l=L[i]-X;
		LL r=L[i]+X;
		if(L[i-1]+1<=r){
			if(L[i-1]+1>=l)L[i]=L[i-1]+1;
			else L[i]=l;
		}
		else return 0;
	}
	return 1;
}
class KingdomAndTrees {
public:
	int minLevel ( vector <int> hh ) {
		h=hh;
		int ret;
		LL l=0,r=2000000000;
		while(r>=l){
			if(r-l<=1){
				if(check(l))ret=int(l);
				else ret=int(r);
				break;
			}
			LL mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid;
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
			int heights[]             = {9, 5, 11};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int heights[]             = {5, 8};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int heights[]             = {1, 1, 1, 1, 1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int heights[]             = {548, 47, 58, 250, 2012};
			int expected__            = 251;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomAndTrees().minLevel( vector <int>( heights, heights + ( sizeof heights / sizeof heights[0] ) ) );
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
