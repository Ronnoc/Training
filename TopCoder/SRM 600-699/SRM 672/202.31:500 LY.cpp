/*
通过OEIS得到了欧拉图计数的转移公式
通过下文知道了做法
提前看解题报告系列
原问题规约到欧拉图计数
等价为联通偶图计数En
Dn为偶图计数，Rn为不连通偶图计数
Dn中，去掉1点随便练，1点连其他奇度点保证偶图
En枚举1所在联通偶图大小k
Fn=Dn-/sum_{1<=k<n}C(n-1,k-1)EkD[n-k]/
http://codeforces.com/blog/entry/21112
*/
#line 61 "AlmostEulerianGraph.cpp"
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
LL cb[2005][2005];
LL ep[2005];
LL modPow(LL a,LL n){
	LL ret=1;
	while(n){
		if(n&1)ret=ret*a%MOD;
		a=a*a%MOD;
		n/=2;
	}
	return ret;
}
LL modInv(LL a){return modPow(a,MOD-2);}
class AlmostEulerianGraph {
	public:
	int calculateGraphs(int n) {
		int i,j;
		for(i=0;i<=n;i++){
			cb[i][0]=cb[i][i]=1;
			for(j=1;j<i;j++)
				cb[i][j]=(cb[i-1][j-1]+cb[i-1][j])%MOD;
		}
		ep[1]=1;
		for(i=2;i<=n;i++){
			ep[i]=modPow(2,(i-1)*(i-2)/2)%MOD;
			for(j=1;j<i;j++)
				ep[i]=(ep[i]+MOD-cb[i-1][j-1]%MOD*modPow(2,(i-j-1)*(i-j-2)/2)%MOD*ep[j]%MOD)%MOD;
			ep[i]=ep[i]%MOD;
		}
		return ep[n]*(n*(n-1)%MOD*modInv(2)%MOD+1)%MOD;
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
			int n                     = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AlmostEulerianGraph().calculateGraphs( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AlmostEulerianGraph().calculateGraphs( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 42;
			int expected__            = 29010676;

			clock_t start__           = clock();
			int received__            = AlmostEulerianGraph().calculateGraphs( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlmostEulerianGraph().calculateGraphs( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlmostEulerianGraph().calculateGraphs( n );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlmostEulerianGraph().calculateGraphs( n );
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
