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
/*
and
1 0
0 0
or
1 1
1 0
xor
0 1
1 0
*/
class TheDevice {
public:
  int minimumAdditional (vector <string> p) {
    int i,j,k;
    int cnt[55];
    int tnc[55];
    for(i=0;i<p[0].SZ;i++)cnt[i]=0;
    for(i=0;i<p[0].SZ;i++)tnc[i]=0;
    for (i=0; i<p.SZ; i++){
			for(j=0;j<p[i].SZ;j++)
				if(p[i][j]=='1')cnt[j]++;
    }
    for (i=0; i<p.SZ; i++){
			for(j=0;j<p[i].SZ;j++)
				if(p[i][j]=='0')tnc[j]++;
    }
    int ret=0;
    for(j=0;j<p[0].SZ;j++){
			if(cnt[j]>2)cnt[j]=2;
			if(tnc[j])ret=max(ret,2-cnt[j]);
			else ret=max(ret,3-cnt[j]);
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
      string plates[]           = {"010",  "011",  "101"};
      int expected__            = 1;
      
      clock_t start__           = clock();
      int received__            = TheDevice().minimumAdditional (vector <string> (plates, plates + (sizeof plates / sizeof plates[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 1: {
      string plates[]           = {"0",  "1",  "0",  "1"};
      int expected__            = 0;
      
      clock_t start__           = clock();
      int received__            = TheDevice().minimumAdditional (vector <string> (plates, plates + (sizeof plates / sizeof plates[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 2: {
      string plates[]           = {"01010101",  "10101010"};
      int expected__            = 1;
      
      clock_t start__           = clock();
      int received__            = TheDevice().minimumAdditional (vector <string> (plates, plates + (sizeof plates / sizeof plates[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 3: {
      string plates[]           = {"10010101011",  "00010101001",  "00100010111",  "00101010101",  "01010111101"};
      int expected__            = 1;
      
      clock_t start__           = clock();
      int received__            = TheDevice().minimumAdditional (vector <string> (plates, plates + (sizeof plates / sizeof plates[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 4: {
      string plates[]           = {"1101001011010",  "0010000010101",  "1010101011110",  "1101010100111",  "1011111110111"};
      int expected__            = 0;
      
      clock_t start__           = clock();
      int received__            = TheDevice().minimumAdditional (vector <string> (plates, plates + (sizeof plates / sizeof plates[0])));
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    
    // custom cases
    
    /*      case 5: {
    			string plates[]           = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 6: {
    			string plates[]           = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 7: {
    			string plates[]           = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = TheDevice().minimumAdditional( vector <string>( plates, plates + ( sizeof plates / sizeof plates[0] ) ) );
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
