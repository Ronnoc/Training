// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A new starport has just started working. Starting from some moment of time (call it minute 0), a new spaceship arrives at the starport every M minutes. In other words, spaceships arrive at the starport at minutes 0, M, 2*M, 3*M and so on. 

Similarly, starting from minute 0 and repeating each N minutes, all arrived spaceships that are still placed at the port are teleported to the shed. If a spaceship arrives at the exact same minute when such a teleportation happens, it will be teleported immediately. Otherwise it will need to wait until the next teleportation happens.

Let the waiting time of a spaceship be the time between its arrival and its teleportation to the shed. Return the average waiting time of a spaceship in minutes. See notes for an exact definition.


DEFINITION
Class:Starport
Method:getExpectedTime
Parameters:int, int
Returns:double
Method signature:double getExpectedTime(int N, int M)


NOTES
-Let W(i) be the waiting time for the spaceship that arrives at minute M * i. The average waiting time can be defined as the limit of (W(0) + W(1) + ... + W(P - 1)) / P when P tends to positive infinity. This limit will always exist.
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N and M will each be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
4
2

Returns: 1.0

Spaceships arrive at the starport at minutes 0, 2, 4, 6, 8, and so on. Teleportations are done at minutes 0, 4, 8, and so on. The waiting times for the spaceships are, correspondingly, 0, 2, 0, 2, 0, and so on, so the expected waiting time is 1.

1)
5
3

Returns: 2.0



2)
6
1

Returns: 2.5



3)
12345
2345

Returns: 6170.0



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

//0,5,10(M)
//0,3,6,9,12(N)
class Starport {
public:
  double getExpectedTime (int N, int M) {
//  	cout<<N<<" "<<M<<endl;
    double ret;
    int gd=__gcd(N,M);
    N/=gd;M/=gd;
    ret=(0.0+1.0*(N-1))*(1.0*N)/2.0;
//    cout<<ret<<endl;
    ret*=gd;
    ret/=N;
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
			int N                     = 4;
			int M                     = 2;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			int M                     = 3;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 6;
			int M                     = 1;
			double expected__         = 2.5;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 12345;
			int M                     = 2345;
			double expected__         = 6170.0;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int M                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int M                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Starport().getExpectedTime( N, M );
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
