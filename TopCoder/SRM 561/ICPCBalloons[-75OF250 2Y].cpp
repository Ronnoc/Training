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
#include <assert.h>
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
int play (vector<int>L,vector<int>ma) {
  int i,ret=0;
  for (i=0; i<ma.SZ; i++) {
    if (i<L.SZ) ret-=min (L[i],ma[i]);
    ret+=ma[i];
  }
  return ret;
}
class ICPCBalloons {
public:
  int minRepaintings (vector <int> bc, string bs, vector <int> ma) {
    int ret=1000000007,i,j;
    sort (ma.rbegin(),ma.rend());
    vector<int>M,L;
    for (i=0; i<bs.size(); i++)
      if (bs[i]=='M') M.PB (bc[i]);
      else L.PB (bc[i]);
    sort (M.rbegin(),M.rend());
    sort (L.rbegin(),L.rend());
    int sumM=accumulate (M.OP,M.ED,0);
    int sumL=accumulate (L.OP,L.ED,0);
    for (i=0; i< (1<<int (ma.SZ)); i++) {
      int tom=0,tol=0;
      vector<int>l,m;
      for (j=0; j<ma.SZ; j++) if (i>>j&1) tom+=ma[j];
        else tol+=ma[j];
      for (j=0; j<ma.SZ; j++) if (i>>j&1) m.PB (ma[j]);
        else l.PB (ma[j]);
      if (tom<=sumM&&tol<=sumL) ret=min (ret,play (M,m) +play (L,l));
    }
    if (ret==1000000007) return -1;
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
      int balloonCount[]        = {100};
      string balloonSize        = "L";
      int maxAccepted[]         = {1,2,3,4,5};
      int expected__            = 10;
      
      clock_t start__           = clock();
      int received__            = ICPCBalloons().minRepaintings (vector <int> (balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int> (maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
  case 1: {
    int balloonCount[]        = {100};
    string balloonSize        = "M";
    int maxAccepted[]         = {10,20,30,40,50};
    int expected__            = -1;

    clock_t start__           = clock();
    int received__            = ICPCBalloons().minRepaintings (vector <int> (balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int> (maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
    return verify_case (casenum, expected__, received__, clock()-start__);
  }
  case 2: {
    int balloonCount[]        = {5,6,1,5,6,1,5,6,1};
    string balloonSize        = "MLMMLMMLM";
    int maxAccepted[]         = {7,7,4,4,7,7};
    int expected__            = 6;

    clock_t start__           = clock();
    int received__            = ICPCBalloons().minRepaintings (vector <int> (balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int> (maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
    return verify_case (casenum, expected__, received__, clock()-start__);
  }
  case 3: {
    int balloonCount[]        = {100,100};
    string balloonSize        = "ML";
    int maxAccepted[]         = {50,51,51};
    int expected__            = -1;

    clock_t start__           = clock();
    int received__            = ICPCBalloons().minRepaintings (vector <int> (balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int> (maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
    return verify_case (casenum, expected__, received__, clock()-start__);
  }
  case 4: {
    int balloonCount[]        = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
    string balloonSize        = "MMMLLLMMLLMLMLM";
    int maxAccepted[]         = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
    int expected__            = 5;

    clock_t start__           = clock();
    int received__            = ICPCBalloons().minRepaintings (vector <int> (balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int> (maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
    return verify_case (casenum, expected__, received__, clock()-start__);
  }
  case 5: {
    int balloonCount[]        = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
    string balloonSize        = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
    int maxAccepted[]         = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
    int expected__            = 210;

    clock_t start__           = clock();
    int received__            = ICPCBalloons().minRepaintings (vector <int> (balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int> (maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
    return verify_case (casenum, expected__, received__, clock()-start__);
  }

  // custom cases

        case 6: {
  			int balloonCount[]        = {4, 2, 14, 17, 10, 10, 13, 10, 8, 3, 9, 7, 10, 7, 2, 16, 6, 6, 13, 17, 1, 17, 16, 1, 6, 18, 16, 11, 4, 6, 17, 7, 1, 14, 11, 14, 9, 16, 6, 1, 8, 17, 6, 15, 15, 5, 18, 5, 6, 2};
  			string balloonSize        = "LLLLLLLLLLLLLLLLLMLLLMLLLLLLLLLLLLLLLLLLMLLLLLLLLL";
  			int maxAccepted[]         = {45, 30, 69, 52, 2, 40, 6, 36, 10, 11, 13, 41, 56, 47, 15};
  			int expected__            = 266;

  			clock_t start__           = clock();
  			int received__            = ICPCBalloons().minRepaintings( vector <int>( balloonCount, balloonCount + ( sizeof balloonCount / sizeof balloonCount[0] ) ), balloonSize, vector <int>( maxAccepted, maxAccepted + ( sizeof maxAccepted / sizeof maxAccepted[0] ) ) );
  			return verify_case( casenum, expected__, received__, clock()-start__ );
  		}
  /*      case 7: {
  			int balloonCount[]        = ;
  			string balloonSize        = ;
  			int maxAccepted[]         = ;
  			int expected__            = ;

  			clock_t start__           = clock();
  			int received__            = ICPCBalloons().minRepaintings( vector <int>( balloonCount, balloonCount + ( sizeof balloonCount / sizeof balloonCount[0] ) ), balloonSize, vector <int>( maxAccepted, maxAccepted + ( sizeof maxAccepted / sizeof maxAccepted[0] ) ) );
  			return verify_case( casenum, expected__, received__, clock()-start__ );
  		}*/
    /*      case 8: {
    			int balloonCount[]        = ;
    			string balloonSize        = ;
    			int maxAccepted[]         = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = ICPCBalloons().minRepaintings( vector <int>( balloonCount, balloonCount + ( sizeof balloonCount / sizeof balloonCount[0] ) ), balloonSize, vector <int>( maxAccepted, maxAccepted + ( sizeof maxAccepted / sizeof maxAccepted[0] ) ) );
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
