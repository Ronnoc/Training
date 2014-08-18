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
const long double eps=1e-8;
const long double PI=acos( -1. );
const LL MOD = 1000000007;

long double L[2],R[2],mid,d[2],g;

long double getSpeed(long double d,long double s,long double L,long double R){
	long double tmin=s/d*L/(s-d);
	long double tmax=s/d*R/(s-d);
	long double s1=(1+SQ(tmin))/2/tmin;
	long double s2=(1+SQ(tmax))/2/tmax;
	long double ret=s*g*min(s1,s2);
	if(tmin<=1.&&tmax>=1.)ret=s*g;
	return sqrt(ret);
}
long double _getSpeed(long double d, long double s, long double b, long double t) {
	long double c = d * (1 - d / s);
	b /= c;
	t /= c;
	if (b > 1) {
		return sqrt(g * s / 2 * (b + 1 / b));
	} else if (t < 1) {
		return sqrt(g * s / 2 * (t + 1 / t));
	} else {
		return sqrt(g * s);
	}
}
long double gao(long double x){
	return max(getSpeed(d[0],x+d[0],L[0],R[0]),getSpeed(d[1],mid-x+d[1],L[1],R[1]));
}
int main() {
//	freopen("jumper.in","r",stdin);
//	freopen("jumper.out","w",stdout);
	int i,j,k;
	while(cin>>L[0]>>R[0]>>L[1]>>R[1]>>mid>>d[0]>>d[1]>>g){
		long double l=0,r=mid;
		long double fl=gao(l),fr=gao(r);
		for(i=0;i<300;i++){
			long double p=(l*2+r)/3;
			long double q=(l+r*2)/3;
			long double fp=gao(p),fq=gao(q);
			if(fp>fq)l=p,fl=fp;
			else r=q,fr=fq;
		}
		printf("%.16lf\n",(double)gao((l+r)/2));
	}
	return 0;
}
