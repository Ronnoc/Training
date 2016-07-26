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
#define SZ size()
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
LL vis[1005];
class BearKRoads {
public:
	int maxHappy( vector <int> x, vector <int> a, vector <int> b, int K ) {
		int i,j;
		int ret=0;
		vector<pair<int,PII>>L;
		rep(i,0,sz(a))L.PB(MP(-x[a[i]]-x[b[i]],MP(a[i],b[i])));
		sort(all(L));
		int m=(K-1)*5+1;
		cmin(m,sz(L));
		LL sub=(1LL<<K)-1;
		memset(vis,-1,sizeof vis);
		while (sub < 1LL << m) {	//枚举大小为k的子集
			set<int>S;
			LL tp=sub;
			int sum=0;
			while(tp){
				int id=__builtin_ctzll(tp);
				tp^=1LL<<id;
				int u;
				u=L[id].BB.AA;
				if(vis[u]!=sub){
					vis[u]=sub;
					sum+=x[u];
				}
				u=L[id].BB.BB;
				if(vis[u]!=sub){
					vis[u]=sub;
					sum+=x[u];
				}
			}
			cmax(ret,sum);
			LL x = sub & -sub, y = sub + x;
			sub = (sub & ~y) / x >> 1 | y;
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
			int x[]                   = {10, 50, 50, 10};
			int a[]                   = {0, 1, 2};
			int b[]                   = {1, 2, 3};
			int K                     = 1;
			int expected__            = 100;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {10, 50, 50, 10};
			int a[]                   = {0, 1, 2};
			int b[]                   = {1, 2, 3};
			int K                     = 2;
			int expected__            = 120;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {42, 100, 500};
			int a[]                   = {0, 1};
			int b[]                   = {1, 2};
			int K                     = 2;
			int expected__            = 642;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {42, 100, 500, 999, 999, 999, 999};
			int a[]                   = {0, 1};
			int b[]                   = {1, 2};
			int K                     = 2;
			int expected__            = 642;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {969,467,808,263,179,428,595,557,406,80};
			int a[]                   = {5,4,9,7,9,3};
			int b[]                   = {4,0,8,8,0,1};
			int K                     = 3;
			int expected__            = 2841;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x[]                   = {1,2,3,4};
			int a[]                   = {0,0,0};
			int b[]                   = {1,2,3};
			int K                     = 2;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int x[]                   = {1,2,3,4,2};
			int a[]                   = {0,0,0,1};
			int b[]                   = {1,2,3,4};
			int K                     = 2;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int x[]                   = {8,18,14,10,7,16,4,19,6,12,17,10,12,3,15,8,15,12};
			int a[]                   = {0,15,1,5,7,3,17,4,15,3,13,14,4,7};
			int b[]                   = {8,10,16,13,2,10,2,10,11,13,0,9,3,6};
			int K                     = 7;
			int expected__            = 173;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 8: {
			int x[]                   = {999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 499, 499};
			int a[]                   = {0, 1, 2, 3, 4, 5, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 36};
			int b[]                   = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 37};
			int K                     = 7;
			int expected__            = 12986;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 9: {
			int x[]                   = ;
			int a[]                   = ;
			int b[]                   = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			int x[]                   = ;
			int a[]                   = ;
			int b[]                   = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearKRoads().maxHappy( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), K );
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
