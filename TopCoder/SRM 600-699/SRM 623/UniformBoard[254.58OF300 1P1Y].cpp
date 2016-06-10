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

class UniformBoard {
public:
  int getBoard (vector <string> b, int K) {
    int ret=0;
    int i,j,p,q,z,x;
    int n=b.SZ;
    int A=0,B=0,E=0;
    for(i=0;i<b.SZ;i++)for(j=0;j<b.SZ;j++)if(b[i][j]=='P')B++;
    for(i=0;i<b.SZ;i++)for(j=0;j<b.SZ;j++)if(b[i][j]=='A')A++;
    for(i=0;i<b.SZ;i++)for(j=0;j<b.SZ;j++)if(b[i][j]=='.')E++;
    for(i=0;i<b.SZ;i++)for(j=0;j<b.SZ;j++)for(p=i;p<b.SZ;p++)for(q=j;q<b.SZ;q++){
			int ca=0,cb=0,ce=0;
			int S=(p-i+1)*(q-j+1);
			if(S>A)continue;
			for(z=i;z<=p;z++)for(x=j;x<=q;x++)if(b[z][x]=='P')cb++;
			for(z=i;z<=p;z++)for(x=j;x<=q;x++)if(b[z][x]=='A')ca++;
			for(z=i;z<=p;z++)for(x=j;x<=q;x++)if(b[z][x]=='.')ce++;
			if(cb==0&&ce==0){cmax(ret,S);continue;}
			int oa=A-ca,ob=B-cb,oe=E-ce;
			int cnt=0;
			if(oa&&ce){
				int f=min(oa,ce);
				cnt+=f;
				oa-=f,ca+=f;
				ce-=f,oe+=f;
			}
			if(cnt>K)continue;
			while(1){
				if(cb==0&&ce==0){if(cnt<=K)cmax(ret,S);break;}
				if(cb&&oa&&oe){
					cnt+=2;
					oa--,ca++;
					ob++,cb--;
				}else break;
				if(cnt>K)break;
			}
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
			string board[]            = {"AP",  ".A"};
			int K                     = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {"AP",  ".A"};
			int K                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {"PPP",  "APA",  "A.P"};
			int K                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {"AAA",  "PPP",  "AAA"};
			int K                     = 10;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {"."};
			int K                     = 1000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string board[]            = {"PPAAPA..AP",  "PPA.APAP..",  "..P.AA.PPP",  "P.P..APAA.",  "P.P..P.APA",  "PPA..AP.AA",  "APP..AAPAA",  "P.P.AP...P",  ".P.A.PAPPA",  "..PAPAP..P"};
			int K                     = 10;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			string board[]            = {".A.A","A.A.",".A.A","A.A."};
			int K                     = 100;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UniformBoard().getBoard( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
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
