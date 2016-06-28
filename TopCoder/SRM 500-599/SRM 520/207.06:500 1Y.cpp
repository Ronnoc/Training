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
const int MXN = 110000+60000+30000+5;
int dp[2][MXN];
int sp[2][MXN];
int f[8][4][MXN];
int sf[8][4][MXN];
class SRMIntermissionPhase {
	int play(string s){
		int ret=0;
		rep(i,0,sz(s))if(s[i]=='Y')
			ret|=1<<i;
		return ret;
	}
public:
	int countWays( vector <int> pts, vector <string> dsp ) {
		memset(dp,0,sizeof dp);
		memset(f,0,sizeof f);
		rep(i,0,1<<sz(pts)){
			int last=0;
			f[i][0][0]=1;
			rep(j,0,sz(pts)){
				sf[i][j][0]=f[i][j][0];
				last+=pts[j];
				rep(k,1,last+1)
					sf[i][j][k]=(sf[i][j][k-1]+f[i][j][k])%MOD;
				rep(k,0,last+1){
					if(i>>j&1){
						if(k>=1)
							f[i][j+1][k]+=sf[i][j][k-1];
						if(k>pts[j])
							f[i][j+1][k]+=MOD-sf[i][j][k-pts[j]-1];
					}else 
						f[i][j+1][k]=f[i][j][k];
					f[i][j+1][k]%=MOD;
				}
			}
		}
		int n=sz(dsp);
		reverse(all(dsp));
		int full=accumulate(all(pts),0)+1;
		int x=0,y=1;
		dp[x][0]=1;
		rep(i,0,n){
			sp[x][0]=dp[x][0];
			rep(j,1,full)
				sp[x][j]=(sp[x][j-1]+dp[x][j])%MOD;
			dp[y][0]=1LL*dp[x][0]*f[play(dsp[i])][3][0]*(i==0)%MOD;
			rep(j,1,full)
				dp[y][j]=1LL*f[play(dsp[i])][3][j]*sp[x][j-1]%MOD;
			swap(x,y);
		}
		LL ret=0;
		rep(j,0,full)
			ret+=dp[x][j]%MOD;
		return ret%MOD;
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
			int points[]              = {2, 4, 6};
			string description[]      = {"NNN",  "NNN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int points[]              = {30000, 60000, 90000};
			string description[]      = {"NYN",  "NYN"};
			int expected__            = 799969993;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int points[]              = {25000, 45000, 110000};
			string description[]      = {"NNN",  "YYY"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int points[]              = {25600, 51200, 102400};
			string description[]      = {"NYY",  "YNY",  "YYY",  "YNN",  "YYN",  "NNY",  "NYN",  "NNN"};
			int expected__            = 867560805;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int points[]              = ;
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int points[]              = ;
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int points[]              = ;
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays( vector <int>( points, points + ( sizeof points / sizeof points[0] ) ), vector <string>( description, description + ( sizeof description / sizeof description[0] ) ) );
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
