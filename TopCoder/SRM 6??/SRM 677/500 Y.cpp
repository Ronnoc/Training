/*
标准类背包树dp
dp[i][j][k]表示i为根子树，最深节点为j，字数直径为k的种数
类背包转移即可
*/
#line 89 "DiameterOfRandomTree.cpp"
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

double dp[55][105][105];
vector<PII>lp[55];
double tp[2][105][105];
vector<PII>lt[2];
vector<int>G[55];
void dfs(int u,int f){
	int i,j,k;
	for(i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		dfs(v,u);
	}
	memset(tp,0,sizeof tp);
	int x=0,y=1;
	lt[x].clear();
	tp[x][0][0]=1;
	lt[x].PB(MP(0,0));
	for(i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		memset(tp[y],0,sizeof tp[y]);
		lt[y].clear();
		for(j=0;j<lt[x].SZ;j++){
			int a=lt[x][j].AA,b=lt[x][j].BB;
			for(k=0;k<lp[v].SZ;k++){
				int c=lp[v][k].AA,d=lp[v][k].BB;
				//cout<<a<<" "<<b<<" "<<c<<" "<<d<<": ";
				int U,V;
				//len 1
				U=max(a,c+1);
				V=max(d,max(a+1+c,b));
				//cout<<u<<","<<v<<" ";
				tp[y][U][V]+=.5*tp[x][a][b]*dp[v][c][d];
				//len 2
				U=max(a,c+2);
				V=max(d,max(a+2+c,b));
				//cout<<u<<","<<v<<"\n";
				tp[y][U][V]+=.5*tp[x][a][b]*dp[v][c][d];
			}
		}
		for(j=0;j<=102;j++)for(k=0;k<=102;k++)if(tp[y][j][k]>1e-100){
			//cout<<u<<"+"<<v<<"-> "<<j<<" "<<k<<" "<<tp[y][j][k]<<"\n";
			lt[y].PB(MP(j,k));
		}
		swap(x,y);
	}
	lp[u]=lt[x];
	for(j=0;j<=102;j++)for(k=0;k<=102;k++)dp[u][j][k]=tp[x][j][k];
	for(i=0;i<lp[u].SZ;i++){
		int a=lp[u][i].AA;
		int b=lp[u][i].BB;
		//cout<<u<<"~"<<a<<" "<<b<<" "<<dp[u][a][b]<<"\n";
	}
}
class DiameterOfRandomTree {
	public:
	double getExpectation(vector <int> a, vector <int> b) {
		int n=a.SZ+1;
		int i,j,k;
		for(i=0;i<n;i++)G[i].clear(),lp[i].clear();
		for(i=0;i<a.SZ;i++)G[a[i]].PB(b[i]),G[b[i]].PB(a[i]);
		dfs(0,-1);
		double ans=0;
		for(i=0;i<=2*n;i++)for(j=0;j<2*n;j++)ans+=dp[0][i][j]*j;
		return ans;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int a[]                   = {0,1,2,3};
			int b[]                   = {1,2,3,4};
			double expected__         = 6.0;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {0,0,0};
			int b[]                   = {1,2,3};
			double expected__         = 3.375;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {0,0,0,1,4};
			int b[]                   = {1,2,3,4,5};
			double expected__         = 6.25;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {0,0,0,0,0,0,0,0};
			int b[]                   = {1,2,3,4,5,6,7,8};
			double expected__         = 3.9609375;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a[]                   = {0,0,0,1,2,3,5,6,8};
			int b[]                   = {1,2,3,4,5,6,7,8,9};
			double expected__         = 10.53125;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int a[]                   = {0,0,1,1,2,2,3,3,4,4 ,5 ,5 ,6 ,6 ,7 ,7 ,8 ,8 ,9 ,9 ,10,10,11,11
			,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24};
			int b[]                   = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24
			,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			double expected__         = -1;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = DiameterOfRandomTree().getExpectation( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ) );
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
