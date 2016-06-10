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

int sum[55][55];
int call(int a,int b,int c,int d){
	return sum[c][d]+sum[a-1][b-1]-sum[a-1][d]-sum[c][b-1];
}
class ChocolateDividingEasy {
public:
  int findBest (vector <string> s) {
    int ret=-1;
    int i,j;
    int n=s.SZ;
    int m=s[0].SZ;
    memset(sum,0,sizeof sum);
    for(i=0;i<n;i++)for(j=0;j<m;j++)
			sum[i+1][j+1]=s[i][j]-'0';
		for(i=0;i<=n;i++)for(j=1;j<=m;j++)sum[i][j]+=sum[i][j-1];
		for(i=1;i<=n;i++)for(j=0;j<=m;j++)sum[i][j]+=sum[i-1][j];
		int a,b,c,d;
		for(a=1;a<=n;a++)for(b=a+1;b<n;b++)
			for(c=1;c<=m;c++)for(d=c+1;d<m;d++){
				int S[9];
				S[0]=call(1,1,a,c);
				S[1]=call(1,c+1,a,d);
				S[2]=call(1,d+1,a,m);
				S[3]=call(a+1,1,b,c);
				S[4]=call(a+1,c+1,b,d);
				S[5]=call(a+1,d+1,b,m);
				S[6]=call(b+1,1,n,c);
				S[7]=call(b+1,c+1,n,d);
				S[8]=call(b+1,d+1,n,m);
				int mS=*min_element(S,S+9);
				cmax(ret,mS);
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
			string chocolate[]        = { "9768", "6767", "5313" };
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ChocolateDividingEasy().findBest( vector <string>( chocolate, chocolate + ( sizeof chocolate / sizeof chocolate[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string chocolate[]        = { "36753562", "91270936", "06261879", "20237592", "28973612", "93194784" };
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = ChocolateDividingEasy().findBest( vector <string>( chocolate, chocolate + ( sizeof chocolate / sizeof chocolate[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string chocolate[]        = { "012", "345", "678" };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ChocolateDividingEasy().findBest( vector <string>( chocolate, chocolate + ( sizeof chocolate / sizeof chocolate[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 3: {
			string chocolate[]        = {"999","999","999"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ChocolateDividingEasy().findBest( vector <string>( chocolate, chocolate + ( sizeof chocolate / sizeof chocolate[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 4: {
			string chocolate[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChocolateDividingEasy().findBest( vector <string>( chocolate, chocolate + ( sizeof chocolate / sizeof chocolate[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			string chocolate[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChocolateDividingEasy().findBest( vector <string>( chocolate, chocolate + ( sizeof chocolate / sizeof chocolate[0] ) ) );
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
