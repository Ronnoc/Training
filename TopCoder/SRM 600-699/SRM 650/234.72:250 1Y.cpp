#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
class TaroFillingAStringDiv1 {
public:
	int getNumber( int N, vector <int> pos, string value ) {
		int i,j;
		int ret=1;
		vector<PII>L;
		rep(i,0,sz(pos))L.PB(MP(pos[i],value[i]-'A'));
		sort(all(L));
		rep(i,1,sz(L)){
			int le=L[i-1].AA,re=L[i].AA;
			int d=re-le-1;
			if(d==0)continue;
			d%=2;
			if(d){
				if(L[i-1].BB!=L[i].BB)
					ret=1LL*ret*(re-le)%MOD;
			}else {
				if(L[i-1].BB==L[i].BB)
					ret=1LL*ret*(re-le)%MOD;
			}
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
			int N                     = 3;
			int position[]            = {1, 3};
			string value              = "AB";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 4;
			int position[]            = {2, 1, 3, 4};
			string value              = "ABBA";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 25;
			int position[]            = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13};
			string value              = "ABBBBABABBAAABA";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 305;
			int position[]            = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246};
			string value              = "ABAABBABBAABABBBBAAAABBABBBA";
			int expected__            = 43068480;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int position[]            = ;
			string value              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int N                     = ;
			int position[]            = ;
			string value              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			int position[]            = ;
			string value              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroFillingAStringDiv1().getNumber( N, vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), value );
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
