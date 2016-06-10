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
const int Maxn = 3005;
const int Maxm = 300005;
struct node {
	int u, v, c, w, next;
} e[Maxm];
int tot, last[Maxn];
int dist[Maxn], pre[Maxn];
bool visit[Maxn];
queue<int> Q;
#define MOD 0x3f3f3f3f

void adde(int u, int v, int c, int w) {
	e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
	e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
}

bool spfa(int s, int t, int n) {
	memset(dist, 0x3f, sizeof(dist[0]) * (n + 3));
	memset(visit, 0, sizeof(visit[0]) * (n + 3));
	memset(pre, -1, sizeof(pre[0]) * (n + 3));
	while(!Q.empty()) Q.pop();
	Q.push(s);
	visit[s] = true;
	dist[s] = 0;
	pre[s] = -1;
	while(!Q.empty()) {
		int u = Q.front();
		visit[u] =false;
		Q.pop();
		for(int j = last[u]; j != -1; j = e[j].next)
			if(e[j].c > 0 && dist[u] + e[j].w < dist[e[j].v]) {
				dist[e[j].v] = dist[u] + e[j].w;
				pre[e[j].v] = j;
				if(!visit[e[j].v]) {
					Q.push(e[j].v);
					visit[e[j].v] = true;
				}
			}
	}
	if(dist[t] == MOD) return false;
	else return true;
}

int ChangeFlow(int t) {
	int det = MOD, u = t;
	while(~pre[u]) {
		u = pre[u];
		det = min(det, e[u].c);
		u = e[u].u;
	}
	u = t;
	while(~pre[u]) {
		u = pre[u];
		e[u].c -= det;
		e[u ^ 1].c += det;
		u = e[u].u;
	}
	return det;
}

int mincost, maxflow;
int MinCostFlow(int s, int t, int n) {
	mincost = maxflow = 0;
	while(spfa(s, t, n)) {
		int det = ChangeFlow(t);
		mincost += det * dist[t];
		maxflow += det;
	}
	return mincost;
}
class StoryFromTCO {
public:
	int minimumChanges(vector <int> pl, vector <int> co) {
		int ret;
		int i,j;
		tot=0,memset(last,-1,sizeof last);
		int n=pl.SZ;
		int S=2*n,T=2*n+1;
		vector<PII>L;
		for(i=0; i<pl.SZ; i++)L.PB(MP(co[i],pl[i]));
		sort(L.OP,L.ED);
		for(i=0; i<n; i++)adde(S,i,1,0);
		for(j=0; j<n; j++)adde(j+n,T,1,0);
		for(i=0; i<n; i++) {
			if(L[i].BB<=L[i].AA)adde(i,i+n,1,-100000);
			for(j=0; j<n; j++)if(j!=i&&L[i].BB<=L[j].AA)
					{adde(i,j+n,1,0);break;}
			if(i+1<n)adde(i+n,i+1+n,n,0);
		}
		MinCostFlow(S,T,T+1);
		if(maxflow!=n)return -1;
		mincost/=100000;
		return n+mincost;
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

int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
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
			int places[]              = {20,100,500,50};
			int cutoff[]              = {7500,2250,150,24};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int places[]              = {5,4,3,2,1};
			int cutoff[]              = {5,4,3,2,1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int places[]              = {1,5,5,5};
			int cutoff[]              = {8,6,4,2};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int places[]              = {3,1,5};
			int cutoff[]              = {6,4,2};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int places[]              = {14,11,42,9,19};
			int cutoff[]              = {11,16,37,41,47} ;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int places[]              = {4,1,3,3,2,4,5,5,4,4};
			int cutoff[]              = {3,3,5,2,4,4,5,4,3,5};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int places[]              = {213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105, 53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2};
			int cutoff[]              = {33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440, 442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908};
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = StoryFromTCO().minimumChanges(vector <int>(places, places + (sizeof places / sizeof places[0])), vector <int>(cutoff, cutoff + (sizeof cutoff / sizeof cutoff[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

		/*      case 7: {
					int places[]              = ;
					int cutoff[]              = ;
					int expected__            = ;

					clock_t start__           = clock();
					int received__            = StoryFromTCO().minimumChanges( vector <int>( places, places + ( sizeof places / sizeof places[0] ) ), vector <int>( cutoff, cutoff + ( sizeof cutoff / sizeof cutoff[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 8: {
					int places[]              = ;
					int cutoff[]              = ;
					int expected__            = ;

					clock_t start__           = clock();
					int received__            = StoryFromTCO().minimumChanges( vector <int>( places, places + ( sizeof places / sizeof places[0] ) ), vector <int>( cutoff, cutoff + ( sizeof cutoff / sizeof cutoff[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 9: {
					int places[]              = ;
					int cutoff[]              = ;
					int expected__            = ;

					clock_t start__           = clock();
					int received__            = StoryFromTCO().minimumChanges( vector <int>( places, places + ( sizeof places / sizeof places[0] ) ), vector <int>( cutoff, cutoff + ( sizeof cutoff / sizeof cutoff[0] ) ) );
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
