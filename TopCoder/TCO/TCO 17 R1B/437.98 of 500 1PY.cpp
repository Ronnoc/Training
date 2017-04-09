#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
class WaterAndOxygen {
public:
	double maxDays( int remainH20, int remainO2, int costH2O, int costO2 ) {
		int i,j;
		double ret;
		double rh = remainH20,ro = remainO2,ch = costH2O,co = costO2;
		ret = min(rh/ch,ro/co);
		if(rh/ch>ro/co){
			rh -= ro/co*ch;
			cmax(ret, ro/co+rh/(2*co+ch));
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int remainH20             = 64;
			int remainO2              = 70;
			int costH2O               = 3;
			int costO2                = 7;
			double expected__         = 12.0;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int remainH20             = 99;
			int remainO2              = 102;
			int costH2O               = 1;
			int costO2                = 1;
			double expected__         = 99.0;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int remainH20             = 101;
			int remainO2              = 99;
			int costH2O               = 1;
			int costO2                = 1;
			double expected__         = 99.66666666666667;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int remainH20             = 123456789;
			int remainO2              = 987654321;
			int costH2O               = 123;
			int costO2                = 456;
			double expected__         = 1003713.731707317;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int remainH20             = 987654321;
			int remainO2              = 123456789;
			int costH2O               = 456;
			int costO2                = 123;
			double expected__         = 1758643.7307692308;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int remainH20             = 0;
			int remainO2              = 0;
			int costH2O               = 13;
			int costO2                = 27;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int remainH20             = ;
			int remainO2              = ;
			int costH2O               = ;
			int costO2                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int remainH20             = ;
			int remainO2              = ;
			int costH2O               = ;
			int costO2                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int remainH20             = ;
			int remainO2              = ;
			int costH2O               = ;
			int costO2                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = WaterAndOxygen().maxDays( remainH20, remainO2, costH2O, costO2 );
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
