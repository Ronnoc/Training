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
#define UNIQUE(X) X.erase(unique(X.begin(),X.end()),X.end())
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

class HyperKnight {
public:
	long long countCells ( int a, int b, int nr, int nc, int k ) {
		cout<<a<<" "<<b<<" "<<nr<<" "<<nc<<" "<<k<<endl;
		long long ret=0;
		int i,j;
		int dx[11],dy[11];
		for(i=0;i<4;i++)dx[i]=a;
		for(i=4;i<8;i++)dx[i]=b;
		for(i=0;i<4;i++)dy[i]=b;
		for(i=4;i<8;i++)dy[i]=a;
		for(i=1;i<8;i+=2)dy[i]*=-1;
		for(i=2;i<8;i+=4)dx[i]*=-1,dx[i+1]*=-1;
//		for(i=0;i<8;i++)cout<<dx[i]<<" ";cout<<endl;
//		for(i=0;i<8;i++)cout<<dy[i]<<" ";cout<<endl;
		vector<int>L;
		for(i=0;i<(1<<8);i++){
			int tot=0;
			for(j=0;j<8;j++)if(i>>j&1)tot++;
			if(tot==k)L.PB(i);
		}
		vector<pair<PII,PII> >O;
		vector<int>X,Y;
		X.PB(0),X.PB(nr);
		Y.PB(0),Y.PB(nc);
		for(i=0;i<8;i++){
			int xl=max(0,-dx[i]);
			int xr=min(nr,nr-dx[i]);
			int yl=max(0,-dy[i]);
			int yr=min(nc,nc-dy[i]);
//			cout<<xl<<" "<<xr<<" "<<yl<<" "<<yr<<"~~~"<<endl;
			O.PB(MP(MP(xl,xr),MP(yl,yr)));
			X.PB(xl),X.PB(xr);
			Y.PB(yl),Y.PB(yr);
		}
		SORT(X);UNIQUE(X);
		SORT(Y);UNIQUE(Y);
		for(i=1;i<X.SZ;i++)for(j=1;j<Y.SZ;j++){
			LL xl=X[i-1],xr=X[i];
			LL yl=Y[j-1],yr=Y[j];
			int tot=0,t;
			for(t=0;t<8;t++){
				if(xl>=O[t].AA.BB)continue;
				if(yl>=O[t].BB.BB)continue;
				if(xr<=O[t].AA.AA)continue;
				if(yr<=O[t].BB.AA)continue;
				tot++;
			}
//			cout<<xl<<" "<<xr<<" "<<yl<<" "<<yr<<"==>"<<tot<<endl;
			if(tot==k)ret+=(xr-xl)*(yr-yl);
		}
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
			int a                     = 2;
			int b                     = 1;
			int numRows               = 8;
			int numColumns            = 8;
			int k                     = 4;
			long long expected__      = 20LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int a                     = 3;
			int b                     = 2;
			int numRows               = 8;
			int numColumns            = 8;
			int k                     = 2;
			long long expected__      = 16LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int a                     = 1;
			int b                     = 3;
			int numRows               = 7;
			int numColumns            = 11;
			int k                     = 0;
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int a                     = 3;
			int b                     = 2;
			int numRows               = 10;
			int numColumns            = 20;
			int k                     = 8;
			long long expected__      = 56LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int a                     = 1;
			int b                     = 4;
			int numRows               = 100;
			int numColumns            = 10;
			int k                     = 6;
			long long expected__      = 564LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int a                     = 2;
			int b                     = 3;
			int numRows               = 1000000000;
			int numColumns            = 1000000000;
			int k                     = 8;
			long long expected__      = 999999988000000036LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int a                     = ;
			int b                     = ;
			int numRows               = ;
			int numColumns            = ;
			int k                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int numRows               = ;
			int numColumns            = ;
			int k                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int a                     = ;
			int b                     = ;
			int numRows               = ;
			int numColumns            = ;
			int k                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = HyperKnight().countCells( a, b, numRows, numColumns, k );
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
