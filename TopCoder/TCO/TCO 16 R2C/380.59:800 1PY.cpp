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

const LL MOD = 1000000007;
LL inv2=(MOD+1)/2;
LL u[2005],v[2005];
LL w[2005];
LL dp[2005][2005];
LL extGcd (LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if (b) {
		ret = extGcd (b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}
LL modInv (LL a, LL m) {
	LL x, y;
	extGcd(a, m, x, y);
	return (m + x % m) % m;
}
class BearCircleGame {
public:
	int winProbability( int n, int k ) {
		cout<<n<<" "<<k<<"\n";
		int i,j;
		int ret=0;
		dp[1][0]=1;
		for(i=2;i<=n;i++){
			w[0]=0;
			for(j=1;j<i;j++)
				w[j]=dp[i-1][(j+k-1+i-1)%(i-1)]*inv2%MOD;
			int d=k%i;
			int g=__gcd(i,k);
			for(j=0;j<g;j++){
				int x=j;
				u[x]=1,v[x]=0;
				while(1){
					int y=(x+d)%i;
					LL uu=2*u[x]%MOD;
					LL vv=(2*v[x]-2*w[x]+2*MOD)%MOD;
					if(y==j){
						LL z;
						if(uu!=1)z=(MOD-vv*modInv(uu-1,MOD)%MOD)%MOD;
						else z=0;
						dp[i][j]=z;
						for(x=(j+d)%i;x!=j;x=(x+d)%i){
							dp[i][x]=(u[x]*z+v[x])%MOD;
						}
						break;
					}else {
						u[y]=uu;
						v[y]=vv;
						x=y;
					}
				}
			}
		}
		return dp[n][(k-1)%n];
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
			int n                     = 2;
			int k                     = 1;
			int expected__            = 333333336;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 2;
			int k                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 3;
			int k                     = 2;
			int expected__            = 142857144;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 3;
			int k                     = 1;
			int expected__            = 238095240;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 4;
			int k                     = 4;
			int expected__            = 142857144;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int n                     = 5;
			int k                     = 1000000000;
			int expected__            = 142857144;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int n                     = 2000;
			int k                     = 123;
			int expected__            = 429232785;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int n                     = 1987;
			int k                     = 987654321;
			int expected__            = 623410299;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 8: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearCircleGame().winProbability( n, k );
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
