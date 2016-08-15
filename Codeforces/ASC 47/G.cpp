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
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
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
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
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
double ans[2][15][15];
double f[2][3005][3005];
int v[3005][3005];
void solve(){
	int d,b;
	while(~scanf("%d%d",&d,&b)){
		if(!d&&!b)break;
		printf("%.16f %.16f\n",ans[1][d][b],ans[0][d][b]);
	}
}
int s[15];
void dfs(int d,int b,VI w,VI c){
	if(v[w[0]][w[1]])return;
	v[w[0]][w[1]]=1;
	if(c[0]==d&&c[1]==d){
		f[0][w[0]][w[1]]=w[0]>w[1];
		f[1][w[0]][w[1]]=w[0]>w[1];
		return;
	}
	VI t[2];
	rep(i,0,2){
		int temp=w[i];
		rep(j,0,d){
			t[i].PB(temp%(b+1));
			temp/=b+1;
		}
	}
	rep(i,0,2)rep(j,0,d)if(t[i][j]==0)
		rep(k,1,b+1){
			w[i]+=k*s[j];
			c[i]++;
			dfs(d,b,w,c);
			w[i]-=k*s[j];
			c[i]--;
		}
	double per=1./b;
	f[0][w[0]][w[1]]=0;
	rep(k,1,b+1){
		double more=0,less=1;
		rep(j,0,d){
			if(c[0]==d&&t[1][j]==0){
				cmax(more,f[0][w[0]][w[1]+k*s[j]]);
				cmin(less,f[0][w[0]][w[1]+k*s[j]]);
			}
			if(c[0]<d&&t[0][j]==0){
				cmax(more,f[0][w[0]+k*s[j]][w[1]]);
				cmin(less,f[0][w[0]+k*s[j]][w[1]]);
			}
		}
		if(c[0]==d)f[0][w[0]][w[1]]+=less;
		else f[0][w[0]][w[1]]+=more;
	}
	f[0][w[0]][w[1]]/=b;
	f[1][w[0]][w[1]]=0;
	rep(k,1,b+1){
		double more=0,less=1;
		rep(j,0,d){
			if(c[0]>c[1]&&t[1][j]==0){
				cmax(more,f[1][w[0]][w[1]+k*s[j]]);
				cmin(less,f[1][w[0]][w[1]+k*s[j]]);
			}
			if(c[0]==c[1]&&t[0][j]==0){
				cmax(more,f[1][w[0]+k*s[j]][w[1]]);
				cmin(less,f[1][w[0]+k*s[j]][w[1]]);
			}
		}
		if(c[0]>c[1])f[1][w[0]][w[1]]+=less;
		else f[1][w[0]][w[1]]+=more;
	}
	f[1][w[0]][w[1]]/=b;
}
char ss[]="1 2 0.2500000000000000 0.2500000000000000 1 3 0.3333333333333333 0.3333333333333333 1 4 0.3750000000000000 0.3750000000000000 1 5 0.4000000000000000 0.4000000000000000 1 6 0.4166666666666667 0.4166666666666667 1 7 0.4285714285714285 0.4285714285714285 1 8 0.4375000000000000 0.4375000000000000 1 9 0.4444444444444444 0.4444444444444444 1 10 0.4500000000000000 0.4500000000000000 2 2 0.3125000000000000 0.3125000000000000 2 3 0.4074074074074074 0.4197530864197530 2 4 0.4296875000000000 0.4453125000000000 2 5 0.4464000000000000 0.4640000000000000 2 6 0.4498456790123457 0.4714506172839506 2 7 0.4556434818825489 0.4752186588921283 2 8 0.4572753906250000 0.4794921875000000 2 9 0.4587715287303765 0.4798049077884470 2 10 0.4601000000000000 0.4825000000000000 3 2 0.3437500000000000 0.3437500000000000 3 3 0.4320987654320987 0.4513031550068587 3 4 0.4453125000000000 0.4733886718750000 3 5 0.4466559999999999 0.4813440000000000 3 6 0.4486454046639232 0.4821459190672153 3 7 0.4497020799156813 0.4847470016744723 3 8 0.4495086669921875 0.4870758056640625 3 9 0.4474984052792314 0.4862647029491515 3 10 0.4487690000000001 0.4860210000000000 4 2 0.3632812500000000 0.3632812500000000 4 3 0.4415485444292028 0.4657826550830667 4 4 0.4500732421875000 0.4824829101562500 4 5 0.4486016000000000 0.4881945600000000 4 6 0.4430863959381192 0.4883729376238378 5 2 0.3769531250000000 0.3769531250000000 5 3 0.4466290707717320 0.4737760165286457 6 2 0.3872070312500000 0.3872070312500000 7 2 0.3952636718750000 0.3952636718750000";
int main(){
	istringstream sin(ss);
	int d,b;
	double p,q;
	while(sin>>d>>b>>p>>q){
		ans[0][d][b]=p;
		ans[1][d][b]=q;
	}
	/*
	rep(d,1,11)rep(b,2,11){
		LL max=1;
		rep(i,0,d)max*=b+1;
		if(max>3000)continue;
		rep(i,0,max)rep(j,0,max)v[i][j]=0;
		VI w,c;
		w.PB(0);w.PB(0);
		c.PB(0);c.PB(0);
		s[0]=1;
		rep(i,1,d)s[i]=s[i-1]*(b+1);
		dfs(d,b,w,c);
		printf("%d %d %.16f %.16f ",d,b,f[0][0][0],f[1][0][0]);
		fflush(stdout);
	}*/
	freopen("greater.in","r",stdin);
	freopen("greater.out","w",stdout);
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}