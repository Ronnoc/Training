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

const int MXN = 20005;
int x[MXN],y[MXN],n;
struct point{
	LL x,y;
	int id;
	double a;
	point(LL a=0,LL b=0):x(a),y(b){
		if(x>=0&&y>=0)id=0;
		if(x<0&&y>=0)id=1;
		if(x<0&&y<0)id=2;
		if(x>=0&&y<0)id=3;
	}
	bool operator < (const point &p)const {
		if(p.id!=id)return id<p.id;
		return y*p.x<x*p.y;
	}
	LL friend operator ^ (point p,point q){
		return p.y*q.x-p.x*q.y;
	}
	point rle(){
		return point(-y,x);
	}
	point rre(){
		return point (y,-x);
	}
}p[MXN];
bool fitin(double le,double re,double x){
	while(x<=le)x+=2*PI;
	return x<=re;
}
void solve(){
	while(~scanf("%d",&n)){
		rep(i,0,n)scanf("%d%d",&x[i],&y[i]);
		LL A=0,B=0;
		rep(i,0,n){
			int m=0;
			rep(j,0,n)if(j!=i)
				p[m++]=point(x[j]-x[i],y[j]-y[i]);
			sort(p,p+m);
			int le=0,re=0;
			while(le-1>0-m){
				int pe=((le-1)%m+m)%m;
				if((p[pe]^p[0])<=0&&(p[pe]^(p[0].rre()))>0)
					le--;
				else break;
			}
			while(re+1<le+m){
				int qe=(re+1)%m;
				if((p[qe]^p[0])>=0&&(p[qe]^(p[0].rle()))<0)
					re++;
				else break;
			}
			rep(j,0,m){
				if(le<=j-m)le=j-m+1;
				while(!( (p[(le+m)%m]^p[j])<=0&&(p[(le+m)%m]^(p[j].rre()))>0 ))
					le++;
				if(re<=j)re=j;
				while(re+1<le+m&&(p[(re+1)%m]^p[j])>=0&&(p[(re+1)%m]^(p[j].rle()))<0)
					re++;
				//cout<<le<<"~"<<re<<" @ "<<x[i]<<" "<<y[i]<<" , "<<p[j].x+x[i]<<" "<<p[j].y+y[i]<<"\n";
				int less=re-le+1;
				int more=m-less;
				A+=less-1;
				B+=more;
			}
		}
		//cout<<A<<" "<<B<<"\n";
		cout<<(A-2*B)/6<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}