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

LL play(LL k,LL a,LL c){
	LL p=c/k,q=c%k;//c=pk+q
	LL r1=fabs(p-a)+q;
	LL r2=fabs(p+1-a)+k-q;
	return c>q?min(r1,r2):r2;
}
class CorrectMultiplication {
public:
	long long getMinimum( int a, int b, int c ) {
		int i,j,k;
		long long ret=a-1LL+b-1LL+c-1LL;
		for(i=1;i<=200000;i++){
			LL ta=fabs(a-i)+play(i,b,c);
			LL tb=fabs(b-i)+play(i,a,c);
			cmin(ret,ta);
			cmin(ret,tb);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int a                     = 19;
			int b                     = 28;
			int c                     = 522;
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a                     = 10;
			int b                     = 30;
			int c                     = 500;
			long long expected__      = 11LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a                     = 11111;
			int b                     = 11111;
			int c                     = 123454321;
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a                     = 1000;
			int b                     = 100;
			int c                     = 10;
			long long expected__      = 1089LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a                     = 399;
			int b                     = 522;
			int c                     = 199999;
			long long expected__      = 24LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = CorrectMultiplication().getMinimum( a, b, c );
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
