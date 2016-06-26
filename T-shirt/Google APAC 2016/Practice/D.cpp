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

LL f[20000005];
int a[200005];
int S[200005];
LL SS[200005];
LL check(int me,int N){
	if(~f[me])return f[me];
	f[me]=0;
	rep(i,1,N+1)if(S[i]>=me){
		//S[i]-S[j]<=me
		//S[j]>=S[i]-me
		int id=lower_bound(S,S+i,S[i]-me)-S;//S[id]>=S[i]-me
		f[me]+=i-id;
	}else f[me]+=i;
	return f[me];
}
void solve(){
	memset(f,-1,sizeof f);
	int N,Q;
	scanf("%d%d",&N,&Q);
	rep(i,0,N)scanf("%d",&a[i+1]);
	S[0]=0;
	rep(i,0,N)S[i+1]=S[i]+a[i+1];
	SS[0]=0;
	rep(i,0,N)SS[i+1]=SS[i]+S[i+1];
	while(Q--){
		LL a,b;
		scanf("%lld%lld",&a,&b);
		//cerr<<a<<"?"<<b<<"\n";
		int le,re,ge;
		le=0,re=S[N],ge=-1;
		while(re>=le){//max ge s.t. num of SOS[i]<=ge <b
			if(re-le<=1){
				if(check(re,N)<b)ge=re;
				else ge=le;
				break;
			}
			int me=(le+re)>>1;
			LL fm=check(me,N);
			if(fm<b)le=me;
			else re=me;
		}
		int gb=ge;
		le=0,re=S[N],ge=-1;
		while(re>=le){//max ge s.t. num of SOS[i]<=ge <a
			if(re-le<=1){
				if(check(re,N)<a)ge=re;
				else ge=le;
				break;
			}
			int me=(le+re)>>1;
			LL fm=check(me,N);
			if(fm<a)le=me;
			else re=me;
		}
		int ga=ge;
		check(gb+1,N);
		check(gb,N);
		check(ga+1,N);
		check(ga,N);
		//cerr<<"ga = "<<ga<<" gb = "<<gb<<"\n";
		if(ga==gb){
			//cerr<<"\n"<<(b-a+1)<<" * "<<ga+1<<"\n";
			LL ans=1LL*(b-a+1)*(ga+1);
			printf("%lld\n",ans);
			continue;
		}
		LL ans=0;
		//cerr<<"\n";
		//cerr<<(f[ga+1]-a+1)<<" * "<<ga+1<<"\n";
		//cerr<<(b-f[gb])<<" * "<<gb+1<<"\n";
		ans+=1LL*(f[ga+1]-a+1)*(ga+1);
		ans+=1LL*(b-f[gb])*(gb+1);
		//[ga+2,gb];
		rep(i,1,N+1){
			//ga+2<=S[i]-S[j]<=gb
			//S[i]-gb<=S[j]<=S[i]-ga-2
			int lid=lower_bound(S,S+i,S[i]-gb)-S;
			int rid=upper_bound(S,S+i,S[i]-ga-2)-S-1;
			ans+=1LL*(rid-lid+1)*S[i];
			if(rid>=0)ans-=SS[rid];
			if(lid>=1)ans+=SS[lid-1];
			
		}
		printf("%lld\n",ans);
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d:\n",CA+1);
		solve();
	}
	return 0;
}