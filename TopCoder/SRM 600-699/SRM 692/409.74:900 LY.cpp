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
const LL MOD = 1000000000;
int fa[300005];
LL w[300005];

int ns[300005];
LL F[300005];
LL d2r[300005];

LL D[300005];
int o[300005];
int s[300005];
class TreeSums {
public:
	long long findSums( int N, LL seed, LL u, LL v ) {
		int i,j,k;
		LL cur=seed;
		fa[0]=0;
		for(i=0;i<N-1;i++){
			cur=(cur*u+v)%MOD;
			fa[i+1]=cur%(i+1);
			cur=(cur*u+v)%MOD;
			w[i+1]=cur%1000000;
		}
		for(i=0;i<N;i++)ns[i]=1,F[i]=0;
		for(d2r[0]=0,i=1;i<N;i++)
			d2r[i]=d2r[fa[i]]+w[i];
		for(i=N-1;i>0;i--){
			ns[fa[i]]+=ns[i];
			F[fa[i]]+=F[i]+ns[i]*w[i];
		}
		for(i=0;i<N;i++)o[i]=s[i]=-1;
		for(i=N-1;i>=0;i--){
			if(s[i]==-1){
				o[i]=i;
				D[i]=0;
			}else {
				D[i]=D[s[i]]+(F[i]-F[s[i]]-ns[s[i]]*w[s[i]])+(d2r[o[i]]-d2r[i])*(ns[i]-ns[s[i]]);
				//cout<<D[s[i]]<<"+"<<(F[i]-F[s[i]]-ns[s[i]]*w[s[i]])<<"+("<<(d2r[o[i]]-d2r[i])<<"*"<<(ns[i]-ns[s[i]])<<")\n";
				//cout<<o[i]<<" "<<D[i]<<"@"<<i<<"\n";
				while(o[i]!=i){
					int pre=ns[i]-ns[o[i]];
					if(pre>=ns[o[i]]){
						D[i]-=(pre-ns[o[i]])*w[o[i]];
						o[i]=fa[o[i]];
						//cout<<o[i]<<" "<<D[i]<<"@"<<i<<"\n";
					}else break;
				}
			}
			if(~s[fa[i]]){
				if(ns[s[fa[i]]]<ns[i])
					o[fa[i]]=o[i],s[fa[i]]=i;
			}else o[fa[i]]=o[i],s[fa[i]]=i;
			//cout<<i<<" "<<o[i]<<" "<<s[i]<<" "<<D[i]<<"\n";
		}
		long long ret=0;
		for(i=0;i<N;i++)ret^=D[i];
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int N                     = 6;
			int seed                  = 8;
			int C                     = 3;
			int D                     = 13;
			long long expected__      = 856320LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int seed                  = 10;
			int C                     = 20;
			int D                     = 30;
			long long expected__      = 4630LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 6;
			int seed                  = 55;
			int C                     = 1;
			int D                     = 18;
			long long expected__      = 22LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 300000;
			int seed                  = 999999990;
			int C                     = 999999990;
			int D                     = 999999991;
			long long expected__      = 438628640790LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int seed                  = ;
			int C                     = ;
			int D                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int seed                  = ;
			int C                     = ;
			int D                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int seed                  = ;
			int C                     = ;
			int D                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = TreeSums().findSums( N, seed, C, D );
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
