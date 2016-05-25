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

int BIT[100500+10];
int LB( int w ) {return w&( -w );}
LL query( int w ) {
	LL ret=0;
	for ( w+=5; w>0; w-=LB( w ) )ret+=BIT[w];
	return ret;
}
void update( int w,int d ) {
	for ( w+=5; w<100500; w+=LB( w ) )BIT[w]+=d;
}
LL x[100500];
class PackingBallsDiv1 {
public:
  int minPacks (int K, int A, int B, int C, int D) {
    memset(BIT,0,sizeof BIT);
    int ret=0;
    int i,j;
    x[0]=A;
    for(i=1;i<K;i++)
			x[i]=(x[i-1]*B+C)%D+1;
    for(i=0;i<K;i++){
			int add=x[i]/K;
			if(add>0)ret+=add,x[i]-=add*K;
			update(K-x[i],1);
    }
    LL temp=K;
    for(i=0;i<=K;i++)
			cmin(temp,i+query(K-1-i));
    return int(ret+temp);
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
			int K                     = 3;
			int A                     = 4;
			int B                     = 2;
			int C                     = 5;
			int D                     = 6;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int K                     = 1;
			int A                     = 58;
			int B                     = 23;
			int C                     = 39;
			int D                     = 93;
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int K                     = 23;
			int A                     = 10988;
			int B                     = 5573;
			int C                     = 4384;
			int D                     = 100007;
			int expected__            = 47743;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int K                     = 100000;
			int A                     = 123456789;
			int B                     = 234567890;
			int C                     = 345678901;
			int D                     = 1000000000;
			int expected__            = 331988732;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int K                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int K                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int K                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks( K, A, B, C, D );
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
