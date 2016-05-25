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
LL comb3( LL a ) {
	return a*( a-1 )*( a-2 )/6;
}
LL comb2(LL a){
	return a*(a-1)/2;
}
LL comb1(LL a){
	return a;
}
int cnt[2222];
class FoxMakingDice {
public:
	long long theCount( int N, int K ) {
		cout<<N<<" "<<K<<endl;
		memset(cnt,0,sizeof cnt);
		int i,j;
		LL ret=0;
		for(i=1;i<=N;i++)for(j=i+1;j<=N;j++)cnt[i+j]++;
		for(i=K;i<=2*N;i++)ret+=2*comb3(cnt[i]);
		return ret;
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

int verify_case( int casenum, const long long &expected, const long long &received, clock_t elapsed ) {
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
				int N                     = 6;
				int K                     = 7;
				long long expected__      = 2LL;
				
				clock_t start__           = clock();
				long long received__      = FoxMakingDice().theCount( N, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int N                     = 5;
				int K                     = 7;
				long long expected__      = 0LL;
				
				clock_t start__           = clock();
				long long received__      = FoxMakingDice().theCount( N, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int N                     = 1000;
				int K                     = 1;
				long long expected__      = 20625666000LL;
				
				clock_t start__           = clock();
				long long received__      = FoxMakingDice().theCount( N, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int N                     = 456;
				int K                     = 123;
				long long expected__      = 879075732LL;
				
				clock_t start__           = clock();
				long long received__      = FoxMakingDice().theCount( N, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int N                     = 913;
				int K                     = 1014;
				long long expected__      = 4506149340LL;
				
				clock_t start__           = clock();
				long long received__      = FoxMakingDice().theCount( N, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					int N                     = ;
					int K                     = ;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = FoxMakingDice().theCount( N, K );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int N                     = ;
					int K                     = ;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = FoxMakingDice().theCount( N, K );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					int N                     = ;
					int K                     = ;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = FoxMakingDice().theCount( N, K );
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
