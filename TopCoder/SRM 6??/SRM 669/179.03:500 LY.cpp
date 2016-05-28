/*
撸1h未果
看sd0061代码学习了下dp的姿势
Orz
*/
#line 99 "LineMST.cpp"
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
LL modPow(LL a,LL n){
	LL ret=1;
	while(n){
		if(n&1)ret=ret*a%MOD;
		a=a*a%MOD;
		n>>=1;
	}
	return ret;
}
LL f[205][205];//f[i][j]表示j条边,lineMST每条边最大权值为i的ans
class LineMST {
	public:
	int count(int N, int L) {
		int i,j,k;
		f[0][0]=1;
		for(i=1;i<=L;i++){//枚举最大边权
			for(j=0;j<N;j++){//处理共j条边
				f[i][j]=f[i-1][j];//所有权值不超过i-1的情况处理掉，其他情况一定有权值为i的边
				for(k=0;k<j;k++){//设最后一个权值i的边为第k条base0
					f[i][j]+=f[i][k]*f[i-1][j-k-1]%MOD*modPow(L-i+1,(k+1)*(j-k)-1)%MOD;
					f[i][j]%=MOD;
				}
			}
		}
		LL ret=f[L][N-1];
		for(i=3;i<=N;i++)ret=ret*i%MOD;//N!/2作为系数分配下标
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
			int N                     = 3;
			int L                     = 2;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int L                     = 10;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int L                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 8;
			int L                     = 41;
			int expected__            = 655468587;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 200;
			int L                     = 200;
			int expected__            = 152699064;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LineMST().count( N, L );
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
