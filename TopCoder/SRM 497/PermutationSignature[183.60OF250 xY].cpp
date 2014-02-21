#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PermutationSignature {
public:

	vector <int> reconstruct( string s ) {
		cout<<s<<endl;
		int i,len=s.size();
		int flag[60];
		for ( i=len-1; i>=0; i-- )if ( s[i]=='D' )flag[i]=1;
			else flag[i]=0;
		vector<int>rvs,ret;
		int todo=len-1,nxtb=len+1;
		while ( todo>=0 ) {
			if ( flag[todo] ) {
				i=todo;
				while ( flag[i]&&i>=0 )i--;
				cout<<"("<<i<<" "<<todo<<")"<<endl;
				int nnn=todo-i;
				for ( int j=i; j<=todo; j++,nnn-- )rvs.push_back( nxtb-nnn );
				nnn=todo-i;
				todo=i-1;
				for ( i=0; i<rvs.size(); i++ )nxtb=min( nxtb,rvs[i] );
				nxtb--;
				cout<<"<<";
				for ( i=0; i<rvs.size(); i++ )cout<<rvs[i]<<" "; cout<<endl;
			} else {
				rvs.push_back( nxtb );
				cout<<">>";
				for ( i=0; i<rvs.size(); i++ )cout<<rvs[i]<<" "; cout<<endl;
				for ( i=0; i<rvs.size(); i++ )nxtb=min( nxtb,rvs[i] );
				nxtb--;
				todo--;
			}
		}
		while ( rvs.size()<( len+1 ) )rvs.push_back( nxtb-- );
		for ( i=rvs.size()-1; i>=0; i-- )ret.push_back( rvs[i] );
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
				string signature          = "IIIII";
				int expected__[]          = {1, 2, 3, 4, 5, 6 };
				
				clock_t start__           = clock();
				vector <int> received__   = PermutationSignature().reconstruct( signature );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 1: {
				string signature          = "DI";
				int expected__[]          = {2, 1, 3 };
				
				clock_t start__           = clock();
				vector <int> received__   = PermutationSignature().reconstruct( signature );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 2: {
				string signature          = "IIIID";
				int expected__[]          = {1, 2, 3, 4, 6, 5 };
				
				clock_t start__           = clock();
				vector <int> received__   = PermutationSignature().reconstruct( signature );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
		case 3: {
				string signature          = "DIIDID";
				int expected__[]          = {2, 1, 3, 5, 4, 7, 6 };
				
				clock_t start__           = clock();
				vector <int> received__   = PermutationSignature().reconstruct( signature );
				return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 4: {
					string signature          = ;
					int expected__[]          = ;
		
					clock_t start__           = clock();
					vector <int> received__   = PermutationSignature().reconstruct( signature );
					return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
				}*/
		/*      case 5: {
					string signature          = ;
					int expected__[]          = ;
		
					clock_t start__           = clock();
					vector <int> received__   = PermutationSignature().reconstruct( signature );
					return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
				}*/
		/*      case 6: {
					string signature          = ;
					int expected__[]          = ;
		
					clock_t start__           = clock();
					vector <int> received__   = PermutationSignature().reconstruct( signature );
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
