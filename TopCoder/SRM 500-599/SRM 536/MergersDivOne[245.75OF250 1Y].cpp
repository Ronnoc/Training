// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

The candy industry is going through a hard time in Byteland. Some of the biggest companies in the business have decided to perform a series of mergers so as to become one company in the end. Surprisingly, empirical studies conducted by the economists of Byteland have shown that for any m >= 2 the revenue of a company that is created by simultainously merging m companies with revenues equal to r0, r1, ..., rm - 1 is equal to the average of these revenues, that is (r0 + r1 + ... + rm - 1) / m.


You are given a vector <int> revenues. The revenue of the i-th of the companies that want to merge is equal to revenues[i]. Return the maximum possible revenue of the final company that can be created in any series of mergers that joins all the companies. In each of the mergers, we may merge as many of the currently existing companies as we wish.

DEFINITION
Class:MergersDivOne
Method:findMaximum
Parameters:vector <int>
Returns:double
Method signature:double findMaximum(vector <int> revenues)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-Please note that the revenue of a company may be negative; this means that the company is actually losing money.
-It is always possible to merge all companies into a single one: for example, by merging all of them in a single step.


CONSTRAINTS
-revenues will contain between 2 and 50 elements, inclusive.
-Each element of revenues will be between -1,000 and 1,000, inclusive.


EXAMPLES

0)
{5, -7, 3}

Returns: 1.5

The optimal way is to first merge companies 1 and 2, obtaining a company with total revenue -2, and then merge that company with company 0.

1)
{10, -17}

Returns: -3.5



2)
{12, 12, 12, 12, 12}

Returns: 12.0

We can just merge all the companies at once.

3)
{0, 0, 0, 0, 0, 100}

Returns: 50.0

We may first merge companies 0 through 4 and then merge the resulting company with company 5.

4)
{10, -10, 100, -100, 1000, -1000}

Returns: 491.25



*/
// END CUT HERE
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
#include <stdexcept>
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
typedef long long LL;
typedef pair<int, int> PII;


class MergersDivOne {
public:
  double findMaximum (vector <int> r) {
    double ret=0;
    SORT(r);
    double tp=r[0];
    int i;
    for(i=1;i<r.SZ;i++)tp=(tp+r[i])/2;
    return tp;
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
			int revenues[]            = {5, -7, 3};
			double expected__         = 1.5;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int revenues[]            = {10, -17};
			double expected__         = -3.5;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int revenues[]            = {12, 12, 12, 12, 12};
			double expected__         = 12.0;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int revenues[]            = {0, 0, 0, 0, 0, 100};
			double expected__         = 50.0;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int revenues[]            = {10, -10, 100, -100, 1000, -1000};
			double expected__         = 491.25;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int revenues[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int revenues[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int revenues[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MergersDivOne().findMaximum( vector <int>( revenues, revenues + ( sizeof revenues / sizeof revenues[0] ) ) );
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
