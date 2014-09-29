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

class PeriodicJumping {
public:
  int minimalTime (int X, vector <int> J) {
  	LL x=X;
  	if(x==0)return 0;
  	if(x<0)x=-x;
    int ret;
    int i,j;
    LL mx=x;
    LL sum=x;
    for(i=0;i<J.SZ;i++){
			cmax(mx,1LL*J[i]);
			sum+=J[i];
			if(sum-mx>=mx)return i+1;
    }
    for(i=0;i<J.SZ;i++){
			sum+=J[i];
			if(sum-mx>=mx)return i+J.SZ+1;
    }
    sum=0;
    for(i=0;i<J.SZ;i++)sum+=J[i];
    LL tot=x/sum-2;
    LL add=tot*J.SZ;
    sum=tot*sum+x;
    for(i=0;i<J.SZ;i++){
			sum+=J[i];
			if(sum-mx>=mx)return i+1+add;
    }
    add+=J.SZ;
    for(i=0;i<J.SZ;i++){
			sum+=J[i];
			if(sum-mx>=mx)return i+1+add;
    }
    add+=J.SZ;
    for(i=0;i<J.SZ;i++){
			sum+=J[i];
			if(sum-mx>=mx)return i+1+add;
    }
    cout<<sum<<"?"<<mx<<endl;
    return -1;
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
			int x                     = 15;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,10};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x                     = 5;
			int jumpLengths[]         = {5};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x                     = 1;
			int jumpLengths[]         = {10};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x                     = -10;
			int jumpLengths[]         = {2,3,4,500,6,7,8};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x                     = -1000000000;
			int jumpLengths[]         = {1};
			int expected__            = 1000000000;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x                     = 0;
			int jumpLengths[]         = {19911120};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int x                     = 653528017;
			int jumpLengths[]         = {99};
			int expected__            = 6601294;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int x                     = ;
			int jumpLengths[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int x                     = ;
			int jumpLengths[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PeriodicJumping().minimalTime( x, vector <int>( jumpLengths, jumpLengths + ( sizeof jumpLengths / sizeof jumpLengths[0] ) ) );
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
