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

LL f[23][2][2][2];
int dig[23],ndig;		//ndig=max{i}:dig[i]!=0
LL dfs(int id,int who,int how,int even=1,int first=1){
	if(id==-1)return who!=how;
	//cout<<"cal"<<id<<" "<<who<<" "<<how<<" "<<even<<" "<<first<<"\n";
	if(!even&&~f[id][who][how][first])return f[id][who][how][first];
	LL ret=0;
	if(even){
		//cout<<"even "<<id<<" "<<who<<" "<<how<<" "<<even<<" "<<first<<"\n";
		if(first)
			ret+=dfs(id-1,dig[id]&1,1,1,0);
		else if(who==(dig[id]&1)){
			ret+=dfs(id-1,dig[id]&1,how^1,1,0);
		}else if(who!=how){
			ret+=dfs(id-1,dig[id]&1,1,1,0);
		}
	}
	if(first){
		//cout<<"first "<<id<<" "<<who<<" "<<how<<" "<<even<<" "<<first<<"\n";
		ret+=dfs(id-1,0,0,0,1);
	}
	int u=even?dig[id]-1:9;
	for(int i=first;i<=u;i++){
		//cout<<"from "<<i<<":"<<id<<" "<<who<<" "<<how<<" "<<even<<" "<<first<<"\n";
		if(first)
			ret+=dfs(id-1,i&1,1,0,0);
		else if(who==(i&1)){
			ret+=dfs(id-1,i&1,how^1,0,0);
		}else if(who!=how)
			ret+=dfs(id-1,i&1,1,0,0);
	}
	//cout<<id<<" "<<who<<" "<<how<<" "<<even<<" "<<first<<"\t=>"<<ret<<"\n";
	return even?ret:f[id][who][how][first]=ret;
}
LL gao(LL re){
	ndig=0;
	while(re){dig[ndig++]=re%10;re/=10;}
	return dfs(--ndig,0,0);	
}
const int MXN = 100005;
void solve(){
	LL L,R;
	cin>>L>>R;
	cout<<gao(R)-gao(L-1)<<"\n";
}

int main(){
	memset(f,-1,sizeof f);
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		cout<<"Case #"<<CA+1<<": ";
		solve();
	}
	return 0;
}