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

const int MOD = (int)1e9 + 7;
const int inv2 = MOD + 1 >> 1;
int A[1 << 18];

void fwt(int A[],int n,int inv) {
    for (int l = 1; l << 1 <= n; l <<= 1) {
        for (int s = 0; s < n; ++ s) {
            if (~s & l) {
                int a = A[s];
                int b = A[s ^ l];
                if (inv == 1) {
                    A[s] = (a - b + MOD) % MOD;
                    A[s ^ l] = (a + b) % MOD;
                } else {
                    A[s] = (a + b) * 1ll * inv2 % MOD;
                    A[s ^ l] = (b - a + MOD) * 1ll * inv2 % MOD;
                }
            }
        }
    }
}
int isp[1<<18];
LL modPow(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1)ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ret;
}
class Nim {
public:
	int count( int K, int L ) {
		int i,j,k;
		int ret;
		int m=0;
		while(L>>m)m++;
		for(i=2;i<=L;i++)isp[i]=1;
		for(i=2;i<=L;i++)if(isp[i])
			for(j=i+i;j<=L;j+=i)
				isp[j]=0;
		for(i=0;i<1<<m;i++)A[i]=0;
		for(i=2;i<=L;i++)A[i]=isp[i];
		fwt(A,1<<m,1);
		for(i=0;i<1<<m;i++)A[i]=modPow(A[i],K);
		fwt(A,1<<m,0);
		return A[0];
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
			int K                     = 3;
			int L                     = 7;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int K                     = 4;
			int L                     = 13;
			int expected__            = 120;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int K                     = 10;
			int L                     = 100;
			int expected__            = 294844622;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int K                     = 123456789;
			int L                     = 12345;
			int expected__            = 235511047;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int K                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int K                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int K                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Nim().count( K, L );
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
