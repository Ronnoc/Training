#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define PII pair<int,int>
//o.o.ox.,.o.o...,o.o.ox.,.o.o...,o.o.ox.,x.x.x..,......o
bool able (int i, int j, int n) {
  n--;
  if (i < 0 || i > n) return 0;
  if (j < 0 || j > n) return 0;
  return 1;
}
int dx[] = {0, 1, 2, 1, 0, -1, -2, -1};
int dy[] = {2, 1, 0, -1, -2, -1, 0, 1};
int DX[] = {0, 0, 1, -1};
int DY[] = {1, -1, 0, 0};
int solve (int ii, int jj, vector <string> b) {
  stack<PII>L;
  L.push (MP (ii, jj));
  while (!L.empty()) {
    PII u = L.top();
    L.pop();
    int i;
    for (i = 0; i < 8; i++) {
      int x = u.AA + dx[i], y = u.BB + dy[i];
      if (able (x, y, b.size()) && b[x][y] == 'o') L.push (MP (x, y));
    }
    for (i = 0; i < 4; i++) {
      int x = u.AA + DX[i], y = u.BB + DY[i];
      if (able (x, y, b.size()) && b[x][y] == '.') b[x][y] = 'x';
    }
    b[u.AA][u.BB] = '.';
  }
  int ret = 0;
  int i, j;
  for (i = 0; i < b.size(); i++) for (j = 0; j < b.size(); j++) if (b[i][j] == '.') ret++;
  return ret;
}
class FoxAndGo3 {
public:
  int maxEmptyCells (vector <string> b) {
    for (int i = 0; i < b.size(); i++) cout << b[i] << endl;
    while (1) {
      int found = 0;
      int i, j;
      for (i = 0; i < b.size(); i++) for (j = 0; j < b.size(); j++) {
          if (b[i][j] != 'o') continue;
          vector <string> c = b;
          int cost = 0;
          if (able (i + 1, j, b.size()) && c[i + 1][j] == '.') cost++, c[i + 1][j] = 'x';
          if (able (i - 1, j, b.size()) && c[i - 1][j] == '.') cost++, c[i - 1][j] = 'x';
          if (able (i, j + 1, b.size()) && c[i][j + 1] == '.') cost++, c[i][j + 1] = 'x';
          if (able (i, j - 1, b.size()) && c[i][j - 1] == '.') cost++, c[i][j - 1] = 'x';
          int ii, jj;
          int dead = 0;
          for (ii = 0; ii < b.size(); ii++) for (jj = 0; jj < b.size(); jj++) {
              if (c[ii][jj] != 'o') continue;
              if (able (ii + 1, jj, b.size()) && c[ii + 1][jj] == '.') continue;
              if (able (ii - 1, jj, b.size()) && c[ii - 1][jj] == '.') continue;
              if (able (ii, jj + 1, b.size()) && c[ii][jj + 1] == '.') continue;
              if (able (ii, jj - 1, b.size()) && c[ii][jj - 1] == '.') continue;
              dead++;
              c[ii][jj] = '.';
            }
          if (dead >= cost) {
            found = 1;
            b = c;
          }
        }
      if (!found) break;
    }
//  	for(int i=0;i<b.size();i++)cout<<b[i]<<endl;
    int ret = 0;
    int i, j;
    for (i = 0; i < b.size(); i++) for (j = 0; j < b.size(); j++) if (b[i][j] == '.') ret++;
    while (1) {
      int found = 0;
      int ii, jj;
      for (ii = 0; ii < b.size(); ii++) for (jj = 0; jj < b.size(); jj++) {
          if (b[ii][jj] != 'o') continue;
          vector <string> c = b;
          int now = solve (ii, jj, c);
          if (now > ret) {ret = now; found = 1; b = c;}
        }
      if (!found) break;
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
  for (int i = 0;; ++i) {
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
    sprintf (buf, "time %.2fs", elapsed * (1.0 / CLOCKS_PER_SEC));
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
    for (int i = 0; i < (int) info.size(); ++i) {
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
      string board[]            = {"o.o",  ".o.",  "o.o"};
      int expected__            = 5;
      
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    case 1: {
      string board[]            = {"...",  ".o.",  "..."} ;
      int expected__            = 8;
      
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    case 2: {
      string board[]            = {"xxxxx",  "xxoxx",  "xo.ox",  "xxoxx",  "xxxxx"} ;
      int expected__            = 4;
      
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    case 3: {
      string board[]            = {".xox.",  ".o.ox",  "x.o.o",  "ox.ox",  ".ox.."}  ;
      int expected__            = 12;
      
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    case 4: {
      string board[]            = {"o.o.o",  ".ox..",  "oxxxo",  "..x..",  "o.o.o"} ;
      int expected__            = 12;
      
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    case 5: {
      string board[]            = {"...",  "...",  "..."};
      int expected__            = 9;
      
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    
    // custom cases
    
    case 6: {
      string board[]            = {"o.o.ox.", ".o.o...", "o.o.ox.", ".o.o...", "o.o.ox.", "x.x.x..", "......o"};
      int expected__            = 30;
      clock_t start__           = clock();
      int received__            = FoxAndGo3().maxEmptyCells (vector <string> (board, board + (sizeof board / sizeof board[0])));
      return verify_case (casenum, expected__, received__, clock() - start__);
    }
    /*      case 7: {
    			string board[]            = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = FoxAndGo3().maxEmptyCells( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 8: {
    			string board[]            = ;
    			int expected__            = ;
    
    			clock_t start__           = clock();
    			int received__            = FoxAndGo3().maxEmptyCells( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
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
    for (int i = 1; i < argc; ++i)
      moj_harness::run_test (atoi (argv[i]));
  }
}
// END CUT HERE
