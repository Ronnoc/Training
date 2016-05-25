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
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;


vector<int>LS,LT;
set<unsigned int>ST;
map<unsigned int,int>S,T;
map<unsigned int,int>::iterator it;
int tmd[1<<15];
class EllysPairing {
public:
	int getMax( int M, vector <int> num, vector <int> fi, vector <int> mu, vector <int> ad ) {
		int i,j;
		T.clear();
		int all=0;
		for(i=0;i<num.SZ;i++)all+=num[i];
		for ( i=0; i<num.SZ; i++ ) {
			int tot=num[i];
			unsigned int now=fi[i];
			for ( j=0; j<51&&j<tot; j++ ) {
				T[now]++;
				now=( now*mu[i]+ad[i] )&( M-1 );
			} 
		}
		int nani=2;
		for(it=T.OP;it!=T.ED;++it)cmax(nani,(*it).BB);
		for(it=T.OP;it!=T.ED;++it)if((*it).BB==nani)ST.insert((*it).AA);
		for(i=0;i<num.SZ;i++){
			int tot=num[i];
			unsigned int now=fi[i];
			while(tot--) {
				if(ST.count(now))S[now]++;
				now=( now*mu[i]+ad[i] )&( M-1 );
			}
		}
		for ( it=S.OP; it!=S.ED; ++it )
			LS.PB( ( *it ).BB );
		if(LS.empty())return all/2;
		S.clear();
		SORT( LS );
		reverse( LS.OP,LS.ED );
		if ( all&1 )all--,LS[0]--;
		SORT( LS );
		reverse( LS.OP,LS.ED );
		if ( LS[0]*2<=all )return all/2;
		else return all-LS[0];
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
				int M                     = 16;
				int count[]               = {4, 7};
				int first[]               = {5, 3};
				int mult[]                = {2, 3};
				int add[]                 = {1, 0};
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int M                     = 8;
				int count[]               = {6, 4, 3};
				int first[]               = {0, 3, 2};
				int mult[]                = {3, 7, 5};
				int add[]                 = {0, 3, 2};
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int M                     = 128;
				int count[]               = {42, 13, 666, 17, 1337, 42, 1};
				int first[]               = {18, 76, 3, 122, 0, 11, 11};
				int mult[]                = {33, 17, 54, 90, 41, 122, 20};
				int add[]                 = {66, 15, 10, 121, 122, 1, 30};
				int expected__            = 1059;
				
				clock_t start__           = clock();
				int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int M                     = 1048576;
				int count[]               = {4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1};
				int first[]               = {19, 18, 76, 42, 3, 112, 0, 11, 11, 12};
				int mult[]                = {27, 33, 10, 8, 17, 9362, 90, 41, 122, 20};
				int add[]                 = {98, 101, 66, 15, 10, 144, 3, 1, 5, 1};
				int expected__            = 16232;
				
				clock_t start__           = clock();
				int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int M                     = 1073741824;
				int count[]               = {894602, 946569, 887230, 856152, 962583, 949356, 904847, 829100, 842183, 958440,  811081, 864078, 809209, 938727, 949135, 892809, 816528, 961237, 979142, 890922};
				int first[]               = {844085078, 898937259, 243490172, 887804102, 187696417, 156820442, 237600210, 618812924, 153000239, 912364033,  254936966, 650298774, 982988140, 649258331, 566444626, 201481721, 492943390, 1061953081, 492672963, 960519711};
				int mult[]                = {1036482037, 583219072, 819168094, 253755052, 548208982, 401830167, 638626082, 43642932, 123607749, 485521178,  860368129, 30334704, 219771462, 733375600, 130839219, 415503960, 294132484, 1044831462, 256910484, 198852170};
				int add[]                 = {889169006, 604831366, 967292994, 980686280, 844875791, 1027687492, 357734882, 295879743, 48284748, 421729100,  1049536313, 327207332, 948053446, 271229570, 664579359, 795815285, 842856528, 876662975, 675611938, 634229925};
				int expected__            = 8971965;
				
				clock_t start__           = clock();
				int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					int M                     = ;
					int count[]               = ;
					int first[]               = ;
					int mult[]                = ;
					int add[]                 = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int M                     = ;
					int count[]               = ;
					int first[]               = ;
					int mult[]                = ;
					int add[]                 = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					int M                     = ;
					int count[]               = ;
					int first[]               = ;
					int mult[]                = ;
					int add[]                 = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = EllysPairing().getMax( M, vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), vector <int>( first, first + ( sizeof first / sizeof first[0] ) ), vector <int>( mult, mult + ( sizeof mult / sizeof mult[0] ) ), vector <int>( add, add + ( sizeof add / sizeof add[0] ) ) );
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
