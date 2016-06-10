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

class BigFatInteger {
public:
	int minOperations ( int A, int B ) {
		int ret;
		vector<pair<LL,LL> >S;
		LL i;
		for(i=2;i<=A;i++){
			if(A%i)continue;
			LL cnt=0;
			while(A%i==0){A/=i;cnt++;}
			S.PB(MP(i,cnt*B));
		}
//		for(i=0;i<S.SZ;i++)cout<<S[i].AA<<"|"<<S[i].BB<<endl;
		ret=S.size();
		vector<int>L;
		for(i=0;i<S.SZ;i++){
			int tp=0;
			LL x=S[i].BB;
			LL now=1;
			while(now<x){
				if(2*now<=x)now*=2;
				else now+=x-now;
				tp++;
			}
			L.PB(-tp);
		}
		SORT(L);
		ret+=-L[0];
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
			int A                     = 6;
			int B                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int A                     = 162;
			int B                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int A                     = 999983;
			int B                     = 9;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int A                     = 360;
			int B                     = 8;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			int A                     = 12;
			int B                     = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 5: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BigFatInteger().minOperations( A, B );
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
