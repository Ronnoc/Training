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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.begin(),X.end())
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

vector<int>l[333],r[333];
LL dp[3][303][303];
class WolfInZooDivOne {
public:
	int count ( int N, vector <string> L, vector <string> R ) {
		int ret;
		const LL mod = 1000000007;
		int i,j,k,u,v;
		for(i=1;i<=N;i++)l[i].clear();
		for(i=1;i<=N;i++)r[i].clear();
		string sl="",sr="";
		for(i=0;i<L.SZ;i++)sl+=L[i];
		for(i=0;i<R.SZ;i++)sr+=R[i];
		istringstream lin(sl),rin(sr);
		while(lin>>u){
			rin>>v;
			u++;v++;
			l[u].PB(v);
			r[v].PB(u);
		}
		int ff[333];
		for(i=1;i<=N;i++)ff[i]=N+1;
		for(i=1;i<=N;i++)for(j=0;j<r[i].SZ;j++)
			for(k=1;k<=i;k++)ff[k]=min(ff[k],r[i][j]);
		//dp[id][u][v] stand for when place wolf in the id-th zoo , last is in u;last of last is in v
		//if u v not exist, set as 0
		int z=(N+1)%2;
		for(u=0;u<N+1;u++)for(v=0;v<N+1;v++)
			dp[z][u][v]=1;
		for(i=N;i>=1;i--){
			int x=i%2;
			int y=(i+1)%2;
			for(u=0;u<i;u++)for(v=0;v<i;v++){
				if(u&&v)if(v>=u)continue;
				if(v&&!u)continue;
				dp[x][u][v]=dp[y][u][v];
				if(v<ff[i])dp[x][u][v]+=dp[y][i][u];
				dp[x][u][v]%=mod;
			}
		}
		return dp[1][0][0];
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
			int N                     = 5;
			string L[]                = {"0"};
			string R[]                = {"4"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			string L[]                = {"0 1"};
			string R[]                = {"2 4"};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 5;
			string L[]                = {"0 2"};
			string R[]                = {"2 4"};
			int expected__            = 25;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 10;
			string L[]                = {"0 4 2 7"};
			string R[]                = {"3 9 5 9"};
			int expected__            = 225;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 100;
			string L[]                = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
			string R[]                = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
			int expected__            = 6419882;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			string L[]                = ;
			string R[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfInZooDivOne().count( N, vector <string>( L, L + ( sizeof L / sizeof L[0] ) ), vector <string>( R, R + ( sizeof R / sizeof R[0] ) ) );
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
