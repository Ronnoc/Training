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
int sg[1<<20];
void solve(){
	int n;
	scanf("%d",&n);
	int w=0;
	rep(i,0,n){
		int m;
		scanf("%d",&m);
		int mask=0;
		rep(j,0,m){
			int p;
			scanf("%d",&p);
			mask|=1<<(20-p);
		}
		w^=sg[mask];
	}
	if(w)printf("YES\n");
	else printf("NO\n");
}

int v[22];
int main(){
	rep(mask,0,1<<20){
		rep(i,0,20)v[i]=0;
		int le=-20,re=-20;
		rep(i,0,20)if(mask>>i&1){
			if(i==re+1){
				if(le>0)v[(sg[mask^(1<<i)^(1<<(le-1))])]=1;
				re++;
			}else {
				if(i>0)v[(sg[mask^(1<<i)^(1<<(i-1))])]=1;
				re=le=i;
			}
		}
		rep(i,0,20)if(!v[i]){
			sg[mask]=i;
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