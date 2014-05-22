/*

*/
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

long double mabs(long double x){return x>0?x:-x;}
class RadioRange {
public:
  double RadiusProbability (vector <int> X, vector <int> Y, vector <int> R, int Z) {
    double ret;
    int i,j;
    vector<long double>may;
    may.PB(0);
    may.PB(Z);
    for(i=0;i<X.SZ;i++){
			long double x=X[i],y=Y[i],r=R[i];
			long double dis=sqrt(SQ(x)+SQ(y));
			may.PB(mabs(dis-r));
			may.PB(mabs(dis+r));
    }
    SORT(may);
    long double tot=0;
    for(i=0;i+1<may.SZ;i++){
			long double l=may[i],r=may[i+1];
			if(r>Z)continue;
			long double mid=(l+r)/2;
			int flag=1;
			for(j=0;j<X.SZ;j++){
				long double x=X[j],y=Y[j],r=R[j];
				long double dis=sqrt(SQ(x)+SQ(y));
				if(dis>r){
					if(mid>dis-r&&mid<dis+r)flag=0;
				}else {
					if(mid<max(mabs(dis-r),mabs(dis+r)))flag=0;
				}
			}
			if(flag)tot+=r-l;
    }
    return (double)((tot)/Z);
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
			int X[]                   = {0};
			int Y[]                   = {0};
			int R[]                   = {5};
			int Z                     = 10;
			double expected__         = 0.5;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int X[]                   = {0};
			int Y[]                   = {0};
			int R[]                   = {10};
			int Z                     = 10;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int X[]                   = {10};
			int Y[]                   = {10};
			int R[]                   = {10};
			int Z                     = 10;
			double expected__         = 0.4142135623730951;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int X[]                   = {11, -11, 0, 0};
			int Y[]                   = {0, 0, 11, -11};
			int R[]                   = {10, 10, 10, 10};
			int Z                     = 31;
			double expected__         = 0.3548387096774194;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int X[]                   = {100};
			int Y[]                   = {100};
			int R[]                   = {1};
			int Z                     = 10;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int X[]                   = {1000000000};
			int Y[]                   = {1000000000};
			int R[]                   = {1000000000};
			int Z                     = 1000000000;
			double expected__         = 0.41421356237309503;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int X[]                   = {20, -20, 0, 0};
			int Y[]                   = {0, 0, 20, -20};
			int R[]                   = {50, 50, 50, 50};
			int Z                     = 100;
			double expected__         = 0.3;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int X[]                   = {0, -60, -62, -60, 63, -97};
			int Y[]                   = {-72, 67, 61, -8, -32, 89};
			int R[]                   = {6, 7, 8, 7, 5, 6};
			int Z                     = 918;
			double expected__         = 0.9407071068962471;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 8: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int Z                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int Z                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int Z                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RadioRange().RadiusProbability( vector <int>( X, X + ( sizeof X / sizeof X[0] ) ), vector <int>( Y, Y + ( sizeof Y / sizeof Y[0] ) ), vector <int>( R, R + ( sizeof R / sizeof R[0] ) ), Z );
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
