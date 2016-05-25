// BEGIN CUT HERE
/*
PROBLEM STATEMENT

A speed radar is installed in a highway zone where the maximum speed limit is maxLimit mph, and the minimum speed limit is minLimit mph.  Any reading that is strictly above or below this interval is an infringement.


Periodically, the radar readings are analyzed to make sure that the sensors are working properly.  It is assumed that most drivers obey speed limits, and therefore, the radar will be considered faulty if more than 10% of its readings are infringements.


Given the radar readings over a period of time, return the average speed of all cars that are driving within the speed limits.  If the radar is faulty, return 0.0.


DEFINITION
Class:SpeedRadar
Method:averageSpeed
Parameters:int, int, vector <int>
Returns:double
Method signature:double averageSpeed(int minLimit, int maxLimit, vector <int> readings)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-maxLimit will be between 1 and 200, inclusive.
-minLimit will be between 1 and maxLimit, inclusive.
-readings will contain between 1 and 50 elements, inclusive.
-Each element of readings will be between 1 and 200, inclusive.


EXAMPLES

0)
1
50
{45, 40, 50}

Returns: 45.0

With all drivers within the speed limits, the return value is just the average speed.

1)
1
50
{42,43,44,45,46,47,48,49,50,51}

Returns: 46.0

There is only one driver infringing the limit, and it represents 10% of the total readings. The average speed of the other readings is 46.0.

2)
1
50
{42,46,48,50,52}

Returns: 0.0

Only one reading is outside the given limits, but it represents 20% of the total number of readings.  We therefore assume that the radar is not working and return 0.0.

3)
20
60
{25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54}

Returns: 41.68421052631579

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

typedef long long LL;
typedef pair<int, int> PII;


class SpeedRadar {
public:
  double averageSpeed (int MIN, int MAX, vector <int> r) {
		int allow=0;
		double tot=0;
		for(int i=0;i<r.size();i++)if(r[i]>=MIN&&r[i]<=MAX)allow++,tot+=r[i];
		if((r.size()-allow)*10<=r.size())return tot/allow;
    return 0.0;
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
			int minLimit              = 1;
			int maxLimit              = 50;
			int readings[]            = {45, 40, 50};
			double expected__         = 45.0;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int minLimit              = 1;
			int maxLimit              = 50;
			int readings[]            = {42,43,44,45,46,47,48,49,50,51};
			double expected__         = 46.0;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int minLimit              = 1;
			int maxLimit              = 50;
			int readings[]            = {42,46,48,50,52};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int minLimit              = 20;
			int maxLimit              = 60;
			int readings[]            = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54};
			double expected__         = 41.68421052631579;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int minLimit              = ;
			int maxLimit              = ;
			int readings[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int minLimit              = ;
			int maxLimit              = ;
			int readings[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int minLimit              = ;
			int maxLimit              = ;
			int readings[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = SpeedRadar().averageSpeed( minLimit, maxLimit, vector <int>( readings, readings + ( sizeof readings / sizeof readings[0] ) ) );
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
