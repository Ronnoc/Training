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

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	double R,r,H,S;
	int F;
	while(~scanf("%lf%lf%lf%d%lf",&R,&r,&H,&F,&S)){
		double dr=(R-r)/F;
		double dh=H/F;
		double w=S/dh;
		double ans=0;
		for(i=0;i<F;i++){
			double alpha=atan2(w/2,r)*2;
			int t=2*PI/alpha+eps;
			double beta=PI/t;
			double s=tan(beta)*r*2;
			ans+=s*dh*t;
			r+=dr;
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
