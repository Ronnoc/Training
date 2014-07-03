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

double P[55];
double comb[55][55];
class PalindromePermutations {
public:
	double palindromeProbability( string s ) {
		int i,j;
		P[0]=1;
		for ( i=1; i<=50; i++ )P[i]=P[i-1]*i;
		for ( i=0; i<=50; i++ ) {
			comb[i][0]=comb[i][i]=1;
			for ( j=1; j<i; j++ )comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
		double ret=P[s.SZ];
		int cnt[55];
		memset( cnt,0,sizeof cnt );
		SORT( s );
		for ( i=0; i<s.SZ; i++ )cnt[s[i]-'a']++;
		for ( i=0; i<26; i++ )ret/=P[cnt[i]];
		double all=ret;
		int len=s.SZ;
		cout<<s<<endl;
		int how=0;
		for ( i=0; i<26; i++ )if ( cnt[i]&1 )how++;
		if ( how>1 )return 0;
		if ( len%2==1 ) {
			for ( i=0; i<26; i++ )if ( cnt[i]&1 )break;
			ret=ret/comb[len][cnt[i]]*comb[len/2][cnt[i]/2];
			len-=cnt[i];
			cnt[i]=0;
		}
		for ( i=0; i<26; i++ )if ( cnt[i] ) {
				ret=ret/comb[len][cnt[i]]*comb[len/2][cnt[i]/2];
				len-=cnt[i];
			}
		return ret/all;
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
		cerr << "ret " << total << " tests passed!" << endl;
	}
}

static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min( expected * ( 1.0 - MAX_DOUBLE_ERROR ), expected * ( 1.0 + MAX_DOUBLE_ERROR ) ); double mmax = max( expected * ( 1.0 - MAX_DOUBLE_ERROR ), expected * ( 1.0 + MAX_DOUBLE_ERROR ) ); return result > mmin && result < mmax; } }
double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }

int verify_case( int casenum, const double &expected, const double &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( topcoder_fequ( expected, received ) ) {
		verdict = "PASSED";
		double rerr = moj_relative_error( expected, received );
		if ( rerr > 0 ) {
			sprintf( buf, "relative error %.3e", rerr );
			info.push_back( buf );
		}
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
				string word               = "haha";
				double expected__         = 0.3333333333333333;
				
				clock_t start__           = clock();
				double received__         = PalindromePermutations().palindromeProbability( word );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string word               = "xxxxy";
				double expected__         = 0.2;
				
				clock_t start__           = clock();
				double received__         = PalindromePermutations().palindromeProbability( word );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string word               = "xxxx";
				double expected__         = 1.0;
				
				clock_t start__           = clock();
				double received__         = PalindromePermutations().palindromeProbability( word );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string word               = "abcde";
				double expected__         = 0.0;
				
				clock_t start__           = clock();
				double received__         = PalindromePermutations().palindromeProbability( word );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				string word               = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
				double expected__         = 0.025641025641025637;
				
				clock_t start__           = clock();
				double received__         = PalindromePermutations().palindromeProbability( word );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					string word               = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = PalindromePermutations().palindromeProbability( word );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					string word               = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = PalindromePermutations().palindromeProbability( word );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					string word               = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = PalindromePermutations().palindromeProbability( word );
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
