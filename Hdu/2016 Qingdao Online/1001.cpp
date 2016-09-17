//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
void solve(){
	
}

VL Z;
int g[4]={2,3,5,7};
LL f[4][33];
int main(){
	rep(i,0,4){
		f[i][0]=1;
		rep(j,1,31)f[i][j]=f[i][j-1]*g[i];
	}
	rep(i,0,31){
		rep(j,0,31){
			rep(k,0,31){
				rep(r,0,31){
					LL t=f[0][i]*f[1][j]*f[2][k]*f[3][r];
					Z.PB(t);
					if(f[0][i]*f[1][j]*f[2][k]*f[3][r]>1234800000)break;
				}
				if(f[0][i]*f[1][j]*f[2][k]>1234800000)break;
			}
			if(f[0][i]*f[1][j]>1234800000)break;
		}
	}
	sort(Z.OP,Z.ED);
	int _T=1;
	scanf("%d",&_T);
	
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		DRI(m);
		printf("%I64d\n",*lower_bound(all(Z),m));
	}
	return 0;
}