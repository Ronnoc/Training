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
const double PI = acos(-1);
const LL MOD = 1000000007;

class PotentialArithmeticSequence {
public:
  int numberOfSubsequences (vector <int> d) {
    int ret=0;
    int i,j,k,n=d.SZ;
    for(i=0;i<n;i++)for(j=i;j<n;j++){
			vector<int>T;
			for(k=i;k<=j;k++)T.PB(d[k]);
			int next=0,fail=0;
			while(!fail&&T.SZ>1){
				vector<int>S;
				int f0=1,f1=1;
				for(k=0;k<T.SZ;k+=2)if(T[k]!=next)f0=0;
				for(k=1;k<T.SZ;k+=2)if(T[k]!=next)f1=0;
				if(f0&&f1){fail=1;break;}
				if(!f0&&!f1){fail=1;break;}
				if(f0)for(k=1;k<T.SZ;k+=2)if(T[k]<=next)fail=1;
				if(f1)for(k=0;k<T.SZ;k+=2)if(T[k]<=next)fail=1;
				next++;
				if(f0)for(k=1;k<T.SZ;k+=2)S.PB(T[k]);
				else for(k=0;k<T.SZ;k+=2)S.PB(T[k]);
				T=S;
			}
			if(!fail) ret++;
    }
    return ret;
  }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int d[]                   = {0,1,0,2,0,1,0};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int d[]                   = {0,0,0,0,0,0,0};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int d[]                   = {0,0,0,0,1,1,1};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int d[]                   = {0,100,0,2,0};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int d[]                   = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
			int expected__            = 49;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int d[]                   = {2,0,1,0,4};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int d[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PotentialArithmeticSequence().numberOfSubsequences( vector <int>( d, d + ( sizeof d / sizeof d[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
