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

int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	rep(CA,1,_T+1){
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int>L[4];
		rep(i,0,4)rep(j,0,n){
			int x;
			scanf("%d",&x);
			L[i].PB(x);
		}
		map<int,int>P,Q;
		rep(i,0,n)rep(j,0,n){
			P[L[0][i]^L[1][j]]++;
			Q[L[2][i]^L[3][j]]++;
		}
		LL ans=0;
		for(auto p:P)ans+=1LL*p.BB*Q[p.AA^k];
		printf("Case #%d: %lld\n",CA,ans);
	}
	return 0;
}