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
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
LL _abs(LL x){return x>0?x:-x;}
class RobotHerb {
public:
  long long getdist (int T, vector <int> a) {
    long long ret=0;
    int i,j;
    LL xx=0,yy=0;
    int id=0;
    for (j=0; j<T%4; j++) {
      for (i=0; i<a.SZ; i++) {
        xx+=1LL*a[i]*dx[id];
        yy+=1LL*a[i]*dy[id];
        id= (id+1LL*a[i]) %4;
      }
    }
    int t=a.SZ;
    for (j=0; j<3; j++) for (i=0; i<t; i++) a.PB (a[i]);
    LL tx=0,ty=0;
    for (i=0; i<a.SZ; i++) {
      tx+=1LL*a[i]*dx[id];
      ty+=1LL*a[i]*dy[id];
      id= (id+1LL*a[i]) %4;
    }
    xx+=1LL*tx*(T/4);
    yy+=1LL*ty*(T/4);
    return _abs(xx)+_abs(yy);
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

int verify_case (int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
      int T                     = 1;
      int a[]                   = {1,2,3};
      long long expected__      = 2LL;
      
      clock_t start__           = clock();
      long long received__      = RobotHerb().getdist (T, vector <int> (a, a + (sizeof a / sizeof a[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 1: {
      int T                     = 100;
      int a[]                   = {1};
      long long expected__      = 0LL;
      
      clock_t start__           = clock();
      long long received__      = RobotHerb().getdist (T, vector <int> (a, a + (sizeof a / sizeof a[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 2: {
      int T                     = 5;
      int a[]                   = {1,1,2};
      long long expected__      = 10LL;
      
      clock_t start__           = clock();
      long long received__      = RobotHerb().getdist (T, vector <int> (a, a + (sizeof a / sizeof a[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 3: {
      int T                     = 1000000000;
      int a[]                   = {100};
      long long expected__      = 100000000000LL;
      
      clock_t start__           = clock();
      long long received__      = RobotHerb().getdist (T, vector <int> (a, a + (sizeof a / sizeof a[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 4: {
      int T                     = 570;
      int a[]                   = {2013,2,13,314,271,1414,1732};
      long long expected__      = 4112LL;
      
      clock_t start__           = clock();
      long long received__      = RobotHerb().getdist (T, vector <int> (a, a + (sizeof a / sizeof a[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    
    // custom cases
    
    /*      case 5: {
    			int T                     = ;
    			int a[]                   = ;
    			long long expected__      = LL;
    
    			clock_t start__           = clock();
    			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 6: {
    			int T                     = ;
    			int a[]                   = ;
    			long long expected__      = LL;
    
    			clock_t start__           = clock();
    			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 7: {
    			int T                     = ;
    			int a[]                   = ;
    			long long expected__      = LL;
    
    			clock_t start__           = clock();
    			long long received__      = RobotHerb().getdist( T, vector <int>( a, a + ( sizeof a / sizeof a[0] ) ) );
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
