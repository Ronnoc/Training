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
vector<int>w;
int dp[55][55];
int dfs (int n,int t) {
  int &tp=dp[n][t];
  if (tp!=-1) return tp;
  if (n==t) return tp=w[0]*n;
  for (int i=max(0,1-t); i<=n-t; i++) tp=max (tp,dfs (n-1,t+i-1) +w[i]);
  return tp;
}
class P8XGraphBuilder {
public:
  int solve (vector <int> scores) {
    w=scores;
    int n=w.SZ+1;
    memset (dp,-1,sizeof dp);
    return dfs(n-1,1)+w[0];
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
      int scores[]              = {1, 3, 0};
      int expected__            = 8;
      
      clock_t start__           = clock();
      int received__            = P8XGraphBuilder().solve (vector <int> (scores, scores + (sizeof scores / sizeof scores[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 1: {
      int scores[]              = {0, 0, 0, 10};
      int expected__            = 10;
      
      clock_t start__           = clock();
      int received__            = P8XGraphBuilder().solve (vector <int> (scores, scores + (sizeof scores / sizeof scores[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 2: {
      int scores[]              = {1, 2, 3, 4, 5, 6};
      int expected__            = 12;
      
      clock_t start__           = clock();
      int received__            = P8XGraphBuilder().solve (vector <int> (scores, scores + (sizeof scores / sizeof scores[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 3: {
      int scores[]              = {5, 0, 0};
      int expected__            = 15;
      
      clock_t start__           = clock();
      int received__            = P8XGraphBuilder().solve (vector <int> (scores, scores + (sizeof scores / sizeof scores[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 4: {
      int scores[]              = {1, 3, 2, 5, 3, 7, 5};
      int expected__            = 20;
      
      clock_t start__           = clock();
      int received__            = P8XGraphBuilder().solve (vector <int> (scores, scores + (sizeof scores / sizeof scores[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    
    // custom cases
    
    /*      case 5: {
    			int scores[]              = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = P8XGraphBuilder().solve( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 6: {
    			int scores[]              = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = P8XGraphBuilder().solve( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 7: {
    			int scores[]              = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = P8XGraphBuilder().solve( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
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
