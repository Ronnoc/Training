#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define PB push_back
#define SZ size()
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
VI G[55];
VL W;
LL dp[55][2];
void dfs(int u,int f,LL x){
	dp[u][0] = modPow(x,W[u],MOD);
	dp[u][1] = 0;
	rep(i,0,sz(G[u])){
		int v= G[u][i];
		if(v==f)continue;
		dfs(v,u,x);
		dp[u][0] = (dp[u][0]*(dp[v][0]+1))%MOD;
		dp[u][1] += dp[v][1];
	}
	dp[u][1]=(dp[u][1]+dp[u][0])%MOD;
	//cout<<u<<" "<<f<<" "<<dp[u][0]<<" "<<dp[u][1]<<"\n";
}
class SubtreeSumHash {
public:
	int count( vector <int> weight, vector <int> p, int x ) {
		int i,j;
		int ret;
		W.clear();
		memset(dp,0,sizeof dp);
		rep(i,0,sz(weight))W.PB(weight[i]);
		LL X=x;
		rep(i,0,sz(W))G[i].clear();
		rep(i,0,sz(p)){
			int u=i+1,v=p[i];
			G[u].PB(v);
			G[v].PB(u);
		}
		dfs(0,-1,X);
		return (dp[0][1]%MOD+MOD)%MOD;
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
			int weight[]              = {1,2,3};
			int p[]                   = {0,1};
			int x                     = 10;
			int expected__            = 1102110;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int weight[]              = {123456789,987654321,111111111,999999999};
			int p[]                   = {0,0,0};
			int x                     = 1;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int weight[]              = {10};
			int p[]                   = {};
			int x                     = 10;
			int expected__            = 999999937;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int weight[]              = {3,7,6,8,9,4,2,1,5,6,7,8,9,6,1,2,3,5};
			int p[]                   = {0,0,0,3,1,1,2,0,0,3,7,8,9,0,0,4,1};
			int x                     = 987654321;
			int expected__            = 46327623;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int weight[]              = ;
			int p[]                   = ;
			int x                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int weight[]              = ;
			int p[]                   = ;
			int x                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int weight[]              = ;
			int p[]                   = ;
			int x                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SubtreeSumHash().count( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ), vector <int>( p, p + ( sizeof p / sizeof p[0] ) ), x );
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
