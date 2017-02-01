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

const int MXN = 1000000+5;
LL inv[MXN];
LL A[MXN];
LL Ai[MXN];
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(m==1){
		cout<<n<<"\n";
		return;
	}
	LL a=n-k*m-1;
	LL b=m-1;
	if(b>a){
		cout<<"0\n";
		return;
	}
	LL ans=A[a]*Ai[b]%MOD*Ai[a-b]%MOD*n%MOD*inv[m]%MOD;
	cout<<ans<<"\n";
}

int main(){
	int i;
	for(inv[1]=1,i=2;i<=1000000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
	A[0]=Ai[0]=1;
	rep(i,0,1000000)A[i+1]=A[i]*(i+1)%MOD;
	rep(i,0,1000000)Ai[i+1]=Ai[i]*inv[i+1]%MOD;
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}