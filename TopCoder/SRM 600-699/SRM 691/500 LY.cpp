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
int dp[55][55][505];
class Moneymanager {
public:
	int getbest( vector <int> a, vector <int> b, int X ) {
		int i,j,k;
		int n=sz(a);
		vector<PII>L;
		rep(i,0,n)L.PB(MP(a[i],b[i]));
		rep(i,0,n)rep(j,i+1,n){
			if(L[i].AA*L[j].BB<L[j].AA*L[i].BB)
				swap(L[i],L[j]);
		}
		int Sall=accumulate(all(b),0);
		int ans=-1;
		rep(S,0,Sall+1){
			memset(dp,-1,sizeof dp);
			dp[0][0][0]=0;
			int sum=0;
			rep(i,0,n){
				rep(k,0,i+1)rep(j,0,S+1)if(~dp[i][k][j]){
					cmax(dp[i+1][k+1][j+L[i].BB],dp[i][k][j]+L[i].AA*(Sall-j));
					cmax(dp[i+1][k][j],dp[i][k][j]+L[i].AA*(Sall-S-(sum-j)));
				}
				sum+=L[i].BB;
			}
			if(~dp[n][n/2][S])
				cmax(ans,dp[n][n/2][S]+(Sall-S)*X);
		}
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
			int a[]                   = {1,1};
			int b[]                   = {2,1};
			int X                     = 0;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a[]                   = {1,1};
			int b[]                   = {1,5};
			int X                     = 10;
			int expected__            = 61;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a[]                   = {4,4,6,6};
			int b[]                   = {2,2,3,3};
			int X                     = 100;
			int expected__            = 726;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a[]                   = {30,13,28,59,26,62,48,75,6,69,94,51};
			int b[]                   = {4,6,4,5,4,3,1,5,6,5,2,2};
			int X                     = 62;
			int expected__            = 22096;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			int a[]                   = {71, 86, 90, 95, 14, 98, 36, 26, 62, 90, 79, 81, 42, 62, 74, 23, 76, 25, 86, 57, 93, 24, 51, 3, 80, 17, 6, 55, 71, 3, 95, 2, 34, 63, 35, 55, 8, 93, 79, 26};
			int b[]                   = {2, 6, 1, 3, 4, 2, 2, 4, 6, 1, 4, 3, 3, 1, 1, 2, 2, 4, 7, 2, 6, 5, 1, 3, 3, 2, 7, 3, 7, 1, 3, 1, 7, 1, 3, 3, 4, 7, 3, 1};
			int X                     = 17;
			int expected__            = 212683;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Moneymanager().getbest( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), X );
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
