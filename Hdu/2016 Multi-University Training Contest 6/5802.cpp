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

const int MXN = 100005;
int dm[55];
pair<PII,PII> S[MXN];
int ql,qr;
int play(int p,int q){
	if(p<=q)return q-p;
	ql=qr=0;
	S[qr++]=MP(MP(0,p),MP(30,0));
	int ans=q+30;
	while(qr>ql){
		pair<PII,PII> pr =S[ql++];
		//cout<<pr.AA.AA<<" "<<pr.AA.BB<<" "<<pr.BB.AA<<" "<<pr.BB.BB<<"\n";
		int now=pr.AA.BB;
		int cnt=pr.AA.AA;
		rep(i,1,pr.BB.AA){
			int dlt=(1<<i)-1;
			if(now-dlt<=q){
				int mv=q-max(now-dlt,0);
				cmax(mv,pr.BB.BB);
				cmin(ans,cnt+i+mv);
			}else {
				if(now-dlt-q<=dm[i-1])
					S[qr++]=(MP(MP(cnt+i,now-dlt),MP(i,pr.BB.BB+1)));
			}
		}
	}
	return ans;
}
int bf(int p,int q){
	set<pair<int,PII> >S;
	S.insert(MP(0,MP(p,0)));
	while(!S.empty()){
		pair<int,PII> pr=*S.OP;
		//cout<<pr.AA<<" "<<pr.BB.AA<<" "<<pr.BB.BB<<"\n";
		S.erase(S.OP);
		if(pr.BB.AA==q)return pr.AA;
		if(pr.BB.AA<q)
			S.insert(MP(pr.AA+q-pr.BB.AA,MP(q,0)));
		else {
			S.insert(MP(pr.AA+1,MP(pr.BB.AA+1,0)));
			if(pr.BB.BB)
				S.insert(MP(pr.AA+1,MP(pr.BB.AA,0)));
			S.insert(MP(pr.AA+1,MP(max(0,pr.BB.AA-(1<<pr.BB.BB)),pr.BB.BB+1)));
		}
	}
}
void solve(){
	int q,p;
	//q=rand()%1000,p=q+rand()%1000;
	scanf("%d%d",&p,&q);
	int ans=play(p,q);
	printf("%d\n",ans);
	/*int truth=bf(p,q);
	if(truth!=ans)
		cout<<"when "<<p<<" "<<q<<" truth = "<<truth<<" ans = "<<ans<<"\n";*/
}


int main(){
	srand(time(NULL));
	dm[0]=0;
	rep(i,1,31)dm[i]=dm[i-1]+(1<<i)-1;
	int _T=300000;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	//cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}