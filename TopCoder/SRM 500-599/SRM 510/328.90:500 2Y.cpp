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

class TheLuckyGameDivOne {
public:
	int find( long long a, long long b, long long jLen, long long bLen ) {
		int i,j,k;
		vector<LL>L;
		for(int i=1;i<=10;i++){
			for(j=0;j<1<<i;j++){
				LL tp=0;
				for(k=0;k<i;k++){
					tp=tp*10+4;
					if(j>>k&1)tp+=3;
				}
				if(a<=tp&&tp<=b)L.PB(tp);
			}
		}
		sort(L.OP,L.ED);
		vector<pair<LL,LL> >J,B;
		B.PB(MP(a,a+bLen-1));
		B.PB(MP(b-bLen+1,b));
		for(int i=0;i<L.SZ;i++){
			LL w=L[i];
			if(w-bLen+1>=a)B.PB(MP(w-bLen+1,w));
			if(w-bLen>=a)B.PB(MP(w-bLen,w-1));
			if(w+bLen-1<=b)B.PB(MP(w,w+bLen-1));
			if(w+bLen<=b)B.PB(MP(w+1,w+bLen));
		}
		sort(B.OP,B.ED);
		B.erase(unique(B.OP,B.ED),B.ED);
		vector<int>fb;
		for(i=0;i<B.SZ;i++){
			LL re=B[i].BB,le=B[i].AA-1;
			int tot=upper_bound(L.OP,L.ED,re)-upper_bound(L.OP,L.ED,le);
			fb.PB(tot);
		}
		for(i=0;i<B.SZ;i++){
			LL le=B[i].AA,re=B[i].BB;
			if(le+jLen-1<=b)J.PB(MP(le,le+jLen-1));
			if(le+jLen<=b)J.PB(MP(le+1,le+jLen));
			if(re-jLen+1>=a)J.PB(MP(re-jLen+1,re));
			if(re-jLen>=a)J.PB(MP(re-jLen,re-1));
		}
		sort(J.OP,J.ED);
		J.erase(unique(J.OP,J.ED),J.ED);
		int ret=0;
		for(i=0;i<J.SZ;i++){
			int tmp=-1;
			for(j=0;j<B.SZ;j++)if(B[j].AA>=J[i].AA&&B[j].BB<=J[i].BB){
				if(tmp==-1)tmp=fb[j];
				else cmin(tmp,fb[j]);
			}
			cmax(ret,tmp);
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
			long long a               = 1LL;
			long long b               = 10LL;
			long long jLen            = 2LL;
			long long bLen            = 1LL;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			long long a               = 1LL;
			long long b               = 100LL;
			long long jLen            = 100LL;
			long long bLen            = 100LL;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			long long a               = 4LL;
			long long b               = 8LL;
			long long jLen            = 3LL;
			long long bLen            = 2LL;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			long long a               = 1LL;
			long long b               = 100LL;
			long long jLen            = 75LL;
			long long bLen            = 50LL;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			long long a               = 1LL;
			long long b               = 4747LL;
			long long jLen            = 8LL;
			long long bLen            = 3LL;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 5: {
			long long a               = LL;
			long long b               = LL;
			long long jLen            = LL;
			long long bLen            = LL;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			long long a               = LL;
			long long b               = LL;
			long long jLen            = LL;
			long long bLen            = LL;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheLuckyGameDivOne().find( a, b, jLen, bLen );
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
