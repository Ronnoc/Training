/*
限制内存，有限大量整数求第k大
一开始二分显然TLE
学习了下别人的
对数域分块搞即可
*/
#line 97 "LimitedMemorySeries1.cpp"
#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmin(x,y) x=min((x),(y))
#define cmax(x,y) x=max((x),(y))
typedef long long LL;
typedef pair<int,int> PII;

const LL MOD = 1000000007;
const LL LIM = 32000;
class LimitedMemorySeries1 {
	int play[32005];
	int cnt[32005];
	public:
	long long getSum(int n, int x0, int a, int b, vector <int> q) {
		LL ret=0;
		memset(cnt,0,sizeof cnt);
		int i,j;
		LL x=x0;
		for(i=0;i<n;i++){
			cnt[x/LIM]++;
			x=(x*a+b)%MOD;
		}
		for(i=0;i<q.SZ;i++){
			int Q=q[i]+1;
			int id=0;
			while(cnt[id]<Q)Q=Q-cnt[id++];
			memset(play,0,sizeof play);
			x=x0;
			for(j=0;j<n;j++){
				if(x/LIM==id)
					play[x%LIM]++;
				x=(x*a+b)%MOD;
			}
			j=0;
			while(play[j]<Q)Q-=play[j++];
			ret+=id*LIM+j;
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
			int n                     = 5;
			int x0                    = 100;
			int a                     = 1;
			int b                     = 5;
			int query[]               = {0,3};
			long long expected__      = 215LL;

			clock_t start__           = clock();
			long long received__      = LimitedMemorySeries1().getSum( n, x0, a, b, vector <int>( query, query + ( sizeof query / sizeof query[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 5;
			int x0                    = 123456789;
			int a                     = 987654321;
			int b                     = 1000000006;
			int query[]               = {0,1,2,3};
			long long expected__      = 733028692LL;

			clock_t start__           = clock();
			long long received__      = LimitedMemorySeries1().getSum( n, x0, a, b, vector <int>( query, query + ( sizeof query / sizeof query[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 5000000;
			int x0                    = 482995837;
			int a                     = 512849030;
			int b                     = 120583724;
			int query[]               = {4854010,3139503,1855546,219904,846357,2624639,891260,217467,4940091,4802760,2424821,424076,  3848272,2062765,2922407,4850301,1279972,4929307,2035456,3562859,1749594,4089499,3797495,1013980,  1650805,1245213,3020379,4661668,427170,1176815,292944,2435328,420809,4170355,2635197,3940607,  4311718,2098572,4868054,30319,4588969,1460677,1335028,3921495,3621970,4459335,966000,3686977,  2316560,1634961,2280624,1940395,3321546,3168811,1856547,3859093,4340475,1382782,3482928,2517843,  185008,1135373,2821050,3260484,4821220,1700954,3243343,2183615,394339,2630121,1811267,1060542,  3898314,892312,2015580,11161,4965095,2128470,2320933,1095881,3938450,1887098,975426,2098073,3300937,  1145560,2894728,1026181,3259403,4509345,3610224,3584456,1877483,2665752,2243671,616205,504849,3068426,  1471925,4144568};
			long long expected__      = 49684994148LL;

			clock_t start__           = clock();
			long long received__      = LimitedMemorySeries1().getSum( n, x0, a, b, vector <int>( query, query + ( sizeof query / sizeof query[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			int x0                    = ;
			int a                     = ;
			int b                     = ;
			int query[]               = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = LimitedMemorySeries1().getSum( n, x0, a, b, vector <int>( query, query + ( sizeof query / sizeof query[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int n                     = ;
			int x0                    = ;
			int a                     = ;
			int b                     = ;
			int query[]               = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = LimitedMemorySeries1().getSum( n, x0, a, b, vector <int>( query, query + ( sizeof query / sizeof query[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int n                     = ;
			int x0                    = ;
			int a                     = ;
			int b                     = ;
			int query[]               = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = LimitedMemorySeries1().getSum( n, x0, a, b, vector <int>( query, query + ( sizeof query / sizeof query[0] ) ) );
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
