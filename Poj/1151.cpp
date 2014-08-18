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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;

double px[111],qx[111],py[111],qy[111];
vector<pair<double,double> >L[222];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,CA=0;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++)scanf("%lf%lf%lf%lf",&px[i],&py[i],&qx[i],&qy[i]);
		vector<double>X;
		for(i=0;i<n;i++)X.PB(px[i]);
		for(i=0;i<n;i++)X.PB(qx[i]);
		SORT(X);
		for(i=0;i+1<X.SZ;i++)L[i].clear();
		for(i=0;i<n;i++){
			int lid=upper_bound(X.OP,X.ED,px[i]-eps)-X.OP;
			int rid=upper_bound(X.OP,X.ED,qx[i]-eps)-X.OP;
			for(j=lid;j<rid;j++)
				L[j].PB(MP(py[i],qy[i]));
		}
		double S=0;
		for(i=0;i+1<X.SZ;i++)if(!L[i].empty()){
			SORT(L[i]);
			double d=X[i+1]-X[i];
			double l=L[i][0].AA,r=L[i][0].BB;
			for(j=1;j<L[i].SZ;j++){
				if(L[i][j].AA<=r)
					cmax(r,L[i][j].BB);
				else {
					S+=d*(r-l);
					l=L[i][j].AA,r=L[i][j].BB;
				}
			}
			S+=d*(r-l);
		}
		printf("Test case #%d\n",++CA);
		printf("Total explored area: %.2f\n\n",S);
	}
	return 0;
}
