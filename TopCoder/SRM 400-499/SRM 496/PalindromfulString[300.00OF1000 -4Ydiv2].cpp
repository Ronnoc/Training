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
#define UNIQUE(v) (v.erase(unique(v.OP,v.ED),v.ED))
typedef long long LL;
typedef pair<int, int> PII;

vector<string>L;
int play( string &s ) {
	vector<char>T;
	int i;
	for ( i=0; i<s.SZ; i++ )T.PB( s[i] );
	SORT( T );
	UNIQUE( T );
	return T.SZ;
}
void dfs( int h,int N,string &s ) {
	if ( h==N ) {L.PB( s ); return;}
	int c=play( s )+1;
	for ( int i=0; i<c; i++ ) {
		string tp=s;
		tp+='a'+i;
		dfs( h+1,N,tp );
	}
}
int pa(string s){
	int i;
	for(i=0;i+i<s.SZ;i++)if(s[i]!=s[s.SZ-1-i])return 0;
	return 1;
}
bool valid(string &s, int m,int k){
	int i,tot=0;
	for(i=0;i+m-1<s.SZ;i++)if(pa(s.substr(i,m)))tot++;
	return tot>=k;
}
LL A[55];
class PalindromfulString {
public:
	long long count( int N, int M, int K ) {
		long long ret=0;
		int i,j;
		A[0]=1;
		for ( i=1; i<=26; i++ )A[i]=A[i-1]*( 27-i );
		L.clear();
		string s="a";
		dfs( 1,N,s );
		cout<<L.SZ<<endl;
		for ( i=0; i<L.SZ; i++ )
			if ( valid( L[i],M,K ) )ret+=A[play( L[i] )];
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
				int N                     = 2;
				int M                     = 2;
				int K                     = 1;
				long long expected__      = 26LL;
				
				clock_t start__           = clock();
				long long received__      = PalindromfulString().count( N, M, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int N                     = 2;
				int M                     = 2;
				int K                     = 0;
				long long expected__      = 676LL;
				
				clock_t start__           = clock();
				long long received__      = PalindromfulString().count( N, M, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int N                     = 3;
				int M                     = 2;
				int K                     = 1;
				long long expected__      = 1326LL;
				
				clock_t start__           = clock();
				long long received__      = PalindromfulString().count( N, M, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int N                     = 4;
				int M                     = 4;
				int K                     = 1;
				long long expected__      = 676LL;
				
				clock_t start__           = clock();
				long long received__      = PalindromfulString().count( N, M, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int N                     = 7;
				int M                     = 3;
				int K                     = 3;
				long long expected__      = 4310176LL;
				
				clock_t start__           = clock();
				long long received__      = PalindromfulString().count( N, M, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		case 5: {
				int N                     = 11;
				int M                     = 2;
				int K                     = 10;
				long long expected__      = 26LL;
				
				clock_t start__           = clock();
				long long received__      = PalindromfulString().count( N, M, K );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		/*      case 6: {
					int N                     = ;
					int M                     = ;
					int K                     = ;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = PalindromfulString().count( N, M, K );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					int N                     = ;
					int M                     = ;
					int K                     = ;
					long long expected__      = LL;
		
					clock_t start__           = clock();
					long long received__      = PalindromfulString().count( N, M, K );
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
