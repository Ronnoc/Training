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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1);
const LL MOD = 1000000007;
double dp[55][2555];
double sum[2555];
class FixedDiceGameDiv1 {
public:
  double getExpectation (int a, int b, int c, int d) {
    double ret=0;
    int i,j,k;
    for(i=0;i<=51;i++)for(j=0;j<=2550;j++)dp[i][j]=0;
    dp[0][0]=1;
    for(i=0;i<=c;i++)for(j=0;j<=i*d;j++)if(dp[i][j]>0)
			for(k=1;k<=d;k++)dp[i+1][j+k]+=dp[i][j]/d;
    sum[0]=0;
    for(i=1;i<=c*d||i<=a*b;i++)sum[i]=sum[i-1]+dp[c][i];
    for(i=0;i<=51;i++)for(j=0;j<=2550;j++)dp[i][j]=0;
    dp[0][0]=1;
    for(i=0;i<=a;i++)for(j=0;j<=i*b;j++)if(dp[i][j]>0)
			for(k=1;k<=b;k++)dp[i+1][j+k]+=dp[i][j]/b;
		double win=0;
		for(i=1;i<=a*b;i++)win+=sum[i-1]*dp[a][i];
		if(win<=0)return -1;
//		cout<<win<<endl;
    for(i=1;i<=a*b;i++)ret+=i*sum[i-1]*dp[a][i]/win;
//    for(i=1;i<=a*b;i++)cout<<i<<" "<<sum[i-1]<<"*"<<dp[a][i]/win<<endl;
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
			int a                     = 1;
			int b                     = 2;
			int c                     = 1;
			int d                     = 5;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a                     = 3;
			int b                     = 1;
			int c                     = 1;
			int d                     = 3;
			double expected__         = 3.0;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a                     = 1;
			int b                     = 5;
			int c                     = 1;
			int d                     = 1;
			double expected__         = 3.4999999999999996;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a                     = 2;
			int b                     = 6;
			int c                     = 50;
			int d                     = 30;
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a                     = 50;
			int b                     = 11;
			int c                     = 50;
			int d                     = 50;
			double expected__         = 369.8865999182022;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int a                     = 50;
			int b                     = 50;
			int c                     = 50;
			int d                     = 50;
			double expected__         = 1332.7589107;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FixedDiceGameDiv1().getExpectation( a, b, c, d );
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
