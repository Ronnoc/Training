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
const double PI=acos(-1.);
const LL MOD = 1000000007;
const int MXN = 200005+10;
int X[MXN],Y[MXN];
double S[MXN];
int n,L,D;
double YY(int id,double x){
	if(id==1)return Y[1];
	double dx=X[id]-X[id-1];
	double dy=Y[id]-Y[id-1];
	return Y[id-1]+dy*(x-X[id-1])/dx;
}
double cal(int id,double x){
	if(id==1)return 0;
	double y=YY(id,x);
	double ret=S[id-1]+(y+Y[id-1])*(x-X[id-1])*.5;
	return ret;
}
double solve(int le,int pl,int ql,int re,int pr,int qr){
	double ret=0;
	cmax(ret,cal(re,qr)-cal(le,ql));
	cmax(ret,cal(re,pr)-cal(le,pl));
//	cerr<<le<<"@ "<<pl<<"~"<<ql<<" "<<re<<"@ "<<pr<<"~"<<qr<<" =>"<<ret<<"\n";
	if(re==le||pl==ql)return ret;
	double u=ql-pl;
	double a=YY(le,pl);
	double b=YY(le,ql);
	double c=YY(re,pr);
	double d=YY(re,qr);
	double dl=(b-a)/u;
	double dr=(d-c)/u;
	double A=2*(dr-dl);
	if(fabs(A)<eps)return ret;
	double B=2*c+u*dl-a-b;
	double C=(a+b)*u;
	double x=-B/A;
	if(x>0&&x<u)
		cmax(ret,cal(re,pr+x)-cal(le,pl+x));
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--) {
		scanf("%d%d",&n,&L);
		for(i=1; i<=n; i++)scanf("%d%d",&X[i],&Y[i]);
		X[n+1]=MOD<<1;
		scanf("%d",&D);
		D<<=1;
		double ans=0;
		if(!D) {
			for(i=1; i<=n; i++)if(Y[i]>ans)ans=Y[i];
			printf("%.3f\n",ans);
			continue;
		}
		S[1]=0;
		for(i=2; i<=n; i++)
			S[i]=S[i-1]+.5*(Y[i]+Y[i-1])*(X[i]-X[i-1]);
		vector<int>V;
		int le=1,re=1;
		while(X[re]-D<=0)re++;
		while(X[le]+D<=L) {
			int p=X[le],q=X[re]-D;
			if(p<=q) {
				V.PB(p);
				le++;
				if(p==q)re++;
			} else {
				V.PB(q);
				re++;
			}
		}
		sort(V.OP,V.ED);
		V.erase(unique(V.OP,V.ED),V.ED);
		le=1,re=1;
		int last=0;
		for(i=0;i<V.SZ;i++){
			int zz=V[i]+D,yy=V[i];
			while(X[re]<zz)re++;
			while(X[le]<yy)le++;
			cmax(ans,solve(le,last,yy,re,zz-yy+last,zz));
			last=yy;
		}
		printf("%.3f\n",ans/D);
	}
	return 0;
}
