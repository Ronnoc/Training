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

int len[55][55];
int f[55][55];
int d[55];
class BuildingRoutes {
public:
  int build (vector <string> dist, int T) {
    int ret=0;
    int i,j,k,u,v;
    int n=dist.SZ;
    for(i=0;i<n;i++)for(j=0;j<n;j++)
			len[i][j]=dist[i][j]-'0';
		for(i=0;i<n;i++)for(j=0;j<n;j++)f[i][j]=len[i][j];
		for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)
			cmin(f[i][j],f[i][k]+f[k][j]);
		int cnt[55][55];
		memset(cnt,0,sizeof cnt);
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(i!=j){
			for(u=0;u<n;u++)d[u]=MOD;
			d[i]=0;
			set<int>pre[55];
			queue<int>Q;
			Q.push(i);
			while(!Q.empty()){
				u=Q.front();
				Q.pop();
				for(v=0;v<n;v++)if(u!=v){
					int tp=d[u]+len[u][v];
					if(tp<d[v]){
						Q.push(v);
						d[v]=tp;
						pre[v].clear();
						pre[v].insert(u);
					}else if(tp==d[v]){pre[v].insert(u);Q.push(v);}
				}
			}
			queue<int>P;
			int w[55][55];
			memset(w,0,sizeof w);
			P.push(j);
			while(!P.empty()){
				u=P.front();
				P.pop();
				for(set<int>::iterator it=pre[u].OP;it!=pre[u].ED;++it)
					P.push(*it),w[*it][u]=1;
			}
			for(u=0;u<n;u++)for(v=0;v<n;v++)if(w[u][v])cnt[u][v]++;
    }
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(cnt[i][j]>=T)ret+=len[i][j];
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
			string dist[]             = {"011",  "101",  "110"};
			int T                     = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string dist[]             = {"033",  "309",  "390"};
			int T                     = 1;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string dist[]             = {"0123",  "1023",  "1203",  "1230"};
			int T                     = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string dist[]             = {"05789654",  "10347583",  "65085479",  "55602398",  "76590934",  "57939045",  "12345608",  "68647640"};
			int T                     = 3;
			int expected__            = 40;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			string dist[]             = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			string dist[]             = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string dist[]             = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BuildingRoutes().build( vector <string>( dist, dist + ( sizeof dist / sizeof dist[0] ) ), T );
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
