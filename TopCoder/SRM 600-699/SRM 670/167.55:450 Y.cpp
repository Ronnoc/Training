/*
枚举A逃亡步数
看B覆盖区域
是否每个A都能够逃脱
*/
#line 116 "Treestrat.cpp"
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
class Treestrat {
	vector<int>G[55];
	int va[55],vb[55];
	public:
	int roundcnt(vector <int> t, vector <int> A, vector <int> B) {
		int n=t.SZ+1,i,j;
		for(i=0;i<n;i++){
			G[i].clear();
		}
		for(i=0;i<t.SZ;i++){
			G[t[i]].PB(i+1),G[i+1].PB(t[i]);
		}
		for(int k=1;k<=n;k++){
			queue<int>Q;
			memset(vb,-1,sizeof vb);
			for(i=0;i<B.SZ;i++)
				vb[B[i]]=k,Q.push(B[i]);
			while(!Q.empty()){
				int u=Q.front();
				Q.pop();
				for(i=0;i<G[u].SZ;i++){
					int v=G[u][i];
					if(vb[v]==-1){
						vb[v]=vb[u]-1;
						if(vb[v])
							Q.push(v);
					}
				}
			}
			for(i=0;i<A.SZ;i++){
				memset(va,-1,sizeof va);
				va[A[i]]=k,Q.push(A[i]);
				while(!Q.empty()){
					int u=Q.front();
					Q.pop();
					for(j=0;j<G[u].SZ;j++){
						int v=G[u][j];
						if(va[v]==-1){
							va[v]=va[u]-1;
							if(va[v])
								Q.push(v);
						}
					}
				}
				bool exist=0;
				for(j=0;j<n;j++)
					if(~va[j]&&vb[j]==-1)
						exist=1;
				if(!exist)return k;
			}
		}
		return -1;
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
			int tree[]                = {0};
			int A[]                   = {0};
			int B[]                   = {1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int tree[]                = {0,1};
			int A[]                   = {1};
			int B[]                   = {2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int tree[]                = {0,0,0,3,4};
			int A[]                   = {2};
			int B[]                   = {1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {1};
			int B[]                   = {6};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {1};
			int B[]                   = {6,5};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int tree[]                = {0,0,0,3,4,2};
			int A[]                   = {4,1};
			int B[]                   = {3,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int tree[]                = {0, 0, 1, 1, 4, 0, 0, 2, 2, 5, 7, 1, 5, 7, 11, 3, 8, 3, 2, 11, 9, 8, 15, 4, 7, 1, 5, 6, 1, 17, 26, 19, 21, 33, 32, 35, 29, 11, 27, 23, 31, 32};
			int A[]                   = {20, 5, 14, 2};
			int B[]                   = {31, 38, 25};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int tree[]                = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Treestrat().roundcnt( vector <int>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
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
