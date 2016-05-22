//kybconnor
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

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
PII to[12][4][6];
int cl[22][22];
vector<PII>L;
void play () {
	int i;
	int tp=cl[L[L.SZ-1].AA][L[L.SZ-1].BB];
	for (i=L.SZ-1; i>0; i--)
		cl[L[i].AA][L[i].BB]=cl[L[i-1].AA][L[i-1].BB];
	cl[L[0].AA][L[0].BB]=tp;
}
void solve() {
	int t,T,i,j,k,z;
	scanf ("%d",&T);
	for (t=1; t<=T; t++) {
		for (i=0; i<12; i++) for (j=0; j<11; j++) cl[i][j]=i;
		int n;
		scanf ("%d",&n);
		for (i=0; i<n; i++) {
			int p,q;
			scanf ("%d%d",&p,&q);
			for (j=1; j<=3; j++) {
				L.clear();
				for (z=1; z<=5; z++) L.PB (to[p][j][z]);
				if (q==1)
					play ();
				else
					for (z=1; z<=4; z++) play ();
			}
			for (j=0; j<=1; j++) {
				L.clear();
				for (k=j; k<10; k+=2) L.PB (MP (p,k));
				if (q==1)
					play ();
				else
					for (z=1; z<=4; z++) play ();
			}
		}
		printf ("Case %d:\n",t);
		for (i=0; i<12; i++) {
			for (j=0; j<11; j++)
				printf ("%s%d",j?" ":"",cl[i][j]);
			printf ("\n");
		}
	}
}
int main() {
	int i,j,k;
	to[0][1][1]=MP (1,0);
	to[0][1][2]=MP (2,2);
	to[0][1][3]=MP (3,4);
	to[0][1][4]=MP (4,6);
	to[0][1][5]=MP (5,8);
	
	to[1][1][1]=MP (2,4);
	to[1][1][2]=MP (0,4);
	to[1][1][3]=MP (5,6);
	to[1][1][4]=MP (10,6);
	to[1][1][5]=MP (6,6);
	
	to[2][1][1]=MP (3,6);
	to[2][1][2]=MP (0,6);
	to[2][1][3]=MP (1,8);
	to[2][1][4]=MP (6,4);
	to[2][1][5]=MP (7,4);
	
	to[3][1][1]=MP (4,8);
	to[3][1][2]=MP (0,8);
	to[3][1][3]=MP (2,0);
	to[3][1][4]=MP (7,2);
	to[3][1][5]=MP (8,2);
	
	to[4][1][1]=MP (5,0);
	to[4][1][2]=MP (0,0);
	to[4][1][3]=MP (3,2);
	to[4][1][4]=MP (8,0);
	to[4][1][5]=MP (9,0);
	
	to[5][1][1]=MP (1,2);
	to[5][1][2]=MP (0,2);
	to[5][1][3]=MP (4,4);
	to[5][1][4]=MP (9,8);
	to[5][1][5]=MP (10,8);
	
	to[6][1][1]=MP (10,4);
	to[6][1][2]=MP (11,6);
	to[6][1][3]=MP (7,6);
	to[6][1][4]=MP (2,6);
	to[6][1][5]=MP (1,6);
	
	to[7][1][1]=MP (6,2);
	to[7][1][2]=MP (11,4);
	to[7][1][3]=MP (8,4);
	to[7][1][4]=MP (3,8);
	to[7][1][5]=MP (2,8);
	
	to[8][1][1]=MP (7,0);
	to[8][1][2]=MP (11,2);
	to[8][1][3]=MP (9,2);
	to[8][1][4]=MP (4,0);
	to[8][1][5]=MP (3,0);
	
	to[9][1][1]=MP (8,8);
	to[9][1][2]=MP (11,0);
	to[9][1][3]=MP (10,0);
	to[9][1][4]=MP (5,2);
	to[9][1][5]=MP (4,2);
	
	to[10][1][1]=MP (1,4);
	to[10][1][2]=MP (5,4);
	to[10][1][3]=MP (9,6);
	to[10][1][4]=MP (11,8);
	to[10][1][5]=MP (6,8);
	
	to[11][1][1]=MP (10,2);
	to[11][1][2]=MP (9,4);
	to[11][1][3]=MP (8,6);
	to[11][1][4]=MP (7,8);
	to[11][1][5]=MP (6,0);
	
	for (k=0; k<=11; k++) for (i=2; i<=3; i++) for (j=1; j<=5; j++)
				to[k][i][j]=MP (to[k][i-1][j].AA, (to[k][i-1][j].BB+1) %10);
				
//	while(1)
	solve();
	return 0;
}
