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

const int MXN = 2000005;
char a[MXN],s[MXN];
int p[MXN];
int sl[MXN],sr[MXN];
int nl[MXN],nr[MXN];
void add(int &tp,int w){
	tp+=w;
	if(tp<0)tp+=MOD;
	if(tp>=MOD)tp-=MOD;
}
void solve(){
	while(~scanf("%s",a)){
		int len=strlen(a);
		int id=0;
		s[id++]='$';
		rep(i,0,len){
			s[id++]='#';
			s[id++]=a[i];
		}
		s[id++]='#';
		s[id]='\0';
		rep(i,0,id+2)sl[i]=sr[i]=p[i]=nl[i]=nr[i]=0;
		int mx=0,pid;
		rep(i,1,id){
			if(mx>i)p[i]=min(p[2*pid-i],p[pid]+pid-i);
			else p[i]=1;
			for(;s[i+p[i]]==s[i-p[i]];p[i]++);
			if(p[i]+i>mx)mx=p[i]+i,pid=i;
		}
		//rep(i,0,id)cout<<s[i]<<" ";cout<<"\n";
		//rep(i,0,id)cout<<p[i]<<" ";cout<<"\n";
		rep(i,0,id){
			add(sl[i],i);
			add(nl[i],1);
			add(sl[i+p[i]],-i);
			add(nl[i+p[i]],-1);
			add(sr[i-p[i]],-i);
			add(nr[i-p[i]],-1);
			add(sr[i],i);
			add(nr[i],1);
		}
		rep(i,1,id+1){
			add(sl[i],sl[i-1]);
			add(nl[i],nl[i-1]);
			add(sr[id-i],sr[id-i+1]);
			add(nr[id-i],nr[id-i+1]);
		}
		int ans=0;
		rep(i,1,id)if((i&1)==0&&i+2<id){
			LL fl=2LL*sl[i]-1LL*nl[i]*i;
			LL fr=2LL*sr[i+2]-1LL*nr[i+2]*(i+2);
			add(ans,int(fl%MOD*(fr%MOD)%MOD));
		}
		LL inv=(MOD+1)/4;
		ans=1LL*ans*inv%MOD;
		cout<<ans<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}