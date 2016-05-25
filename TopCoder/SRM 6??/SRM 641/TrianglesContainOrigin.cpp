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

bool cmp(const PII &A,const PII &B){
	return 1LL*A.BB*B.AA<1LL*A.AA*B.BB;
}
class TrianglesContainOrigin {
public:
  long long count (vector <int> x, vector <int> y) {
    long long ret=0;
    int i,j,n=x.SZ;
//    for(i=0;i<n;i++)printf("%4d",x[i]);printf("\n");
//    for(i=0;i<n;i++)printf("%4d",y[i]);printf("\n");
    for(i=0;i<n;i++){
			vector<PII>L,R;
			int X=x[i],Y=y[i];
			for(j=0;j<n;j++)if(j!=i){
				if(1LL*Y*x[j]==1LL*X*y[j])continue;
				if(1LL*Y*x[j]>1LL*X*y[j])L.PB(MP(x[j],y[j]));
				else R.PB(MP(x[j],y[j]));
			}
			sort(L.OP,L.ED,cmp);
			sort(R.OP,R.ED,cmp);
			int id=R.SZ;
			for(j=L.SZ-1;j>=0;j--){
				while(id&&cmp(R[id-1],L[j]))id--;
				ret+=R.SZ-id;
			}
    }
    return ret/3;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int x[]                   = {-1,-1,1};
			int y[]                   = {1,-1,0};
			long long expected__      = 1LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {-1,-1,1,2};
			int y[]                   = {1,-1,2,-1};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {-1,-2,3,3,2,1};
			int y[]                   = {-2,-1,1,2,3,3};
			long long expected__      = 8LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6};
			int y[]                   = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9};
			long long expected__      = 256LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TrianglesContainOrigin().count( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
