// Paste me into the FileEdit configuration dialog

#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmax(x,y) x=max((x),(y))
#define cmin(x,y) x=min((x),(y))

typedef long long LL;
typedef pair<int,int> PII;

int fa[1005];
int getfa(int u){
	return fa[u]==u?u:fa[u]=getfa(fa[u]);
}
int dp[1005][1005];
class DarkMatterParticles {
public:
	string SplitParticles( int n, int k, vector <int> x, vector <int> y ) {
		int i,j;
		string ret;
		for(i=0;i<=n;i++)
			fa[i]=i;
		for(i=0;i<x.SZ;i++){
			int u=x[i],v=y[i];
			int fu=getfa(u),fv=getfa(v);
			fa[fu]=fv;
		}
		map<int,int>S;
		for(i=0;i<n;i++)
			S[getfa(i)]++;
		vector<int>L;
		for(auto s:S)
			L.PB(s.BB);
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(i=0;i<L.SZ;i++)
			for(j=0;j<=1000;j++)if(dp[i][j]){
				dp[i+1][j+L[i]]=1;
				dp[i+1][j]=1;
			}
		return dp[L.SZ][k]?"Possible":"Impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int n                     = 4;
			int k                     = 2;
			int x[]                   = {0,1,2,3};
			int y[]                   = {1,2,3,0};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 4;
			int k                     = 4;
			int x[]                   = {0,1,2,3};
			int y[]                   = {1,2,3,0};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 4;
			int k                     = 2;
			int x[]                   = {0,1,2,3};
			int y[]                   = {2,3,0,1};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 4;
			int k                     = 3;
			int x[]                   = {0,1,2,3};
			int y[]                   = {2,3,0,1};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 3;
			int k                     = 3;
			int x[]                   = {0,1,2};
			int y[]                   = {1,2,0};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int n                     = 3;
			int k                     = 2;
			int x[]                   = {0,1,2};
			int y[]                   = {1,2,0};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int n                     = 6;
			int k                     = 1;
			int x[]                   = {0,1,4};
			int y[]                   = {1,2,5};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int n                     = 6;
			int k                     = 2;
			int x[]                   = {0,1,4};
			int y[]                   = {1,2,5};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 8: {
			int n                     = 6;
			int k                     = 3;
			int x[]                   = {0,1,4};
			int y[]                   = {1,2,5};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 9: {
			int n                     = 6;
			int k                     = 6;
			int x[]                   = {0,1,4};
			int y[]                   = {1,2,5};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 10: {
			int n                     = ;
			int k                     = ;
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 11: {
			int n                     = ;
			int k                     = ;
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 12: {
			int n                     = ;
			int k                     = ;
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = DarkMatterParticles().SplitParticles( n, k, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
