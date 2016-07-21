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
class BearPasswordLexic {
public:
	string findPassword( vector <int> x ) {
		int i,j;
		string ret;
		vector<int>L;
		for(int i=sz(x)-1;i>=0;i--){
			while(x[i]){
				L.PB(i+1);
				rep(j,0,i+1){
					x[i-j]-=1+j;
					if(x[i-j]<0)return "";
				}
			}
		}
		sort(all(L));
		int le=0,re=sz(L)-1;
		while(re>=le){
			while(L[re]--)ret+='a';
			re--;
			if(re>=le){
				while(L[le]--)ret+='b';
				le++;
			}
		}
		if(sz(ret)!=sz(x))return "";
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
			int x[]                   = {5,2,0,0,0};
			string expected__         = "aabaa";

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {4,2,1,0};
			string expected__         = "aaab";

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {3,1,1};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {4,3,2,1};
			string expected__         = "aaaa";

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {0};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int x[]                   = {4,0,3,2};
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int x[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int x[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int x[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BearPasswordLexic().findPassword( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ) );
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
