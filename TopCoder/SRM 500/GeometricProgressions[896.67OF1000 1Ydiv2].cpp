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

set<pair<LL,LL> >S;
LL mod1=( 1LL<<62 )-1;
LL mod2=( 1LL<<62 )-3;
LL mul( LL a,LL b,LL mod ) {
	LL ret=0;
	while ( b ) {
		if ( b&1 )ret=( ret+a )%mod;
		a=( a+a )%mod;
		b/=2;
	}
	return ret;
}
void play( LL b,LL q,int n ) {
	LL s1=b%mod1,s2=b%mod2;
	for ( int i=0; i<n; i++ ) {
		S.insert( MP( s1,s2 ) );
		s1=mul( s1,q,mod1 );
		s2=mul( s2,q,mod2 );
	}
}
class GeometricProgressions {
public:
	int count( int b1, int q1, int n1, int b2, int q2, int n2 ) {
		S.clear();
		play( ( LL )b1,q1,n1 );
		play( ( LL )b2,q2,n2 );
		return S.SZ;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case( int );
void run_test( int casenum = -1, bool quiet = false ) {
	if ( casenum != -1 ) {
		if ( run_test_case( casenum ) == -1 && !quiet )
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for ( int i=0;; ++i ) {
		int x = run_test_case( i );
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

int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( expected == received ) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if ( !info.empty() ) {
		cerr << " (";
		for ( int i=0; i<( int )info.size(); ++i ) {
			if ( i > 0 ) cerr << ", ";
			cerr << info[i];
		}
		cerr << ")";
	}
	cerr << endl;
	
	if ( verdict == "FAILED" ) {
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				int b1                    = 3;
				int q1                    = 2;
				int n1                    = 5;
				int b2                    = 6;
				int q2                    = 2;
				int n2                    = 5;
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int b1                    = 3;
				int q1                    = 2;
				int n1                    = 5;
				int b2                    = 2;
				int q2                    = 3;
				int n2                    = 5;
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int b1                    = 1;
				int q1                    = 1;
				int n1                    = 1;
				int b2                    = 0;
				int q2                    = 0;
				int n2                    = 1;
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int b1                    = 3;
				int q1                    = 4;
				int n1                    = 100500;
				int b2                    = 48;
				int q2                    = 1024;
				int n2                    = 1000;
				int expected__            = 100500;
				
				clock_t start__           = clock();
				int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 4: {
					int b1                    = ;
					int q1                    = ;
					int n1                    = ;
					int b2                    = ;
					int q2                    = ;
					int n2                    = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 5: {
					int b1                    = ;
					int q1                    = ;
					int n1                    = ;
					int b2                    = ;
					int q2                    = ;
					int n2                    = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int b1                    = ;
					int q1                    = ;
					int n1                    = ;
					int b2                    = ;
					int q2                    = ;
					int n2                    = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = GeometricProgressions().count( b1, q1, n1, b2, q2, n2 );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		default:
			return -1;
	}
}
}


int main( int argc, char *argv[] ) {
	if ( argc == 1 ) {
		moj_harness::run_test();
	} else {
		for ( int i=1; i<argc; ++i )
			moj_harness::run_test( atoi( argv[i] ) );
	}
}
// END CUT HERE
