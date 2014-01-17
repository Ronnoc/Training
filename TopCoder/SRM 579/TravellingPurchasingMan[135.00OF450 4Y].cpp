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
int dp[55][1<<17];
vector<PII>G[55];
int op[55],ed[55],du[55],ok[55];
int F[1<<17];
class TravellingPurchasingMan {
public:
  int maxStores (int N, vector <string> is, vector <string> r) {
    int i,j,k;
    for (i=0; i<1<<17; i++) {
      F[i]=0;
      for (j=0; j<17; j++) if (i>>j&1) F[i]++;
    }
    memset (ok,0,sizeof ok);
    for (i=0; i<N; i++) G[i].clear();
    memset (dp,-1,sizeof dp);
    for (i=0; i<is.SZ; i++) {
      istringstream sin (is[i]);
      sin>>op[i]>>ed[i]>>du[i];
      ok[i]=1;
    }
    for (i=0; i<r.SZ; i++) {
      istringstream sin (r[i]);
      int u,v,w;
      sin>>u>>v>>w;
      G[u].PB (MP (v,w));
      G[v].PB (MP (u,w));
    }
    deque<pair<int,PII> >pq;
    pq.PB (MP (0,MP (0,N-1)));
    int ret=0;
    while (!pq.empty()) {
      int t=pq.front().AA;
      int mask=pq.front().BB.AA;
      int id=pq.front().BB.BB;
      pq.pop_front();
      int &tp=dp[id][mask];
      ret=max(ret,F[mask]);
      if (tp==-1||t<tp) {
        tp=t;
        if (ok[id]&& (~mask>>id&1) &&t<=ed[id]) {
          int tt= (max (t,op[id]) +du[id]);
          if (!pq.empty() &&tt<pq.front().AA)
            pq.push_front (MP (tt,MP (mask| (1<<id),id)));
          else pq.PB (MP (tt,MP (mask| (1<<id),id)));
        }
        for (int i=0; i<G[id].SZ; i++) {
          int v=G[id][i].AA;
          int w=G[id][i].BB;
          if (!pq.empty() &&t+w<pq.front().AA)
            pq.push_front (MP ( (t+w),MP (mask,v)));
          else pq.PB (MP ( (t+w),MP (mask,v)));
        }
      }
    }
    return ret;
  }
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case (int);
void run_test (int casenum = -1, bool quiet = false) {
  if (casenum != -1) {
    if (run_test_case (casenum) == -1 && !quiet)
      cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
    return;
  }
  
  int correct = 0, total = 0;
  for (int i=0;; ++i) {
    int x = run_test_case (i);
    if (x == -1) {
      if (i >= 100) break;
      continue;
    }
    correct += x;
    ++total;
  }
  
  if (total == 0) {
    cerr << "No test cases run." << endl;
  } else if (correct < total) {
    cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
  } else {
    cerr << "All " << total << " tests passed!" << endl;
  }
}

int verify_case (int casenum, const int &expected, const int &received, clock_t elapsed) {
  cerr << "Example " << casenum << "... ";
  
  string verdict;
  vector<string> info;
  char buf[100];
  
  if (elapsed > CLOCKS_PER_SEC / 200) {
    sprintf (buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
    info.push_back (buf);
  }
  
  if (expected == received) {
    verdict = "PASSED";
  } else {
    verdict = "FAILED";
  }
  
  cerr << verdict;
  if (!info.empty()) {
    cerr << " (";
    for (int i=0; i< (int) info.size(); ++i) {
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

int run_test_case (int casenum) {
  switch (casenum) {
    case 0: {
      int N                     = 3;
      string interestingStores[] = {"1 10 10" , "1 55 31", "10 50 100" };
      string roads[]            = {"1 2 10"};
      int expected__            = 1;
      
      clock_t start__           = clock();
      int received__            = TravellingPurchasingMan().maxStores (N, vector <string> (interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string> (roads, roads + (sizeof roads / sizeof roads[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 1: {
      int N                     = 3;
      string interestingStores[] = {"1 10 10" , "1 55 30", "10 50 100" };
      string roads[]            = {"1 2 10"};
      int expected__            = 2;
      
      clock_t start__           = clock();
      int received__            = TravellingPurchasingMan().maxStores (N, vector <string> (interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string> (roads, roads + (sizeof roads / sizeof roads[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 2: {
      int N                     = 5;
      string interestingStores[] = {"0 1000 17"};
      string roads[]            = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
      int expected__            = 0;
      
      clock_t start__           = clock();
      int received__            = TravellingPurchasingMan().maxStores (N, vector <string> (interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string> (roads, roads + (sizeof roads / sizeof roads[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    
    // custom cases
    
    case 3: {
      int N                     = 2;
      string interestingStores[] = {"0 600000 1","0 600000 1"};
      string roads[]            = {"0 1 50"};
      int expected__            = 2;
      
      clock_t start__           = clock();
      int received__            = TravellingPurchasingMan().maxStores (N, vector <string> (interestingStores, interestingStores + (sizeof interestingStores / sizeof interestingStores[0])), vector <string> (roads, roads + (sizeof roads / sizeof roads[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    /*      case 4: {
    			int N                     = ;
    			string interestingStores[] = ;
    			string roads[]            = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = TravellingPurchasingMan().maxStores( N, vector <string>( interestingStores, interestingStores + ( sizeof interestingStores / sizeof interestingStores[0] ) ), vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 5: {
    			int N                     = ;
    			string interestingStores[] = ;
    			string roads[]            = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = TravellingPurchasingMan().maxStores( N, vector <string>( interestingStores, interestingStores + ( sizeof interestingStores / sizeof interestingStores[0] ) ), vector <string>( roads, roads + ( sizeof roads / sizeof roads[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    default:
      return -1;
  }
}
}


int main (int argc, char *argv[]) {
  if (argc == 1) {
    moj_harness::run_test();
  } else {
    for (int i=1; i<argc; ++i)
      moj_harness::run_test (atoi (argv[i]));
  }
}
// END CUT HERE
