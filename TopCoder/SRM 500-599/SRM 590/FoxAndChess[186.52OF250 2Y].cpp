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


class FoxAndChess {
public:
	string ableToMove( string a, string b ) {
		cout<<a<<" "<<b<<endl;
		string yes="Possible";
		string non="Impossible";
		vector<PII>A,B;
		int i,j;
		for ( i=0; i<a.SZ; i++ )if ( a[i]=='L' )A.PB( MP( i,-1 ) );
			else if ( a[i]=='R' )A.PB( MP( i,1 ) );
		for ( i=0; i<b.SZ; i++ )if ( b[i]=='L' )B.PB( MP( i,-1 ) );
			else if ( b[i]=='R' )B.PB( MP( i,1 ) );
		if ( A.SZ!=B.SZ )return non;
		for ( i=0; i<A.SZ; i++ )if ( A[i].BB!=B[i].BB )return non;
		for ( int t=0; t<A.SZ; t++ )
			for ( i=0; i<A.SZ; i++ ) {
				int now=A[i].AA;
				while ( now!=B[i].AA ) {
					int to=now+A[i].BB;
					if ( i+1<A.SZ&&A[i+1].AA==to )break;
					if ( i>0&&A[i-1].AA==to )break;
					if ( to==a.SZ )break;
					if ( to==-1 )break;
					now=to;
				}
				A[i].AA=now;
			}
		for(i=0;i<A.SZ;i++)if(A[i]!=B[i])return non;
		return yes;
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

int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) {
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
		cerr << "    Expected: \"" << expected << "\"" << endl;
		cerr << "    Received: \"" << received << "\"" << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				string begin              = "R...";
				string target             = "..R.";
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = FoxAndChess().ableToMove( begin, target );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string begin              = "..R.";
				string target             = "R...";
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = FoxAndChess().ableToMove( begin, target );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string begin              = ".L.R.R.";
				string target             = "L...R.R";
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = FoxAndChess().ableToMove( begin, target );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string begin              = ".L.R.";
				string target             = ".R.L.";
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = FoxAndChess().ableToMove( begin, target );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				string begin              = "LRLLRLRLLRLLRLRLRL";
				string target             = "LRLLRLRLLRLLRLRLRL";
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = FoxAndChess().ableToMove( begin, target );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 5: {
				string begin              = "L";
				string target             = ".";
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = FoxAndChess().ableToMove( begin, target );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 6: {
					string begin              = ;
					string target             = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = FoxAndChess().ableToMove( begin, target );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					string begin              = ;
					string target             = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = FoxAndChess().ableToMove( begin, target );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 8: {
					string begin              = ;
					string target             = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = FoxAndChess().ableToMove( begin, target );
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
