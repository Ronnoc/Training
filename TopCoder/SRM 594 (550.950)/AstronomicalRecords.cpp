#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define LL long long
#define PB push_back

LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
//4,6,8,18,12,2,1
//90,80,60,10,1
class AstronomicalRecords {
public:
	int minimalPlanets ( vector <int> A, vector <int> B ) {
		LL gcda=0,gcdb=0;
		int i,j,k,l,ia,ib;
		for(i=0;i<A.size();i++)gcda=gcd(A[i],gcda);
		for(i=0;i<B.size();i++)gcdb=gcd(B[i],gcdb);
		for(i=0;i<A.size();i++)A[i]/=gcda;
		for(i=0;i<B.size();i++)B[i]/=gcdb;
		int ret=A.size()+B.size()-1;
		vector<LL>a,b;
		for(i=0;i<A.size();i++)a.PB(A[i]);
		for(i=0;i<B.size();i++)b.PB(B[i]);
		for(ia=0;ia<a.size();ia++)for(ib=0;ib<b.size();ib++){
			vector<LL>_a,_b;
			LL x=a[ia],y=b[ib];
			LL cmd=x*y/gcd(x,y);
			LL mula=cmd/x,mulb=cmd/y;
			for(i=0;i<a.size();i++)_a.PB(a[i]*mula);
			for(i=0;i<b.size();i++)_b.PB(b[i]*mulb);
			int dp[55][55];
			memset(dp,0,sizeof dp);
			for(i=1;i<=_a.size();i++)for(j=1;j<=_b.size();j++){
				int ii=i-1,jj=j-1;
				if(_a[ii]==_b[jj])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			ret=min((LL)ret,(LL)_a.size()+(LL)_b.size()-dp[_a.size()][_b.size()]);
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
			int A[]                   = {1,2,1,2,1};
			int B[]                   = {2,1,2,1,2};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int A[]                   = {1,2,3,4};
			int B[]                   = {2,4,6,8};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int A[]                   = {2,3,2,3,2,3,2};
			int B[]                   = {600,700,600,700,600,700,600};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int A[]                   = {1,2,3,4,5,6,7,8,9};
			int B[]                   = {6,7,8,9,10,11,12};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int A[]                   = {100000000,200000000};
			int B[]                   = {200000000,100000000};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

//4,6,8,18,12,2,1
//90,80,60,10,1
      case 5: {
			int A[]                   = {4,6,8,18,12,2,1};
			int B[]                   = {90,80,60,10,1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets( vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ) );
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
