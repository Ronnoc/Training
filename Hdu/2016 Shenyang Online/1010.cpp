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
const int MXN = 3000000+5;
const int LIM = MXN-5;
int p[MXN/10], pn;
int flag[MXN];	//true为合数
//for(inv[1]=1,i=2;i<10000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
void sieve(int n) {
	pn = 0;
	flag[1]= 1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			p[pn ++ ] = i;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	flag[1]=0;
	rep(i,2,n+1)flag[i]=flag[i-1]+(!flag[i]);
}
LL f[10005][627];
LL play(LL m,LL n){
	if(n==0)return m;
	if(m<=10000){
		if(f[m][n]!=-1)return f[m][n];
		return f[m][n]=play(m,n-1)-play(m/p[n-1],n-1);
	}
	//if(m>4000)cout<<m<<","<<n<<"\n";
	return play(m,n-1)-play(m/p[n-1],n-1);
}
LL gao(LL m){
	if(m<=LIM)
		return flag[m];
	LL _3=pow(1.*m,1./3)-1;
	_3=max(_3,0LL);
	while(_3*_3*_3<=m)_3++;_3--;
	LL _2=sqrt(1.*m)-1;
	_2=max(_2,0LL);
	while(_2*_2<=m)_2++;_2--;
	LL n=flag[_3],u=flag[_2]-n;
	LL ans=play(m,n)+n*(u+1)+u*(u-1)/2-1;
	rep(k,1,u+1)
		ans-=gao(m/p[n+k-1]);
	return ans;
}
void solve(){
	LL m;
	while(cin>>m){
		cout<<gao(m)<<"\n";
	}
}

int main(){
	memset(f,-1,sizeof f);
	sieve(LIM);
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}