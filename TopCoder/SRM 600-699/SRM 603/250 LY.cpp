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
class MaxMinTreeGame {
public:
	int findend( vector <int> edges, vector <int> costs ) {
		int i,j;
		int ret=-1;
		map<int,int>v;
		rep(i,0,sz(edges)){
			v[i+1]++;
			v[edges[i]]++;
		}
		for(auto pr:v)if(pr.BB==1)cmax(ret,costs[pr.AA]);
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
			int edges[]               = {0};
			int costs[]               = {4,6};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int edges[]               = {0,1};
			int costs[]               = {4,6,5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int edges[]               = {0,1,2,3};
			int costs[]               = {0,1,0,1,0};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int edges[]               = {0,0,0};
			int costs[]               = {5,1,2,3};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int edges[]               = {0,0};
			int costs[]               = {3,2,5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int edges[]               = ;
			int costs[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int edges[]               = ;
			int costs[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int edges[]               = ;
			int costs[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaxMinTreeGame().findend( vector <int>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
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
