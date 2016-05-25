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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1);
const LL MOD = 1000000007;

const int MXN = 1010;
vector<int>G[MXN];
int ans=-1;
int ins[MXN+10];
int BIT[MXN+10];
int LB( int w ) {return w&( -w );}
int query( int w ) {
//	cout<<"query "<<w<<" =" ;
	int ret=0;
	for ( w+=5; w>0; w-=LB( w ) )ret+=BIT[w];
//	cout<<ret<<endl;
	return ret;
}
void update( int w,int d ) {
//	cout<<"update "<<w<<" "<<d<<endl;
	for ( w+=5; w<MXN; w+=LB( w ) )BIT[w]+=d;
}
vector<int>VV,_V;
int cnt;
int getid(int u){
	int id=lower_bound(VV.OP,VV.ED,_V[u])-VV.OP;
	return VV.SZ+1-id;
}
int st[MXN];
void dfs(int u,int h,int mxh){
//	cout<<u<<" "<<h<<" "<<mxh<<endl;
	st[h]=u;
	ins[u]=1;
//	for(int i=0;i<=h;i++)cout<<_V[st[i]]<<" ";
//	cout<<"~~==>"<<cnt<<endl;
	if(h==mxh-1){
		if(ans==-1)ans=cnt;
		else cmin(ans,cnt);
	}else {
		for(int i=0;i<G[u].SZ;i++){
			int v=G[u][i];
			if(ins[v])continue;
			int id=getid(v);
			int add=query(id-1);
			update(id,1);
			cnt+=add;
			dfs(v,h+1,mxh);
			cnt-=add;
			update(id,-1);
		}
	}
	ins[u]=0;
}
class GraphInversions {
public:
  int getMinimumInversions (vector <int> A, vector <int> B, vector <int> V, int K) {
    ans=-1;
    int i,j;
    int n=A.SZ;
    _V=V;
    for(i=0;i<n;i++)G[i].clear();
    for(i=0;i<n;i++)G[A[i]].PB(B[i]);
    for(i=0;i<n;i++)G[B[i]].PB(A[i]);
    VV.clear();
    for(i=0;i<n;i++)VV.PB(V[i]);
    SORT(VV);
    VV.erase(unique(VV.OP,VV.ED),VV.ED);
    for(i=0;i<n;i++){
			memset(ins,0,sizeof ins);
			memset(BIT,0,sizeof BIT);
			cnt=0;
			update(getid(i),1);
			dfs(i,0,K);
    }
    return ans;
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
			int A[]                   = {0,1,2};
			int B[]                   = {1,2,0};
			int V[]                   = {40,50,60};
			int K                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int A[]                   = {0,1,2,3};
			int B[]                   = {1,2,3,0};
			int V[]                   = {60,40,50,30};
			int K                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int A[]                   = {0,1,2,3,0};
			int B[]                   = {1,2,3,0,4};
			int V[]                   = {10,10,10,5,5};
			int K                     = 5;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int A[]                   = {0,1,2,3,0,2};
			int B[]                   = {1,2,3,0,4,5};
			int V[]                   = {10,2,5,3,7,1};
			int K                     = 6;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int A[]                   = {5,7,7,5,5,7,6,4};
			int B[]                   = {2,0,2,0,1,4,7,3};
			int V[]                   = {15,10,5,30,22,10,5,2};
			int K                     = 6;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int A[]                   = ;
			int B[]                   = ;
			int V[]                   = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			int V[]                   = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			int V[]                   = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GraphInversions().getMinimumInversions( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( V, V + ( sizeof V / sizeof V[0] ) ), K );
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
