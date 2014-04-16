#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size() 
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;

LL mod = 1000000007;
int sigma(int l,int r,int K){
	return r/K-(l-1)/K;
}
int power(LL a,int b){
	LL ret=1;
	while(b){
		if(b&1)ret=(ret*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ret;
}
int isp[111111];
class RandomGCD {
public:
  int countTuples (int N, int K, int low, int high) {
    LL ret=0;
    int i,j;
    vector<int>L;
    for(i=low;i<=high;i++)if(i%K==0)L.PB(i/K);
    if(N==1){
			int flag=0;
			for(i=low;i<=high;i++)if(i==K)flag=1;
			return flag;
    }
    if(L.empty())return 0;
    int Lmin=L[0],Lmax=L[L.SZ-1];
    vector<int>R=L;
    vector<int>Q[100010];
		memset(isp,0,sizeof isp);
    for(i=3;i<=50000;i+=2)isp[i]=1;
    for(isp[2]=1,i=3;i<=50000;i+=2)if(isp[i])
			for(LL j=1LL*i*i;j<=50000;j+=2*i)isp[j]=0;
    for(i=2;i*i<=Lmax;i++){
			if(!isp[i])continue;
			if(sigma(Lmin,Lmax,i)==0)continue;
			int tp=Lmin%i;
			int fi=Lmin+i-tp;
			while(fi-i>=Lmin)fi-=i;
			for(j=fi;j<=Lmax;j+=i){
				while(R[j-Lmin]%i==0)R[j-Lmin]/=i;
				Q[j-Lmin].PB(i);
			}
    }
    for(i=0;i<R.SZ;i++)if(R[i]>1)Q[i].PB(R[i]);
    ret=1LL*L.SZ*power(sigma(Lmin,Lmax,1),N-1)%mod;
    for(i=0;i<L.SZ;i++){
			vector<int>&M=Q[i];
			for(int mask=1;mask<1<<M.SZ;mask++){
				int now=1;
				for(j=0;j<M.SZ;j++)if(mask>>j&1)now*=M[j];
				if(__builtin_popcount(mask)&1)ret-=power(sigma(Lmin,Lmax,now),N-1);
				else ret+=power(sigma(Lmin,Lmax,now),N-1);
			}
    }
    ret=(ret%mod+mod)%mod;
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
			int N                     = 2;
			int K                     = 2;
			int low                   = 2;
			int high                  = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int K                     = 100;
			int low                   = 2;
			int high                  = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 1;
			int K                     = 5;
			int low                   = 5;
			int high                  = 5;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 73824;
			int K                     = 17347;
			int low                   = 9293482;
			int high                  = 9313482;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 222;
			int K                     = 222;
			int low                   = 222;
			int high                  = 22222;
			int expected__            = 339886855;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int low                   = ;
			int high                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RandomGCD().countTuples( N, K, low, high );
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
