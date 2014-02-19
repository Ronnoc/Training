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

pair<string,int>dp[1<<17];
string ss[1<<17];
int done[1<<17];
string play( string &a,string &b ) {
	string ret="";
	map<char,int>A,B;
	for ( int i=0; i<a.SZ; i++ )A[a[i]]++;
	for ( int i=0; i<b.SZ; i++ )B[b[i]]++;
	for ( map<char,int>::iterator it=A.OP; it!=A.ED; ++it ) {
		int tot=( *it ).BB;
		tot=min( tot,B[( *it ).AA] );
		while ( tot-- )ret+=( *it ).AA;
	}
	return ret;
}
class PrefixTree {
public:
	int getNumNodes( vector <string> w ) {
		int i,j,n=w.SZ;
		for ( i=0; i<w.SZ; i++ )SORT( w[i] );
		dp[0].AA=""; dp[0].BB=0;
		memset(done,0,sizeof done);
		for ( i=1; i<1<<n; i++ ) {
			dp[i].BB=1<<30;
			for ( j=0; j<n; j++ )
				if ( i==1<<j )
					dp[i]=MP( w[j],w[j].SZ+1 );
			if ( dp[i].BB!=1<<30 )continue;
			int sub=( i-1 )&i;
			do {
				if ( sub+sub>i ) {
					if(!done[i])ss[i]=play(dp[i-sub].AA,dp[sub].AA),done[i]=1;
					int tp=dp[i-sub].BB+dp[sub].BB-ss[i].SZ-1;
					if ( tp<dp[i].BB )dp[i]=MP( ss[i],tp );
				}
				sub=( sub-1 )&i;
			} while ( sub!=0 );
		}
		return dp[( 1<<n )-1].BB;
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
				string words[]            = {"topcoder"};
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string words[]            = {"topcoder","topcoder"};
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string words[]            = {"aab","ca"};
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string words[]            = {"aab","ca","ba"};
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				string words[]            = {"ab","cd","ef"};
				int expected__            = 7;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 5: {
				string words[]            = {"a","aa","aaa"};
				int expected__            = 4;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		case 6: {
				string words[]            = {"abcq","abcw","adcz","adcx","bfen","bfgv"};
				int expected__            = 15;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 7: {
				string words[]            = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p"};
				int expected__            = 17;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 8: {
				string words[]            = {"b", "ab", "aab", "aaab", "aaaab", "aaaaab", "aaaaaab", "aaaaaaab", "aaaaaaaab", "aaaaaaaaab", "aaaaaaaaaab", "aaaaaaaaaaab", "aaaaaaaaaaaab", "aaaaaaaaaaaaab", "aaaaaaaaaaaaaab", "aaaaaaaaaaaaaaab"};
				int expected__            = 17;
				
				clock_t start__           = clock();
				int received__            = PrefixTree().getNumNodes( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
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
