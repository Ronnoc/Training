// Paste me into the FileEdit configuration dialog

#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmax(x,y) x=max((x),(y))
#define cmin(x,y) x=min((x),(y))

typedef long long LL;
typedef pair<int,int> PII;

const int MOD = 1000000007;
class CarrotJumping {
public:
	int theJump( int t ) {
		if(t%MOD==0)return 0;
		int cnt=0;
		while((t%MOD||cnt<=1)&&cnt<=600000){
			t=t+t+1;
			if(t>=MOD)t-=MOD;
			cnt++;
		}
		if(t%MOD)return -1;
		else {
			int ret;
			if(cnt%3==0)
				ret=cnt/3;
			if(cnt%3==1)
				ret=cnt/3+1;
			if(cnt%3==2)
				ret=cnt/3+1;
			return ret<=100000?ret:-1;
		}
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
			int init                  = 125000000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int init                  = 281250001;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int init                  = 18426114;
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int init                  = 4530664;
			int expected__            = 478;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int init                  = 705616876;
			int expected__            = 100000;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int init                  = 852808441;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int init                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int init                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int init                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarrotJumping().theJump( init );
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
