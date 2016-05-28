/*
假设每一位有解全局有解
计算每一位的解的范围
似乎不暴也可以，为了方便还是暴吧
*/
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

int F[2505],L[2505];
class ANewHope {
public:
	int count( vector <int> p, vector <int> q, int D ) {
		int i,j,k;
		int ret=1,N=p.SZ;
		for(i=0;i<N;i++)F[p[i]]=i;
		for(i=0;i<N;i++)L[q[i]]=i;
		for(i=1;i<=N;i++){
			int f=F[i],l=L[i];
			if(f==l)continue;
			int tp=1;
			while(1){
				f=f+D;tp++;
				if(f<=N)break;
				f-=N;
				if(l>=f)break;
			}
			cmax(ret,tp);
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
			int firstWeek[]           = {1,2,3,4};
			int lastWeek[]            = {4,3,2,1};
			int D                     = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ANewHope().count( vector <int>( firstWeek, firstWeek + ( sizeof firstWeek / sizeof firstWeek[0] ) ), vector <int>( lastWeek, lastWeek + ( sizeof lastWeek / sizeof lastWeek[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int firstWeek[]           = {8,5,4,1,7,6,3,2};
			int lastWeek[]            = {2,4,6,8,1,3,5,7};
			int D                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ANewHope().count( vector <int>( firstWeek, firstWeek + ( sizeof firstWeek / sizeof firstWeek[0] ) ), vector <int>( lastWeek, lastWeek + ( sizeof lastWeek / sizeof lastWeek[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int firstWeek[]           = {1,2,3,4};
			int lastWeek[]            = {1,2,3,4};
			int D                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ANewHope().count( vector <int>( firstWeek, firstWeek + ( sizeof firstWeek / sizeof firstWeek[0] ) ), vector <int>( lastWeek, lastWeek + ( sizeof lastWeek / sizeof lastWeek[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int firstWeek[]           = ;
			int lastWeek[]            = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ANewHope().count( vector <int>( firstWeek, firstWeek + ( sizeof firstWeek / sizeof firstWeek[0] ) ), vector <int>( lastWeek, lastWeek + ( sizeof lastWeek / sizeof lastWeek[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int firstWeek[]           = ;
			int lastWeek[]            = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ANewHope().count( vector <int>( firstWeek, firstWeek + ( sizeof firstWeek / sizeof firstWeek[0] ) ), vector <int>( lastWeek, lastWeek + ( sizeof lastWeek / sizeof lastWeek[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int firstWeek[]           = ;
			int lastWeek[]            = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ANewHope().count( vector <int>( firstWeek, firstWeek + ( sizeof firstWeek / sizeof firstWeek[0] ) ), vector <int>( lastWeek, lastWeek + ( sizeof lastWeek / sizeof lastWeek[0] ) ), D );
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
