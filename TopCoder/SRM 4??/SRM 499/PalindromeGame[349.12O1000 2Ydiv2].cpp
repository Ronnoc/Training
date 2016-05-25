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

map<string,vector<int> >L;
map<string,vector<int> >::iterator it;
class PalindromeGame {
public:
	int getMaximum( vector <string> B, vector <int> x ) {
		L.clear();
		int add=0,i,ret=0,pr=0;
		for ( i=0; i<B.SZ; i++ )L[B[i]].PB( x[i] );
		for ( it=L.OP; it!=L.ED; ++it ) {
			string a=( *it ).AA;
			cout<<a<<endl;
			string b=a;
			reverse( b.OP,b.ED );
			vector<int>A=( *it ).BB;
			SORT(A);
			reverse(A.OP,A.ED);
			if ( b==a ) {
				for ( i=1; i<A.SZ; i+=2 )ret+=A[i]+A[i-1];
				if ( ( int( A.SZ ) )&1 )add=max( add,A[A.SZ-1] );
			} else {
				vector<int>B=L[b];
			SORT(B);
			reverse(B.OP,B.ED);
				for ( i=0; i<A.SZ&&i<B.SZ; i++ )pr+=A[i]+B[i];
			}
		}
		return pr/2+ret+add;
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
				string front[]            = { "topcoder", "redcoder", "redocpot","aaaaaaaa" };
				int back[]                = { 7, 5, 3,111 };
				int expected__            = 121;
				
				clock_t start__           = clock();
				int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string front[]            = { "rabbit" };
				int back[]                = { 1000000 };
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string front[]            = { "abc", "abc", "def", "cba", "fed" };
				int back[]                = { 24, 7, 63, 222, 190 };
				int expected__            = 499;
				
				clock_t start__           = clock();
				int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 3: {
					string front[]            = ;
					int back[]                = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 4: {
					string front[]            = ;
					int back[]                = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 5: {
					string front[]            = ;
					int back[]                = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = PalindromeGame().getMaximum( vector <string>( front, front + ( sizeof front / sizeof front[0] ) ), vector <int>( back, back + ( sizeof back / sizeof back[0] ) ) );
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
