/*
dp[i][j][k]表示i个数最小值在第j项，当前笛卡尔树func值为k的种数
dp[i+j+1][i][ i-p+ip+q+iq+1]+=dp[i][p][ip]*dp[j][q][iq]*comb(i+j,i) simple的dp
dp[x][y][z]->X[x][x-y+z]，Y[x][y+z]
dp[i+j+1][i][p+q+1]+=X[i][p]*Y[j][q]*comb(i+j,i) 优化的dp
注意p+q+1的范围超过了N+S
*/
#line 133 "BearPermutations.cpp"
#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmax(x,y) x=max(x,y);
#define cmin(x,y) x=min(x,y);
typedef long long LL;
typedef pair<int,int> PII;
LL dp[105][105][105];
LL cb[105][105];
LL X[105][205],Y[105][205];
class BearPermutations {
	public:
	void add(LL &a,LL b,LL MOD){a=(a%MOD+b%MOD)%MOD;}
	int countPermutations(int N, int S, LL MOD) {
		int i,j,k,p,q;
		for(i=0;i<=N;i++){
			cb[i][0]=cb[i][i]=1;
			for(j=1;j<i;j++)
				cb[i][j]=(cb[i-1][j-1]+cb[i-1][j])%MOD;
		}
		memset(dp,0,sizeof dp);
		memset(X,0,sizeof X);
		memset(Y,0,sizeof Y);
		//dp[x][y][z]=w
		//X[x][x-y+z]+=w
		//Y[x][y+z]+=w
		dp[1][1][0]=1;
		add(X[1][1-1+0],dp[1][1][0],MOD);
		add(Y[1][1+0],dp[1][1][0],MOD);
		for(i=2;i<=N;i++){
			for(j=1;j<=i-1;j++)for(k=0;k<=S;k++)if(dp[i-1][j][k]){
				add(dp[i][1][k],dp[i-1][j][k],MOD);
				add(dp[i][i][k],dp[i-1][j][k],MOD);
			}
			for(j=2;j<i;j++){
				LL mul=cb[i-1][j-1];
				//j-1 vs i-j
				for(p=0;p<=S+j-1;p++)if(X[j-1][p])//X[j-1][p]
					for(q=0;q<=S+i-j;q++)if(Y[i-j][q])//Y[i-j][q]
						if(p+q+1<=S)add(dp[i][j][p+q+1],X[j-1][p]*Y[i-j][q]%MOD*mul%MOD,MOD);
			}
			for(j=1;j<=i;j++)
				for(k=0;k<=S;k++)
					if(dp[i][j][k]){
						add(X[i][i-j+k],dp[i][j][k],MOD);
						add(Y[i][j+k],dp[i][j][k],MOD);
					}
		}
		LL ret=0;
		for(j=1;j<=N;j++)
			for(k=0;k<=S;k++)
				add(ret,dp[N][j][k],MOD);
		return (int)ret;
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
			int N                     = 3;
			int S                     = 1;
			int MOD                   = 71876209;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 4;
			int S                     = 0;
			int MOD                   = 1000003;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 4;
			int S                     = 1;
			int MOD                   = 483128897;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 5;
			int S                     = 3;
			int MOD                   = 907283243;
			int expected__            = 82;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 5;
			int S                     = 100;
			int MOD                   = 101;
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 20;
			int S                     = 30;
			int MOD                   = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}/*

		// custom cases

      case 6: {
			int N                     = 100;
			int S                     = 100;
			int MOD                   = 1000000007;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int N                     = ;
			int S                     = ;
			int MOD                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int S                     = ;
			int MOD                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearPermutations().countPermutations( N, S, MOD );
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
