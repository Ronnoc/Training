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
#define _clr(x) memset(x,0xff,sizeof(int)*n)
typedef long long LL;
typedef pair<int, int> PII;

int play(PII a,PII b){
	return abs(a.AA-b.AA)+abs(a.BB-b.BB);
}
const int inf = 1000000007;
int kuhn_munkras(int m,int n,int mat[][55],int match1[],int match2[]){
	int s[55],t[55],l1[55],l2[55],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}
class DucksAlignment {
public:
	int minimumTime ( vector <string> B ) {
		int ret;
		int n=B.SZ;
		int m=B[0].SZ;
		ret=-inf;
		int i,j,k,l;
		vector<PII>L;
		int lch[55],rch[55];
		int mat[55][55];
		for(i=0;i<n;i++)for(j=0;j<m;j++)if(B[i][j]=='o')L.PB(MP(i,j));
		for(i=0;i<n;i++)for(j=0;j<m;j++){
			if(i+L.SZ<=n){
				for(k=0;k<L.SZ;k++)for(l=0;l<L.SZ;l++)
					mat[k][l]=-play(L[k],MP(i+l,j));
				int tp=kuhn_munkras(L.SZ,L.SZ,mat,lch,rch);
//				cout<<"l:\t";for(k=0;k<L.SZ;k++)printf("(%2d,%2d) ",L[k].AA,L[k].BB);cout<<endl;
//				cout<<"r:\t";for(k=0;k<L.SZ;k++)printf("(%2d,%2d) ",i+k,j);cout<<endl;
				ret=max(ret,tp);
//				cout<<"lch:\t";for(k=0;k<L.SZ;k++)cout<<lch[k]<<" ";cout<<endl;
//				cout<<"rch:\t";for(k=0;k<L.SZ;k++)cout<<rch[k]<<" ";cout<<endl;
//				cout<<tp<<endl;
//				system("pause");
			}
			if(j+L.SZ<=m){
				for(k=0;k<L.SZ;k++)for(l=0;l<L.SZ;l++)
					mat[k][l]=-play(L[k],MP(i,j+l));
				int tp=kuhn_munkras(L.SZ,L.SZ,mat,lch,rch);
//				cout<<"l:\t";for(k=0;k<L.SZ;k++)printf("(%2d,%2d) ",L[k].AA,L[k].BB);cout<<endl;
//				cout<<"r:\t";for(k=0;k<L.SZ;k++)printf("(%2d,%2d) ",i,j+k);cout<<endl;
				ret=max(ret,tp);
//				cout<<"lch:\t";for(k=0;k<L.SZ;k++)cout<<lch[k]<<" ";cout<<endl;
//				cout<<"rch:\t";for(k=0;k<L.SZ;k++)cout<<rch[k]<<" ";cout<<endl;
//				cout<<tp<<endl;
//				system("pause");
			}
		}
		return -ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
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

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string grid[]             = {".o",  "o."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string grid[]             = {".o...",  "..o..",  "....o"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string grid[]             = {"o..........",  "..o........",  ".......o...",  "...........",  "...........",  "...........",  "........o..",  "..........."};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string grid[]             = {".........",  "....o....",  "........."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string grid[]             = {"...o..........................",  "............................o.",  ".o............................",  "............o.................",  ".................o............",  "......................o.......",  "......o.......................",  "....o.........................",  "...............o..............",  ".......................o......",  "...........................o..",  ".......o......................"};
			int expected__            = 99;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
