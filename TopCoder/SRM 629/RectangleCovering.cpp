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

void update(int &ret,int a){
	if(ret==-1)ret=a;
	else cmin(ret,a);
}
class RectangleCovering {
public:
  int minimumNumber (int h, int w, vector <int> H, vector <int> W) {
    int ret=-1;
    int i,j;
    if(h>w)swap(h,w);
//    for(i=0;i<H.SZ;i++)if(H[i]>W[i])swap(H[i],W[i]);//H[i]<=W[i]
    priority_queue<int>A,B;
    for(i=0;i<H.SZ;i++){
			if(H[i]>h)A.push(W[i]);
			else if(W[i]>h)A.push(H[i]);
			if(H[i]>w)B.push(W[i]);
			else if(W[i]>w)B.push(H[i]);
    }
    int ch=h,cw=w;
    int aa=0,ab=0;
    while(!A.empty()&&cw>0){
			cw-=A.top();
			A.pop();
			aa++;
    }
    while(!B.empty()&&ch>0){
			ch-=B.top();
			B.pop();
			ab++;
    }
    if(ch<=0)update(ret,ab);
    if(cw<=0)update(ret,aa);
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor

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
			int holeH                 = 5;
			int holeW                 = 5;
			int boardH[]              = {8,8,8};
			int boardW[]              = {2,3,4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int holeH                 = 10;
			int holeW                 = 10;
			int boardH[]              = {6,6,6,6};
			int boardW[]              = {6,6,6,6};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int holeH                 = 5;
			int holeW                 = 5;
			int boardH[]              = {5};
			int boardW[]              = {5};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int holeH                 = 3;
			int holeW                 = 5;
			int boardH[]              = {6};
			int boardW[]              = {4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int holeH                 = 10000;
			int holeW                 = 5000;
			int boardH[]              = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
			int boardW[]              = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int holeH                 = ;
			int holeW                 = ;
			int boardH[]              = ;
			int boardW[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RectangleCovering().minimumNumber( holeH, holeW, vector <int>( boardH, boardH + ( sizeof boardH / sizeof boardH[0] ) ), vector <int>( boardW, boardW + ( sizeof boardW / sizeof boardW[0] ) ) );
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
