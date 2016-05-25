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
#define UNIQUE(X) X.erase(unique(X.begin(),X.end()),X.end())
#define PB push_back
#define MP make_pair
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
vector<PII>T[5010];
int play (int c,int a,int b) {
  if (SQ (a) +SQ (b) ==SQ (c)) return 1;
  return 0;
}
class FindPolygons {
public:
  double minimumPolygon (int L) {
    if (L&1) return -1.0;
    if (L==2) return -1.0;
    int flag=0,ret=L;
    int i,j,p,q,r,h,a,b,c,d,m,n;
    for (i=0; i<=L; i++) T[i].clear();
    for (i=0; i<=L; i++) for (j=i; j<=L; j++) {
        h=sqrt (i*i+j*j+1e-6);
        if (h>L) break;
        if (play (h,i,j)) T[h].PB (MP (i,j));
      }
    for(i=0;i<=L;i++)SORT(T[i]);
    for(i=0;i<=L;i++)UNIQUE(T[i]);
    for (p=1; p<L; p++) for (q=p; q+p<L; q++) {
        r=L-p-q;
        if (r<q) continue;
        if (p+q<=r) continue;
        for (i=0; i<T[p].SZ; i++)
          for (j=0; j<T[q].SZ; j++) {
						a=T[p][i].AA,b=T[p][i].BB;
						c=T[q][j].AA,d=T[q][j].BB;
						m=a+c,n=b+d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						m=a+c,n=b-d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						m=a-c,n=b+d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						m=a-c,n=b-d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						swap(c,d);
						m=a+c,n=b+d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						m=a+c,n=b-d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						m=a-c,n=b+d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
						m=a-c,n=b-d;
						if(play(r,m,n))flag=1,ret=min(ret,r-p);
          }
      }
    if(flag)return ret;
    if(L%4==0)return 0;
    return 1;
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

static const double MAX_DOUBLE_ERROR = 1e-9;
static bool topcoder_fequ (double expected, double result) { if (isnan (expected)) { return isnan (result); } else if (isinf (expected)) { if (expected > 0) { return result > 0 && isinf (result); } else { return result < 0 && isinf (result); } } else if (isnan (result) || isinf (result)) { return false; } else if (fabs (result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min (expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max (expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
double moj_relative_error (double expected, double result) { if (isnan (expected) || isinf (expected) || isnan (result) || isinf (result) || expected == 0) return 0; return fabs (result-expected) / fabs (expected); }

int verify_case (int casenum, const double &expected, const double &received, clock_t elapsed) {
  cerr << "Example " << casenum << "... ";
  
  string verdict;
  vector<string> info;
  char buf[100];
  
  if (elapsed > CLOCKS_PER_SEC / 200) {
    sprintf (buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
    info.push_back (buf);
  }
  
  if (topcoder_fequ (expected, received)) {
    verdict = "PASSED";
    double rerr = moj_relative_error (expected, received);
    if (rerr > 0) {
      sprintf (buf, "relative error %.3e", rerr);
      info.push_back (buf);
    }
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
      int L                     = 4;
      double expected__         = 0.0;
      
      clock_t start__           = clock();
      double received__         = FindPolygons().minimumPolygon (L);
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 1: {
      int L                     = 5;
      double expected__         = -1.0;
      
      clock_t start__           = clock();
      double received__         = FindPolygons().minimumPolygon (L);
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 2: {
      int L                     = 12;
      double expected__         = 2.0;
      
      clock_t start__           = clock();
      double received__         = FindPolygons().minimumPolygon (L);
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 3: {
      int L                     = 4984;
      double expected__         = 819.0;
      
      clock_t start__           = clock();
      double received__         = FindPolygons().minimumPolygon (L);
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    
    // custom cases
    
    case 4: {
      int L                     = 60;
      double expected__         = 10;
      
      clock_t start__           = clock();
      double received__         = FindPolygons().minimumPolygon (L);
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    case 5: {
      int L                     = 720;
      double expected__         = 120;
      
      clock_t start__           = clock();
      double received__         = FindPolygons().minimumPolygon (L);
      return verify_case (casenum, expected__, received__, clock()-start__);
    }
    /*      case 6: {
    			int L                     = ;
    			double expected__         = ;
    
    			clock_t start__           = clock();
    			double received__         = FindPolygons().minimumPolygon( L );
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
