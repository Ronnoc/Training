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

class TheCoffeeTimeDivOne {
public:
	long long find( int n, vector <int> tea ) {
		int i,j,k;
		set<int>TEA(tea.OP,tea.ED);
		int csz=n-tea.SZ;
		LL ret=4*n;
		int ct=-1,cc=-1;
		for(i=n;i>=1;i--){
			if(TEA.count(i)){
				ct++;
				if(ct%7==0)
					ret+=2*i+47;
			}else {
				cc++;
				if(cc%7==0)
					ret+=2*i+47;
			}
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
			int n                     = 2;
			int tea[]                 = {1};
			long long expected__      = 108LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 2;
			int tea[]                 = {2, 1};
			long long expected__      = 59LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 15;
			int tea[]                 = {1, 2, 3, 4, 5, 6, 7};
			long long expected__      = 261LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 47;
			int tea[]                 = {1, 10, 6, 2, 4};
			long long expected__      = 891LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			int n                     = 16177770;
			int tea[]                 = {3953997, 14034575, 13458310, 6713667, 6127747, 14786801, 1740977, 6698337, 9815509, 9859739, 942916, 10073431, 12894853, 8618765, 4276273, 3550381, 14816731, 10650403, 3300373, 9574006, 9630391, 12197525, 250903, 1267942, 12088302, 2288971, 7919301, 5819382, 3579661, 11171725, 5731487, 14555683, 9782928, 13883317, 15797443, 7591809, 12635781, 11927892, 2114611, 5353692};
			long long expected__      = 37388809134855LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 5: {
			int n                     = ;
			int tea[]                 = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int n                     = ;
			int tea[]                 = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TheCoffeeTimeDivOne().find( n, vector <int>( tea, tea + ( sizeof tea / sizeof tea[0] ) ) );
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
