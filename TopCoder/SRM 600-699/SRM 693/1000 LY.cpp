// Paste me into the FileEdit configuration dialog
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
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
int fr[1<<21];
class TriangleFree {
public:
	long long count( int n, vector <int> x, vector <int> y ) {
		int m=sz(x);
		vector<int>G[66];
		rep(i,0,m)
			G[x[i]].PB(y[i]),G[y[i]].PB(x[i]);
		int g[66][66];
		memset(g,0,sizeof g);
		rep(i,0,m)g[x[i]][y[i]]=g[y[i]][x[i]]=1;
		int deg[66];
		memset(deg,0,sizeof deg);
		rep(i,0,n)deg[i]=sz(G[i]);
		int red[66];
		memset(red,-1,sizeof red);
		vector<int>R;
		while(1){
			int mxid=max_element(deg,deg+n)-deg;
			if(deg[mxid]<3)break;
			red[mxid]=sz(R);
			R.PB(mxid);
			for(auto v:G[mxid])
				if(-1==red[v])
					deg[v]--,deg[mxid]--;
		}
		fr[0]=1;
		rep(msk,1,1<<sz(R)){
			int ui=__builtin_ctz(msk);
			int u=R[ui];
			vector<int>adj;
			for(auto v:G[u])if(~red[v]&&(msk>>red[v]&1))
				adj.PB(v);
			fr[msk]=fr[msk^(1<<ui)];
			rep(i,0,sz(adj))
				rep(j,i+1,sz(adj))
					fr[msk]&=!g[adj[i]][adj[j]];
		}
		VI A;
		vector<VI>B,C;
		int vis[66];
		memset(vis,0,sizeof vis);
		rep(i,0,n)if(-1==red[i]&&deg[i]==0)A.PB(i);
		rep(i,0,n)if(-1==red[i]&&!vis[i]&&deg[i]==1){
			vector<int>L;
			int u=i,fa=-1;
			while(1){
				L.PB(u);
				vis[u]=1;
				int v=-1;
				for(auto w:G[u])if(-1==red[w]&&w!=fa)
					v=w;
				if(~v){fa=u;u=v;}
				else break;
			}
			B.PB(L);
		}
		rep(i,0,n)if(-1==red[i]&&!vis[i]&&deg[i]==2){
			vector<int>L;
			int u=i,fa=-1;
			for(auto v:G[u])if(-1==red[v])fa=v;
			while(1){
				L.PB(u);
				vis[u]=1;
				int v=-1;
				for(auto w:G[u])if(-1==red[w]&&w!=fa)
					v=w;
				if(v!=i){fa=u;u=v;}
				else break;
			}
			C.PB(L);
		}
		long long ret=0;
		int valid[66];
		int vp[66][66];
		VI con[66];
		int mvp[66];
		rep(msk,0,1<<sz(R))if(fr[msk]){
			LL mul=1;
			memset(mvp,0,sizeof mvp);
			rep(i,0,n)con[i].clear();
			rep(i,0,sz(R))if(msk>>i&1)
				for(auto v:G[R[i]])
					con[v].PB(R[i]),mvp[v]|=1<<i;
			rep(i,0,n){
				valid[i]=1;
				rep(u,0,sz(con[i]))
					rep(v,u+1,sz(con[i]))
						valid[i]&=!g[ con[i][u] ][ con[i][v] ];
			}
			for(auto u:A)
				mul<<=valid[u];
			for(auto L:B){
				vector<LL>dp[2];
				rep(j,0,2)dp[j].resize(sz(L));
				dp[0][0]=1;
				dp[1][0]=valid[L[0]];
				rep(k,1,sz(L)){
					dp[0][k]=dp[0][k-1]+dp[1][k-1];
					dp[1][k]=0;
					if(valid[L[k]]){
						dp[1][k]+=dp[0][k-1]; 
						if(!(mvp[L[k]]&mvp[L[k-1]]))
							dp[1][k]+=dp[1][k-1];
					}
				}
				mul*=dp[0][sz(L)-1]+dp[1][sz(L)-1];
			}
			for(auto L:C){
				vector<LL>dp[2];
				rep(j,0,2)dp[j].resize(sz(L));
				dp[0][0]=1;
				dp[1][0]=0;
				rep(k,1,sz(L)){
					dp[0][k]=dp[0][k-1]+dp[1][k-1];
					dp[1][k]=0;
					if(valid[L[k]]){
						dp[1][k]+=dp[0][k-1]; 
						if(!(mvp[L[k]]&mvp[L[k-1]]))
							dp[1][k]+=dp[1][k-1];
					}
				}
				LL now=dp[0][sz(L)-1]+dp[1][sz(L)-1];
				if(valid[L[0]]){
					dp[0][0]=0;
					dp[1][0]=1;
					rep(k,1,sz(L)){
						dp[0][k]=dp[0][k-1]+dp[1][k-1];
						dp[1][k]=0;
						if(valid[L[k]]){
							dp[1][k]+=dp[0][k-1]; 
							if(!(mvp[L[k]]&mvp[L[k-1]]))
								dp[1][k]+=dp[1][k-1];
						}
					}
					now+=dp[0][sz(L)-1];
					int fail=mvp[L[0]]&mvp[L[sz(L)-1]];
					if(!fail)now+=dp[1][sz(L)-1];
				}
				if(sz(L)==3){
					int fail=0;
					rep(j,0,3){
						fail|=!valid[L[j]];
						fail|=mvp[L[j]]&mvp[L[(j+1)%3]];
					}
					if(!fail)now--;
				}
				mul*=now;
			}
			ret+=mul;
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
			int n                     = 4;
			int x[]                   = {0,1,2,3};
			int y[]                   = {1,2,0,2};
			long long expected__      = 14LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 5;
			int x[]                   = {0,0,0,0,1,1,1,2,2,3};
			int y[]                   = {1,2,3,4,2,3,4,3,4,4};
			long long expected__      = 16LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 6;
			int x[]                   = {0,0,1,1,1,3,1,2,2,4};
			int y[]                   = {1,2,2,3,4,4,5,4,5,5};
			long long expected__      = 40LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 60;
			int x[]                   = {10,20,30};
			int y[]                   = {20,30,10};
			long long expected__      = 1008806316530991104LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
     	case 4: {
			int n                     = 31;
			int x[]                   = {0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9};
			int y[]                   = {1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3};
			long long expected__      = 1077229952LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int n                     = 60;
			int x[]                   = {0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9};
			int y[]                   = {1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3};
			long long expected__      = 578333426763956224LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int n                     = 60;
			int x[]                   = {0, 0, 0, 4, 4, 4, 5, 5, 5, 9, 9, 9, 10, 10, 10, 14, 14, 14, 15, 15, 15, 19, 19, 19, 20, 20, 20, 24, 24, 24, 25, 25, 25, 29, 29, 29, 30, 30, 30, 34, 34, 34, 35, 35, 35, 39, 39, 39, 40, 40, 40, 44, 44, 44, 45, 45, 45, 49, 49, 49};
			int y[]                   = {1, 2, 3, 1, 2, 3, 6, 7, 8, 6, 7, 8, 11, 12, 13, 11, 12, 13, 16, 17, 18, 16, 17, 18, 21, 22, 23, 21, 22, 23, 26, 27, 28, 26, 27, 28, 31, 32, 33, 31, 32, 33, 36, 37, 38, 36, 37, 38, 41, 42, 43, 41, 42, 43, 46, 47, 48, 46, 47, 48};
			long long expected__      = 1152921504606846976LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TriangleFree().count( n, vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
