#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
int x[MXN],y[MXN];
LL z[MXN];
void solve(){
	int n,w,v,u;
	scanf("%d%d%d%d",&n,&w,&v,&u);
	rep(i,0,n)scanf("%d%d",&x[i],&y[i]);
	int le=0,re=0;
	rep(i,0,n){//(v,u) ^ (x[i],y[i])
		z[i]=1LL*u*x[i]-1LL*v*y[i];
		if(z[i]<0)le=1;
		if(z[i]>0)re=1;
	}
	if(!le||!re){
		printf("%.16f\n",1.*w/u);
		return;
	}
	int id=max_element(x,x+n)-x;
	while(1){
		int jd=(id-1+n)%n;
		if(x[jd]>=0&&y[jd]<=y[id])
			id=jd;
		else break;
	}
	double t=1.*y[id]/u;
	while(1){
		//cout<<t<<" "<<x[id]<<","<<y[id]<<"\n";
		double lt=1.*x[id]/v;
		cmax(t,lt);
		int jd=(id+1+n)%n;
		if(x[jd]<x[id])break;
		double rt=1.*x[jd]/v;
		t=max(rt,t+1.*(y[jd]-y[id])/u);
		id=jd;
	}
	t+=1.*(w-y[id])/u;
	printf("%.16f\n",t);
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}