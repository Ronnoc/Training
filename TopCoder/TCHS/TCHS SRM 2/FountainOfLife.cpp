// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A Fountain of Life is a special fountain that produces the elixir of life at a constant speed of elixir liters per second. A dark mage managed to cast a Curse of Death on the Fountain so in addition to the elixir it now produces a deadly poison at a constant speed of poison liters per second. Both the poison and elixir are collected in an infinitely large pool around the Fountain and form a mixture. The mixture will become deadly once the percentage of poison in the mixture is at least 50%. Your task is to calculate the time at which the mixture will become deadly. At the beginning (0-th second) the pool contains pool liters of 100% elixir.

Your program must return a double, the time in seconds at which the mixture becomes deadly. If the mixture never becomes deadly, return -1.0.

DEFINITION
Class:FountainOfLife
Method:elixirOfDeath
Parameters:int, int, int
Returns:double
Method signature:double elixirOfDeath(int elixir, int poison, int pool)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-elixir will be between 1 and 10000, inclusive.
-poison will be between 1 and 10000, inclusive.
-pool will be between 1 and 10000, inclusive.


EXAMPLES

0)
1
2
2

Returns: 2.0

At t = 0s there are 2 liters of 100% elixir.
At t = 1s there are 3 liters of elixir and 2 liters of poison for a total volume of 5 liters. 2 liters of poison is 40% of 5 liters so the mixture is still not deadly.
At t = 2s there are 4 liters of elixir and 4 liters of poison for a total volume of 8 liters. 4 liters of poison is exactly 50% of the mixture so it is now deadly.

1)
200
100
1

Returns: -1.0

With 200 liters of elixir per second and only 100 liters of poison per second, the mixture never becomes deadly.

2)
9999
10000
10000

Returns: 10000.0

It might take a long time for the mixture to become deadly.

3)
1
10000
1

Returns: 1.0001000100010001E-4

On the other hand, it might take a short time for the mixture to become deadly.

4)
40
43
41

Returns: 13.666666666666666

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


class FountainOfLife {
public:
  double elixirOfDeath (int elixir, int poison, int pool) {
		double cha=poison-elixir;
		if(cha<1e-8)return -1;
    return double(pool)/cha;
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
			int elixir                = 1;
			int poison                = 2;
			int pool                  = 2;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int elixir                = 200;
			int poison                = 100;
			int pool                  = 1;
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int elixir                = 9999;
			int poison                = 10000;
			int pool                  = 10000;
			double expected__         = 10000.0;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int elixir                = 1;
			int poison                = 10000;
			int pool                  = 1;
			double expected__         = 1.0001000100010001E-4;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int elixir                = 40;
			int poison                = 43;
			int pool                  = 41;
			double expected__         = 13.666666666666666;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int elixir                = ;
			int poison                = ;
			int pool                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int elixir                = ;
			int poison                = ;
			int pool                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int elixir                = ;
			int poison                = ;
			int pool                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FountainOfLife().elixirOfDeath( elixir, poison, pool );
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
