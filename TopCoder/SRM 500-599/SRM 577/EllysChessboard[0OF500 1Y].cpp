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
vector<PII>L;
int dp[20][20][20][20];
int fabs( int x ) {return x>0?x:-x;}
bool outside( int id,int lx,int ly,int rx,int ry ) {
  if ( L[id].AA<lx )return 1;
  if ( L[id].AA>rx )return 1;
  if ( L[id].BB<ly )return 1;
  if ( L[id].BB>ry )return 1;
  return 0;
}
int dfs( int lx,int ly,int rx,int ry ) {
  int &tp=dp[lx][ly][rx][ry];
  if ( tp!=-1 )return tp;
  int i,j;
  tp=1e9;
  bool allinside=1;
  for ( i=0; i<L.SZ; i++ ) {
    if ( !outside( i,lx,ly,rx,ry ) )continue;
    allinside=0;
    int cost=max( max( fabs( L[i].AA-lx ),fabs( L[i].AA-rx ) ),max( fabs( L[i].BB-ly ),fabs( L[i].BB-ry ) ) );
    int _lx=min( L[i].AA,lx );
    int _ly=min( L[i].BB,ly );
    int _rx=max( L[i].AA,rx );
    int _ry=max( L[i].BB,ry );
    for ( j=0; j<L.SZ; j++ ) {
			if(i==j)continue;
      if ( outside( j,lx,ly,rx,ry )&&!outside( j,_lx,_ly,_rx,_ry ) )
        cost+=max( max( fabs( L[j].AA-_lx ),fabs( L[j].AA-_rx ) ),max( fabs( L[j].BB-_ly ),fabs( L[j].BB-_ry ) ) );
    }
    int temp=dfs( _lx,_ly,_rx,_ry );
    tp=min( tp,cost+temp );
  }
  if ( allinside ) tp=0;
  return tp;
}
class EllysChessboard {
public:
  int minCost( vector <string> B ) {
    int ret=1e9;
    int i,j;
    L.clear();
    for ( i=0; i<B.SZ; i++ )
      for ( j=0; j<B[0].SZ; j++ )
        if ( B[i][j]=='#' ) {
          int tx=i+j;
          int ty=i-j;
          ty+=8;
          L.PB( MP( tx,ty ) );
        }
    if ( L.size()<=1 )return 0;
    memset( dp,-1,sizeof dp );
    for ( i=0; i<L.SZ; i++ ) {
      int tp=dfs( L[i].AA,L[i].BB,L[i].AA,L[i].BB );
      ret=min( ret,tp );
    }
    return ret;
  }
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case( int );
void run_test( int casenum = -1, bool quiet = false ) {
  if ( casenum != -1 ) {
    if ( run_test_case( casenum ) == -1 && !quiet )
      cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
    return;
  }

  int correct = 0, total = 0;
  for ( int i=0;; ++i ) {
    int x = run_test_case( i );
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

int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
  cerr << "Example " << casenum << "... ";

  string verdict;
  vector<string> info;
  char buf[100];

  if ( elapsed > CLOCKS_PER_SEC / 200 ) {
    sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
    info.push_back( buf );
  }

  if ( expected == received ) {
    verdict = "PASSED";
  } else {
    verdict = "FAILED";
  }

  cerr << verdict;
  if ( !info.empty() ) {
    cerr << " (";
    for ( int i=0; i<( int )info.size(); ++i ) {
      if ( i > 0 ) cerr << ", ";
      cerr << info[i];
    }
    cerr << ")";
  }
  cerr << endl;

  if ( verdict == "FAILED" ) {
    cerr << "    Expected: " << expected << endl;
    cerr << "    Received: " << received << endl;
  }

  return verdict == "PASSED";
}

int run_test_case( int casenum ) {
  switch ( casenum ) {
    case 0: {
      string board[]            = {"........",  "........",  "...#....",  ".#......",  ".......#",  "........",  "........",  "........"};
      int expected__            = 10;

      clock_t start__           = clock();
      int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
      return verify_case( casenum, expected__, received__, clock()-start__ );
    }
    case 1: {
      string board[]            = {"........",  "........",  "........",  "........",  "........",  "........",  "........",  "........"};
      int expected__            = 0;

      clock_t start__           = clock();
      int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
      return verify_case( casenum, expected__, received__, clock()-start__ );
    }
  case 2: {
    string board[]            = {".#......",  "........",  "..#..#.#",  "...#..#.",  "........",  "...#...#",  "...#...#",  "........"};
    int expected__            = 58;

    clock_t start__           = clock();
    int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
    return verify_case( casenum, expected__, received__, clock()-start__ );
  }
  case 3: {
    string board[]            = {"##..####",  "#####..#",  "..#.#...",  "#..##.##",  ".#.###.#",  "####.###",  "#.#...#.",  "##....#."};
    int expected__            = 275;

    clock_t start__           = clock();
    int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
    return verify_case( casenum, expected__, received__, clock()-start__ );
  }
  case 4: {
    string board[]            = {"########",  "########",  "########",  "########",  "########",  "########",  "########",  "########"};
    int expected__            = 476;

    clock_t start__           = clock();
    int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
    return verify_case( casenum, expected__, received__, clock()-start__ );
  }

  // custom cases

  /*      case 5: {
  			string board[]            = ;
  			int expected__            = ;

  			clock_t start__           = clock();
  			int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
  			return verify_case( casenum, expected__, received__, clock()-start__ );
  		}*/
    /*      case 6: {
    			string board[]            = ;
    			int expected__            = ;

    			clock_t start__           = clock();
    			int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    /*      case 7: {
    			string board[]            = ;
    			int expected__            = ;

    			clock_t start__           = clock();
    			int received__            = EllysChessboard().minCost( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
    			return verify_case( casenum, expected__, received__, clock()-start__ );
    		}*/
    default:
      return -1;
  }
}
}


int main( int argc, char *argv[] ) {
  if ( argc == 1 ) {
    moj_harness::run_test();
  } else {
    for ( int i=1; i<argc; ++i )
      moj_harness::run_test( atoi( argv[i] ) );
  }
}
// END CUT HERE
