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
inline LL mabs(LL a) {return a<0?-a:a;}
struct frac {
	LL x,y;
	frac(LL _x=0,LL _y=1) {
		LL g=__gcd(mabs(_x),mabs(_y));
		x=_x/g,y=_y/g;
		if(y<0)y=-y,x=-x;
	}
	frac operator + (frac f) {return frac(f.y*x+y*f.x,y*f.y);}
	frac operator * (LL a) {return frac(x*a,y);}
	frac operator / (LL a) {return frac(x,y*a);}
	void show() {printf("(%I64d/%I64d)",x,y);}
};
LL comb[33][33];
frac sn[33][33];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	for(i=0; i<=25; i++) {
		comb[i][0]=comb[i][i]=1;
		for(j=1; j<i; j++)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
	}
	sn[0][1]=frac(1,1);
	for(k=1; k<=20; k++) {
		sn[k][k+1]=frac(1,1);
		for(i=0; i<k; i++)
			for(j=1; j<=i+1; j++)
				sn[k][j]=sn[k][j]+sn[i][j]*(comb[k+1][i]*(k%2==i%2?-1:1));
		for(i=1; i<=k+1; i++)
			sn[k][i]=sn[k][i]/(k+1);
	}
	while(~scanf("%d",&k)){
		LL M=1;
		for(i=1;i<=k+1;i++)M=M/__gcd(M,sn[k][i].y)*sn[k][i].y;
		printf("%I64d",M);
		for(i=k+1;i>=1;i--)printf(" %I64d",M/sn[k][i].y*sn[k][i].x);
		printf(" 0\n");
	}
	return 0;
}
