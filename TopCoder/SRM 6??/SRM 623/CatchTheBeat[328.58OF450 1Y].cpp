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

LL x[500005],y[500005];
class CatchTheBeat {
public:
  int maxCatched (int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
    int ret;
    int i,j;
    for(x[0]=x0,i=1;i<n;i++)
			x[i]=(x[i-1]*a+b)%mod1;
		for(i=0;i<n;i++)x[i]-=offset;
		for(y[0]=y0,i=1;i<n;i++)
			y[i]=(y[i-1]*c+d)%mod2;
//		for(i=0;i<10&&i<n;i++)cout<<x[i]<<"~"<<y[i]<<" ==> "<<(x[i]+y[i])<<"~"<<(y[i]-x[i])<<endl;
    vector<pair<LL,LL> >L;
    for(i=0;i<n;i++)L.PB(MP(x[i]+y[i],y[i]-x[i]));
    SORT(L);
    vector<LL>T;
//    cout<<i<<endl;
    for(i=0;i<L.SZ;i++){
    	LL yy=(L[i].AA+L[i].BB)/2;
			LL xx=L[i].AA-yy;
			if(yy<xx||yy<-xx)continue;
			int id=upper_bound(T.OP,T.ED,L[i].BB)-T.OP;
			if(id<T.SZ)T[id]=L[i].BB;
			else T.PB(L[i].BB);
    }
    return T.SZ;
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
			int n                     = 3;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 1;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 100;
			int mod2                  = 100;
			int offset                = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 1;
			int x0                    = 0;
			int y0                    = 1234;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 1000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 1;
			int x0                    = 0;
			int y0                    = 999;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 1000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 100;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 1;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 3;
			int mod2                  = 58585858;
			int offset                = 1;
			int expected__            = 66;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 500000;
			int x0                    = 123456;
			int y0                    = 0;
			int a                     = 1;
			int b                     = 0;
			int c                     = 1;
			int d                     = 1;
			int mod1                  = 1000000000;
			int mod2                  = 1000000000;
			int offset                = 0;
			int expected__            = 376544;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int n                     = 500000;
			int x0                    = 0;
			int y0                    = 0;
			int a                     = 0;
			int b                     = 0;
			int c                     = 0;
			int d                     = 0;
			int mod1                  = 1;
			int mod2                  = 1;
			int offset                = 0;
			int expected__            = 500000;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int n                     = 10;
			int x0                    = 999999957;
			int y0                    = 79;
			int a                     = 993948167;
			int b                     = 24597383;
			int c                     = 212151897;
			int d                     = 999940854;
			int mod1                  = 999999986;
			int mod2                  = 999940855;
			int offset                = 3404;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int n                     = ;
			int x0                    = ;
			int y0                    = ;
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int mod1                  = ;
			int mod2                  = ;
			int offset                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CatchTheBeat().maxCatched( n, x0, y0, a, b, c, d, mod1, mod2, offset );
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
