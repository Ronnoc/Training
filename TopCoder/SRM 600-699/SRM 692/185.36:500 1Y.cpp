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
const LL MOD = 1000000009LL;
LL f[1005][105];
LL dp[1005][1005];
int nxt[105];
int g[105][26];
int con[105];
LL w[1005];
LL Sum[1005];
LL C[1005];
//逆元
//>验题: poj2447
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
//if m为质数 [费马小定理]a^(m-1)=1 mod m ==>a^(m-2)是a关于m的逆元
class LinenCenter {
public:
	int countStrings( string S, int N, int K ) {
		cout<<S<<" "<<N<<" "<<K<<"\n";
		int i,j,k,n=S.SZ;
		for(C[i=0]=1;i<=N&&i<K;i++)
			C[i+1]=C[i]*(K-i)%MOD*modInv(i+1,MOD)%MOD;
		//for(i=0;i<=N&&i<=K;i++)cout<<C[i]<<" ";cout<<"Comb\n";
		for(i=0;i<n;i++){
			nxt[i]=-1;
			for(j=i-1;j>=0;j--){
				int fail=0;
				for(k=0;k<j;k++){
					fail|=S[k]!=S[i-(j-k)];
				}
				if(!fail){
					nxt[i]=j;
					break;
				}
			}
			for(j=0;j<26;j++){
				int id=i;
				while(id>=0){
					if(S[id]==j+'a')break;
					id=nxt[id];
				}
				g[i][j]=id+1;
			}
			if(i){
				con[i]=0;
				for(j=0;j<n-i;j++)
					if(S[i+j]!=S[j])con[i]=1;
			}else con[i]=1;
		}
		//for(i=0;i<n;i++)cout<<nxt[i]<<" ";cout<<"next\n";
		//for(i=0;i<n;i++,cout<<"\n")
		//	for(j=0;j<26;j++)printf("%c%2d ",j+'a',g[i][j]);
		//for(i=0;i<n;i++)cout<<con[i]<<" ";cout<<"con\n";
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(i=0;i<N;i++)for(j=0;j<n;j++)if(f[i][j]){
			for(k=0;k<26;k++)
				f[i+1][g[j][k]]=(f[i+1][g[j][k]]+f[i][j])%MOD;
		}
		for(i=1;i<=N;i++){
			w[i]=0;
			for(j=0;j<n;j++)
				w[i]+=f[i][j]*con[j];
			w[i]%=MOD;
		}
		Sum[0]=1;
		for(i=1;i<=N;i++){
			Sum[i]=Sum[i-1];
			for(j=0;j<n;j++)
				Sum[i]+=f[i][j];
			Sum[i]%=MOD;
		}
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(i=0;i<N;i++)for(j=0;j<=i;j++)if(dp[i][j]){
			for(k=1;k+i<=N;k++)
				dp[i+k][j+1]=(dp[i+k][j+1]+dp[i][j]*w[k])%MOD;
		}
		LL ret=0;
		for(i=0;i<=N;i++)for(j=0;j<=i&&j<=K;j++)if(dp[i][j]){
			ret+=dp[i][j]*Sum[N-i]%MOD*C[j]%MOD;
		}
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
			string S                  = "xy";
			int N                     = 2;
			int K                     = 1;
			int expected__            = 2079;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string S                  = "q";
			int N                     = 2;
			int K                     = 1;
			int expected__            = 1926;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string S                  = "ababab";
			int N                     = 5;
			int K                     = 4;
			int expected__            = 527166180;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string S                  = "abcde";
			int N                     = 500;
			int K                     = 10;
			int expected__            = 942389748;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string S                  = "ghjhhhgjhjhgjhghghjhjg";
			int N                     = 8;
			int K                     = 10000000;
			int expected__            = 618639712;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string S                  = "pdpfrpfdfdpfdpfdpfpdfldfpfldpfdlfpdlfdpflepflfldpflofpwpldlfpde";
			int N                     = 999;
			int K                     = 500000000;
			int expected__            = 852730493;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			string S                  = "a";
			int N                     = 100;
			int K                     = 0;
			int expected__            = 990669582;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			string S                  = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
			int N                     = 1000;
			int K                     = 1000000000;
			int expected__            = 286425258;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 8: {
			string S                  = ;
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			string S                  = ;
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			string S                  = ;
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LinenCenter().countStrings( S, N, K );
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
