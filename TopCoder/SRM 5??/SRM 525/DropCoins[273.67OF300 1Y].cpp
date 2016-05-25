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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.begin(),X.end())
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
int dp[33][33][33][33];
vector <string> B;
int play(int l,int r,int n){
	int d=min(l,n-1-r);
	return d+n-(r-l+1);
}
int dfs(int i,int j,int k,int l){
	int &tp=dp[i][j][k][l];
	if(tp!=-1)return tp;
	if(i<k)return tp=dfs(i,j,k-1,l)+dfs(k,j,k,l);
	if(j<l)return tp=dfs(i,j,k,l-1)+dfs(i,l,k,l);
	return tp=B[i][j]=='o';
}
class DropCoins {
public:
	int getMinimum ( vector <string> Bo, int K ) {
		B=Bo;
		int ret=-1;
		int i,j,k,l;
		int n=B.SZ,m=B[0].SZ;
		memset(dp,-1,sizeof dp);
		for(i=0;i<n;i++)for(j=0;j<m;j++)
			for(k=i;k<n;k++)for(l=j;l<m;l++){
				if(dfs(i,j,k,l)==K){
					if(ret==-1)ret=play(i,k,n)+play(j,l,m);
					else ret=min(ret,play(i,k,n)+play(j,l,m));
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
			string board[]            = {".o.." ,"oooo" ,"..o."} ;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {".....o" ,"......" ,"oooooo" ,"oooooo" ,"......" ,"o....."} ;
			int K                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {"...." ,".oo." ,".oo." ,"...."} ;
			int K                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {"......." ,"..ooo.." ,"ooooooo" ,".oo.oo." ,"oo...oo"} ;
			int K                     = 12;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {"................." ,".ooooooo...oooo.." ,".ooooooo..oooooo." ,".oo.......oo..oo." ,".oo.......oo..oo." ,".ooooo.....oooo.." ,".ooooooo...oooo.." ,".....ooo..oo..oo." ,"......oo..oo..oo." ,".ooooooo..oooooo." ,".oooooo....oooo.." ,"................."} ;
			int K                     = 58;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K );
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
