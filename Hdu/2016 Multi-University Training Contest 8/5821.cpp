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

const int MXN = 1005;
int a[MXN],b[MXN];
int id[MXN];
bool solve(){
	DRI(n);
	DRI(m);
	rep(i,0,n)id[i]=-1;
	rep(i,0,n)RI(a[i]);
	rep(i,0,n)RI(b[i]);
	VPII A,B;
	rep(i,0,n)A.PB(MP(a[i],i));
	rep(i,0,n)B.PB(MP(b[i],i));
	sort(all(A));
	sort(all(B));
	int flag=1;
	rep(i,0,n){
		if(A[i].AA!=B[i].AA)
			flag=0;
		id[A[i].BB]=B[i].BB;
	}
	VPII L;
	rep(i,0,n)L.PB(MP(id[i],a[i]));
	while(m--){
		DRI(l);
		DRI(r);
		l--;
		sort(L.OP+l,L.OP+r);
	}
	rep(i,0,n)if(L[i].BB!=b[i])flag=0;
	return flag;
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		int flag=solve();
		printf("%s\n",flag?"Yes":"No");
	}
	return 0;
}