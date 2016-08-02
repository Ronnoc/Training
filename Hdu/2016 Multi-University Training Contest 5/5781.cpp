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
double E[2005][2005];
int id[2005][2005];
void solve(){
	int K,W;
	while(~scanf("%d%d",&K,&W))
		printf("%6f\n",E[W][K]);
}

int main(){
	int up=2000;
	rep(i,0,up+1)rep(j,0,up+1)E[i][j]=1e10;
	E[0][0]=0;
	rep(i,1,up+1){
		E[i][0]=0;
		id[i][0]=1;
		rep(j,1,up+1){
			int jd=id[i][j]=id[i][j-1];
			E[i][j]=1+(E[i][j-jd]*(j+1-jd)+E[i-1][jd-1]*jd)/(j+1);
			while(id[i][j]<j){
				int jd=id[i][j]+1;
				double exp=1+(E[i][j-jd]*(j+1-jd)+E[i-1][jd-1]*jd)/(j+1);
				if(exp<=E[i][j])E[i][j]=exp,id[i][j]++;
				else break;
			}
		}
	}
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}
/*
[0-4] 2
.4 [0-1] 1 
.6 [0-2] 1
*/