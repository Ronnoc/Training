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

class AgeEncoding {
public:
	double getRadix( int age, string s ) {
		int i,j,k;
		int has=0;
		for(auto c:s)
			has+=c=='1';
		reverse(s.OP,s.ED);
		if(!has){
			if(age==0)return -2;
			return -1;
		}
		if(age==1&&s[0]=='1'){
			if(has==1)return -2;
			return -1;
		}
		reverse(s.OP,s.ED);
		double le=0,re=age;
		while(re-le>1e-12){
			double me=(le+re)/2;
			double x=0;
			for(i=0;i<s.SZ;i++)
				x=x*me+s[i]-'0';
			if(x>age)re=me;
			else le=me;
		}
		double ret=(le+re)/2;
		double x=0;
		for(i=0;i<s.SZ;i++)
			x=x*ret+s[i]-'0';
		return fabs(x-age)<1e-9?ret:-1;
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
			int age                   = 10;
			string candlesLine        = "00010";
			double expected__         = 10.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int age                   = 21;
			string candlesLine        = "10101";
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int age                   = 6;
			string candlesLine        = "10100";
			double expected__         = 1.414213562373095;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int age                   = 21;
			string candlesLine        = "10111111110111101111111100111111110111111111111100";
			double expected__         = 0.9685012944510603;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int age                   = 16;
			string candlesLine        = "1";
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int age                   = 1;
			string candlesLine        = "1";
			double expected__         = -2.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int age                   = 1;
			string candlesLine        = "001000";
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			int age                   = ;
			string candlesLine        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int age                   = ;
			string candlesLine        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int age                   = ;
			string candlesLine        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AgeEncoding().getRadix( age, candlesLine );
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
