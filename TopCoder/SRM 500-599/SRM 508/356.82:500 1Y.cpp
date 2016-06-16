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

const LL MOD = 1000000009;
LL one(LL x){
	return (x+1)/2%MOD;
}
LL zero(LL x){
	return (x+1-one(x))%MOD;
}
map<vector<LL>,int>F;
class YetAnotherORProblem {
public:
	int countSequences( vector<long long> R ) {
		int i,j,k;
		LL ret=0;
		if(R.empty())return 1;
		if(F.find(R)!=F.ED)return F[R];
		for(i=0;i<R.SZ;i++){
			vector<LL>G;
			for(j=0;j<R.SZ;j++){
				LL next=-1;
				if(i==j){
					next=(R[j]-1)/2;
				}else {
					next=R[j]/2;
				}
				if(next)G.PB(next);
			}
			ret+=countSequences(G);
		}
		vector<LL>G;
		for(auto r:R)
			if(r>1)G.PB(r/2);
		ret+=countSequences(G);
		return F[R]=ret%MOD;
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
			long R[]                  = {3,5};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			long R[]                  = {3,3,3};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			long R[]                  = {1,128};
			int expected__            = 194;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			long R[]                  = {26,74,25,30};
			int expected__            = 8409;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			long R[]                  = {1000000000,1000000000};
			int expected__            = 420352509;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			long R[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			long R[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			long R[]                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherORProblem().countSequences( vector<long long>( R, R + ( sizeof R / sizeof R[0] ) ) );
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
