#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
double dp[305][305][305];
double powqq[305];
class CoinFlips {
public:
	double getExpectation( vector <int> vals, int prob ) {
		double ret=0;
		int n=sz(vals);
		double pp=1.*prob/1000000000;
		double qq=1.*(1000000000-prob)/1000000000;
		powqq[0]=1;
		rep(i,1,n+1)powqq[i]=powqq[i-1]*qq;
		rep(i,3,n+1)rep(j,0,i-2)rep(k,3,i-j+1){
			dp[i][j][k]=0;
			double pr=powqq[j+k]-powqq[i];
			double pl=powqq[i]+1-powqq[j];
			double pm=powqq[j+1]*(1-powqq[k-2]);
			if(j+k<i)dp[i][j][k]+=dp[i-1][j][k]*pr;
			if(j)dp[i][j][k]+=dp[i-1][j-1][k]*pl;
			if(k>3)dp[i][j][k]+=dp[i-1][j][k-1]*pm;
			else dp[i][j][k]+=pm;
		}
		rep(i,0,n)rep(j,i+2,n)
			ret+=vals[i]*vals[j]*dp[n][i][j-i+1];
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
			int vals[]                = {2,3,4};
			int prob                  = 500000000;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int vals[]                = {5,1,4,2,3};
			int prob                  = 100000000;
			double expected__         = 4.985392200480001;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int vals[]                = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int prob                  = 0;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int vals[]                = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int prob                  = 1000000000;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int vals[]                = {1,2,3,4,5,6,7,8,9,10};
			int prob                  = 250000000;
			double expected__         = 130.25145424313288;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int vals[]                = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,5,6,2,6,4,3,3,8,3,2,7,9,5};
			int prob                  = 123456789;
			double expected__         = 481.6707820920715;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int vals[]                = ;
			int prob                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int vals[]                = ;
			int prob                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int vals[]                = ;
			int prob                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CoinFlips().getExpectation( vector <int>( vals, vals + ( sizeof vals / sizeof vals[0] ) ), prob );
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
