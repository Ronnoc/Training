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

bool ok[51][256][256][8];
class TrySail {
public:
	int get( vector <int> L ) {
		memset(ok,0,sizeof ok);
		ok[0][0][0][0]=1;
		int n=L.SZ;
		rep(i,0,n)rep(j,0,256)rep(k,0,256)rep(l,0,8)if(ok[i][j][k][l]){
			ok[i+1][j^L[i]][k][l|1]=1;
			ok[i+1][j][k^L[i]][l|2]=1;
			ok[i+1][j][k][l|4]=1;
		}
		int ret=-1;
		int all=0;
		rep(i,0,n)all^=L[i];
		rep(j,0,256)rep(k,0,256)if(ok[n][j][k][7]){
			int l=all^j^k;
			cmax(ret,j+k+l);
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
			int strength[]            = {2,3,3};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int strength[]            = {7,3,5,2};
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int strength[]            = {13,13,13,13,13,13,13,13};
			int expected__            = 26;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int strength[]            = {114,51,4,191,9,81,0,89,3};
			int expected__            = 470;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int strength[]            = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
			int expected__            = 567;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int strength[]            = {14,13,3,7};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrySail().get( vector <int>( strength, strength + ( sizeof strength / sizeof strength[0] ) ) );
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
