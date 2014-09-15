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

vector<LL>Lu;
LL ans;
double mx;
void dfs(int next,LL now,LL sign,LL a) {
	for(int i=next; i<Lu.SZ; i++) {
		if(1.*now*Lu[i]>mx*a)break;
		LL tmp=now/__gcd(now,Lu[i])*Lu[i];
		ans+=sign*a/tmp;
		dfs(i+1,tmp,-sign,a);
	}
}
LL F(LL a) {
	ans=0;
	dfs(0,1,1,a);
	return ans;
}
class TheAlmostLuckyNumbers {
public:
	long long count(long long a, long long b) {
		int i,j,k;
		for(i=1; i<=10; i++)
			for(j=0; j<1<<i; j++) {
				LL now=0;
				for(k=0; k<i; k++)
					if(j>>k&1)now=now*10+4;
					else now=now*10+7;
				Lu.PB(now);
			}
		sort(Lu.OP,Lu.ED);
		vector<LL>tmp;
		for(i=0; i<Lu.SZ; i++) {
			int fail=0;
			for(j=0; j<tmp.SZ; j++)if(Lu[i]%tmp[j]==0)fail=1;
			if(!fail)tmp.PB(Lu[i]);
		}
		Lu=tmp;
		mx=0;
		for(i=0; i<Lu.SZ; i++)
			for(j=i+1; j<Lu.SZ; j++) {
				LL tmp=__gcd(Lu[i],Lu[j]);
				if(tmp>mx)mx=tmp;
			}
		cout<<mx<<endl;
		return F(b)-F(a-1);
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case(int);
void run_test(int casenum = -1, bool quiet = false) {
	if(casenum != -1) {
		if(run_test_case(casenum) == -1 && !quiet)
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}

	int correct = 0, total = 0;
	for(int i=0;; ++i) {
		int x = run_test_case(i);
		if(x == -1) {
			if(i >= 100) break;
			continue;
		}
		correct += x;
		++total;
	}

	if(total == 0) {
		cerr << "No test cases run." << endl;
	} else if(correct < total) {
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

	if(elapsed > CLOCKS_PER_SEC / 200) {
		sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
		info.push_back(buf);
	}

	if(expected == received) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}

	cerr << verdict;
	if(!info.empty()) {
		cerr << " (";
		for(int i=0; i<(int)info.size(); ++i) {
			if(i > 0) cerr << ", ";
			cerr << info[i];
		}
		cerr << ")";
	}
	cerr << endl;

	if(verdict == "FAILED") {
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}

	return verdict == "PASSED";
}

int run_test_case(int casenum) {
	switch(casenum) {
	case 0: {
		long long a               = 1LL;
		long long b               = 10LL;
		long long expected__      = 3LL;

		clock_t start__           = clock();
		long long received__      = TheAlmostLuckyNumbers().count(a, b);
		return verify_case(casenum, expected__, received__, clock()-start__);
	}
	case 1: {
		long long a               = 14LL;
		long long b               = 14LL;
		long long expected__      = 1LL;

		clock_t start__           = clock();
		long long received__      = TheAlmostLuckyNumbers().count(a, b);
		return verify_case(casenum, expected__, received__, clock()-start__);
	}
	case 2: {
		long long a               = 1LL;
		long long b               = 100LL;
		long long expected__      = 39LL;

		clock_t start__           = clock();
		long long received__      = TheAlmostLuckyNumbers().count(a, b);
		return verify_case(casenum, expected__, received__, clock()-start__);
	}
	case 3: {
		long long a               = 1234LL;
		long long b               = 4321LL;
		long long expected__      = 1178LL;

		clock_t start__           = clock();
		long long received__      = TheAlmostLuckyNumbers().count(a, b);
		return verify_case(casenum, expected__, received__, clock()-start__);
	}

	// custom cases

	case 4: {
		long long a               = 1LL;
		long long b               = 10000000000LL;
		long long expected__      = 3823045312LL;

		clock_t start__           = clock();
		long long received__      = TheAlmostLuckyNumbers().count(a, b);
		return verify_case(casenum, expected__, received__, clock()-start__);
	}
	/*      case 5: {
				long long a               = LL;
				long long b               = LL;
				long long expected__      = LL;

				clock_t start__           = clock();
				long long received__      = TheAlmostLuckyNumbers().count( a, b );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}*/
	/*      case 6: {
				long long a               = LL;
				long long b               = LL;
				long long expected__      = LL;

				clock_t start__           = clock();
				long long received__      = TheAlmostLuckyNumbers().count( a, b );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}*/
	default:
		return -1;
	}
}
}


int main(int argc, char *argv[]) {
	if(argc == 1) {
		moj_harness::run_test();
	} else {
		for(int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
