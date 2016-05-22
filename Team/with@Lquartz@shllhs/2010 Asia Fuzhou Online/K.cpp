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
#define double long double
LL m,ox[11111],oy[11111],oz[11111];
LL n,ex[11111],ey[11111],ez[11111];
int etx[11111],ety[11111],etz[11111];
int otx[11111],oty[11111],otz[11111];
vector<double >X,Y,Z;
vector<double >::iterator iter;
const double eps = 1e-8;
LL vx,vy,vz;
vector<pair<int,PII> >Q;
vector<pair<double,int> >P[22222];
void solve() {
	int T,i,j;
	scanf ("%d",&T);
	for (int t=1; t<=T; t++) {
		scanf ("%I64d%I64d",&n,&m);
		X.clear(),Y.clear(),Z.clear(),Q.clear();
		for (i=0; i<=n+m; i++) P[i].clear();
		for (i=1; i<=n; i++)
			scanf ("%I64d%I64d%I64d",&ex[i],&ey[i],&ez[i]);
		for (i=1; i<=m; i++)
			scanf ("%I64d%I64d%I64d",&ox[i],&oy[i],&oz[i]);
		scanf ("%I64d%I64d%I64d",&vx,&vy,&vz);
		for (i=1; i<=n; i++) {
			double left=vx*ex[i]+vy*ey[i]+vz*ez[i];
			left=-left;
			left/= (vx*vx+vy*vy+vz*vz);
			X.PB (ex[i]+left*vx);
			Y.PB (ey[i]+left*vy);
			Z.PB (ez[i]+left*vz);
		}
		for (i=1; i<=m; i++) {
			double left=vx*ox[i]+vy*oy[i]+vz*oz[i];
			left=-left;
			left/= (vx*vx+vy*vy+vz*vz);
			X.PB (ox[i]+left*vx);
			Y.PB (oy[i]+left*vy);
			Z.PB (oz[i]+left*vz);
		}
		SORT (X); UNIQUE (X);
		SORT (Y); UNIQUE (Y);
		SORT (Z); UNIQUE (Z);
		for (i=1; i<=n; i++) {
			double left=vx*ex[i]+vy*ey[i]+vz*ez[i];
			left=-left;
			left/= (vx*vx+vy*vy+vz*vz);
			int tx=etx[i]=upper_bound (X.OP,X.ED,ex[i]+left*vx-eps)-X.OP;
			int ty=ety[i]=upper_bound (Y.OP,Y.ED,ey[i]+left*vy-eps)-Y.OP;
			int tz=etz[i]=upper_bound (Z.OP,Z.ED,ez[i]+left*vz-eps)-Z.OP;
			Q.PB (MP (tx,MP (ty,tz)));
		}
		for (i=1; i<=m; i++) {
			double left=vx*ox[i]+vy*oy[i]+vz*oz[i];
			left=-left;
			left/= (vx*vx+vy*vy+vz*vz);
			int tx=otx[i]=upper_bound (X.OP,X.ED,ox[i]+left*vx-eps)-X.OP;
			int ty=oty[i]=upper_bound (Y.OP,Y.ED,oy[i]+left*vy-eps)-Y.OP;
			int tz=otz[i]=upper_bound (Z.OP,Z.ED,oz[i]+left*vz-eps)-Z.OP;
			Q.PB (MP (tx,MP (ty,tz)));
		}
		SORT (Q); UNIQUE (Q);
		for (i=1; i<=n; i++) {
			double left=vx*ex[i]+vy*ey[i]+vz*ez[i];
			left=-left;
			left/= (vx*vx+vy*vy+vz*vz);
			int tx=etx[i];
			int ty=ety[i];
			int tz=etz[i];
			int tq=lower_bound (Q.OP,Q.ED,MP (tx,MP (ty,tz)))-Q.OP;
			P[tq].PB (MP (-left,1));
		}
		for (i=1; i<=m; i++) {
			double left=vx*ox[i]+vy*oy[i]+vz*oz[i];
			left=-left;
			left/= (vx*vx+vy*vy+vz*vz);
			int tx=otx[i];
			int ty=oty[i];
			int tz=otz[i];
			int tq=lower_bound (Q.OP,Q.ED,MP (tx,MP (ty,tz)))-Q.OP;
			P[tq].PB (MP (-left,0));
		}
		int res=0;
		for (i=0; i<Q.SZ; i++) {
			SORT (P[i]);
			for (j=0; j<P[i].SZ; j++) if (P[i][j].BB==0) break;
			for (; j<P[i].SZ; j++) if (P[i][j].BB==1) res++;
		}
		printf ("Case %d: %d\n",t,res);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
