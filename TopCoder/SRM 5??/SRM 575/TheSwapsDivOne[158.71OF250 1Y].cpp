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

double x[1000001];
double y[1000001];
double e[3333];
class TheSwapsDivOne {
public:
	double find( vector <string> se, int k ) {
		double ret=0;
		string s;
		int i,j;
		for(i=0;i<se.SZ;i++)s+=se[i];
		int n=s.SZ;
		double all=n*( n-1 )/2;
		double xx=( n-1 )*( n-2 )/2;
		x[1]=xx/all;
		y[1]=1/all;
		for(i=2;i<=k;i++){
			x[i]=x[i-1]*x[1]+(n-1)*y[1]*y[i-1];
			y[i]=x[1]*y[i-1]+x[i-1]*y[1]+(n-2)*y[1]*y[i-1];
		}
//		cout<<x[k]<<" "<<y[k]<<endl;
		for(i=0;i<n;i++)e[i]=(i+1)*(n-i)*1.0/((n*(n+1)/2));
//		for(i=0;i<n;i++)cout<<e[i]<<" ";cout<<endl;
		for(i=0;i<n;i++){
			double quan=0;
			for(j=0;j<n;j++)
				if(i==j)quan+=x[k]*e[j];
				else quan+=y[k]*e[j];
//			cout<<quan<<" "<<s[i]<<endl;
			ret+=quan*(s[i]-'0');
		}
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
				string sequence[]         = {"4", "77"};
				int k                     = 1;
				double expected__         = 10.0;
				
				clock_t start__           = clock();
				double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string sequence[]         = {"4", "77"};
				int k                     = 47;
				double expected__         = 10.0;
				
				clock_t start__           = clock();
				double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string sequence[]         = {"1", "1", "1", "1", "1", "1", "1"};
				int k                     = 1000000;
				double expected__         = 3.0;
				
				clock_t start__           = clock();
				double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string sequence[]         = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"};
				int k                     = 7;
				double expected__         = 98.3238536775161;
				
				clock_t start__           = clock();
				double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 4: {
					string sequence[]         = ;
					int k                     = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 5: {
					string sequence[]         = ;
					int k                     = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					string sequence[]         = ;
					int k                     = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = TheSwapsDivOne().find( vector <string>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ), k );
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
