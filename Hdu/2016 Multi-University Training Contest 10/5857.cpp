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
int w[MXN],n;
int f[MXN];
int g(int a,int b,int c){
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	if(b<=c)return b-a+1;
	if(a>c)return 0;
	return c-a+1;
}
int play(int a,int b,int c,int d,int K){
	int le=1,re=n;
	while(re>=le){
		if(re-le<=1){
			int me=le;
			int fm=g(a,b,f[me])+g(c,d,f[me]);
			//cout<<me<<"->"<<fm<<"\n";
			if(fm>=K)return le;
			else return re;
		}
		int me=(le+re)/2;
		int fm=g(a,b,f[me])+g(c,d,f[me]);
		//cout<<me<<"->"<<fm<<"\n";
		if(fm>=K)re=me;
		else le=me;
	}
}
void solve(){
	RI(n);DRI(q);
	rep(i,1,n+1)RI(w[i]);
	f[n]=n;
	for(int i=n-1;i>=1;i--){
		if(w[i]==w[i+1])f[i]=f[i+1];
		else f[i]=i;
	}
	while(q--){
		DRI(a);DRI(b);DRI(c);DRI(d);
		int tot=b-a+1+d-c+1;
		LL ans=0;
		if(tot&1)
			ans+=w[play(a,b,c,d,(tot+1)/2)]*2LL;
		else {
			ans+=w[play(a,b,c,d,tot/2)]*2LL;
			ans+=w[play(a,b,c,d,tot/2+1)]*2LL;
			ans/=2;
		}
		//cout<<ans<<"\n";
		if(ans<0)putchar('-'),ans=-ans;
		if(ans==0)cout<<"0.0\n";
		else if(ans%2==0)cout<<ans/2<<".0\n";
		else cout<<ans/2<<".5\n";
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}