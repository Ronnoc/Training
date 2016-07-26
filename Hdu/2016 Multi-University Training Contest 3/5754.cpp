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

int sg[1005][1005];
int vis[3][2005];
int ff[1005][1005];
void solve(){
	int type,n,m;
	scanf("%d%d%d",&type,&n,&m);
	n--;m--;
	if(type==1){
		if(sg[n][m])printf("B\n");
		else printf("G\n");
		return;
	}
	if(type==2){
		if(n==m)printf("G\n");
		else printf("B\n");
		return;
	}
	if(type==4){
		if(ff[n][m])printf("G\n");
		else printf("B\n");
		return;
	}
	while(n>=3&&m>=3)n-=3,m-=3;
	if(n==1&&m==2){
		printf("B\n");
		return;
	}
	if(n==2&&m==1){
		printf("B\n");
		return;
	}
	if(n==0&&m==0){
		printf("G\n");
		return;
	}
	printf("D\n");
}


int main(){
	memset(vis,0,sizeof vis);
	rep(i,0,1000)rep(j,0,1000){
		if(!vis[0][i]&&!vis[1][j]&&!vis[2][i-j+1000]){
			ff[i][j]=1;
			vis[0][i]=vis[1][j]=vis[2][i-j+1000]=1;
		}else ff[i][j]=0;
	}
	rep(i,0,1000)rep(j,0,1000){
		int vis[4];
		rep(k,0,4)vis[k]=0;
		if(i)vis[sg[i-1][j]]=1;
		if(j)vis[sg[i][j-1]]=1;
		if(i&&j)vis[sg[i-1][j-1]]=1;
		rep(k,0,4)if(!vis[k]){
			sg[i][j]=k;
			break;
		}
	}
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}