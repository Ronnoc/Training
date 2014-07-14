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
const double PI = acos( -1 );
const LL MOD = 1000000007;

int dp[9][9];
int f[9][9];
bool isprime( int x ) {
	if ( x==1 )return 0;
	for ( int i=2; i*i<=x; i++ )if ( x%i==0 )return 0;
	return 1;
}
class PrimeAnagrams {
public:
	vector <int> primes( string s ) {
		vector <int> ret;
		int mx=MOD;
		int i,j,k;
		SORT( s );
		do {
			memset( dp,0,sizeof dp );
			for ( i=0; i<s.SZ; i++ )if ( s[i]!='0' )for ( j=i; j<s.SZ; j++ ) {
						dp[i][j]=0,f[i][j]=0;
						for ( k=i; k<=j; k++ )f[i][j]=f[i][j]*10+s[k]-'0';
						if ( isprime( f[i][j] ) )dp[i][j]=1;
					}
			for ( i=0; i<s.SZ; i++ )if ( dp[0][i] )
					for ( j=i+1; j+1<s.SZ; j++ )if ( dp[i+1][j]&&dp[j+1][s.SZ-1] ) {
							int tp=f[0][i]*f[i+1][j]*f[j+1][s.SZ-1];
							if ( mx>tp ) {
								mx=tp;
								ret.clear();
								ret.PB( f[0][i] );
								ret.PB( f[i+1][j] );
								ret.PB( f[j+1][s.SZ-1] );
								SORT(ret);
							}
						}
		} while ( next_permutation( s.OP,s.ED ) );
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

template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

int verify_case( int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed ) {
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
				string anagram            = "39151";
				int expected__[]          = { 5,  13,  19 };
				
				clock_t start__           = clock();
				vector <int> received__   = PrimeAnagrams().primes( anagram );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 1: {
				string anagram            = "921179";
				int expected__[]          = { 2,  17,  199 };
				
				clock_t start__           = clock();
				vector <int> received__   = PrimeAnagrams().primes( anagram );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 2: {
				string anagram            = "01123";
				int expected__[]          = { 2,  3,  101 };
				
				clock_t start__           = clock();
				vector <int> received__   = PrimeAnagrams().primes( anagram );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 3: {
				string anagram            = "0707070";
				int expected__[]          = { };
				
				clock_t start__           = clock();
				vector <int> received__   = PrimeAnagrams().primes( anagram );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 4: {
				string anagram            = "222";
				int expected__[]          = { 2,  2,  2 };
				
				clock_t start__           = clock();
				vector <int> received__   = PrimeAnagrams().primes( anagram );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 5: {
				string anagram            = "123";
				int expected__[]          = { };
				
				clock_t start__           = clock();
				vector <int> received__   = PrimeAnagrams().primes( anagram );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 6: {
					string anagram            = ;
					int expected__[]          = ;
		
					clock_t start__           = clock();
					vector <int> received__   = PrimeAnagrams().primes( anagram );
					return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
				}*/
		/*      case 7: {
					string anagram            = ;
					int expected__[]          = ;
		
					clock_t start__           = clock();
					vector <int> received__   = PrimeAnagrams().primes( anagram );
					return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
				}*/
		/*      case 8: {
					string anagram            = ;
					int expected__[]          = ;
		
					clock_t start__           = clock();
					vector <int> received__   = PrimeAnagrams().primes( anagram );
					return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
