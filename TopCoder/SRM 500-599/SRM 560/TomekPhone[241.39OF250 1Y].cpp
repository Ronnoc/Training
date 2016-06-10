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

class TomekPhone {
public:
	int minKeystrokes ( vector <int> f, vector <int> ks ) {
		int ret=0,i;
		priority_queue<PII>pQ;
		for(i=0;i<ks.SZ;i++)pQ.push(MP(-1,ks[i]));
		int flag=1;
		sort(f.rbegin(),f.rend());
		for(i=0;i<f.SZ;i++){
			if(!pQ.empty()){
				PII tp=pQ.top();
				pQ.pop();
				ret+=-tp.AA*f[i];
				if(-tp.AA+1<=tp.BB)pQ.push(MP(tp.AA-1,tp.BB));
			}
			else flag=0;
		}
		if(flag)
			return ret;
		else return -1;
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
			int frequencies[]         = {7,3,4,1};
			int keySizes[]            = {2,2};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int frequencies[]         = {13,7,4,20};
			int keySizes[]            = {2,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int frequencies[]         = {11,23,4,50,1000,7,18};
			int keySizes[]            = {3,1,4};
			int expected__            = 1164;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int frequencies[]         = {100,1000,1,10};
			int keySizes[]            = {50};
			int expected__            = 1234;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int frequencies[]         = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			int keySizes[]            = {10,10,10,10,10,10,10,10};
			int expected__            = 3353;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int frequencies[]         = ;
			int keySizes[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int frequencies[]         = ;
			int keySizes[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int frequencies[]         = ;
			int keySizes[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TomekPhone().minKeystrokes( vector <int>( frequencies, frequencies + ( sizeof frequencies / sizeof frequencies[0] ) ), vector <int>( keySizes, keySizes + ( sizeof keySizes / sizeof keySizes[0] ) ) );
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
